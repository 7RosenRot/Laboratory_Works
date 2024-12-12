package com.example;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        flowCommandList m_flowCommandList = new flowCommandList();
        CPU m_CPU = assemblyCPU.AssemblyCPU(50);
        runSolution m_runSolytion = new runSolution(m_CPU);

        m_flowCommandList.CommandList_add(new CommandList("INITIALIZE 1 10"));
        m_flowCommandList.CommandList_add(new CommandList("INITIALIZE 1 10"));
        m_flowCommandList.CommandList_add(new CommandList("INITIALIZE 1 10"));

        m_flowCommandList.CommandList_add(new CommandList("LOAD A 1"));
        m_flowCommandList.CommandList_add(new CommandList("LOAD B 2"));

        m_flowCommandList.CommandList_add(new CommandList("ADD A B C"));

        m_runSolytion.Start(m_flowCommandList);

        m_CPU.unitMemory_print();
        m_CPU.unitRegister_print();

        System.out.println(m_flowCommandList.ComandList_groupbyTop());
        System.out.println(m_flowCommandList.CommandList_groupbyFrequency());
        System.out.println(m_flowCommandList.CommandList_AddressByValue());
        System.out.println(m_CPU.unitMemoryLenght_get());
    }
}