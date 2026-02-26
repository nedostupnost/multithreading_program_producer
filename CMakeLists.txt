cmake_minimum_required(VERSION 3.10)

project(ThreadSafeValidator CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

set(SOURCES
    src/main.cpp
    src/application.cpp
    src/validator.cpp
)

add_executable(app ${SOURCES})

target_link_libraries(app PRIVATE Threads::Threads)