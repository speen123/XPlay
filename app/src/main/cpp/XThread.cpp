//
// Created by speen1 on 2020/3/4.
//

#include "XThread.h"
#include "XLog.h"
#include <thread>
using namespace std;


void XSleep(int mis) {
    chrono::milliseconds du(mis);
    this_thread::sleep_for(du);
}

void XThread::SetPause(bool isP)
{
    isPause = isP;
    //等待100毫秒
    for(int i = 0; i < 10; i++) {
        if(isPausing == isP) {
            break;
        }
        XSleep(10);
    }
}

//启动线程
bool XThread::Start()
{
    isExit = false;
    isPause = false;
    thread th(&XThread::ThreadMain,this);//存储当前线程指针 创建一个线程
    th.detach();//放弃对线程的控制
    return true;
}
void XThread::ThreadMain()
{
    isRuning = true;
    XLOGI("线程函数进入");
    Main();
    XLOGI("线程函数退出");
    isRuning = false;
}


//通过控制isExit安全停止线程（不一定成功）
void XThread::Stop()
{XLOGI("Stop 停止线程begin!");
    isExit = true;
    for(int i = 0; i < 200; i++)
    {
        if(!isRuning)
        {
            XLOGI("Stop 停止线程成功!");
            return;
        }
        XSleep(1);
    }
    XLOGI("Stop 停止线程超时!");

}
