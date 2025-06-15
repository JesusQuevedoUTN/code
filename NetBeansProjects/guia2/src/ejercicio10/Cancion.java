package ejercicio10;

import java.util.ArrayList;

/**
* Código generado por la app UXFtoJava by Charly Cimino
* @see https://github.com/CharlyCimino/uxf-to-java
*/
public class Cancion {

    private int id;
    private String titulo;
    private int duracinEnSegundos;
    private ArrayList<Usuario> likes;

    public Cancion(int id, String titulo, int duracinEnSegundos, ArrayList<Usuario> likes) {
        this.id = id;
        this.titulo = titulo;
        this.duracinEnSegundos = duracinEnSegundos;
        this.likes = likes;
    }
    
    public int getDuracinEnSegundos() {
        return duracinEnSegundos;
    }

    public Usuario buscarUsuario(Usuario fan) {
        Usuario seBusca = null;
        boolean seEncuentra = false;
        int i = 0;
        while (i < likes.size() && !seEncuentra) {
            if (likes.get(i) == fan) {
                seEncuentra = !seEncuentra;
                seBusca = likes.get(i);
            }
            i++;
        }
        return seBusca;
    }

    public void borrarUsuario(Usuario aBorrar) {
        likes.remove(buscarUsuario(aBorrar));
    }

    public String getTitulo() {
        return titulo;
    }
    
    
    
}