package ejercicio11;

/**
* Código generado por la app UXFtoJava by Charly Cimino
* @see https://github.com/CharlyCimino/uxf-to-java
*/
public class Cliente implements Interesado {

    private String apellido;
    private String nombre;
    private int telefono;
    private String mail;

    public Cliente(String apellido, String nombre, int telefono, String mail) {
        this.apellido = apellido;
        this.nombre = nombre;
        this.telefono = telefono;
        this.mail = mail;
    }

    
    
    @Override
    public void cambioDePrecio(String domicilio, double precioViejo, double precioNuevo) {
        System.out.println("He recibido un SMS en mi teléfono " + telefono  + " con el mensaje: ");
        System.out.println("El inmueble" + domicilio + " por el que ha demostrado interés cambió su precio de " + precioViejo + " a " + precioNuevo + "." );

    }

}