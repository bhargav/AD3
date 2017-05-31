package edu.cmu.cs.ark.ad3;

class AD3CObj {
    private long cptr = 0L;
    private int type = -1;

    AD3CObj() {
        this.cptr = 0L;
        this.type = -1;
    }

    AD3CObj(long paramLong, int paramInt) {
        this.cptr = paramLong;
        this.type = paramInt;
    }

    long get() {
        return this.cptr;
    }

    public void dispose() {
        // Implement this.
    }

    @Override
    protected void finalize() throws Throwable {
        dispose();
    }
}
