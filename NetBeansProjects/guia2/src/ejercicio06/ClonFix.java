package ejercicio06;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class ClonFix {

    private ArrayList<Cliente> clientes;
    private ArrayList<Pelicula> peliculas;

    public ClonFix(ArrayList<Cliente> clientes, ArrayList<Pelicula> peliculas) {
        this.clientes = clientes;
        this.peliculas = peliculas;
    }

    //
    public ResultadoPelicula verPelicula(String DNI, String Titulo) {
        return ResultadoPelicula.obtenerResultado(buscarCliente(DNI), buscarPelicula(Titulo));
    }

    private Pelicula buscarPelicula(String Titulo) {
        Pelicula pAVer = null;
        boolean seEncuentra = false;
        int i = 0;
        while (i < peliculas.size() && !seEncuentra) {
            if (peliculas.get(i).getTitulo().equals(Titulo)) {
                seEncuentra = !seEncuentra;
                pAVer = peliculas.get(i);
            }
            i++;
        }
        return pAVer;
    }

    private Cliente buscarCliente(String DNI) {
        Cliente cABuscar = null;
        int i;
        boolean seEncuentra;
        seEncuentra = false;
        i = 0;
        while (i < clientes.size() && !seEncuentra) {
            if (clientes.get(i).getDNI().equals(DNI)) {
                seEncuentra = !seEncuentra;
                cABuscar = clientes.get(i);
            }
            i++;
        }
        return cABuscar;
    }

    //
    public void darDeBaja(String DNI) {
        clientes.remove(buscarCliente(DNI));
    }

    public void addClientes(ArrayList<Cliente> clientesNuevos) {
        this.clientes.addAll(clientesNuevos);
    }

    public void addPeliculas(ArrayList<Pelicula> peliAAgregar) {
        this.peliculas.addAll(peliAAgregar);
    }

}
