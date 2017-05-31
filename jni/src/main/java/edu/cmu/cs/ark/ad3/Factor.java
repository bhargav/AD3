package edu.cmu.cs.ark.ad3;

public final class Factor {
    public double[] GetAdditionalLogPotentials() {
        return new double[]{};
    }

    public void SetAdditionalLogPotentials(double[] additionalLogPotentials) {
    }

    public int Degree() {
        return 0;
    }

    public int GetLinkId(int i) {
        return 0;
    }

    public BinaryVariable GetVariable(int i) {
        return null;
    }

    public void SolveMap(double[] variableLogPotentials, double[] additionalLogPotentials, double[] variablePosteriors /* return value */, double[] additionalPosteriors /* return value */, double value /* return value */) {
    }
}
