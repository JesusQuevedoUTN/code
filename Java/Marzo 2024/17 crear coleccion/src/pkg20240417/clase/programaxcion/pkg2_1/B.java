package pkg20240417.clase.programaxcion.pkg2_1;

public class B {

    private int dni;
    private String apellido;

    public B(int dni, String apellido) {
        this.dni = dni;
        this.apellido = apellido;
    }

    public String getApellido() {
        return apellido;
    }

    public void setApellido(String apellido) {
        this.apellido = apellido;
    }

    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        if (dni >= 1) {
            this.dni = dni;
        }
    }

    public String toString() {
        return "{" + dni + "," + apellido + "}";
    }

    public void eliminarDatos() {
        this.dni = 0;
        this.apellido = "";
    }

}
