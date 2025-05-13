package ejercicio01;
import java.time.Year;

public class Persona {

    private String nombre;
    private String apellido;
    private int anioDeNacimiento;

    //CONSTRUTCTOR
    /*
    Debe llamarse igual que la clase
    No retorna nada (nisiquiera void)
    Se ejecuta por única vez en el momento del 'new'
     */
    public Persona(String nombre, String apellido, int anioDeNacimiento) {
        setNombre(nombre);
        setApellido(apellido);
        setAniodenacimiento(anioDeNacimiento);
    }

    //SETTERS
    public void setNombreCompleto(String nombre, String apellido) {
        setNombre(nombre);
        setApellido(apellido);
    }

    private void setAniodenacimiento(int anioDeNacimiento) {
        if (anioDeNacimiento > 1900 && anioDeNacimiento < anioActual()) {
            this.anioDeNacimiento = anioDeNacimiento;
        }
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setApellido(String apellido) {
        this.apellido = apellido;
    }

    //ATRIBUTOS
    public String getNombreCompleto() {
        return nombre + " " + apellido;
    }

    private int anioActual() {
        return Year.now().getValue();
    }

    public int edad() {
        return anioActual() - anioDeNacimiento;
    }

    public boolean esMayorA(int x) {
        return edad() > x;
    }

    //MOSTRAR
    @Override
    public String toString() {
        return "Nombre: "+ nombre + "\nApeliido: " + apellido + "\nFecha de nacimiento: "+ anioDeNacimiento +"\nEdad: " + edad();
    }

}
