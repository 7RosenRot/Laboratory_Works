package com.example;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class flowCommandList {
    private List<CommandList> list;

    public flowCommandList() { list = new ArrayList<>(); }

    public void CommandList_add(CommandList m_CommandList) { list.add(m_CommandList); }

    public List<CommandList> CommandList_get() { return list; }

    public void CommandList_remove(int index) {
        if (index < 0) { return; }
        if (index >= list.size()) { return; }

        list.remove(index);
    }

    public void CommandList_raise(int index) {
        if (index <= 0) { return; }
        if (index >= list.size()) { return; }

        Collections.swap(list, index, index - 1);
    }

    public void CommandList_lower(int index) {
        if (index < 0) { return; }
        if (index >= list.size()) { return; }

        Collections.swap(list, index, index + 1);
    }

    public String ComandList_groupbyTop() {
        return list.stream()
                .collect(Collectors.groupingBy(CommandList::CommandList_entry, Collectors.counting()))
                .entrySet().stream()
                .max(Map.Entry.comparingByValue())
                .map(m_Entry -> m_Entry.getKey())
                .orElse("Impossible to create top");
    }

    public String CommandList_AddressByValue() {
        List<Integer> m_Address = list.stream()
                .filter(Order -> Order.CommandList_entry().equals("INITIALIZE"))
                .map(Order -> Integer.parseInt(Order.CommandList_body(1)))
                .collect(Collectors.toList());
        if (m_Address.isEmpty()) { return "ERROR:\nAddress list is empty!"; }

        int maxAddress = Collections.max(m_Address);
        int minAddress = Collections.min(m_Address);

        return String.format("FOUND: Maximum - %d;\n       Minimum - %d.", maxAddress, minAddress);
    }

    public String CommandList_groupbyFrequency() {
        return list.stream()
                .collect(Collectors.groupingBy(CommandList::CommandList_entry, Collectors.counting()))
                .entrySet().stream()
                .sorted(Map.Entry.comparingByValue(Collections.reverseOrder()))
                .map(m_Entry -> m_Entry.getKey() + ": " + m_Entry.getValue())
                .collect(Collectors.joining("\n"));
    }
}