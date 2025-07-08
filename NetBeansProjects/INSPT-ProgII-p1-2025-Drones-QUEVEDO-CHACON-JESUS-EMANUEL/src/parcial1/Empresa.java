package parcial1;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Empresa {

    private ArrayList<Dron> drones;

    public Empresa() {
        this.drones = new ArrayList();
    }

    /**
     * Agrega un nuevo dron a la flota de la empresa
     *
     * @param d El dron a agregar
     */
    public void agregarDron(Dron d) {
        this.drones.add(d);
    }

    /**
     *
     * @param distancia expresada en km.
     * @param paq el paquete a entregar, para una misión de ENVÍO
     * @return el Dron con mayor nivel de batería que pueda aceptar la misión
     * encomendada.
     */
    public Dron elegirDron(double distancia, Paquete paq) {
        Dron dronElegido = null;
        for (Dron d : drones) {
            if (d instanceof Repartidor r) {
                if (dronElegido == null || r.soportaElPeso(paq) && r.tieneSuficienteBateria(distancia) && (r.getBateriaActual() > dronElegido.getBateriaActual()) ) {
                    dronElegido = r;
                }
            }
        }
        //FALTA DESCONTAR ENERGIA
        return dronElegido;
    }

    /**
     *
     * @param distancia expresada en km.
     * @param minutosDeFilmacion para una misión de FILMACION
     * @return el Dron con mayor nivel de batería que pueda aceptar la misión
     * encomendada.
     */
    public Dron elegirDron(double distancia, double minutosDeFilmacion) {
        
        Dron dronElegido = null;
        for (Dron d : drones) {
            if (d instanceof Filmador f) {
                if (dronElegido == null || f.tieneSuficienteBateria(distancia, minutosDeFilmacion) && (f.getBateriaActual() > dronElegido.getBateriaActual()) ) {
                    dronElegido = f;
                }
            }
        }
        //FALTA DESCONTAR ENERGIA
        return dronElegido;
    }

    /**
     * Debe apagar a todos los Drones.
     */
    public void apagarDrones() {
        for (Dron d : drones) {
            d.apagar();
        }
    }

    public void encenderDrones() {
        for (Dron d : drones) {
            d.encender();
        }
    }

}
