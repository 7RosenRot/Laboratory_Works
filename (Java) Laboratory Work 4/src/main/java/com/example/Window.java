package com.example;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

public class Window extends Application {
    @Override public void start(Stage m_Stage) {
        try {
            BorderPane borderWindow = FXMLLoader.load(getClass().getResource("/Window.fxml"));
            Scene m_Scene = new Scene(borderWindow, 790, 510);

            m_Stage.setTitle("CPU&Emulator by Shemetov Daniil Olegovich");
            m_Stage.getIcons().add(new Image(getClass().getResourceAsStream("/Icon.png")));
            m_Stage.setResizable(false);
            m_Stage.setScene(m_Scene);
            m_Stage.show();
        }
        catch (Exception m_Exception) { m_Exception.printStackTrace(); }
    }

    public static void main(String[] args) { launch(args); }
}