#include<iostream>
#include<string>
#include "friend.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"
#include <vector>
#include<logger.h>
class FriendService : public fixbug::FriendServiceRpc
{
public:
    std::vector<std::string> GetFriendsList(uint32_t userid)
    {
        std::cout << "do GetFriendsList service! userid:" << userid << std::endl;
        std::vector<std::string> vec;
        vec.push_back("gao yang");
        vec.push_back("liu hong");
        vec.push_back("wang shuo");
        return vec;
    }

    // 重写基类方法
    void GetFriendsList(::google::protobuf::RpcController* controller,
                       const ::fixbug::GetFriendListRequest* request,
                       ::fixbug::GetFriendListRespose* response,
                       ::google::protobuf::Closure* done)
    {
        //std::cout << "进入重写基类方法" <<std::endl;
        uint32_t userid = request->userid();
        std::vector<std::string> friendsList = GetFriendsList(userid);
        response->mutable_result()->set_errcode(0);
        response->mutable_result()->set_errmsg("");

        
        for (std::string &name : friendsList)
        {
            std::string *p = response->add_friends();
            *p = name;
        }
        done->Run();
    }
};


int main(int argc, char **argv)
{
    //调用框架初始化操作
    Log_INFO("first log message!");
    Log_ERR("%s:%s:%s",__FILE__, __FUNCTION__, __LINE__);
    MprpcApplication::Init(argc, argv);

    //provider是一个rpc网络服务启动一个rpc服务发布节点
    RpcProvider provider;
    provider.NotifyService(new FriendService());

    //启动一个rpc服务发布节点  Run以后，进程进入阻塞状态，等待远程rpc调用
    provider.Run();
    return 0;
}