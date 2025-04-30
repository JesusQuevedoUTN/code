/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ejes;

/**
 *
 * @author jesus
 */
public class Guita {
    static int pesos;
    static int centavos;
    static double total;
    
    public Guita (int pesos, int centavos){
        this.pesos = pesos;
        this.centavos = centavos;
    }
    
    private void centavosAPesos(){
        while (centavos>=100) {
            centavos-=100;
            pesos++;
        }
        total=(double)pesos + (double)centavos/100;
    }
    
    public void cantidadDeGuita(){
        centavosAPesos();
        System.out.println("A usted le quedan " + total + "$");
    }
}
