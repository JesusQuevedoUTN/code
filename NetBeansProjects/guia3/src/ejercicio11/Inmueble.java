package ejercicio11;

import java.util.ArrayList;

/**
* Código generado por la app UXFtoJava by Charly Cimino
* @see https://github.com/CharlyCimino/uxf-to-java
*/
public class Inmueble {

    private String nombre;
    private String superficie;
    private String cantidadDeAmbientes;
    private double precio;
    private ArrayList<Interesado> interesados;

    public Inmueble(String nombre, String superficie, String cantidadDeAmbientes, double precio) {
        this.nombre = nombre;
        this.superficie = superficie;
        this.cantidadDeAmbientes = cantidadDeAmbientes;
        this.precio = precio;
        this.interesados = new ArrayList<>();
    }

    public void agregarInteresado(Interesado interesado){
        this.interesados.add(interesado);
    }

    public void setPrecio(double precio) {
        double precioViejo = this.precio;
        this.precio = precio;
        for (Interesado i : interesados) {
            i.cambioDePrecio(nombre,precioViejo,precio);
        }
    }
    


}