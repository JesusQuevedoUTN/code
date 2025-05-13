package ejercicio08;

/**
 * 8) Desarrollá la clase Password Su único atributo será el valor de la
 * password (String)
 */
public class Test {

    public static void main(String[] args) {
        Password aleatoria = new Password();
        Password insegura = new Password("123456");
        Password segura = new Password("detrasdelhumoNULLseve");
        
        aleatoria.mostrar();
        insegura.mostrar();
        if (!insegura.esFuerte()) {
            System.out.println("No, es fuerte");
        }
        
        insegura.nuevoValor("HolaTarola123");
        if (insegura.esFuerte()) {
            System.out.println("Si, es fuerte");
        }
        insegura.mostrar();
        segura.mostrar();
    }

}
