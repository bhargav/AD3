#include "edu_cmu_cs_ark_ad3_AD3Jni.h"
#include "Factor.h"

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    BinaryVariable
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_BinaryVariable
  (JNIEnv *env, jclass cls) {
    AD3::BinaryVariable *variable = new AD3::BinaryVariable();
    return reinterpret_cast<jlong>(variable);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    BinaryVariable_Dispose
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_BinaryVariable_1Dispose
        (JNIEnv *env, jclass cls, jlong handle) {
    AD3::BinaryVariable *b = reinterpret_cast<AD3::BinaryVariable *>(handle);
    delete b;
}

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    BinaryVariable_GetLogPotential
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_BinaryVariable_1GetLogPotential
  (JNIEnv *env, jclass cls, jlong handle) {
    AD3::BinaryVariable *b = reinterpret_cast<AD3::BinaryVariable *>(handle);
    return b->GetLogPotential();
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    BinaryVariable_SetLogPotential
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_BinaryVariable_1SetLogPotential
  (JNIEnv *env, jclass cls, jlong handle, jdouble log_potential) {
    AD3::BinaryVariable *b = reinterpret_cast<AD3::BinaryVariable *>(handle);
    b->SetLogPotential(log_potential); 
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    BinaryVariable_GetId
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_BinaryVariable_1GetId
  (JNIEnv *env, jclass cls, jlong handle) {
    AD3::BinaryVariable *b = reinterpret_cast<AD3::BinaryVariable *>(handle);
    return b->GetId();
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    BinaryVariable_Degree
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_BinaryVariable_1Degree
  (JNIEnv *env, jclass cls, jlong handle) {
    AD3::BinaryVariable *b = reinterpret_cast<AD3::BinaryVariable *>(handle);
    return b->Degree();
  }