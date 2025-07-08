package todoLibre;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Usuario {

    private int id;
    private String nombre;
    private String apellido;
    private String mail;
    private Domicilio domicilio;

    public Usuario(int id, String nombre, String apellido, String mail, Domicilio domicilio) {
        this.id = id;
        this.nombre = nombre;
        this.apellido = apellido;
        this.mail = mail;
        this.domicilio = domicilio;
    }

    public Domicilio getDomicilio() {
        return domicilio;
    }

}
