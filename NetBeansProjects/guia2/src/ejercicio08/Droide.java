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
    public void agregarPiezaOperativa(TipoDePieza tipoDePieza, Estado estado) {
        Pieza pieza = new Pieza(tipoDePieza, estado);
        if (estado != Estado.ROTO && estado != Estado.IRREPARABLE) {
            this.piezasSanas.add(pieza);
        } else {
            this.piezasInservibles.add(pieza);
        }
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
    public TipoDeEstado autoRepararse() {
        TipoDeEstado estado = null;
        ArrayList<Pieza> reemplazar = new ArrayList<Pieza>();
        Droide partesDeRepuesto = null;
        //Si hay piezas en esta lista, implica que es mejorable
        if (!piezasInservibles.isEmpty()) {
            for (Pieza pieza : piezasInservibles) {
                partesDeRepuesto = buscarParteEnDroides(pieza);
                if (partesDeRepuesto != null) {
                    //lo encontró, entonces, se agrega a las piezas sanas, se pone en las de reemplazo para luego borrarlas
                    //en el droide encontrado, se intercambian las piezas
                    intercambiarPiezas(partesDeRepuesto, pieza);
                    piezasSanas.add(pieza);
                    reemplazar.add(pieza);
                }
            }
            piezasInservibles.removeAll(reemplazar);
        }

        //si acaba vacía esta lista, implica que se reparó, si no se reparó al 100, se busca que solo esté roto, pero no inservible
        if (!piezasInservibles.isEmpty()) {
            estado = TipoDeEstado.COMPLETAMENTE_OPERATIVO;
        } else if (funcional()) {
            estado = TipoDeEstado.REPARACION_PARCIAL;
        } else {
            estado = TipoDeEstado.REPARACION_IMPOSIBLE;
        }
        return estado;
    }

    //GETTER
    public String getNombre() {
        return nombre;
    }

    private ArrayList<Pieza> getPiezasSanas() {
        return piezasSanas;
    }

    //METODOS
    private Droide buscarParteEnDroides(Pieza buscada) {
        Droide encontrado = null;
//        Pieza mejorable = new Pieza(buscada.getNombre(), Estado.IRREPARABLE);
        Pieza encontrada = null;

        for (Droide droide : chatarras) {
            encontrada = buscarParteEnDroide(droide, buscada);
//            encontrada = buscarPieza(buscada);
//            if (encontrada != null && encontrada.getEstado().ordinal() < mejorable.getEstado().ordinal()) {
//                encontrado ;
//            }
        }

        return encontrado;
    }

    private Pieza buscarParteEnDroide(Droide seleccionado, Pieza buscar) {
        Pieza encontrada = new Pieza(buscar.getNombre(), Estado.IRREPARABLE);
        ArrayList<Pieza> piezasDeLaChatarra = new ArrayList<Pieza>();

        for (Droide robot : chatarras) {
            piezasDeLaChatarra = robot.getPiezasSanas();

        }

        return encontrada;
    }

//    private void reemplazarPieza(Pieza aReemplazar) {
//        Pieza mejorar = new Pieza(aReemplazar.getNombre(), Estado.IRREPARABLE);
//        Pieza encontrada = null;
//        for (Droide droide : chatarras) {
//            encontrada = buscarPieza(aReemplazar);
//            if (encontrada != null && encontrada.getEstado().ordinal() < mejorar.getEstado().ordinal()) {
//                cambiarPieza(encontrada, droide);
//            }
//        }
//    }
//
//    private Pieza buscarPieza(Pieza buscada) {
//        int i = 0;
//        while (i < piezas.size() && (piezas.get(i).getNombre() != buscada.getNombre())) {
//            i++;
//        }
//        return i == piezas.size() ? null : piezas.get(i);
//    }
//
//    private void cambiarPieza(Pieza encontrada, Droide robot) {
//        Pieza auxiliar = robot.buscarPieza(encontrada);
//        intercambiarPiezas(buscarPieza(encontrada),robot.buscarPieza(encontrada));
//        intercambiarPiezas(auxiliar,buscarPieza(encontrada));
//    }
    private void intercambiarPiezas(Pieza pie1, Pieza pie2) {
        Pieza aux = pie1;
        pie2 = pie1;
        pie1 = aux;
    }

    private void mostrarPiezas() {
        if (!piezas.isEmpty()) {
            int i = 1;
            for (Pieza p : piezas) {
                System.out.println(i + "." + p);
                i++;
            }
        }
    }

    private boolean funcional() {
        int i = 0;
        while (i < piezasInservibles.size() && piezasInservibles.get(i).getEstado() != Estado.IRREPARABLE) {
            i++;
        }
        return i == piezasInservibles.size();
    }

}
