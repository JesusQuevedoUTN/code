package parcial1;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Principal {

    /**
     * Creando las instancias e invocando los métodos que correspondan, debe
     * permitir comprobar los resultados de todas las operaciones de la clase
     * Empresa.
     *
     * @param args argumentos proveninentes de la línea de comandos (no los
     * usamos)
     */
    public static void main(String[] args) {
        Empresa AMAZON = new Empresa();

        ArrayList<Dron> drones = new ArrayList();
        drones.add(new Filmador(new Camara(2), "Phillip V2.03", 100, 3, 4));
        drones.add(new Repartidor(40, "Amazon Droide V5.1.074", 15, 1, 1));
        drones.add(new Filmador(new Camara(5), "Samsung LG Max", 64, 8, 8));
        drones.add(new Repartidor(20, "MercadoBot - Modelo repartidor", 78, 5, 1));
        drones.add(new Filmador(new Camara(10), "Phillip V1", 99, 4, 3));
        drones.add(new Repartidor(15, "Droide Apple XLG", 75, 7, 7));
        drones.add(new Filmador(new Camara(1), "Android supongo que hace camaras", 45, 8, 4));
        drones.add(new Repartidor(100, "Droide Motorola LTS", 4, 8, 7));

        for (int i = 0; i < drones.size(); i++) {
            AMAZON.agregarDron(drones.get(i));
        }

        AMAZON.encenderDrones();
        
        //FALTO PONER UN IF QUE DIGA "EL QUE LLEVA EL PAQUETE ES" PERO NO LLEGUE
        AMAZON.elegirDron(5, new Paquete(20, 50));
        AMAZON.elegirDron(20, new Paquete(3, 5));
        AMAZON.elegirDron(12, new Paquete(5, 100));
        AMAZON.elegirDron(4, new Paquete(1, 1));
        AMAZON.elegirDron(50, new Paquete(100, 20));
        
        //FALTO PONER UN IF QUE DIGA "EL QUE LLEVA EL PAQUETE ES" PERO NO LLEGUE
        AMAZON.elegirDron(20, 20);
        AMAZON.elegirDron(84, 16);
        AMAZON.elegirDron(64, 45);
        AMAZON.elegirDron(15, 30);
        AMAZON.elegirDron(2, 22);
        AMAZON.elegirDron(65, 60);
        
        AMAZON.apagarDrones();

    }

}
