package pkg20240417.clase.programaxcion.pkg2_1;

import java.util.ArrayList;

public class A {

    private ArrayList<B> w;

    public A(ArrayList<B> w) {
        this.w = w;
    }

    public ArrayList<B> getW() {
        return w;
    }

    public void setW(ArrayList<B> w) {
        this.w = w;
    }

    public void mostrar() {
        System.out.println(w);
    }
}
