package ejercicio02;

import java.util.List;


public class Test {
    public static void main(String[] args) {
        Inmobiliaria inmobiliaria = new Inmobiliaria();

        // Crear propiedades
        Propiedad p1 = new Propiedad(new Domicilio("Av. Santa Fe", 1234, "La Matanza"), 200000, TipoDeInmoviliaria.DEPARTAMENTO);
        Propiedad p2 = new Propiedad(new Domicilio("Calle Falsa", 123, "La Matanza"), 1000, TipoDeInmoviliaria.PH);
        Propiedad p3 = new Propiedad(new Domicilio("Av. Libertador", 456, "Villa Madero"), 300000, TipoDeInmoviliaria.CASA);
        Propiedad p4 = new Propiedad(new Domicilio("Malabia", 321, "General Paz"), 180000, TipoDeInmoviliaria.DEPARTAMENTO);
        Propiedad p5 = new Propiedad(new Domicilio("Armenia", 234, "La Matanza"), 120000, TipoDeInmoviliaria.PH);
        Propiedad p6 = new Propiedad(new Domicilio("Av. Cabildo", 1111, "CABA"), 220000, TipoDeInmoviliaria.CASA);
        Propiedad p7 = new Propiedad(new Domicilio("Guatemala", 999, "CABA"), 160000, TipoDeInmoviliaria.DEPARTAMENTO);
        Propiedad p8 = new Propiedad(new Domicilio("Av. Santa Fe", 1234, "San Martin"), 200000, TipoDeInmoviliaria.DEPARTAMENTO); // Duplicada a propósito

        // Agregar propiedades a la inmobiliaria
        inmobiliaria.agregarPropiedad(p1);
        inmobiliaria.agregarPropiedad(p2);
        inmobiliaria.agregarPropiedad(p3);
        inmobiliaria.agregarPropiedad(p4);
        inmobiliaria.agregarPropiedad(p5);
        inmobiliaria.agregarPropiedad(p6);
        inmobiliaria.agregarPropiedad(p7);
        inmobiliaria.agregarPropiedad(p8);
        
        // Llamados de prueba
        System.out.println( "Promedio de precios: " + inmobiliaria.promedioDePrecio() );

        System.out.println("\nPropiedades mas economicas:");
        List<Propiedad> economicas = inmobiliaria.propiedadesMasEconomicas();
        for (Propiedad p : economicas) {
            System.out.println(p);
        }
        System.out.println("- - - - - - -");
        System.out.println("Cantidad de propiedades tipo "+ TipoDeInmoviliaria.DEPARTAMENTO + ": " + inmobiliaria.cantidadDePropiedadesSegunTipo(TipoDeInmoviliaria.DEPARTAMENTO));
    }
}