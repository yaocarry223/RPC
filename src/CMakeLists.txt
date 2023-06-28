aux_source_directory(. SRC_LIST) #cmakelist没改动是不生成makefile的

add_library(mprpc SHARED ${SRC_LIST})