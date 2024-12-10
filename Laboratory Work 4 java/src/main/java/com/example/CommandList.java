package com.example;

public class CommandList implements interfaceCommandLsit {
    private String[] Instruction;

    public CommandList(String m_Instruction) { Instruction = m_Instruction.split(" "); }

    @Override public String CommandList_entry() { return Instruction.length > 0 ? Instruction[0] : ""; }

    @Override public String CommandList_body(int i) { return Instruction.length > i ? Instruction[i] : ""; }

    @Override public String[] CommandList_full() { return  Instruction.length > 0 ? Instruction : new String[] {}; }

    @Override public String toString() { return String.join(" ", Instruction); }
}
