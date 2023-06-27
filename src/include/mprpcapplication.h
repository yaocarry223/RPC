#pragma once



// mprpc框架的基础类

class MprpcApplication
{
public:
    static void Init(int argc, char **argv);
    static MprpcApplication& GetInstance();
   
private:
    MprpcApplication(){}
    MprpcApplication(const MprpcApplication&) = delete;
    MprpcApplication operator=(const MprpcApplication&) = delete;
};