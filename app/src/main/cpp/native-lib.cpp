#include <jni.h>
#include <string>
#include "PPM.h"
#include "native-lib.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_yolis_firstnativecapp_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jbyteArray JNICALL
Java_com_yolis_firstnativecapp_MainActivity_compressString(
        JNIEnv *env,
        jobject instance,
        jstring inputString) {
    PPM *ppm = new PPM();
    std::string out = ppm->run("c", jstring2string(env, inputString));
    delete ppm;
    jbyteArray ret = env->NewByteArray(static_cast<jsize>(out.size()));
    env->SetByteArrayRegion (ret, 0, static_cast<jsize>(out.size()), out.getBytes());
    return getByteArray(env, out.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_yolis_firstnativecapp_MainActivity_decompressString(
        JNIEnv *env,
        jobject instance,
        jbyteArray inputData) {
    PPM *ppm = new PPM();
    std::string out = ppm->run("d", jstring2string(env, inputString));
    delete ppm;
    return env->NewStringUTF(out.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_yolis_firstnativecapp_MainActivity_compressDecompressString(
        JNIEnv *env,
        jobject instance,
        jstring inputString) {
    PPM *ppm = new PPM();
    std::string out = ppm->run("c", jstring2string(env, inputString));
    std::string reverse = ppm->run("d", out);
    delete ppm;
    return env->NewStringUTF(reverse.c_str());
}

std::string jstring2string(JNIEnv *env, jstring jStr) {
    if (!jStr)
        return "";

    const jclass stringClass = env->GetObjectClass(jStr);
    const jmethodID getBytes = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
    const jbyteArray stringJbytes = (jbyteArray) env->CallObjectMethod(jStr, getBytes, env->NewStringUTF("UTF-8"));

    size_t length = (size_t) env->GetArrayLength(stringJbytes);
    jbyte* pBytes = env->GetByteArrayElements(stringJbytes, NULL);

    std::string ret = std::string((char *)pBytes, length);
    env->ReleaseByteArrayElements(stringJbytes, pBytes, JNI_ABORT);

    env->DeleteLocalRef(stringJbytes);
    env->DeleteLocalRef(stringClass);
    return ret;
}

jbyteArray getByteArray(JNIEnv *env, std::string jStr) {

    const jclass stringClass = env->GetObjectClass(jStr);
    const jmethodID getBytes = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
    const jbyteArray stringJbytes = (jbyteArray) env->CallObjectMethod(jStr, getBytes, env->NewStringUTF("UTF-8"));

    return stringJbytes;
}


