//
// Created by speen1 on 2020/3/4.
//

#ifndef XPLAY_IDEMUX_H
#define XPLAY_IDEMUX_H

#include "XData.h"
#include "XParameter.h"
#include "IObserver.h"

class IDemux :public IObserver{
public:
    //打开文件，或者流媒体 rmtp http rtsp
    virtual bool Open(const char *url) = 0;//纯虚函数 即是接口

    //seek 位置 pos 0.0~1.0
    virtual bool Seek(double pos) = 0;
    //关闭文件，或者流媒体 rmtp http rtsp
    virtual void Close() = 0;

    //获取视频参数
    virtual XParameter GetVPara() = 0;

    //获取音频参数
    virtual XParameter GetAPara() = 0;

    //读取一帧数据，数据由调用者清理
    virtual XData Read() = 0;

    //总时长（毫秒）
    int totalMs = 0;
protected:
    virtual void Main();
};


#endif //XPLAY_IDEMUX_H
