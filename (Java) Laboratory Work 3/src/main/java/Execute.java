package org.example;

public class Execute {
    private interfaceCPU CPU;

    public Execute(interfaceCPU CPU) { this.CPU = CPU; }

    public void startProgram(Program m_Program) {
        for (interfaceCommand Command : m_Program.get_listCommand()) { CPU.cpuExecute(Command); }
    }
}