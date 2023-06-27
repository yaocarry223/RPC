#include "test.pb.h"
#include<iostream>
using namespace fixbug;
int main(){
    /*LoginRespose rsp;
    ResultCode *rc = rsp.mutable_rrsult();
    rc->set_errcode("登录处理失败了");
    */
    GetFriendListResponse rsp;
    ResultCode *rc = rsp.mutable_result();  //消息类型里面有对象 用mutable_来操作
    rc->set_errcode(0);
    //新增加好友对象
    User *user1 = rsp.add_friend_list();
    user1->set_name("zhang san");
    user1->set_age(20);
    user1->set_sex(User::MAN);
     
    
    User *user2 = rsp.add_friend_list();
    user2->set_name("li si");
    user2->set_age(22);
    user2->set_sex(User::MAN);
    std::cout << rsp.friend_list_size() << std::endl;

    

    return 0;
}
int main1(){
    //封装了login请求对象的数据
    LoginRequst req;
    req.set_name("zhang san");
    req.set_pwd("123456");

    std::string send_str;
    //对象数据序列化 ----》 char*
    if(req.SerializeToString(&send_str)){
        std::cout << send_str.c_str() << std::endl;
    }

    //从send_str反序列化一个login请求对象
    LoginRequst reqB;
    if(reqB.ParseFromString(send_str)){
        std::cout << reqB.name() << std::endl;
        std::cout << reqB.pwd() << std::endl;
    }
    return 0;
}