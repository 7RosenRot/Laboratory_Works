package org.example;
import java.util.HashMap;
import java.util.Map;

public class CPU implements interfaceCPU {
    /*Создаём массив памяти и структуру регистров*/
    private final int[] Memory = new int[1024];
    private final Map<String, Integer> Register = new HashMap<>();

    /*Описываем структуру регистров*/
    public CPU() {
        Register.put("A", 0);
        Register.put("B", 0);
        Register.put("C", 0);
        Register.put("D", 0);
    }

    /*Собираем проект*/
    public static CPU Build() { return new CPU(); }

    /*Добавляем значение в ячейку памяти*/
    @Override public void valueMemory_set(int m_Address, int m_Value) {
        if (m_Address >= 0 && m_Address < Memory.length) { Memory[m_Address] = m_Value; }
        else { System.out.println("ERROR: Memory address (" + m_Address + ") doesn`t exist!"); }
    }

    /*Возвращаем значение из ячейки памяти*/
    @Override public int valueMemory_get(int m_Address) {
        if (m_Address >= 0 && m_Address < Memory.length) { return Memory[m_Address]; }
        else {
            System.out.println("ERROR: Memory address (" + m_Address + ") doesn`t exist!");
            return 0;
        }
    }

    /*Устанавлваем значение в регистр*/
    @Override public void valueRegister_set(String m_Register, int m_Value) {
        if (Register.containsKey(m_Register)) { Register.put(m_Register, m_Value); }
        else { System.out.println("ERROR: Register (" + m_Register + ") doesn`t exist!"); }
    }

    /*Возвращаем значение из регистра*/
    @Override public int valueRegister_get(String m_Register) { return Register.getOrDefault(m_Register, 0); }

    /*Выводим значение регистров*/
    @Override public void Print() {
        System.out.println("Register value: ");
        for (Map.Entry<String, Integer> m_Enter: Register.entrySet()) { System.out.println(m_Enter.getKey() + ": " + m_Enter.getValue()); }
    }

    @Override public void cpuExecute(interfaceCommand Command) { Command.commandExecute(this); }
}