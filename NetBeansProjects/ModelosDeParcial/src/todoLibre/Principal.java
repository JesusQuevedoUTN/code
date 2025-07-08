package todoLibre;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Principal {

    public static void main(String[] args) {

        // Usuarios
        Usuario vendedor1 = new Usuario(1, "Carlos", "Perez", "carlos@mail.com", new Domicilio("Calle Falsa", 123, 1));
        Usuario comprador1 = new Usuario(2, "Ana", "Gomez", "ana@mail.com", new Domicilio("Av Siempre Viva", 742, 1));

        Usuario vendedor2 = new Usuario(3, "Luis", "Lopez", "luis@mail.com", new Domicilio("Otra Calle", 456, 2));
        Usuario comprador2 = new Usuario(4, "Maria", "Diaz", "maria@mail.com", new Domicilio("Calle Nueva", 789, 3));

        // Sucursales
        Domicilio sucursal1 = new Domicilio("Sucursal Centro", 10, 1);
        Domicilio sucursal2 = new Domicilio("Sucursal Norte", 20, 3);

        // Órdenes
        ArrayList<OrdenDeCompra> ordenes = new ArrayList<>();

        // Puerta a Puerta con envío gratis
        ordenes.add(new PuertaAPuerta(5000, comprador1, vendedor1)); // misma comuna

        // Puerta a Puerta sin envío gratis
        ordenes.add(new PuertaAPuerta(3000, comprador2, vendedor2)); // distintas comunas

        // Retiro en Persona en la misma comuna
        ordenes.add(new RetiroEnPersona(sucursal1, 2000, comprador1, vendedor1)); // misma comuna

        // Retiro en Persona en distinta comuna
        ordenes.add(new RetiroEnPersona(sucursal2, 4500, comprador2, vendedor2)); // distintas comunas

        // Otro Puerta a Puerta sin envío gratis
        ordenes.add(new PuertaAPuerta(6000, comprador1, vendedor2)); // distintas comunas

        // Otro Puerta a Puerta con envío gratis
        ordenes.add(new PuertaAPuerta(2500, comprador1, vendedor1)); // misma comuna

        // Usuarios en lista
        ArrayList<Usuario> usuarios = new ArrayList<>();
        usuarios.add(vendedor1);
        usuarios.add(vendedor2);
        usuarios.add(comprador1);
        usuarios.add(comprador2);

        // Sistema
        TodoLibre sistema = new TodoLibre(usuarios, ordenes);

        // Resultados
        double porcentajeMismaComuna = sistema.porcentajeDeOrdenesEnComuna();
        int cantidadEnvioGratis = sistema.enviogratis();

        System.out.println("Porcentaje de ordenes con origen y destino en la misma comuna: " + porcentajeMismaComuna + "%");
        System.out.println("Cantidad de ordenes con envio gratis: " + cantidadEnvioGratis);
    }
}
