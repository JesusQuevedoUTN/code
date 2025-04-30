package palitos;

public class PilaDePalitos {

    private int cantidad;

    public PilaDePalitos(int i) {
        cantidad = i;
    }

    public boolean partidaSigue() {
        return cantidad > 1;
    }

    public boolean jugadaGanadora() {
        return cantidad == 1;
    }

    public boolean jugadaPerdedora() {
        return cantidad == 0;
    }

    public String ofrecerQuitar(String nombre) {
        return nombre + ", quedan " + cantidad + " palitos. "
                + "Cuántos retiras (1 a " + (cantidad > 3 ? 3 : cantidad) + ")?";
    }

    public boolean imposibleQuitar(int n) {
        return n < 1 || n > 3 || n > cantidad;
    }

    public void quitar(int n) {
        cantidad -= n;
    }
}
