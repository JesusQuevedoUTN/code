package ejercicio10;
import java.util.ArrayList;
/**
* Código generado por la app UXFtoJava by Charly Cimino
* @see https://github.com/CharlyCimino/uxf-to-java
*/
public class Test10 {

     public static void main(String[] args) {
        // Crear usuarios
        Usuario u1 = new Usuario("luciaFan", TipoDeEstado.HABILITADO);
        Usuario u2 = new Usuario("octavioBox", TipoDeEstado.PRUEBA_GRATIS);
        Usuario u3 = new Usuario("jose", TipoDeEstado.SUSPENDIDO);

        // Crear canciones con likes
        ArrayList<Usuario> likes1 = new ArrayList<>();
        likes1.add(u1);
        likes1.add(u2);
        Cancion c1 = new Cancion(1, "Tentacool Rave", 210, likes1); // 3min30s

        ArrayList<Usuario> likes2 = new ArrayList<>();
        likes2.add(u1); // luciaFan le dio like
        Cancion c2 = new Cancion(2, "Inky Jam", 180, likes2); // 3min

        ArrayList<Usuario> likes3 = new ArrayList<>();
        likes3.add(u3);
        Cancion c3 = new Cancion(3, "OctoGroove", 240, likes3); // 4min

        // Lista de canciones
        ArrayList<Cancion> cancionesArtista = new ArrayList<>();
        cancionesArtista.add(c1);
        cancionesArtista.add(c2);
        cancionesArtista.add(c3);

        // Crear artista
        Artista artista = new Artista(100, "DJ Mosu", cancionesArtista);

        // Probar mostrarDuracionPromedio
        System.out.println("Duración promedio: " + artista.mostrarDuracionPromedio());

        // Probar esFanDestacado
        System.out.println("¿Lucia es fan destacado?: " + artista.esFanDestacado(u1)); // dio like a 2 de 3 canciones

        // Probar primeras5Canciones
        System.out.println("\nPrimeras canciones:");
        ArrayList<Cancion> canciones = artista.primeras5Canciones();
        for (Cancion c : canciones) {
            System.out.println("- " + c.getTitulo());
        }

        // Crear Clonify
        ArrayList<Usuario> listaUsuarios = new ArrayList<>();
        listaUsuarios.add(u1);
        listaUsuarios.add(u2);
        listaUsuarios.add(u3);

        ArrayList<Artista> listaArtistas = new ArrayList<>();
        listaArtistas.add(artista);

        ArrayList<Cancion> listaCanciones = new ArrayList<>();
        listaCanciones.add(c1);
        listaCanciones.add(c2);
        listaCanciones.add(c3);

        Clonify clonify = new Clonify(listaArtistas, listaCanciones, listaUsuarios);

        // Borrar usuario
        System.out.println("\nBorrando usuario jose...");
        Usuario borrado = clonify.borrarUsuario("jose");
        System.out.println(borrado != null ? "Usuario eliminado" : "Usuario no encontrado");

        // Verificar que se borró de la canción
        System.out.println("¿jose sigue en c3?: " + (c3.buscarUsuario(u3) != null));
    }
}