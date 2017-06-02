package edu.cmu.cs.ark.ad3;

public final class MAPResult {
    public final double[] variablePosteriors;
    public final double[] additionalPosteriors;
    public final double value;
    public final int status;

    public MAPResult(double[] variablePosteriors, double[] additionalPosteriors, double value) {
        this.variablePosteriors = variablePosteriors;
        this.additionalPosteriors = additionalPosteriors;
        this.value = value;
        this.status = -1;
    }

    public MAPResult(double[] variablePosteriors, double[] additionalPosteriors, double value, int status) {
        this.variablePosteriors = variablePosteriors;
        this.additionalPosteriors = additionalPosteriors;
        this.value = value;
        this.status = status;
    }
}
