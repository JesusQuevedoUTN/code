package ejercicio01;

public class test {

    public static void main(String[] args) {
        Persona elDiez = new Persona("Diego", "Maradona", 1945);
        Persona elSiete = new Persona("Lionel", "Messi", 1987);
        int mayor = 50;

        System.out.println(elDiez.toString());
        mostrarMayor(elDiez, mayor);

        System.out.println(elSiete.toString());
        mostrarMayor(elSiete, mayor);
    }

    //atributos
    static void espacio() {
        System.out.printf("\n");
    }

    static void mostrarMayor(Persona x, int mayor) {
        if (x.esMayorA(mayor)) {
            System.out.println("Si, es mayor");
        } else {
            System.out.println("No, no es mayor");
        }
    }

}
//CIERRE DE LA CLASE
