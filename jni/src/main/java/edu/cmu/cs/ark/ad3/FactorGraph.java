package edu.cmu.cs.ark.ad3;

public class FactorGraph {
    private AD3CObj nativeObj = null;

    FactorGraph(long cPtr) {
        this.nativeObj = new AD3CObj(cPtr, AD3CObjType.NATIVE);
    }

    public FactorGraph() {
        long nativeHandle = AD3Jni.FactorGraph();
        this.nativeObj = new AD3CObj(nativeHandle, AD3CObjType.MANAGED);
    }

    public void SetVerbosity(int verbosity) {
        AD3Jni.FactorGraph_SetVerbosity(this.nativeObj.get(), verbosity);
    }

    public void SetEtaPSDD(double eta) {
        AD3Jni.FactorGraph_SetEtaPSDD(this.nativeObj.get(), eta);
    }

    public void SetMaxIterationsPSDD(int max_iterations) {
        AD3Jni.FactorGraph_SetMaxIterationsPSDD(this.nativeObj.get(), max_iterations);
    }

    public MAPResult SolveLPMAPWithPSDD() {
        return AD3Jni.FactorGraph_SolveLPMAPWithPSDD(this.nativeObj.get());
    }

    public void SetEtaAD3(double eta) {
        AD3Jni.FactorGraph_SetEtaAD3(this.nativeObj.get(), eta);
    }

    public void AdaptEtaAD3(boolean adapt) {
        AD3Jni.FactorGraph_AdaptEtaAD3(this.nativeObj.get(), adapt);
    }

    public void SetMaxIterationsAD3(int max_iterations) {
        AD3Jni.FactorGraph_SetMaxIterationsAD3(this.nativeObj.get(), max_iterations);
    }

    public void FixMultiVariablesWithoutFactors() {
        AD3Jni.FactorGraph_FixMultiVariablesWithoutFactors(this.nativeObj.get());
    }

    public MAPResult SolveLPMAPWithAD3() {
        return AD3Jni.FactorGraph_SolveLPMAPWithAD3(this.nativeObj.get());
    }

    public MAPResult SolveExactMAPWithAD3() {
        return AD3Jni.FactorGraph_SolveExactMAPWithAD3(this.nativeObj.get());
    }

    public double[] GetDualVariables() {
        return AD3Jni.FactorGraph_GetDualVariables(this.nativeObj.get());
    }

    public double[] GetLocalPrimalVariables() {
        return AD3Jni.FactorGraph_GetLocalPrimalVariables(this.nativeObj.get());
    }

    public double[] GetGlobalPrimalVariables() {
        return AD3Jni.FactorGraph_GetGlobalPrimalVariables(this.nativeObj.get());
    }

    public BinaryVariable CreateBinaryVariable() {
        long bvPtr = AD3Jni.FactorGraph_CreateBinaryVariable(this.nativeObj.get());
        return new BinaryVariable(bvPtr);
    }

    public MultiVariable CreateMultiVariable(int num_states) {
        long mvPtr = AD3Jni.FactorGraph_CreateMultiVariable(this.nativeObj.get(), num_states);
        return new MultiVariable(mvPtr);
    }

    public Factor CreateFactorDense(MultiVariable[] multi_variables,
                                    double[] additional_log_potentials,
                                    boolean owned_by_graph) {
        long[] multiVariableHandles = new long[multi_variables.length];
        for (int i = 0; i < multiVariableHandles.length; i++) {
            multiVariableHandles[i] = multi_variables[i].getNativeHandle();
        }

        long fPtr = AD3Jni.FactorGraph_CreateFactorDense(this.nativeObj.get(), multiVariableHandles, additional_log_potentials, owned_by_graph);
        return new Factor(fPtr);
    }

    public Factor CreateFactorXOR(BinaryVariable[] binaryVariables,
                                  boolean[] negated,
                                  boolean owned_by_graph) {
        long[] binaryVariableHandles = new long[binaryVariables.length];
        for (int i = 0; i < binaryVariableHandles.length; i++) {
            binaryVariableHandles[i] = binaryVariables[i].getNativeHandle();
        }

        long fPtr = AD3Jni.FactorGraph_CreateFactorXOR(this.nativeObj.get(), binaryVariableHandles, negated, owned_by_graph);
        return new Factor(fPtr);
    }

    public Factor CreateFactorXOROUT(BinaryVariable[] binaryVariables,
                                     boolean[] negated,
                                     boolean owned_by_graph) {
        long[] binaryVariableHandles = new long[binaryVariables.length];
        for (int i = 0; i < binaryVariableHandles.length; i++) {
            binaryVariableHandles[i] = binaryVariables[i].getNativeHandle();
        }

        long fPtr = AD3Jni.FactorGraph_CreateFactorXOROUT(this.nativeObj.get(), binaryVariableHandles, negated, owned_by_graph);
        return new Factor(fPtr);
    }

