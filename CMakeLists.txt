cmake_minimum_required(VERSION 3.16)
project(ficha-1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(ficha-1
    src/main.cpp
    src/validator.cpp
)

find_package(Threads REQUIRED)
target_link_libraries(ficha-1 Threads::Threads)