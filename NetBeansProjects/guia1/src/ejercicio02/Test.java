package ejercicio02;

/*
2) Desarrollar la clase Empleado, cuyos atributos sean su DNI, nombre,
apellido, salario base, 
estado civil (soltero, casado, divorciado o viudo) y cantidad de hijos.
Se sabe que todos los empleados cobran el salario base más un plus del
3% de éste por cada hijo, con un tope de hasta 10%. Del salario
resultante debe descontarse un 4% en caso de que el estado civil 
sea soltero.
Desarrollar el método obtenerSalarioFinal() que retorne el valor del
salario del empleado 
según las reglas enunciadas
 */
public class Test {

    public static void main(String[] args) {
        Empleado jesus = new Empleado(42932604, "Jesus", "Quevedo", 300000);
        System.out.println(jesus.toString());
        
        System.out.println("");
        Empleado mosu = new Empleado(696969, "Mosu", "Noru", 600,2,"Soltero");
        System.out.println(mosu.toString());
        
        System.out.println("");
        Empleado edgardo = new Empleado(1111111, "Edgardo", "Exequiel", 1000000 ,5,"Casado");
        System.out.println(edgardo.toString());
    }
}
