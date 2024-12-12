package org.example;

interface interfaceCommand {
    void commandExecute(interfaceCPU CPU);
    public String Instruction_get();
    public String[] partInstruction_get();
}