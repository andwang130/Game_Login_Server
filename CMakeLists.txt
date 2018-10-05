cmake_minimum_required(VERSION 3.10)
project(LoginServer)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")#多线程需要的参数
add_executable(LoginServer main.cpp Net/Acceptor.cpp Net/Acceptor.h Net/Mboost.cpp Net/Mboost.h Net/Socket.cpp Net/Socket.h Net/TcpServer.cpp Net/TcpServer.h Net/Types.h Net/StringPiece.h Net/EventloopThread.cpp Net/EventloopThread.h Net/CurrentThread.h Net/Eventloop.cpp Net/Channel.cpp Net/Epollpoller.cpp Net/CurrentThread.h Net/EventloopThreadpool.cpp Net/EventloopThreadpool.h Net/inetAddress.cpp Net/Tcpcoonetion.cpp Net/TcpServer.cpp Net/Buffer.cpp commds.h intermediary.h Handler/LoginHandler.cpp Handler/LoginHandler.h Handler/BaseHandler.cpp Handler/BaseHandler.h Model/User.h Model/User.cpp)