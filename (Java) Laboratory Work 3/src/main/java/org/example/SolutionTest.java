package org.example;

public class SolutionTest {
    public static void Test() {
        Program m_Program = new Program();
        m_Program.add_listCommand(new Command("Initialize 0 1"));
        m_Program.add_listCommand(new Command("Initialize 32 2"));
        m_Program.add_listCommand(new Command("Initialize 64 3"));
        m_Program.add_listCommand(new Command("Initialize 96 4"));
        m_Program.add_listCommand(new Command("Load A 0"));
        m_Program.add_listCommand(new Command("Load B 32"));
        m_Program.add_listCommand(new Command("Add A B C"));
        m_Program.add_listCommand(new Command("Move C D"));
        m_Program.add_listCommand(new Command("Print"));

        System.out.println(m_Program.populareInstruction_most() + "\n");
        System.out.println(m_Program.populareInstruction_list() + "\n");
        System.out.println(m_Program.memoryAddress() + "\n");

        interfaceCPU m_CPU = CPU.Build();
        org.example.Execute m_Execute = new org.example.Execute(m_CPU);
        m_Execute.startProgram(m_Program);
    }
}
