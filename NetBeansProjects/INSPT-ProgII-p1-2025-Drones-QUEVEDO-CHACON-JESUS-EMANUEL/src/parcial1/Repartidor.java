/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package parcial1;

/**
 *
 * @author Alumno
 */
public class Repartidor extends Dron {

    private int capacidadMaximaDeCarga;

    public Repartidor(int capacidadMaximaDeCarga, String id, double bateriaActual, double consumoPorMinuto, double consumoPorKm) {
        super(id, bateriaActual, consumoPorMinuto, consumoPorKm);
        this.capacidadMaximaDeCarga = capacidadMaximaDeCarga;
    }

    public boolean soportaElPeso(Paquete paq){
        return paq.getPeso() >= this.capacidadMaximaDeCarga;
    }
    
    public boolean tieneSuficienteBateria(double distancia) {
        return bateriaNecesaria(distancia) < super.getBateriaActual();
    }





}
