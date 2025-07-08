package ejercicio10;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Metodo implements Calificable {

    private String nombre;
    private int cantidadDeParametros;
    private int cantidadDeInstrucciones;
    private int cantidadDeRamificaciones;

    public Metodo(String nombre, int cantidadDeParametros, int cantidadDeInstrucciones, int cantidadDeRamificaciones) {
        this.nombre = nombre;
        this.cantidadDeParametros = cantidadDeParametros;
        this.cantidadDeInstrucciones = cantidadDeInstrucciones;
        this.cantidadDeRamificaciones = cantidadDeRamificaciones;
    }

    @Override
    public double indiceCalidad() {
        return 5 / (cantidadDeParametros + 1) + 20 / cantidadDeInstrucciones + 3 / (cantidadDeRamificaciones + 1);
    }

    public String getNombre() {
        return nombre;
    }

    void mostrar() {
        System.out.println("Cant de parametros:" + this.cantidadDeParametros);
        System.out.println("Cant de instrucciones:" + this.cantidadDeInstrucciones);
        System.out.println("Cant de ramificaciones:" + this.cantidadDeRamificaciones);
    }

}
