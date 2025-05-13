package ejercicio09;

/**
9) Refactoreá la clase Persona del ejercicio
* a) cambiando el año de nacimiento por su fecha de nacimiento 
* b) agregando el atributo domicilio
*     i)calle, altura y barrio.
 */
public class Test {

    public static void main(String[] args) {
        Persona diez = new Persona("Lionel", "Messi", new Fecha(1987,6,24), new Domicilio ("Calle Falsa", 123, "La Matanza") );
        diez.show();
    }
}
