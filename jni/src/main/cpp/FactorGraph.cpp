#include "edu_cmu_cs_ark_ad3_AD3Jni.h"
#include "Factor.h"
#include "FactorGraph.h"
#include "MultiVariable.h"
#include "Utils.h"

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph
  (JNIEnv *env, jclass cls) {
    AD3::FactorGraph *fg = new AD3::FactorGraph();
    return reinterpret_cast<jlong>(fg);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_SetVerbosity
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1SetVerbosity
  (JNIEnv *env, jclass cls, jlong handle, jint verbosity) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);
    fg->SetVerbosity(verbosity);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_SetEtaPSDD
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1SetEtaPSDD
  (JNIEnv *env, jclass cls, jlong handle, jdouble eta) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);
    fg->SetEtaPSDD(eta);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_SetMaxIterationsPSDD
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1SetMaxIterationsPSDD
  (JNIEnv *env, jclass cls, jlong handle, jint max_iterations) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);
    fg->SetMaxIterationsPSDD(max_iterations);
  }

/*
  * Class:     edu_cmu_cs_ark_ad3_AD3Jni
  * Method:    FactorGraph_SolveLPMAPWithPSDD
  * Signature: (J)Ledu/cmu/cs/ark/ad3/MAPResult;
  */
JNIEXPORT jobject JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1SolveLPMAPWithPSDD
  (JNIEnv *env, jclass cls, jlong handle) {
    AD3::FactorGraph *f = reinterpret_cast<AD3::FactorGraph *>(handle);
    std::vector<double> variable_posteriors;
    std::vector<double> additional_posteriors;
    double value;
    int status = f->SolveLPMAPWithPSDD(&variable_posteriors, &additional_posteriors, &value);

    return Utils::createMAPResultWithStatus(env, variable_posteriors, additional_posteriors, value, status);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_SetEtaAD3
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1SetEtaAD3
  (JNIEnv *env, jclass cls, jlong handle, jdouble eta) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);
    fg->SetEtaAD3(eta);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_AdaptEtaAD3
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1AdaptEtaAD3
  (JNIEnv *env, jclass cls, jlong handle, jboolean adapt) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);
    fg->AdaptEtaAD3(adapt);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_SetMaxIterationsAD3
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1SetMaxIterationsAD3
  (JNIEnv *env, jclass cls, jlong handle, jint max_iterations) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);
    fg->SetMaxIterationsAD3(max_iterations);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_FixMultiVariablesWithoutFactors
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1FixMultiVariablesWithoutFactors
  (JNIEnv *env, jclass cls, jlong handle) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);
    fg->FixMultiVariablesWithoutFactors();
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_SolveLPMAPWithAD3
 * Signature: (J)Ledu/cmu/cs/ark/ad3/MAPResult;
 */
