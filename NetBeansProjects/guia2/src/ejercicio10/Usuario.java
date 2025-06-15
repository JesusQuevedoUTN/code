package ejercicio10;

/**
* Código generado por la app UXFtoJava by Charly Cimino
* @see https://github.com/CharlyCimino/uxf-to-java
*/
public class Usuario {

    private String nombre;
    private TipoDeEstado estado;

    public Usuario(String nombre, TipoDeEstado estado) {
        this.nombre = nombre;
        this.estado = estado;
    }

    public String getNombre() {
        return nombre;
    }
    
}