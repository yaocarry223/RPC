# CMakeLists.txt
if(UNIX OR APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -std=c++11")
endif()

cmake_minimum_required(VERSION 3.0)
project(mprpc)
#生产debug版本 可以进行调试
#set(CMAKE_BUILD_TYPE "Debug")
#设置可执行文件输出的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#设置项目库件输出的路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#设置项目编译头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)
#设置项目库文件搜索路径
link_directories(${PROJECT_SOURCE_DIR}/lib)
# src包含了mprpc框架所有的相关代码
add_subdirectory(src)
# example 包含了mprpc框架的示例代码
add_subdirectory(example)