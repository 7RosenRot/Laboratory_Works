package com.example;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.ListCell;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;

public class WindowController {
    private CPU m_CPU;
    private flowCommandList m_flowCommandList;
    private runSolution  m_runSolution;

    @FXML ListView<String> list;
    @FXML Label label_Memory;
    @FXML Label label_Register;
    @FXML TextField CommandReceiver;
    @FXML Label label_groupbyFrequency;
    @FXML Label label_groupbyTop;
    @FXML Label label_AddressByValue;

    public WindowController() {
        m_CPU = assemblyCPU.AssemblyCPU(32);
        m_flowCommandList = new flowCommandList();
        m_runSolution = new runSolution(m_CPU);
    }

    @FXML public void onInitialize() {
        list.setCellFactory(m_list -> new ListCell<String>() {
            protected void itemUpdate(String Item, boolean isEmpty) {
                super.updateItem(Item, isEmpty);
                if (Item == null || isEmpty) {
                    setText(null);
                    setGraphic(null);
                }
                else {
                    setText(Item);
                    if (getIndex() == m_runSolution.cellIndex_get() - 1) { setTextFill(Color.RED); }
                    else { setTextFill(Color.BLACK); }
                }
            }
        });
    }

    @FXML private void addtoList(ActionEvent m_Event) {
        String Order = CommandReceiver.getText();
        if (!Order.isEmpty()) {
            m_flowCommandList.CommandList_add(new CommandList(Order));

            onUpdate();
            CommandReceiver.clear();
        }
    }

    @FXML private void deletefromList(ActionEvent m_Event) {
        int SelectedIndex = list.getSelectionModel().getSelectedIndex();
        if (SelectedIndex >= 0) {
            m_flowCommandList.CommandList_remove(SelectedIndex);
            onUpdate();
        }
    }

    @FXML private void raiseList(ActionEvent m_Event) {
        int SelectedIndex = list.getSelectionModel().getSelectedIndex();
        if (SelectedIndex > 0) {
            m_flowCommandList.CommandList_raise(SelectedIndex);
            onUpdate();
            list.getSelectionModel().select(SelectedIndex - 1);
        }
    }

    @FXML private void lowerList(ActionEvent m_Event) {
        int SelectedIndex = list.getSelectionModel().getSelectedIndex();
        if (SelectedIndex >= 0 && SelectedIndex < m_flowCommandList.CommandList_get().size() - 1) {
            m_flowCommandList.CommandList_lower(SelectedIndex);
            onUpdate();
            list.getSelectionModel().select(SelectedIndex + 1);
        }
    }

    @FXML private void Start(ActionEvent m_Event) {
        m_runSolution.Start(m_flowCommandList);
        onUpdate();
    }

    @FXML protected void reStart(ActionEvent m_Event) {
        m_CPU = assemblyCPU.reAssemblyCPU(m_CPU, 32);
        m_runSolution.cellIndex_null();
        onUpdate();
    }

    @FXML private void cellMove(ActionEvent m_Event) {
        m_runSolution.cellMove(list, m_flowCommandList, this);
        onUpdate();
    }

    private void onUpdate() {
        ObservableList<String> Order = FXCollections.observableArrayList();
        for (CommandList m_CommandList : m_flowCommandList.CommandList_get()) { Order.add(m_CommandList.toString()); }
        list.setItems(Order);

        label_groupbyFrequency.setText(m_flowCommandList.CommandList_groupbyFrequency());
        label_AddressByValue.setText(m_flowCommandList.CommandList_AddressByValue());
        label_groupbyTop.setText(m_flowCommandList.ComandList_groupbyTop());

        label_Memory.setText(m_CPU.unitMemory_print());
        label_Register.setText(m_CPU.unitRegister_print());
    }
}
