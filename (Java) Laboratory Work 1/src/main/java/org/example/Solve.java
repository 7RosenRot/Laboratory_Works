package org.example;
import java.util.Scanner;

public class Solve {
    public static void main(String[] args) {
        Scanner Input = new Scanner(System.in);
        int Input_1 = Input.nextInt() % 12;
        int Input_2 = Input.nextInt() % 12;
        int Input_3 = Input.nextInt() % 12;
        int Input_4 = Input.nextInt() % 12;

        /*Прверяем, если обе точки второго отрезка находятся на дуге 1-2 */
        if (Input_1 < Input_3 && Input_2 > Input_4) {
            System.out.println("Пересечение не обнаружено!");
            return;
        }

        /* Проверяем, если первая точка второго отрезка находится на дуге 1-2 */
        if (Input_1 <= Input_3 && Input_2 >= Input_3) {
            System.out.println("Пересечение обнаружено!");
            return;
        }
        /* Проверяем, если вторая точка второго отрезка находится на дуге 1-2 */
        if (Input_1 <= Input_4 && Input_2 >= Input_4) {
            System.out.println("Пересечение обнаружено!");
            return;
        }

        System.out.println("Пересечение не обнаружено!");
        return;
    }
}