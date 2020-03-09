#include <jni.h>
#include <string>
#include "FFDemux.h"
#include "FFDecode.h"
#include <android/native_window_jni.h>
#include "XLog.h"
#include "IPlayerProxy.h"

extern "C"
JNIEXPORT
jint JNI_OnLoad(JavaVM *vm,void *res)
{
    IPlayerProxy::Get()->Init(vm);
    //IPlayerProxy::Get()->Open("/sdcard/v1080.mp4");
    //IPlayerProxy::Get()->Start();
    return JNI_VERSION_1_4;
}


extern "C"
JNIEXPORT void JNICALL
Java_xplay_xplay_XPlay_InitView(JNIEnv *env, jobject instance, jobject surface) {

    ANativeWindow* win = ANativeWindow_fromSurface(env,surface);
    IPlayerProxy::Get()->InitView(win);
    //XEGL::Get()->Init(win);
    //XShader shader;
    //shader.Init();

}

extern "C"
JNIEXPORT void JNICALL
Java_xplay_xplay_OpenUrl_Open(JNIEnv *env, jobject instance, jstring url_) {
    const char *url = env->GetStringUTFChars(url_, 0);

    IPlayerProxy::Get()->Open(url);
    IPlayerProxy::Get()->Start();

    env->ReleaseStringUTFChars(url_, url);
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_xplay_xplay_MainActivity_PlayPos(JNIEnv *env, jobject instance) {

    return IPlayerProxy::Get()->PlayPos();

}

extern "C"
JNIEXPORT void JNICALL
Java_xplay_xplay_MainActivity_Seek(JNIEnv *env, jobject instance, jdouble pos) {

    IPlayerProxy::Get()->Seek(pos);
}

extern "C"
JNIEXPORT void JNICALL
Java_xplay_xplay_XPlay_PlayOrPause(JNIEnv *env, jobject instance) {

    IPlayerProxy::Get()->SetPause(!IPlayerProxy::Get()->IsPause());

}