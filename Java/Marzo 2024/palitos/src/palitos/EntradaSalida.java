package palitos;

import java.util.Scanner;
import javax.swing.*;

public class EntradaSalida {

    public static void mostrarMensaje(String mensaje) {
//        JOptionPane.showMessageDialog(null, mensaje);
        System.out.println(mensaje);
    }

    public static String leerCadena(String mensaje) {
//        return JOptionPane.showInputDialog(mensaje);
        System.out.println(mensaje);
        Scanner sc = new Scanner(System.in);
        String renglon = sc.nextLine();
        return renglon;
    }

    public static int leerEntero(String mensaje) {
//        String strLeida = JOptionPane.showInputDialog(mensaje);
        System.out.println(mensaje);
        Scanner sc = new Scanner(System.in);
        String strLeida = sc.nextLine();

        int iLeido;
        try {
            iLeido = Integer.parseInt(strLeida);
        } catch (NumberFormatException ex) {
//            JOptionPane.showMessageDialog(null, "El valor ingresado es incorrecto.\n" + ex);
            System.out.println("El valor ingresado es incorrecto.\n" + ex);
            iLeido = 0;
        }
        return iLeido;
    }
}
