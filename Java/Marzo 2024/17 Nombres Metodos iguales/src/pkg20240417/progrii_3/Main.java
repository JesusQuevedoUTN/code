/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package pkg20240417.progrii_3;

public class Main {

    static int num1 = 2, num2 = 3, r = 9;
    static String texto1 = "Hola", texto2 = "Mundo";

    public static void main(String[] args) {
        System.out.println(Metodos.juntar(num1, num2));
        System.out.println(Metodos.juntar(texto1, texto2));
        Metodos.duplicar(r);
        System.out.println(r);
    }

}
