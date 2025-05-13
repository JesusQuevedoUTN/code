package ejercicio14;

public class SistemaDeAgua {

    private double temperatura;
    private boolean manteniemiento;

    public void romperSistema() {
        this.manteniemiento = true;
    }

    public void repararSistema() {
        this.manteniemiento = false;
    }

    public void encenderMotor(double temperatura) {
        this.temperatura = temperatura;
    }

    public void apagarMotor() {
        this.temperatura = 0;
    }

    public boolean estaSano() {
        if (manteniemiento) {
            System.out.println("ERROR. el sistema de Agua necesita mantenimiento");
        }
        return !manteniemiento;
    }
}
