package ejercicio10;
import java.time.Year;

public class Persona {

    private String nombre;
    private String apellido;
    private Fecha fechaDeNacimiento;

    //CONSTRUTCTOR
    /*
    Debe llamarse igual que la clase
    No retorna nada (nisiquiera void)
    Se ejecuta por única vez en el momento del 'new'
     */
    public Persona(String nombre, String apellido, Fecha fechaDeNacimiento) {
        setNombre(nombre);
        setApellido(apellido);
        this.fechaDeNacimiento = fechaDeNacimiento; 
        //fechaDeNacimiento = new Fecha(dayNacimiento, monthNacimiento, yearNacimiento);
        //this.vivienda = vivienda;
    }
    
    public Persona(String nombre, String apellido) {
        setNombre(nombre);
        setApellido(apellido);
        fechaDeNacimiento = new Fecha();
    }

    //SETTERS
    public void setNombreCompleto(String nombre, String apellido) {
        setNombre(nombre);
        setApellido(apellido);
    }
    /*
    private void setAniodenacimiento(Fecha fechaDeNacimiento) {
        if (fechaDeNacimiento > 1900 && fechaDeNacimiento < anioActual()) {
            this.fechaDeNacimiento = fechaDeNacimiento;
        }
    } */

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

    /*
    private boolean esMayorA(int x) {
        return edad() > x;
    }
    */

    //MOSTRAR
    @Override
    public String toString() {
        return "Nombre: "+ nombre + "\nApeliido: " + apellido ;
    }
    
    public void show(){
        System.out.println(toString() + "\n" + fechaDeNacimiento.toString() );
    }

}
