cmake_minimum_required(VERSION 3.8)
project(memMappedQ)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp IQueue.h ArrayQ.cpp ArrayQ.h EmptyQException.h LLQ.cpp LLQ.h MMQ.cpp MMQ.h)
add_executable(memMappedQ ${SOURCE_FILES})