JNIEXPORT jobject JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1SolveLPMAPWithAD3
  (JNIEnv *env, jclass cls, jlong handle) {
    AD3::FactorGraph *f = reinterpret_cast<AD3::FactorGraph *>(handle);
    std::vector<double> variable_posteriors;
    std::vector<double> additional_posteriors;
    double value;
    int status = f->SolveLPMAPWithAD3(&variable_posteriors, &additional_posteriors, &value);

    return Utils::createMAPResultWithStatus(env, variable_posteriors, additional_posteriors, value, status);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_SolveExactMAPWithAD3
 * Signature: (J)Ledu/cmu/cs/ark/ad3/MAPResult;
 */
JNIEXPORT jobject JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1SolveExactMAPWithAD3
  (JNIEnv *env, jclass cls, jlong handle) {
    AD3::FactorGraph *f = reinterpret_cast<AD3::FactorGraph *>(handle);
    std::vector<double> variable_posteriors;
    std::vector<double> additional_posteriors;
    double value;
    int status = f->SolveExactMAPWithAD3(&variable_posteriors, &additional_posteriors, &value);

    return Utils::createMAPResultWithStatus(env, variable_posteriors, additional_posteriors, value, status);


  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_GetDualVariables
 * Signature: (J)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1GetDualVariables
  (JNIEnv *env, jclass cls, jlong handle) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);

    std::vector<double> variables = fg->GetDualVariables();
    return Utils::convertToJDoubleArray(env, variables);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_GetLocalPrimalVariables
 * Signature: (J)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1GetLocalPrimalVariables
  (JNIEnv *env, jclass cls, jlong handle) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);

    std::vector<double> variables = fg->GetLocalPrimalVariables();
    return Utils::convertToJDoubleArray(env, variables);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_GetGlobalPrimalVariables
 * Signature: (J)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1GetGlobalPrimalVariables
  (JNIEnv *env, jclass cls, jlong handle) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);

    std::vector<double> variables = fg->GetGlobalPrimalVariables();
    return Utils::convertToJDoubleArray(env, variables);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_CreateBinaryVariable
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1CreateBinaryVariable
  (JNIEnv *env, jclass cls, jlong handle) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);
    AD3::BinaryVariable *bvPtr = fg->CreateBinaryVariable();
    return reinterpret_cast<jlong>(bvPtr);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_CreateMultiVariable
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1CreateMultiVariable
  (JNIEnv *env, jclass cls, jlong handle, jint num_states) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);
    AD3::MultiVariable *mvPtr = fg->CreateMultiVariable(num_states);
    return reinterpret_cast<jlong>(mvPtr);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_CreateFactorDense
 * Signature: (J[J[DZ)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1CreateFactorDense
  (JNIEnv *env, jclass cls, jlong handle, jlongArray multi_variable_handles, jdoubleArray additional_log_potentials, jboolean owned_by_graph) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);

    jsize size = env->GetArrayLength(multi_variable_handles);
    std::vector<AD3::MultiVariable*> multi_variables(size);

    jlong *body = env->GetLongArrayElements(multi_variable_handles, 0);
    for (int i = 0; i < size; i++) {
      AD3::MultiVariable *var = reinterpret_cast<AD3::MultiVariable *>(body[i]);
      multi_variables.push_back(var);
    }
    env->ReleaseLongArrayElements(multi_variable_handles, body, 0);

    std::vector<double> addtn_log_potentials = Utils::convertToDoubleVector(env, additional_log_potentials);
    AD3::Factor *factor = fg->CreateFactorDense(multi_variables, addtn_log_potentials, owned_by_graph);
    return reinterpret_cast<jlong>(factor);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_CreateFactorXOR
 * Signature: (J[J[ZZ)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1CreateFactorXOR
  (JNIEnv *env, jclass cls, jlong handle, jlongArray binary_variable_handles, jbooleanArray negated, jboolean owned_by_graph) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);

    jsize size = env->GetArrayLength(binary_variable_handles);
    std::vector<AD3::BinaryVariable*> binary_variables(size);

    jlong *body = env->GetLongArrayElements(binary_variable_handles, 0);
    for (int i = 0; i < size; i++) {
      AD3::BinaryVariable *var = reinterpret_cast<AD3::BinaryVariable *>(body[i]);
      binary_variables.push_back(var);
    }
    env->ReleaseLongArrayElements(binary_variable_handles, body, 0);

    std::vector<bool> c_negated = Utils::convertToBoolVector(env, negated);
    AD3::Factor *factor = fg->CreateFactorXOR(binary_variables, c_negated, owned_by_graph);
    return reinterpret_cast<jlong>(factor);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_CreateFactorXOROUT
 * Signature: (J[J[ZZ)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1CreateFactorXOROUT
  (JNIEnv *env, jclass cls, jlong handle, jlongArray binary_variable_handles, jbooleanArray negated, jboolean owned_by_graph) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);

    jsize size = env->GetArrayLength(binary_variable_handles);
    std::vector<AD3::BinaryVariable*> binary_variables(size);

    jlong *body = env->GetLongArrayElements(binary_variable_handles, 0);
    for (int i = 0; i < size; i++) {
      AD3::BinaryVariable *var = reinterpret_cast<AD3::BinaryVariable *>(body[i]);
      binary_variables.push_back(var);
    }
    env->ReleaseLongArrayElements(binary_variable_handles, body, 0);

    std::vector<bool> c_negated = Utils::convertToBoolVector(env, negated);
    AD3::Factor *factor = fg->CreateFactorXOROUT(binary_variables, c_negated, owned_by_graph);
    return reinterpret_cast<jlong>(factor);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_CreateFactorAtMostOne
 * Signature: (J[J[ZZ)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1CreateFactorAtMostOne
  (JNIEnv *env, jclass cls, jlong handle, jlongArray binary_variable_handles, jbooleanArray negated, jboolean owned_by_graph) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);

    jsize size = env->GetArrayLength(binary_variable_handles);
    std::vector<AD3::BinaryVariable*> binary_variables(size);

    jlong *body = env->GetLongArrayElements(binary_variable_handles, 0);
    for (int i = 0; i < size; i++) {
      AD3::BinaryVariable *var = reinterpret_cast<AD3::BinaryVariable *>(body[i]);
      binary_variables.push_back(var);
    }
    env->ReleaseLongArrayElements(binary_variable_handles, body, 0);

    std::vector<bool> c_negated = Utils::convertToBoolVector(env, negated);
    AD3::Factor *factor = fg->CreateFactorAtMostOne(binary_variables, c_negated, owned_by_graph);
    return reinterpret_cast<jlong>(factor);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_CreateFactorOR
 * Signature: (J[J[ZZ)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1CreateFactorOR
  (JNIEnv *env, jclass cls, jlong handle, jlongArray binary_variable_handles, jbooleanArray negated, jboolean owned_by_graph) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);

    jsize size = env->GetArrayLength(binary_variable_handles);
    std::vector<AD3::BinaryVariable*> binary_variables(size);

    jlong *body = env->GetLongArrayElements(binary_variable_handles, 0);
    for (int i = 0; i < size; i++) {
      AD3::BinaryVariable *var = reinterpret_cast<AD3::BinaryVariable *>(body[i]);
      binary_variables.push_back(var);
    }
    env->ReleaseLongArrayElements(binary_variable_handles, body, 0);

    std::vector<bool> c_negated = Utils::convertToBoolVector(env, negated);
    AD3::Factor *factor = fg->CreateFactorOR(binary_variables, c_negated, owned_by_graph);
    return reinterpret_cast<jlong>(factor);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_CreateFactorOROUT
 * Signature: (J[J[ZZ)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1CreateFactorOROUT
  (JNIEnv *env, jclass cls, jlong handle, jlongArray binary_variable_handles, jbooleanArray negated, jboolean owned_by_graph) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);

    jsize size = env->GetArrayLength(binary_variable_handles);
    std::vector<AD3::BinaryVariable*> binary_variables(size);

    jlong *body = env->GetLongArrayElements(binary_variable_handles, 0);
    for (int i = 0; i < size; i++) {
      AD3::BinaryVariable *var = reinterpret_cast<AD3::BinaryVariable *>(body[i]);
      binary_variables.push_back(var);
    }
    env->ReleaseLongArrayElements(binary_variable_handles, body, 0);

    std::vector<bool> c_negated = Utils::convertToBoolVector(env, negated);
    AD3::Factor *factor = fg->CreateFactorOROUT(binary_variables, c_negated, owned_by_graph);
    return reinterpret_cast<jlong>(factor);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_CreateFactorANDOUT
 * Signature: (J[J[ZZ)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1CreateFactorANDOUT
  (JNIEnv *env, jclass cls, jlong handle, jlongArray binary_variable_handles, jbooleanArray negated, jboolean owned_by_graph) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);

    jsize size = env->GetArrayLength(binary_variable_handles);
    std::vector<AD3::BinaryVariable*> binary_variables(size);

    jlong *body = env->GetLongArrayElements(binary_variable_handles, 0);
    for (int i = 0; i < size; i++) {
      AD3::BinaryVariable *var = reinterpret_cast<AD3::BinaryVariable *>(body[i]);
      binary_variables.push_back(var);
    }
    env->ReleaseLongArrayElements(binary_variable_handles, body, 0);

    std::vector<bool> c_negated = Utils::convertToBoolVector(env, negated);
    AD3::Factor *factor = fg->CreateFactorANDOUT(binary_variables, c_negated, owned_by_graph);
    return reinterpret_cast<jlong>(factor);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_CreateFactorIMPLY
 * Signature: (J[J[ZZ)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1CreateFactorIMPLY
  (JNIEnv *env, jclass cls, jlong handle, jlongArray binary_variable_handles, jbooleanArray negated, jboolean owned_by_graph) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);

    jsize size = env->GetArrayLength(binary_variable_handles);
    std::vector<AD3::BinaryVariable*> binary_variables(size);

    jlong *body = env->GetLongArrayElements(binary_variable_handles, 0);
    for (int i = 0; i < size; i++) {
      AD3::BinaryVariable *var = reinterpret_cast<AD3::BinaryVariable *>(body[i]);
      binary_variables.push_back(var);
    }
    env->ReleaseLongArrayElements(binary_variable_handles, body, 0);

    std::vector<bool> c_negated = Utils::convertToBoolVector(env, negated);
    AD3::Factor *factor = fg->CreateFactorIMPLY(binary_variables, c_negated, owned_by_graph);
    return reinterpret_cast<jlong>(factor);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_CreateFactorPAIR
 * Signature: (J[JDZ)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1CreateFactorPAIR
  (JNIEnv *env, jclass cls, jlong handle, jlongArray binary_variable_handles, jdouble edge_log_potential, jboolean owned_by_graph) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);

    jsize size = env->GetArrayLength(binary_variable_handles);
    std::vector<AD3::BinaryVariable*> binary_variables(size);

    jlong *body = env->GetLongArrayElements(binary_variable_handles, 0);
    for (int i = 0; i < size; i++) {
      AD3::BinaryVariable *var = reinterpret_cast<AD3::BinaryVariable *>(body[i]);
      binary_variables.push_back(var);
    }
    env->ReleaseLongArrayElements(binary_variable_handles, body, 0);

    AD3::Factor *factor = fg->CreateFactorPAIR(binary_variables, edge_log_potential, owned_by_graph);
    return reinterpret_cast<jlong>(factor);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_CreateFactorBUDGET
 * Signature: (J[J[ZIZ)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1CreateFactorBUDGET
  (JNIEnv *env, jclass cls, jlong handle, jlongArray binary_variable_handles, jbooleanArray negated, jint budget, jboolean owned_by_graph) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);

    jsize size = env->GetArrayLength(binary_variable_handles);
    std::vector<AD3::BinaryVariable*> binary_variables(size);

    jlong *body = env->GetLongArrayElements(binary_variable_handles, 0);
    for (int i = 0; i < size; i++) {
      AD3::BinaryVariable *var = reinterpret_cast<AD3::BinaryVariable *>(body[i]);
      binary_variables.push_back(var);
    }
    env->ReleaseLongArrayElements(binary_variable_handles, body, 0);

    std::vector<bool> c_negated = Utils::convertToBoolVector(env, negated);
    AD3::Factor *factor = fg->CreateFactorBUDGET(binary_variables, c_negated, budget, owned_by_graph);
    return reinterpret_cast<jlong>(factor);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_CreateFactorKNAPSACK
 * Signature: (J[J[Z[DDZ)J
 */
JNIEXPORT jlong JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1CreateFactorKNAPSACK
  (JNIEnv *env, jclass cls, jlong handle, jlongArray binary_variable_handles, jbooleanArray negated, jdoubleArray costs, jdouble budget, jboolean owned_by_graph) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);

    jsize size = env->GetArrayLength(binary_variable_handles);
    std::vector<AD3::BinaryVariable*> binary_variables(size);

    jlong *body = env->GetLongArrayElements(binary_variable_handles, 0);
    for (int i = 0; i < size; i++) {
      AD3::BinaryVariable *var = reinterpret_cast<AD3::BinaryVariable *>(body[i]);
      binary_variables.push_back(var);
    }
    env->ReleaseLongArrayElements(binary_variable_handles, body, 0);

    std::vector<bool> c_negated = Utils::convertToBoolVector(env, negated);
    std::vector<double> c_costs = Utils::convertToDoubleVector(env, costs);
    AD3::Factor *factor = fg->CreateFactorKNAPSACK(binary_variables, c_negated, c_costs, budget, owned_by_graph);
    return reinterpret_cast<jlong>(factor);
  }

/*
 * Class:     edu_cmu_cs_ark_ad3_AD3Jni
 * Method:    FactorGraph_DeclareFactor
 * Signature: (JJ[JZ)V
 */
JNIEXPORT void JNICALL Java_edu_cmu_cs_ark_ad3_AD3Jni_FactorGraph_1DeclareFactor
  (JNIEnv *env, jclass cls, jlong handle, jlong factorHandle, jlongArray binary_variable_handles, jboolean owned_by_graph) {
    AD3::FactorGraph *fg = reinterpret_cast<AD3::FactorGraph *>(handle);
    AD3::Factor *factor = reinterpret_cast<AD3::Factor *>(factorHandle);

    jsize size = env->GetArrayLength(binary_variable_handles);
    std::vector<AD3::BinaryVariable*> binary_variables(size);

    jlong *body = env->GetLongArrayElements(binary_variable_handles, 0);
    for (int i = 0; i < size; i++) {
      AD3::BinaryVariable *var = reinterpret_cast<AD3::BinaryVariable *>(body[i]);
      binary_variables.push_back(var);
    }
    env->ReleaseLongArrayElements(binary_variable_handles, body, 0);

    fg->DeclareFactor(factor, binary_variables, owned_by_graph);
  }
