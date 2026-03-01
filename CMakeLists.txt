cmake_minimum_required(VERSION 3.10)

project(ThreadSafeValidator CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

set(CLIENT_SOURCES
    src/main_client.cpp
    src/client_application.cpp
    src/validator.cpp
)

add_executable(process1 ${CLIENT_SOURCES})

target_link_libraries(process1 PRIVATE Threads::Threads)

set(SERVER_SOURCES
    src/main_server.cpp
    src/server_application.cpp
)

add_executable(process2 ${SERVER_SOURCES})