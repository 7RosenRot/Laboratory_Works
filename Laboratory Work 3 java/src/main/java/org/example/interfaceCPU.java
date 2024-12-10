package org.example;

public interface interfaceCPU {
    void valueMemory_set(int Address, int Value);
    int valueMemory_get(int Address);
    void valueRegister_set(String Register, int Value);
    int valueRegister_get(String Register);
    void Print();
    void cpuExecute(interfaceCommand Command);
}