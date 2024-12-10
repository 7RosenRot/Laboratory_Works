package org.example;

interface Command { void Execute(CPU m_CPU); }

/* Функция ввода (Добавляем занчение в массив регистров m_CPU.Register по адресу Register_Index) */
class Command_Initialize implements Command {
    private int Register_Index;
    private int Value;

    public Command_Initialize(int Register_Index, int Value) {
        this.Register_Index = Register_Index;
        this.Value = Value;
    }

    @Override public void Execute(CPU m_CPU) { m_CPU.Register[Register_Index] = Value; }
}

/* Функция суммирования (Складываем занчение ячейки регистра по адресу Register_First со значением ячейки по адресу Register_Second) */
class Command_Fold implements Command {
    private int Register_First;
    private int Register_Second;

    public Command_Fold(int Register_First, int Register_Second) {
        this.Register_First = Register_First;
        this.Register_Second = Register_Second;
    }

    @Override public void Execute(CPU m_CPU) {m_CPU.Register[Register_First] += m_CPU.Register[Register_Second]; }
}

/* Функция вычитания (Вычитаем из занчения ячейки регистра по адресу Register_First значение ячейки по адресу Register_Second) */
class Command_Subtract implements Command {
    private int Register_First;
    private int Register_Second;

    public Command_Subtract(int Register_First, int Register_Second) {
        this.Register_First = Register_First;
        this.Register_Second = Register_Second;
    }

    @Override public void Execute(CPU m_CPU) {m_CPU.Register[Register_First] -= m_CPU.Register[Register_Second]; }
}

/* Функция умножения (Умножаем занчение ячейки регистра по адресу Register_First на значение ячейки по адресу Register_Second) */
class Command_Multiply implements Command {
    private int Register_First;
    private int Register_Second;

    public Command_Multiply(int Register_First, int Register_Second) {
        this.Register_First = Register_First;
        this.Register_Second = Register_Second;
    }

    @Override public void Execute(CPU m_CPU) {m_CPU.Register[Register_First] *= m_CPU.Register[Register_Second]; }
}

/* Функция деления (Делим занчение ячейки регистра по адресу Register_First на значение ячейки по адресу Register_Second) */
class Command_Divide implements Command {
    private int Register_First;
    private int Register_Second;

    public Command_Divide(int Register_First, int Register_Second) {
        this.Register_First = Register_First;
        this.Register_Second = Register_Second;
    }

    @Override public void Execute(CPU m_CPU) {
        if (m_CPU.Register[Register_Second] == 0) {
            System.out.println("ОШИБКА: Обнаружено деление на 0!");
            return;
        }

        m_CPU.Register[Register_First] /= m_CPU.Register[Register_Second];
    }
}

/* Функция выгрузки (Передаём значение из ячейки регистра по адресу Register_Index в ячйку памяти по адресу Memory_Address) */
class Command_Upload implements Command {
    private int Register_Index;
    private int Memory_Address;

    public Command_Upload(int Register_Index, int Memory_Address) {
        this.Register_Index = Register_Index;
        this.Memory_Address = Memory_Address;
    }

    @Override public void Execute(CPU m_CPU) { m_CPU.Memory[Memory_Address] = m_CPU.Register[Register_Index]; }
}

/* Функция загрузки (Забираем значение из ячейки памяти по адресу Memory_Address изаписываем в ячейку регистра по адресу Register_Index) */
class Command_Download implements Command {
    private int Register_Index;
    private int Memory_Address;

    public Command_Download(int Register_Index, int Memory_Address) {
        this.Register_Index = Register_Index;
        this.Memory_Address = Memory_Address;
    }

    @Override public void Execute(CPU m_CPU) {m_CPU.Register[Register_Index] = m_CPU.Memory[Memory_Address]; }
}

/* Функция вывода */
class Command_Println implements Command {
    private int Register_Index;

    public Command_Println(int Register_Index) { this.Register_Index = Register_Index; }

    @Override public void Execute(CPU m_CPU) { System.out.println("Регистр №" + Register_Index + ": " + m_CPU.Register[Register_Index]); }
}