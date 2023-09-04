cmake_minimum_required(VERSION 3.25)
project(allinOne)

set(CMAKE_CXX_STANDARD 17)

add_executable(allinOne main.cpp Proc_PC.h Proc_PC.cpp ProcessMange.h ProcessManage.cpp DeviceManage.h DeviceManage.cpp FileManage.h FileManage.cpp MemoryManage.h MemoryManage.cpp Proc_Priority.h Proc_Priority.cpp Proc_FCFS.h Proc_FCFS.cpp Proc_ROUND.h Proc_ROUND.cpp Dev_Bank.h Dev_Bank.cpp Mem_FIFO.h Mem_FIFO.cpp Mem_LRU.h Mem_LRU.cpp)
