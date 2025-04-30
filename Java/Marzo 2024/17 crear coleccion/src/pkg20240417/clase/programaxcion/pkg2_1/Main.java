package pkg20240417.clase.programaxcion.pkg2_1;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        /**/
        //Primera mitad de clase
        B b1 = new B(42932604, "Chisus");
        B b2 = new B(40228938, "Silva");
        b2.setDni(-45);
        System.out.println(b2.getDni());
        ArrayList<B> coleccion = new ArrayList<>();
        coleccion.add(b1);
        coleccion.add(b2);
        A a = new A(coleccion);
        a.mostrar();

        //Segunda mitad de clase
        B b3 = new B(25, "Lopez");
        darDeBaja(b3);
        System.out.println(b3);

        int x = cuadrado((int) 1000L);
        System.out.println(x);
    }

    static public void darDeBaja(B persona) {
        persona.eliminarDatos();
    }

    static public int cuadrado(int numero) {
        return numero *= numero;
    }
}
