package ejercicio01;

import java.time.Year;

/**
 *
 * @author Charly Cimino Aprendé más Java en mi canal:
 * https://www.youtube.com/c/CharlyCimino Encontrá más código en mi repo de
 * GitHub: https://github.com/CharlyCimino
 */
public class Persona {
    // Modelá la clase Persona, la cual posea como atributos nombre, apellido y año de nacimiento. 

    // Atributos    
    private String DNI;
    private String nombre;
    private String apellido;
    private Fecha fechaDeNacimiento;
    private Domicilio domicilio;

    /* Constructor de la clase
        Debe llamarse igual que la clase
        No retorna nada (ni si quiera void)
        Se ejecuta por única vez en el momento del 'new'
     */
    public Persona(String DNI, String nombre, String apellido, Domicilio domicilio) {
        this.DNI = DNI;
        this.nombre = nombre;
        this.apellido = apellido;
        this.domicilio = domicilio;
    }

    public Persona(String DNI, String nombre, String apellido, Domicilio domicilio, Fecha fechaDeNacimiento) {
        this(DNI, nombre, apellido, domicilio);
        this.fechaDeNacimiento = fechaDeNacimiento;
    }
    

    
    // Métodos
    // Devolver el nombre completo de la persona.
    public String nombreCompleto() {
        return nombre + " " + apellido;
    }

    public String getApellido() {
        return apellido;
    }

    public String getDNI() {
        return DNI;
    }
    
    public String getBarrio(){
        return this.domicilio.getBarrio();
    }
    
    
    // Mostrar su estado en la consola.
    // Obtener su edad actual.
    public int edad() {
        // final int ANIO_ACTUAL = Year.now().getValue();
        return anioActual() - fechaDeNacimiento.getYear();
    }

    private int anioActual() {
        return Year.now().getValue();
    }

    // Saber si es mayor que una edad dada.
    public boolean esMayorQue(int unaEdadDada) {
        // Reutilizo el método edad(), no vuelvo a hacer el calculo
        return edad() > unaEdadDada;
    }

    public void setDNI(String DNI) {
        this.DNI = DNI;
    }

    // Cambiar su nombre.
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    // Cambiar su apellido.
    public void setApellido(String apellido) {
        this.apellido = apellido;
    }

    public void setDomicilio(Domicilio domicilio) {
        this.domicilio = domicilio;
    }

    @Override
    public String toString() {
        return "Persona{" + "DNI=" + DNI + ", nombre=" + nombre + ", apellido=" + apellido + ", fechaDeNacimiento=" + fechaDeNacimiento + ", domicilio=" + domicilio + '}';
    }
}
