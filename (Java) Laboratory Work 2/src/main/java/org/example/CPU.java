package org.example;

interface CPU_Interface { void Execute(Command m_Command); }

public class CPU implements CPU_Interface {
    protected int[] Register = new int[4];
    protected int[] Memory = new int[1024];

    @Override public void Execute(Command m_Command) { m_Command.Execute(this); }

    public void Register_Show() { System.out.println("Регистр: " + java.util.Arrays.toString(Register)); }
}