package org.example;
import java.util.*;
import java.util.stream.Collectors;

public class Program {
    private List<interfaceCommand> listCommand;

    public Program() { listCommand = new ArrayList<>(); }

    public void add_listCommand(interfaceCommand Command) { listCommand.add(Command); }

    public List<interfaceCommand> get_listCommand() { return listCommand; }

    public String populareInstruction_list() {
        return "Most populare instruction:\n" + listCommand.stream()
                .collect(Collectors.groupingBy(interfaceCommand::Instruction_get, Collectors.counting()))
                .entrySet().stream()
                .sorted(Map.Entry.comparingByValue(Collections.reverseOrder()))
                .map(Enter -> Enter.getKey() + ": " + Enter.getValue())
                .collect(Collectors.joining("\n"));
    }

    public String populareInstruction_most() {
        return listCommand.stream()
                .collect(Collectors.groupingBy(interfaceCommand::Instruction_get, Collectors.counting()))
                .entrySet().stream()
                .max(Map.Entry.comparingByValue())
                .map(Enter -> "Most populare command: " + "'" + Enter.getKey() + "'")
                .orElse("No populare instruction");
    }

    public String memoryAddress() {
        List<Integer> Address = listCommand.stream()
                .filter(Command -> Command.Instruction_get().equals("Initialize"))
                .flatMap(Command -> Arrays.stream(Command.partInstruction_get()))
                .skip(1)
                .map(Integer::parseInt)
                .limit(1)
                .collect(Collectors.toList());
        if (Address.isEmpty()) { return "ERROR: No such memory address!"; }

        return String.format("Memory range:  (%d; %d)", Collections.min(Address), Collections.max(Address));
    }
}