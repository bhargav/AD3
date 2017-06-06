package edu.cmu.cs.ark.ad3;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class MultiVariableTest {
    @Test
    public void testCreateNewInstance() {
        MultiVariable variable = new MultiVariable();
        assertEquals(variable.getNumStates(), 0);
    }

}
