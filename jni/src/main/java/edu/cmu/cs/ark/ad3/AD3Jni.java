package edu.cmu.cs.ark.ad3;

public class AD3Jni {
    static {
        System.loadLibrary("AD3Jni20");
    }

    // Binary Variable Methods

    public native double BinaryVariable_GetLogPotential();

    public native void BinaryVariable_SetLogPotential(double logPotential);

    public native int BinaryVariable_GetId();

    public native int BinaryVariable_Degree();

    // Multi Variable Methods

    public native int MultiVariable_GetNumStates();

    public native BinaryVariable MultiVariable_GetState(int i);

    public native double MultiVariable_GetLogPotential(int i);

    public native void MultiVariable_SetLogPotential(int i, double logPotential);

    // Factor Methods

    public native double[] Factor_GetAdditionalLogPotentials();

    public native void Factor_SetAdditionalLogPotentials(double[] additionalLogPotentials);

    public native int Factor_Degree();

    public native int Factor_GetLinkId(int i);

    public native BinaryVariable Factor_GetVariable(int i);

    public native void Factor_SolveMap(double[] variableLogPotentials, double[] additionalLogPotentials, double[] variablePosteriors /* return value */, double[] additionalPosteriors /* return value */, double value /* return value */);

    // Factor Graph Methods

    public native void FactorGraph_SetVerbosity(int verbosity);

    public native void FactorGraph_SetEtaPSDD(double eta);

    public native void FactorGraph_SetMaxIterationsPSDD(int max_iterations);

    public native int FactorGraph_SolveLPMAPWithPSDD(double[] posteriors /* return value */,
                                                     double[] additional_posteriors /* return value */,
                                                     double value /* return value */);

    public native void FactorGraph_SetEtaAD3(double eta);

    public native void FactorGraph_AdaptEtaAD3(boolean adapt);

    public native void FactorGraph_SetMaxIterationsAD3(int max_iterations);

    public native void FactorGraph_FixMultiVariablesWithoutFactors();

    public native int FactorGraph_SolveLPMAPWithAD3(double[] posteriors /* return value */,
                                                    double[] additional_posteriors /* return value */,
                                                    double value /* return value */);

    public native int FactorGraph_SolveExactMAPWithAD3(double[] posteriors /* return value */,
                                                       double[] additional_posteriors /* return value */,
                                                       double value /* return value */);

    public native double[] FactorGraph_GetDualVariables();

    public native double[] FactorGraph_GetLocalPrimalVariables();

    public native double[] FactorGraph_GetGlobalPrimalVariables();

    public native BinaryVariable FactorGraph_CreateBinaryVariable();

    public native MultiVariable FactorGraph_CreateMultiVariable(int num_states);

    public native Factor FactorGraph_CreateFactorDense(MultiVariable[] multi_variables,
                                                       double[] additional_log_potentials,
                                                       boolean owned_by_graph);

    public native Factor FactorGraph_CreateFactorXOR(BinaryVariable[] variables,
                                                     boolean[] negated,
                                                     boolean owned_by_graph);

    public native Factor FactorGraph_CreateFactorXOROUT(BinaryVariable[] variables,
                                                        boolean[] negated,
                                                        boolean owned_by_graph);

    public native Factor FactorGraph_CreateFactorAtMostOne(BinaryVariable[] variables,
                                                           boolean[] negated,
                                                           boolean owned_by_graph);

    public native Factor FactorGraph_CreateFactorOR(BinaryVariable[] variables,
                                                    boolean[] negated,
                                                    boolean owned_by_graph);

    public native Factor FactorGraph_CreateFactorOROUT(BinaryVariable[] variables,
                                                       boolean[] negated,
                                                       boolean owned_by_graph);

    public native Factor FactorGraph_CreateFactorANDOUT(BinaryVariable[] variables,
                                                        boolean[] negated,
                                                        boolean owned_by_graph);

    public native Factor FactorGraph_CreateFactorIMPLY(BinaryVariable[] variables,
                                                       boolean[] negated,
                                                       boolean owned_by_graph);

    public native Factor FactorGraph_CreateFactorPAIR(BinaryVariable[] variables,
                                                      double edge_log_potential,
                                                      boolean owned_by_graph);

    public native Factor FactorGraph_CreateFactorBUDGET(BinaryVariable[] variables,
                                                        boolean[] negated,
                                                        int budget,
                                                        boolean owned_by_graph);

    public native Factor FactorGraph_CreateFactorKNAPSACK(BinaryVariable[] variables,
                                                          boolean[] negated,
                                                          double[] costs,
                                                          double budget,
                                                          boolean owned_by_graph);

    public native void FactorGraph_DeclareFactor(Factor factor,
                                                 BinaryVariable[] variables,
                                                 boolean owned_by_graph);
}
