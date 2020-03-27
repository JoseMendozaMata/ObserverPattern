cmake_minimum_required(VERSION 3.15)
project(ObserverPattern)

set(CMAKE_CXX_STANDARD 14)

add_executable(ObserverPattern main.cpp App/SubService.cpp App/SubService.h DataStructures/SubsLinkedList.cpp DataStructures/SubsLinkedList.h Client/ClientNode.cpp Client/ClientNode.h)