#pragma once
#include "mprpcconfig.h"


// mprpc框架的基础类

class MprpcApplication
{
public:
    static void Init(int argc, char **argv);
    static MprpcApplication& GetInstance();
   
private:
    static Mprpcconfig m_config;

    MprpcApplication(){}
    MprpcApplication(const MprpcApplication&) = delete;
    MprpcApplication operator=(const MprpcApplication&) = delete;
};