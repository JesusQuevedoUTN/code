package ejercicio06;

import java.util.ArrayList;

// Autor: Chisus
// Fecha de creación: 01/06/2025
public class Test6 {

    public static void main(String[] args) {
        // Crear películas
        Pelicula p1 = new Pelicula("La gran aventura", 2025); // estreno
        Pelicula p2 = new Pelicula("Clásico del cine", 2010); // no estreno
        Pelicula p3 = new Pelicula("Película perdida", 2023); // estreno, pero no en la lista del sitio

        // Crear listas de películas
        ArrayList<Pelicula> listaPeliculas = new ArrayList<>();
        listaPeliculas.add(p1);
        listaPeliculas.add(p2);

        // Crear clientes
        Cliente c1 = new Cliente("123", "Ana", Servicios.ESTANDAR); // estándar
        Cliente c2 = new Cliente("456", "Luis", Servicios.PREMIUN); // premiun
        Cliente c3 = new Cliente("789", "Mara", Servicios.PREMIUN); // premiun, pero con deuda

        // Endeudamos a c3
        c3.seEndeudo();

        // Crear lista de clientes
        ArrayList<Cliente> listaClientes = new ArrayList<>();
        listaClientes.add(c1);
        listaClientes.add(c2);
        listaClientes.add(c3);

        // Crear el sistema ClonFix
        ClonFix clonflix = new ClonFix(listaClientes, listaPeliculas);

        // Probar distintos casos
        System.out.println(clonflix.verPelicula("123", "La gran aventura")); // CONTENIDO_NO_DISPONIBLE
        System.out.println(clonflix.verPelicula("123", "Clásico del cine")); // ALQUILER_OK
        System.out.println(clonflix.verPelicula("456", "La gran aventura")); // ALQUILER_OK
        System.out.println(clonflix.verPelicula("789", "Clásico del cine")); // CLIENTE_DEUDOR
        System.out.println(clonflix.verPelicula("000", "Clásico del cine")); // CLIENTE_INEXISTENTE
        System.out.println(clonflix.verPelicula("456", "Película perdida")); // CONTENIDO_INEXISTENTE

        // Dar de baja a un cliente
        clonflix.darDeBaja("456");
        System.out.println(clonflix.verPelicula("456", "La gran aventura")); // CLIENTE_INEXISTENTE
    }
}