    public Factor CreateFactorAtMostOne(BinaryVariable[] binaryVariables,
                                        boolean[] negated,
                                        boolean owned_by_graph) {
        long[] binaryVariableHandles = new long[binaryVariables.length];
        for (int i = 0; i < binaryVariableHandles.length; i++) {
            binaryVariableHandles[i] = binaryVariables[i].getNativeHandle();
        }

        long fPtr = AD3Jni.FactorGraph_CreateFactorAtMostOne(this.nativeObj.get(), binaryVariableHandles, negated, owned_by_graph);
        return new Factor(fPtr);
    }

    public Factor CreateFactorOR(BinaryVariable[] binaryVariables,
                                 boolean[] negated,
                                 boolean owned_by_graph) {
        long[] binaryVariableHandles = new long[binaryVariables.length];
        for (int i = 0; i < binaryVariableHandles.length; i++) {
            binaryVariableHandles[i] = binaryVariables[i].getNativeHandle();
        }

        long fPtr = AD3Jni.FactorGraph_CreateFactorOR(this.nativeObj.get(), binaryVariableHandles, negated, owned_by_graph);
        return new Factor(fPtr);
    }

    public Factor CreateFactorOROUT(BinaryVariable[] binaryVariables,
                                    boolean[] negated,
                                    boolean owned_by_graph) {
        long[] binaryVariableHandles = new long[binaryVariables.length];
        for (int i = 0; i < binaryVariableHandles.length; i++) {
            binaryVariableHandles[i] = binaryVariables[i].getNativeHandle();
        }

        long fPtr = AD3Jni.FactorGraph_CreateFactorOROUT(this.nativeObj.get(), binaryVariableHandles, negated, owned_by_graph);
        return new Factor(fPtr);
    }

    public Factor CreateFactorANDOUT(BinaryVariable[] binaryVariables,
                                     boolean[] negated,
                                     boolean owned_by_graph) {
        long[] binaryVariableHandles = new long[binaryVariables.length];
        for (int i = 0; i < binaryVariableHandles.length; i++) {
            binaryVariableHandles[i] = binaryVariables[i].getNativeHandle();
        }

        long fPtr = AD3Jni.FactorGraph_CreateFactorANDOUT(this.nativeObj.get(), binaryVariableHandles, negated, owned_by_graph);
        return new Factor(fPtr);
    }

    public Factor CreateFactorIMPLY(BinaryVariable[] binaryVariables,
                                    boolean[] negated,
                                    boolean owned_by_graph) {
        long[] binaryVariableHandles = new long[binaryVariables.length];
        for (int i = 0; i < binaryVariableHandles.length; i++) {
            binaryVariableHandles[i] = binaryVariables[i].getNativeHandle();
        }

        long fPtr = AD3Jni.FactorGraph_CreateFactorIMPLY(this.nativeObj.get(), binaryVariableHandles, negated, owned_by_graph);
        return new Factor(fPtr);
    }

    public Factor CreateFactorPAIR(BinaryVariable[] binaryVariables,
                                   double edge_log_potential,
                                   boolean owned_by_graph) {
        long[] binaryVariableHandles = new long[binaryVariables.length];
        for (int i = 0; i < binaryVariableHandles.length; i++) {
            binaryVariableHandles[i] = binaryVariables[i].getNativeHandle();
        }

        long fPtr = AD3Jni.FactorGraph_CreateFactorPAIR(this.nativeObj.get(), binaryVariableHandles, edge_log_potential, owned_by_graph);
        return new Factor(fPtr);
    }

    public Factor CreateFactorBUDGET(BinaryVariable[] binaryVariables,
                                     boolean[] negated,
                                     int budget,
                                     boolean owned_by_graph) {
        long[] binaryVariableHandles = new long[binaryVariables.length];
        for (int i = 0; i < binaryVariableHandles.length; i++) {
            binaryVariableHandles[i] = binaryVariables[i].getNativeHandle();
        }

        long fPtr = AD3Jni.FactorGraph_CreateFactorBUDGET(this.nativeObj.get(), binaryVariableHandles, negated, budget, owned_by_graph);
        return new Factor(fPtr);
    }

    public Factor CreateFactorKNAPSACK(BinaryVariable[] binaryVariables,
                                       boolean[] negated,
                                       double[] costs,
                                       double budget,
                                       boolean owned_by_graph) {
        long[] binaryVariableHandles = new long[binaryVariables.length];
        for (int i = 0; i < binaryVariableHandles.length; i++) {
            binaryVariableHandles[i] = binaryVariables[i].getNativeHandle();
        }

        long fPtr = AD3Jni.FactorGraph_CreateFactorKNAPSACK(this.nativeObj.get(), binaryVariableHandles, negated, costs, budget, owned_by_graph);
        return new Factor(fPtr);
    }

    public void DeclareFactor(Factor factor,
                              BinaryVariable[] binaryVariables,
                              boolean owned_by_graph) {
        long factorHandle = factor.getNativeHandle();
        long[] binaryVariableHandles = new long[binaryVariables.length];
        for (int i = 0; i < binaryVariableHandles.length; i++) {
            binaryVariableHandles[i] = binaryVariables[i].getNativeHandle();
        }

        AD3Jni.FactorGraph_DeclareFactor(this.nativeObj.get(), factorHandle, binaryVariableHandles, owned_by_graph);
    }
}
