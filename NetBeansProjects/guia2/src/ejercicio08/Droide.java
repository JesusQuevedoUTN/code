package ejercicio08;

import java.util.ArrayList;

// Autor: Chisus
// Fecha de creación: 17/05/2025
public class Droide {

    private String nombre;
    private ArrayList<Pieza> piezasSanas;
    private ArrayList<Pieza> piezasInservibles;
    private ArrayList<Droide> chatarras;

    //CONSTRUCT
    public Droide(String nombre) {
        this.nombre = nombre;
        this.piezasSanas = new ArrayList<Pieza>();
        this.piezasInservibles = new ArrayList<Pieza>();
        this.chatarras = new ArrayList<Droide>();
    }

    //METODOS MAIN
    //1
    public void agregarPiezaOperativa(Pieza pieza) {
        this.piezasSanas.add(pieza);
    }

    public void agregarPiezaNoOperativa(Pieza pieza) {
        this.piezasInservibles.add(pieza);
    }

    //2
    public void registrarDroideRoto(Droide chatarra) {
        this.chatarras.add(chatarra);
    }

    //3
    public void estado() {
        System.out.println("MODELO: " + this.nombre + "(C)");
        mostrarPiezas();
    }

    //4
    public ResultadoReparacion autoRepararse() {
        int i = 0;
        Pieza pieza;
        Pieza piezaOperativa;
        boolean encontreAlMenosUnaPieza = false;

        while (i < this.piezasInservibles.size()) {
            pieza = this.piezasInservibles.get(i);
            piezaOperativa = this.buscarPiezaOperativa(pieza);

            if (piezaOperativa != null) {
                encontreAlMenosUnaPieza = true;
                this.reemplazarPieza(pieza, piezaOperativa);
            } else {
                i++;
            }
        }

        return this.obtenerResultadoRepacion(encontreAlMenosUnaPieza);
    }

    //GETTER
    public String getNombre() {
        return nombre;
    }

    private ArrayList<Pieza> getPiezasSanas() {
        return piezasSanas;
    }

    //METODOS
    private Pieza obtenerPiezaOperativa(Pieza buscada) {
        for (Pieza p : this.piezasSanas) {
            if (p.getNombre() == buscada.getNombre()) {
                this.piezasSanas.remove(p); // Sacamos la pieza del droide actual
                return p;
            }
        }
        return null;
    }

    private Pieza buscarPiezaOperativa(Pieza pieza) {
        int i = 0;
        Droide d;
        Pieza piezaEncontrada = null;

        while (i < this.chatarras.size() && piezaEncontrada == null) {
            d = this.chatarras.get(i);
            piezaEncontrada = d.obtenerPiezaOperativa(pieza);  // ahora correcto
            i++;
        }

        return piezaEncontrada;
    }

    private void reemplazarPieza(Pieza piezaNoOperativa, Pieza piezaOperativa) {
        this.piezasInservibles.remove(piezaNoOperativa);
        this.piezasSanas.add(piezaOperativa);
    }

    private void mostrarPiezas() {
        if (!piezasSanas.isEmpty()) {
            int i = 1;
            System.out.println("Piezas Sanas:");
            for (Pieza p : piezasSanas) {
                System.out.println(i + "." + p);
                i++;
            }
        } else {
            System.out.println("No hay piezas sanas.");
        }
        if (!piezasInservibles.isEmpty()) {
            int i = 1;
            System.out.println("Piezas Inservibles:");
            for (Pieza p : piezasInservibles) {
                System.out.println(i + "." + p);
                i++;
            }
        } else {
            System.out.println("No hay piezas inservibles.");
        }
    }

    private ResultadoReparacion obtenerResultadoRepacion(boolean encontreAlMenosUnaPieza) {
        ResultadoReparacion estado = ResultadoReparacion.REPARACION_IMPOSIBLE;

        if (piezasInservibles.isEmpty()) {
            estado = ResultadoReparacion.COMPLETAMENTE_OPERATIVO;
        } else if (encontreAlMenosUnaPieza) {
            estado = ResultadoReparacion.REPARACION_PARCIAL;
        }

        return estado;
    }

}
