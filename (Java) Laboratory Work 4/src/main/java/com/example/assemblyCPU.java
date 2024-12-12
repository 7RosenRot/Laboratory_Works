package com.example;

public class assemblyCPU {
    public static CPU AssemblyCPU() { return new CPU(); }

    public static CPU AssemblyCPU(int lengthMemory, int[] valueRegister) { return new CPU(lengthMemory, valueRegister); }

    public static CPU AssemblyCPU(int lengthMemory) { return new CPU(lengthMemory, new int[] {0, 0, 0, 0}); }

    public static CPU AssemblyCPU(int[] valueRegister) { return new CPU(1024, valueRegister); }

    public static CPU reAssemblyCPU(CPU m_CPU, int lengthMemory, int[] valueRegister) {
        m_CPU.rebuild(lengthMemory, valueRegister);
        return m_CPU;
    }

    public static CPU reAssemblyCPU(CPU m_CPU, int lengthMemory) { return reAssemblyCPU(m_CPU, lengthMemory, new int[] {0, 0, 0, 0}); }

    public static CPU reAssemblyCPU(CPU m_CPU, int[] valueRegister) { return reAssemblyCPU(m_CPU, 1024, valueRegister); }
}
