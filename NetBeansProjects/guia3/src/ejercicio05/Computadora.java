package ejercicio05;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Computadora {

    private String modelo;
    private ArrayList<Archivo> archivos;

    public Computadora(String modelo, ArrayList<Archivo> archivos) {
        this.modelo = modelo;
        this.archivos = archivos;
    }

    public void cerrarTodos() {
        for (Archivo a : archivos) {
            a.cerrar();
        }
    }

    public int cantArchivosDeTexto() {
        int cantidad = 0;
        for (Archivo a : archivos) {
            if (a instanceof Texto) {
                cantidad++;
            }
        }
        return cantidad;
    }

    public void cifrarArchivos() {
        for (Archivo a : archivos) {
            if (a instanceof Texto texto) {
                texto.cifrar();
            }
        }
    }

    public double duracionPromedio() {
        double promedio = 0;
        int cantidadDeVideos = 0;
        for (Archivo a : archivos) {
            if (a instanceof Multimedia multimedia) {
                promedio = promedio + multimedia.getDuracion();
                cantidadDeVideos++;
            }
        }
        if (cantidadDeVideos > 0) {
            promedio = promedio / cantidadDeVideos;
        }
        return promedio;
    }

    public ArrayList videosFullHD() {
        Pixeles HD = new Pixeles(1920, 1080);
        ArrayList<Archivo> lista = new ArrayList<Archivo>();
        for (Archivo a : archivos) {
            if (a instanceof Video video && video.esTamanio(HD)) {
                lista.add(a);
            }
        }
        return lista;
    }
}
