#include<iostream>
#include<string>
#include "user.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"
#include "logger.h"


/*
  UserService原来是一个本地服务，提供两个进程内的本地方法Login和GetFriendLists
*/

class UserService : public fixbug::UserServiceRpc  //使用者RPC服务发布段（rpc服务提供者）
{
public:
    
    bool Login(std::string name,std::string pwd)
    {
        std::cout << "doing local service: Login" << std::endl;
        std::cout << "name: "<< name << "pwd: "<< pwd <<std::endl;
        return true;
    }
    bool Register(uint32_t id,std::string name,std::string pwd)
    {
        std::cout << "doing local service: Register" <<std::endl;
        std::cout << "id:" << id <<"name: " << name << "pwd: "<< std::endl;
    }
    /*
    //重写基类UserServiceRpc的虚函数  下面这些方法都是框架直接调用的
    1. caller   ---->  Login(LoginRequest)  -> muduo -> callee
    2. Callee  ---->   Login(LoginRequest) -> 交到下面重写的这个Login方法上
    */

    virtual void Login(::google::protobuf::RpcController* controller,
                       const ::fixbug::LoginRequest* request,
                       ::fixbug::LoginRespose* response,
                       ::google::protobuf::Closure* done)
    {
        //框架给业务上报了请求参数LoginRequest,应用获取相应数据做本地业务
        std::string name = request->name();
        std::string pwd = request->pwd();
        //做本地业务
        bool Login_result = Login(name,pwd); 
        //把相应写入
        fixbug::ResultCode *Code = response->mutable_result();
        Code->set_errcode(0);
        Code->set_errmsg("");
        response->set_sucess(Login_result);

        //执行回调操作  执行响应对象数据的序列化和网络发生由框架完成
        done->Run();

    }
    void Register(::google::protobuf::RpcController* controller,
                       const ::fixbug::RegisterRequest* request,
                       ::fixbug::RegisterRespose* response,
                       ::google::protobuf::Closure* done)
    {
        uint32_t id = request->id();
        std::string name = request->name();
        std::string pwd = request->pwd();

        //做本地业务
        bool ret = Register(id,name,pwd);
        //写入响应
        response->mutable_result()->set_errcode(0);
        response->mutable_result()->set_errmsg("");
        response->set_sucess(ret);

        //执行回调  把填好的响应序列化并通过网络框架发回prc_client
        done->Run(); 
    }
};

int main(int argc, char **argv)
{
    //调用框架初始化操作
    
    MprpcApplication::Init(argc, argv);

    //provider是一个rpc网络服务启动一个rpc服务发布节点
    RpcProvider provider;
    provider.NotifyService(new UserService());

    //启动一个rpc服务发布节点  Run以后，进程进入阻塞状态，等待远程rpc调用
    provider.Run();
    return 0;
}