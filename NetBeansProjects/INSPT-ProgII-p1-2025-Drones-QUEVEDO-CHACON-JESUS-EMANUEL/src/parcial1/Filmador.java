/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package parcial1;

/**
 *
 * @author Alumno
 */
public class Filmador extends Dron {

    private Camara camara;

    public Filmador(Camara camara, String id, double bateriaActual, double consumoPorMinuto, double consumoPorKm) {
        super(id, bateriaActual, consumoPorMinuto, consumoPorKm);
        this.camara = camara;
    }

    @Override
    public void apagar() {
        super.apagar();
        camara.apagar();
    }

    boolean tieneSuficienteBateria(double distancia, double minutosDeFilmacion) {
        return bateriaNecesaria(distancia) + camara.bateriaNecesaria(minutosDeFilmacion) < super.getBateriaActual();
    }

    


}
