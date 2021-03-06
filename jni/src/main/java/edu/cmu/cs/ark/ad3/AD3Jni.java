package edu.cmu.cs.ark.ad3;

import org.scijava.nativelib.NativeLibraryUtil;

final class AD3Jni {
    private static final String nativeLibraryName = "AD3Jni20";

    static {
        boolean loadFromLibraryPath = false;

        try {
            System.loadLibrary(nativeLibraryName);
            loadFromLibraryPath = true;
        } catch (UnsatisfiedLinkError err) {
            // XXX - Log this.
        }

        if (!loadFromLibraryPath) {
            // Try to load from classpath or JAR file as an alternative
            NativeLibraryUtil.loadNativeLibrary(AD3Jni.class, nativeLibraryName);
        }
    }

    // Binary Variable Methods

    public static native long BinaryVariable();

    public static native void BinaryVariable_Dispose(long cPtr);

    public static native double BinaryVariable_GetLogPotential(long cPtr);

    public static native void BinaryVariable_SetLogPotential(long cPtr, double logPotential);

    public static native int BinaryVariable_GetId(long cPtr);

    public static native int BinaryVariable_Degree(long cPtr);

    // Multi Variable Methods

    public static native long MultiVariable();

    public static native void MultiVariable_Dispose(long cPtr);

    public static native int MultiVariable_GetNumStates(long cPtr);

    public static native long MultiVariable_GetState(long cPtr, int i);

    public static native double MultiVariable_GetLogPotential(long cPtr, int i);

    public static native void MultiVariable_SetLogPotential(long cPtr, int i, double logPotential);

    // Factor Methods

    public static native double[] Factor_GetAdditionalLogPotentials(long cPtr);

    public static native void Factor_SetAdditionalLogPotentials(long cPtr, double[] additionalLogPotentials);

    public static native int Factor_Degree(long cPtr);

    public static native int Factor_GetLinkId(long cPtr, int i);

    public static native long Factor_GetVariable(long cPtr, int i);

    public static native MAPResult Factor_SolveMAP(long cPtr, double[] variableLogPotentials, double[] additionalLogPotentials);

    // Factor Graph Methods

    public static native long FactorGraph();

    public static native void FactorGraph_Dispose(long cPtr);

    public static native void FactorGraph_SetVerbosity(long cPtr, int verbosity);

    public static native void FactorGraph_SetEtaPSDD(long cPtr, double eta);

    public static native void FactorGraph_SetMaxIterationsPSDD(long cPtr, int max_iterations);

    public static native MAPResult FactorGraph_SolveLPMAPWithPSDD(long cPtr);

    public static native void FactorGraph_SetEtaAD3(long cPtr, double eta);

    public static native void FactorGraph_AdaptEtaAD3(long cPtr, boolean adapt);

    public static native void FactorGraph_SetMaxIterationsAD3(long cPtr, int max_iterations);

    public static native void FactorGraph_FixMultiVariablesWithoutFactors(long cPtr);

    public static native MAPResult FactorGraph_SolveLPMAPWithAD3(long cPtr);

    public static native MAPResult FactorGraph_SolveExactMAPWithAD3(long cPtr);

    public static native double[] FactorGraph_GetDualVariables(long cPtr);

    public static native double[] FactorGraph_GetLocalPrimalVariables(long cPtr);

    public static native double[] FactorGraph_GetGlobalPrimalVariables(long cPtr);

    public static native long FactorGraph_CreateBinaryVariable(long cPtr);

    public static native long FactorGraph_CreateMultiVariable(long cPtr, int num_states);

    public static native long FactorGraph_CreateFactorDense(long cPtr, long[] multi_variables,
                                                            double[] additional_log_potentials,
                                                            boolean owned_by_graph);

    public static native long FactorGraph_CreateFactorXOR(long cPtr, long[] binaryVariables,
                                                          boolean[] negated,
                                                          boolean owned_by_graph);

    public static native long FactorGraph_CreateFactorXOROUT(long cPtr, long[] binaryVariables,
                                                             boolean[] negated,
                                                             boolean owned_by_graph);

    public static native long FactorGraph_CreateFactorAtMostOne(long cPtr, long[] binaryVariables,
                                                                boolean[] negated,
                                                                boolean owned_by_graph);

    public static native long FactorGraph_CreateFactorOR(long cPtr, long[] binaryVariables,
                                                         boolean[] negated,
                                                         boolean owned_by_graph);

    public static native long FactorGraph_CreateFactorOROUT(long cPtr, long[] binaryVariables,
                                                            boolean[] negated,
                                                            boolean owned_by_graph);

    public static native long FactorGraph_CreateFactorANDOUT(long cPtr, long[] binaryVariables,
                                                             boolean[] negated,
                                                             boolean owned_by_graph);

    public static native long FactorGraph_CreateFactorIMPLY(long cPtr, long[] binaryVariables,
                                                            boolean[] negated,
                                                            boolean owned_by_graph);

    public static native long FactorGraph_CreateFactorPAIR(long cPtr, long[] binaryVariables,
                                                           double edge_log_potential,
                                                           boolean owned_by_graph);

    public static native long FactorGraph_CreateFactorBUDGET(long cPtr, long[] binaryVariables,
                                                             boolean[] negated,
                                                             int budget,
                                                             boolean owned_by_graph);

    public static native long FactorGraph_CreateFactorKNAPSACK(long cPtr, long[] binaryVariables,
                                                               boolean[] negated,
                                                               double[] costs,
                                                               double budget,
                                                               boolean owned_by_graph);

    public static native void FactorGraph_DeclareFactor(long cPtr, long factor,
                                                        long[] binaryVariables,
                                                        boolean owned_by_graph);
}
