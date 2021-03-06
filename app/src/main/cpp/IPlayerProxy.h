//
// Created by speen1 on 2020/3/6.
//

#ifndef XPLAY_IPLAYERPROXY_H
#define XPLAY_IPLAYERPROXY_H
#include "IPlayer.h"
#include <mutex>
class IPlayerProxy: public IPlayer {
public:
    static IPlayerProxy* Get()
    {
        static IPlayerProxy px;
        return &px;
    }
    void Init(void *vm = 0);

    virtual bool Open(const char *path);
    virtual bool Seek(double pos);
    virtual void Close();
    virtual bool Start();
    virtual void InitView(void *win);
    virtual void SetPause(bool isP);
    virtual bool IsPause();
    //获取当前的播放进度 0.0 ~ 1.0
    virtual double PlayPos();

protected:
    IPlayerProxy(){}
    IPlayer *player = 0;
    std::mutex mux;
};


#endif //XPLAY_IPLAYERPROXY_H
