package edu.cmu.cs.ark.ad3;

public class FactorGraph {
    public void SetVerbosity(int verbosity) {
    }

    public void SetEtaPSDD(double eta) {
    }

    public void SetMaxIterationsPSDD(int max_iterations) {
    }

    public int SolveLPMAPWithPSDD(double[] posteriors /* return value */,
                                  double[] additional_posteriors /* return value */,
                                  double value /* return value */) {
        return 0;
    }

    public void SetEtaAD3(double eta) {
    }

    public void AdaptEtaAD3(boolean adapt) {
    }

    public void SetMaxIterationsAD3(int max_iterations) {
    }

    public void FixMultiVariablesWithoutFactors() {
    }

    public int SolveLPMAPWithAD3(double[] posteriors /* return value */,
                                 double[] additional_posteriors /* return value */,
                                 double value /* return value */) {
        return 0;
    }

    public int SolveExactMAPWithAD3(double[] posteriors /* return value */,
                                    double[] additional_posteriors /* return value */,
                                    double value /* return value */) {
        return 0;
    }

    public double[] GetDualVariables() {
        return new double[]{};
    }

    public double[] GetLocalPrimalVariables() {
        return new double[]{};
    }

    public double[] GetGlobalPrimalVariables() {
        return new double[]{};
    }

    public BinaryVariable CreateBinaryVariable() {
        return null;
    }

    public MultiVariable CreateMultiVariable(int num_states) {
        return null;
    }

    public Factor CreateFactorDense(MultiVariable[] multi_variables,
                                    double[] additional_log_potentials,
                                    boolean owned_by_graph) {
        return null;
    }

    public Factor CreateFactorXOR(BinaryVariable[] variables,
                                  boolean[] negated,
                                  boolean owned_by_graph) {
        return null;
    }

    public Factor CreateFactorXOROUT(BinaryVariable[] variables,
                                     boolean[] negated,
                                     boolean owned_by_graph) {
        return null;
    }

    public Factor CreateFactorAtMostOne(BinaryVariable[] variables,
                                        boolean[] negated,
                                        boolean owned_by_graph) {
        return null;
    }

    public Factor CreateFactorOR(BinaryVariable[] variables,
                                 boolean[] negated,
                                 boolean owned_by_graph) {
        return null;
    }

    public Factor CreateFactorOROUT(BinaryVariable[] variables,
                                    boolean[] negated,
                                    boolean owned_by_graph) {
        return null;
    }

    public Factor CreateFactorANDOUT(BinaryVariable[] variables,
                                     boolean[] negated,
                                     boolean owned_by_graph) {
        return null;
    }

    public Factor CreateFactorIMPLY(BinaryVariable[] variables,
                                    boolean[] negated,
                                    boolean owned_by_graph) {
        return null;
    }

    public Factor CreateFactorPAIR(BinaryVariable[] variables,
                                   double edge_log_potential,
                                   boolean owned_by_graph) {
        return null;
    }

    public Factor CreateFactorBUDGET(BinaryVariable[] variables,
                                     boolean[] negated,
                                     int budget,
                                     boolean owned_by_graph) {
        return null;
    }

    public Factor CreateFactorKNAPSACK(BinaryVariable[] variables,
                                       boolean[] negated,
                                       double[] costs,
                                       double budget,
                                       boolean owned_by_graph) {
        return null;
    }

    public void DeclareFactor(Factor factor,
                              BinaryVariable[] variables,
                              boolean owned_by_graph) {
    }
}
