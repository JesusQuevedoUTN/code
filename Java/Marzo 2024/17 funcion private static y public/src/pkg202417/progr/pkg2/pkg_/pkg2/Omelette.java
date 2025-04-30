package pkg202417.progr.pkg2.pkg_.pkg2;

public class Omelette {

    private int cantidadDeHuevos;

    public Omelette(int cantidadDeHuevos) {
        this.cantidadDeHuevos = cantidadDeHuevos;
    }

    private void romperHuevos() {
        for (int i = 0; i < cantidadDeHuevos; i++) {
            System.out.println("Romper");
        }
    }

    private void batirHuevos() {
        System.out.println("Batir los huevitos");
    }

    private void calentarSarten() {
        System.out.println("Batir los huevitos");
    }

    private void cocinar() {
        System.out.println("Cocinar el omelette");
    }

    public void preparar() {
        if (cantidadDeHuevos < 1) {
            System.out.println("Tenes que darme huevos pipi");
            return;
        }
        romperHuevos();
        batirHuevos();
        calentarSarten();
        cocinar();
    }

    public int getCantidadDeHuevos() {
        return cantidadDeHuevos;
    }

    public void setCantidadDeHuevos(int cantidadDeHuevos) {
        this.cantidadDeHuevos = cantidadDeHuevos;
    }

}
