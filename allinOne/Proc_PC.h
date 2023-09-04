//
// Created by fengzhanwei on 2023/8/31.
//

#ifndef ALLINONE_PROC_PC_H
#define ALLINONE_PROC_PC_H

#include <windows.h>
#include <conio.h>
#include <stdio.h>

namespace PC {
    void Proclucer();//生产者函数
    void Consumer();//消费者函数
    int tStop(); //停止函数
    void Start();//开始函数
    void shengcanzexiaofeize(); //主函数
}

#endif //ALLINONE_PROC_PC_H
