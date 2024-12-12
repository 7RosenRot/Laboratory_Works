package com.example;
import javafx.scene.control.ListView;

public class runSolution {
    private interfaceCPU m_interfaceCPU;
    private int index = 0;

    public runSolution(interfaceCPU m_interfaceCPU) { this.m_interfaceCPU = m_interfaceCPU; }

    public void Start(flowCommandList m_flowCommandList) {
        for (CommandList m_CommandList : m_flowCommandList.CommandList_get()) { m_interfaceCPU.Assembly(m_CommandList); }
    }

    public void Start(CommandList m_CommandList) { m_interfaceCPU.Assembly(m_CommandList); }

    public void cellMove(ListView<String> list, flowCommandList m_flowCommandList, WindowController m_Window) {
        if (index < 0) {
            index = 0;
            m_Window.reStart(null);
        }
        if (index >= m_flowCommandList.CommandList_get().size()) {
            index = 0;
            m_Window.reStart(null);
        }

        CommandList m_CommandList = m_flowCommandList.CommandList_get().get(index);
        Start(m_CommandList);
        index += 1;
    }

    public int cellIndex_get() { return index; }

    public void cellIndex_null() { index = 0;}
}