package ejercicio10;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Programa implements Calificable {

    private int id;
    private String nombre;
    private String nombreDelResponsable;
    private int pasoLasPruebas;
    private ArrayList<Fuente> fuentes;

    public Programa(int id, String nombre, String nombreDelResponsable) {
        this.id = id;
        this.nombre = nombre;
        this.nombreDelResponsable = nombreDelResponsable;
        this.fuentes = new ArrayList();
    }

    public void mostrarDetalleDeMetodo(String nombre) {
        boolean encontrado = false;
        for (Fuente f : fuentes) {
            if (f instanceof FuenteDeLenguajeDeProgramacion FDLP && FDLP.buscarMetodo(nombre)) {
                FDLP.mostrarMetodo(nombre);
                encontrado = true;
            }
        }
        if (!encontrado) {
            System.out.println("No se encontro");
        }
    }

    public ArrayList listadoFuentesMayoresAlPromedio(double calidadMinima) {
        ArrayList<Fuente> mayorAlPromedio = new ArrayList<>();
        for (Fuente f : fuentes) {
            if (f.indiceCalidad() > calidadMinima) {
                mayorAlPromedio.add(f);
            }
        }
        return mayorAlPromedio;
    }

    @Override
    public double indiceCalidad() {
        double calidad = 0;
        for (Fuente f : fuentes) {
            calidad += f.indiceCalidad();
        }
        return calidad;
    }

    void agregarFuente(Fuente fuenteProg1) {
        this.fuentes.add(fuenteProg1);
    }

    public String getNombre() {
        return nombre;
    }

}
