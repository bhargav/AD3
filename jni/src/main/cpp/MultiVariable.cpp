#include "edu_cmu_cs_ark_ad3_AD3Jni.h"
#include "MultiVariable.h"

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    MultiVariable
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_MultiVariable
  (JNIEnv *env, jclass cls) {
    AD3::MultiVariable *variable = new AD3::MultiVariable();
    return reinterpret_cast<jlong>(variable);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    MultiVariable_GetNumStates
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_MultiVariable_1GetNumStates
  (JNIEnv *env, jclass cls, jlong handle) {
    AD3::MultiVariable *m = reinterpret_cast<AD3::MultiVariable *>(handle);
    return m->GetNumStates();
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    MultiVariable_GetState
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_MultiVariable_1GetState
  (JNIEnv *env, jclass cls, jlong handle, jint i) {
    AD3::MultiVariable *m = reinterpret_cast<AD3::MultiVariable *>(handle);
    AD3::BinaryVariable *b = m->GetState(i);
    return reinterpret_cast<jlong>(b);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    MultiVariable_GetLogPotential
 * Signature: (JI)D
 */
JNIEXPORT jdouble JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_MultiVariable_1GetLogPotential
  (JNIEnv *env, jclass cls, jlong handle, jint i) {
    AD3::MultiVariable *m = reinterpret_cast<AD3::MultiVariable *>(handle);
    return m->GetLogPotential(i);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    MultiVariable_SetLogPotential
 * Signature: (JID)V
 */
JNIEXPORT void JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_MultiVariable_1SetLogPotential
  (JNIEnv *env, jclass cls, jlong handle, jint i, jdouble log_potential) {
    AD3::MultiVariable *m = reinterpret_cast<AD3::MultiVariable *>(handle);
    m->SetLogPotential(i, log_potential);
  }