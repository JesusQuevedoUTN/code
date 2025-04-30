package prueba.pkg3;

public class Prueba3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        String saludo = "hola";
        
        //String.equals(cadena) es util para comparar 2 cadenas de caracteres
        if (saludo.equals("hola")) {
            System.out.println("Hello");
        }
        
        //String.charAr(int) es util para poder obtener el char de una cadena en la posicion int
        if (saludo.charAt(0) == 'k') {
            System.out.println("Hello");
        }
        
        //mostrar que casi cualquier nombre es valido
        String __ = "Hola ";
        String ___ = "Jesus";
        String ____ = " como estas?";
        System.out.println(__ + ___ + ____);
    }

}
