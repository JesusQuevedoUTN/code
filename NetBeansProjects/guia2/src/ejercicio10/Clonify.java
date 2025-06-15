package ejercicio10;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Clonify {

    private ArrayList<Artista> clientes;
    private ArrayList<Cancion> canciones;
    private ArrayList<Usuario> usuarios;

    public Clonify(ArrayList<Artista> clientes, ArrayList<Cancion> canciones, ArrayList<Usuario> usuarios) {
        this.clientes = clientes;
        this.canciones = canciones;
        this.usuarios = usuarios;
    }

    public Usuario borrarUsuario(String nombre) {
        Usuario aBorrar = null;
        aBorrar = buscarUsuario(nombre);
        if (aBorrar != null) {
            usuarios.remove(aBorrar);
            for (Cancion c : canciones) {
                c.borrarUsuario(aBorrar);
            }
        }
        return aBorrar;
    }

    private Usuario buscarUsuario(String nombre) {
        Usuario seBusca = null;
        boolean seEncuentra = false;
        int i = 0;
        while (i < usuarios.size() && !seEncuentra) {
            if (usuarios.get(i).getNombre().equals(nombre)) {
                seEncuentra = !seEncuentra;
                seBusca = usuarios.get(i);
            }
            i++;
        }
        return seBusca;
    }

}
