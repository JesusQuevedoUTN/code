/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package parcial1;

/**
 *
 * @author Alumno
 */
class Camara implements Energizable {

    private double consumoPorMinutoDeGrabacion;

    public Camara(double consumoPorMinutoDeGrabacion) {
        this.consumoPorMinutoDeGrabacion = consumoPorMinutoDeGrabacion;
    }

    @Override
    public void apagar() {
        System.out.println("Camara apagada...");
    }
    
    public double bateriaNecesaria(double minutosDeFilmacion){
        return this.consumoPorMinutoDeGrabacion*minutosDeFilmacion;
    }

    

}
