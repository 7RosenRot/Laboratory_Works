package org.example;

public class Solution_Test {
    public static void Test() {
        Command Test[] = {
                new Command_Initialize(0, 5),
                new Command_Initialize(1, 5),
                new Command_Println(0),
                new Command_Println(1),

                new Command_Fold(0, 1),
                new Command_Println(0),

                new Command_Subtract(0, 1),
                new Command_Println(0),

                new Command_Multiply(0, 1),
                new Command_Println(0),

                new Command_Divide(0, 1),
                new Command_Println(0),

                new Command_Upload(0, 0),
                new Command_Download(1, 0)
        };

        CPU m_CPU = CPU_Build.Build();

        for (Command m_Command : Test) { m_CPU.Execute(m_Command); }
        m_CPU.Register_Show();
    }
}