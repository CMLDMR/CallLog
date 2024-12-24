cmake_minimum_required(VERSION 3.16)

project(MongoCoreItem)

find_package(OpenSSL REQUIRED)

find_package(bsoncxx REQUIRED)
include_directories(${LIBBSONCXX_INCLUDE_DIR})

add_library(MongoCoreItem
    item.h
    item.cpp
)

target_link_libraries(MongoCoreItem PUBLIC mongo::bsoncxx_shared OpenSSL::SSL OpenSSL::Crypto )
target_include_directories(MongoCoreItem PUBLIC "/usr/local/include/bsoncxx/v_noabi")
target_include_directories(MongoCoreItem PUBLIC "/usr/local/include/libbson-1.0")


