package parcial1;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public abstract class Dron implements Energizable {

    private String id;
    private double bateriaActual;
    private double consumoPorMinuto;
    private double consumoPorKm;
    private final int MINUTOS_DE_AUTONOMIA = 10;

    public Dron(String id, double bateriaActual, double consumoPorMinuto, double consumoPorKm) {
        // Debería llamar a cada setter con su validación, pero lo omitimos para simplificar la solución.
        this.id = id;
        this.bateriaActual = bateriaActual; // Entre 1 y 100
        this.consumoPorMinuto = consumoPorMinuto;
        this.consumoPorKm = consumoPorKm;
    }

    @Override
    public void apagar() {
        System.out.println("Dron " + this.id + " apagado...");
    }
    
    @Override
    public void encender(){
        System.out.println("Dron " + this.id + " encendido");
        System.out.println("Nivel actual de bateria" + this.bateriaActual);
    }

    public double getBateriaActual() {
        return bateriaActual;
    }


    public double getConsumoPorKm() {
        return consumoPorKm;
    }
    
    public double bateriaNecesaria(double distancia){
        return distancia * this.consumoPorKm * 2 + this.MINUTOS_DE_AUTONOMIA * this.consumoPorMinuto;
    }

}
