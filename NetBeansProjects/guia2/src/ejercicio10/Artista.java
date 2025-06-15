package ejercicio10;

import java.util.ArrayList;

/**
* Código generado por la app UXFtoJava by Charly Cimino
* @see https://github.com/CharlyCimino/uxf-to-java
*/
public class Artista {

    private int id;
    private String nombre;
    private ArrayList<Cancion> canciones;

    public Artista(int id, String nombre, ArrayList<Cancion> canciones) {
        this.id = id;
        this.nombre = nombre;
        this.canciones = canciones;
    }

    
    //
    public String mostrarDuracionPromedio() {
        double total = 0;
        for (Cancion c : canciones) {
            total = total + c.getDuracinEnSegundos();
        }
        if (canciones.size()!=0) {
            total = total / canciones.size(); 
        }
        return total>=60? (int)(total/60) + " minuto/s y " + (int)(total%60) : total + " segundos" ;
    }

    //
    public boolean esFanDestacado(Usuario fan) {
        int i = 0;
        for (Cancion c : canciones) {
            if (c.buscarUsuario(fan) != null) {
                i++;
            }
        }
        return i>=(canciones.size()/2);
    }

    //
    public ArrayList primeras5Canciones() {
        final int MAXIMO = 5;
        ArrayList<Cancion> primerasCanciones = new ArrayList<Cancion>();
        int i = 0;
        while (i < MAXIMO && i < canciones.size()){
            primerasCanciones.add(canciones.get(i));
            i++;
        }
        return primerasCanciones;
    }

}