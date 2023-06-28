#pragma once  //防止头文件被重复包含
#include<unordered_map>
#include<string>

//rpcserverip repcservicrport zookeeperip  zookeeperport
//框架读取配置文件类

class Mprpcconfig
{
public:
    //负责解析加载配置文件
    void LoadConfigFile(const char *config_file);
    //查询配置项信息
    std::string Load(std::string key);
private:
    std::unordered_map<std::string, std:: string> m_configMap;    
};