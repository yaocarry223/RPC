#aux_source_directory(. SRC_LIST) #cmakelist没改动是不生成makefile的
set(SRC_LIST mprpcapplication.cc mprpcconfig.cc rpcheader.pb.cc rpcprovider.cc)
add_library(mprpc  ${SRC_LIST})
target_link_libraries(mprpc   muduo_net muduo_base  pthread)