  import java.util.ArrayList;

public class Test06 {

    public static void main(String[] args) {
        // Crear una lista de bicicletas
        ArrayList<Bicicleta> listaBicicletas = new ArrayList<>();

        // Bicicletas comunes
        Bicicleta bici1 = new Bicicleta("Trek", "Domane", 1500);
        Bicicleta bici2 = new Bicicleta("Giant", "Escape", 2500);  // No debería entrar

        // Bicicletas eléctricas
        Electrica eBike1 = new Electrica(240, "Specialized", "Turbo", 1900);  // Sí debería entrar
        Electrica eBike2 = new Electrica(210, "Merida", "eSpresso", 1000);    // No debería entrar
        Electrica eBike3 = new Electrica(230, "Cube", "Kathmandu", 2200);     // No debería entrar

        // Agregarlas a la lista
        listaBicicletas.add(bici1);
        listaBicicletas.add(bici2);
        listaBicicletas.add(eBike1);
        listaBicicletas.add(eBike2);
        listaBicicletas.add(eBike3);

        // Crear instancia de taller y ejecutar el método
        Taller taller = new Taller();
        taller.cantServiciosPosibles(listaBicicletas);
    }
}
