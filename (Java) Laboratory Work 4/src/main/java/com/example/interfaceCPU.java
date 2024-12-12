package com.example;
import java.util.Map;

public interface interfaceCPU {
    void  unitMemoryStore_set(int address, int value); //Передаёт значение на хранение в памяти
    int unitMemoryStore_get(int address); //Получает значение, хранимое в памяти
    int unitMemoryLenght_get(); //Получает длину (ёмкость) памяти
    String unitMemory_print(); //Выводит информацию на экран

    void unitRegisterStore_set(String registerKey, int value); //Передаёт значение на хранение в регистр
    int unitRegisterStore_get(String registerKey); //Получает значение, хранимое в регистре
    Map<String, Integer> unitRegister_get();
    String unitRegister_print(); //Выводит информацию на экран

    void Assembly(CommandList m_CommandList); //Собирает и запускает решение
}