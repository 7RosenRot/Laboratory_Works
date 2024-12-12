package com.example;
import java.util.Map;
import java.util.HashMap;

public class CPU implements interfaceCPU {
    private int[] unitMemory;
    private Map<String, Integer> unitRegister;

    public CPU() { this(1024, new int[] {0, 0, 0, 0}); }

    public void rebuild(int lengthMemory, int[] value) {
        this.unitMemory = new int[lengthMemory];
        this.unitRegister = new HashMap<>();

        unitRegister.put("A", value.length > 0 ? value[0] : 0);
        unitRegister.put("B", value.length > 1 ? value[1] : 0);
        unitRegister.put("C", value.length > 2 ? value[2] : 0);
        unitRegister.put("D", value.length > 3 ? value[3] : 0);
    }

    public CPU(int lengthMemory, int[] value) { rebuild(lengthMemory, value); }

    @Override public void  unitMemoryStore_set(int address, int value) {
        if (address < 0) { System.out.println("ERROR:Address does not exist!"); }
        if (address >= unitMemory.length) { System.out.println("ERROR:Address does not exist!"); }

        unitMemory[address] = value;
    }

    @Override public int unitMemoryStore_get(int address) {
        if (address < 0) { System.out.println("ERROR:Address does not exist!"); }
        if (address >= unitMemory.length) { System.out.println("ERROR:Address does not exist!"); }

        return unitMemory[address];
    }

    @Override public int unitMemoryLenght_get() { return unitMemory.length; }

    @Override public String unitMemory_print() {
        StringBuilder outMemory = new StringBuilder();

        for (int i = 0; i < unitMemory.length; i += 1) {
            outMemory.append((i + 1) + ". ").append(unitMemory[i]).append(" ");
            if ((i + 1) % 4 == 0) { outMemory.append("\n"); }
        }

        return outMemory.toString();
    }

    @Override public void unitRegisterStore_set(String registerKey, int value) {
        if (!unitRegister.containsKey(registerKey)) { System.out.println("ERROR: Register key does not exist!"); }

        unitRegister.put(registerKey, value);
    }

    @Override public int unitRegisterStore_get(String registerKey) {
        if (!unitRegister.containsKey(registerKey)) { System.out.println("ERROR: Register key does not exist!"); }

        return unitRegister.getOrDefault(registerKey, 0);
    }

    @Override public Map<String, Integer> unitRegister_get() { return unitRegister; }

    @Override public String unitRegister_print() {
        StringBuilder outRegister = new StringBuilder();

        for (Map.Entry<String, Integer> m_Entry : unitRegister.entrySet()) { outRegister.append(m_Entry.getKey()).append(". ").append(m_Entry.getValue()).append("\n"); }

        return outRegister.toString();
    }

    @Override public void Assembly(CommandList m_CommandList) {
        String Order = m_CommandList.CommandList_entry();
        switch (Order) {
            case "INITIALIZE":
                int INITIALIZE_Address = Integer.parseInt(m_CommandList.CommandList_body(1)) - 1;
                int INITIALIZE_Value = Integer.parseInt(m_CommandList.CommandList_body(2));

                unitMemoryStore_set(INITIALIZE_Address, INITIALIZE_Value);
                break;
            case "LOAD":
                int LOAD_Address = Integer.parseInt(m_CommandList.CommandList_body(2)) - 1;
                int LOAD_Value = unitMemoryStore_get(LOAD_Address);
                String LOAD_Register = m_CommandList.CommandList_body(1);

                unitRegisterStore_set(LOAD_Register, LOAD_Value);
                break;
            case "MOVE":
                String MOVE_firstRegister = m_CommandList.CommandList_body(1);
                String MOVE_secondRegister = m_CommandList.CommandList_body(2);
                int MOVE_Value = unitRegisterStore_get(MOVE_firstRegister);

                unitRegisterStore_set(MOVE_secondRegister, MOVE_Value);
                break;
            case "ADD":
                String ADD_firstRegister = m_CommandList.CommandList_body(1);
                String ADD_secondRegister = m_CommandList.CommandList_body(2);
                String ADD_thirdRegister = m_CommandList.CommandList_body(3);
                int ADD_firstValue = unitRegisterStore_get(ADD_firstRegister);
                int ADD_secondValue = unitRegisterStore_get(ADD_secondRegister);

                unitRegisterStore_set(ADD_thirdRegister, ADD_firstValue + ADD_secondValue);
                break;
            default:
                System.out.println("ERROR:Command does not exist!");
                break;
        }
    }
}
