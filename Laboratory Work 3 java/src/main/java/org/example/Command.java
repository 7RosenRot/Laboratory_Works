package org.example;

public class Command implements interfaceCommand {
    private String Instruction;
    private String[] partInstruction;

    public Command(String Instruction) {
        this.Instruction = Instruction;
        partInstruction = Instruction.split(" ");
    }

    @Override public void commandExecute(interfaceCPU CPU) {
        String Command = partInstruction[0];

        switch (Command) {
            /*Инитиализируем ячейку памяти. По адресу памяти записываем значение*/
            case "Initialize":
                int i_Address = Integer.parseInt(partInstruction[1]);
                int i_Value = Integer.parseInt(partInstruction[2]);
                CPU.valueMemory_set(i_Address, i_Value);
                break;
            /*Загружаем в регистр (ИМЯ), какое-то занчение (ЧИСЛО)*/
            case "Load":
                String Register = partInstruction[1];
                int l_Address = Integer.parseInt(partInstruction[2]);
                int l_Value = CPU.valueMemory_get(l_Address);
                CPU.valueRegister_set(Register, l_Value);
                break;
            /*Перемещаем в регистр (ИМЯ), какое-то занчение из регистра (ИМЯ)*/
            case "Move":
                String sourceRegister = partInstruction[1];
                String m_finitRegister = partInstruction[2];
                int m_Value = CPU.valueRegister_get(sourceRegister);
                CPU.valueRegister_set(m_finitRegister, m_Value);
                break;
            /*Записываем значение суммы регистра (ИМЯ 1) и регистра (ИМЯ 2) в регистр (ИМЯ 3)*/
            case "Add":
                String firstRegister = partInstruction[1];
                String secondRegister = partInstruction[2];
                String a_finitRegister = partInstruction[3];
                int firstValue = CPU.valueRegister_get(firstRegister);
                int secondValue = CPU.valueRegister_get(secondRegister);
                CPU.valueRegister_set(a_finitRegister, firstValue + secondValue);
                break;
            /*Выводим значение регистра*/
            case "Print":
                CPU.Print();
                break;
            default:
                System.out.println("ERROR: Undefined command!");
                break;
        }
    }

    @Override public String Instruction_get() {
        if (partInstruction.length > 0) { return partInstruction[0]; }
        else { return " "; }
    }

    @Override public String[] partInstruction_get() { return partInstruction; }
}