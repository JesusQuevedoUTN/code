package ejercicio04;

/*
4) Modelá la clase Fecha, la cual posea como atributos el día, el mes y el año. Luego, implementá 
métodos que permitan:
▪ Obtener la fecha como cadena, en formato "dd/mm/aaaa".
▪ Saber si es Navidad.
▪ Sumar un mes.
Finalmente, instanciá una fecha en el método main y probá todos sus métodos.

 */
public class Test {
    public static void main(String[] args) {
        Fecha hoy = new Fecha();
        Fecha christmas = new Fecha(25, 12, 2012);
        Fecha birthday = new Fecha(25, 1, 2000);
        
        System.out.println(hoy.toString());
        System.out.println(christmas.toString());
        System.out.println(birthday.toString());
        
        birthday.sumarMes(6);
        System.out.println(birthday.toString());
        
        System.out.println(hoy.getMonth());
    }
}
