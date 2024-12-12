package org.example;

public class Main_2 {
    public static void main(String []Args) {
        task m_task = new task() {
            @Override
            public int task(int value) {
                return value + 2;
            }
        };

        System.out.println(m_task.task(2));
    }
}
