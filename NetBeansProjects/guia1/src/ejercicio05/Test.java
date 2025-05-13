package ejercicio05;

/*
5) Modelá la clase Fraccion, la cual posea como atributos numerador y denominador. Luego, 
implementá métodos que permitan:
▪ Mostrarse en consola, con el formato "numerador/denominador".
▪ Obtener el valor decimal.
▪ Sumarle un entero.
▪ Sumarle una fracción.
▪ Simplificar la fracción.
▪ Saber si la fracción es propia, impropia u aparente.1
Finalmente, instanciá una fracción en el método main y probá todos sus métodos
 */
public class Test {

    public static void main(String[] args) {
        
        Fraccion fraccion = new Fraccion(5,2);
        Fraccion fraccion1 = new Fraccion(8,6);
        
        System.out.println(fraccion1.getDecimal());
        System.out.println(fraccion1.toString());
        
        fraccion.sumarEntero(5);
        System.out.println(fraccion1.getDecimal());
        System.out.println(fraccion1.toString());
        
        System.out.println(fraccion1.tipoDeFraccion());
        
        Fraccion f1 = new Fraccion(2,3);
        Fraccion f2 = new Fraccion(3,2);
        Fraccion f3 = new Fraccion(8,2);
        Fraccion f4 = new Fraccion(5,0);
        Fraccion f5 = new Fraccion(3,7);

        f1.mostrar();
        System.out.println(f1.getDecimal());
        f1.sumarEntero(2);
        f1.mostrar();
        System.out.println(f1.getDecimal());
        f1.sumarFraccion(new Fraccion(3, 4));
        f1.mostrar();
        System.out.println(f1.getDecimal());
    }

}
