#include "mprpcapplication.h"
#include<unistd.h>
#include<iostream>
void ShowArgsHelp()
{
    std::cout << "format comand -i <configfile" << std::endl;
}
void MprpcApplication::Init(int argc ,char **argv)
{
    if(argc < 2)
    {
        ShowArgsHelp();
        exit(EXIT_FAILURE);
    }
    
    int c = 0;
    std::string config_file;
    while((c = getopt(argc,argv,"i :")) != -1)
    {
        switch (c)
        {
        case 'i':
            config_file = optarg;
            break;
        case '?':
            std::cout << "invalid args!"<<std::endl;
            ShowArgsHelp();
            break;
        case ':':
            std::cout << "need<configfile>" << std::endl;
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        default:
            break;
        }
    }
    //开始加载文件 rocserver_ip=  rpcserver_port zookeeper_ip = zookepper_port=
}
MprpcApplication& MprpcApplication::GetInstance()
{
    static MprpcApplication app;
    return app;   
}