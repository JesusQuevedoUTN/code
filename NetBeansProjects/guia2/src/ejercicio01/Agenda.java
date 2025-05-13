package ejercicio01;

import java.util.ArrayList;

public class Agenda {

    private ArrayList<Persona> personas;

    public Agenda() {
        // Al construirse una agenda, se construye una lista vacía (no queda en null)
        this.personas = new ArrayList<Persona>();
    }

    public int cantPersonas() {
        return personas.size();
    }

    /*
A) listarPersonas, que muestre en la consola un listado con todos los datos de cada persona
de la colección.
     */
    public void listarPersonas() {
        if (personas.size() != 0) {
            int i = 1;
            System.out.println("- - - - - - - - - - - - - - -");
            for (Persona p : personas) {
                System.out.println(i + ") " + p);
                i++;
            }
            System.out.println("- - - - - - - - - - - - - - -");
        } else {

        }
    }

    /*
B) devolverUltimo, que retorne (no muestre por consola) a la última persona de la colección
(o retorne null si está vacía la colección).
     */
    public Persona devolverUltimo() {
        return personas.get(personas.size() - 1);
    }

    /*
C) buscarPersona, que busca en la colección a la persona que posea el DNI recibido por
parámetro y la retorne (o retorna null si no se encuentra).
     */
    public Persona buscarPersona(String DNI) {
        int i = 0;
        //PONERLO EN UNA FUNCION
        while (i < personas.size() && !encontrar(personas.get(i), DNI)) {
            i++;
        }
        return i == personas.size() ? null : personas.get(i);
    }

    private boolean encontrar(Persona persona, String DNI) {
        return persona.getDNI().equals(DNI);
    }

    /*
D) agregarPersona, que recibe por parámetro todos los datos necesarios para construir una
Persona. Se construirá y agregará una persona a la colección con esos datos, siempre y
cuando no exista ya alguien con ese DNI en tal colección. Retorna un boolean indicando si
se pudo agregar o no.
     */
    public boolean agregarPersona(String DNI, String nombre, String apellido, Domicilio dom) {
        boolean existe = buscarPersona(DNI) != null;
        if (!existe) {
            this.personas.add(new Persona(DNI, nombre, apellido, dom));
        }
        return !existe;
    }

    /*
E) removerPersona, que recibe por parámetro un DNI. Debe borrar de la colección a la
persona con ese DNI y retornarla (o retornar null si no existe tal persona).
     */
    public Persona removerPersona(String DNI) {
        Persona persona = buscarPersona(DNI);
        if (persona != null) {
            personas.remove(persona);
        }
        return persona;
    }

    /*
F) modificarDomicilio, que recibe por parámetro un DNI y un domicilio. Debe modificar el
domicilio de la persona encontrada con ese DNI por el recibido por parámetro. Retorna un
boolean indicando la operación fue exitosa o no.
     */
    public boolean modificarDomicilio(String DNI, Domicilio nuevo) {
        Persona persona = buscarPersona(DNI);
        if (persona!=null) {
        //  buscarPersona(DNI).setDomicilio(nuevo);
            persona.setDomicilio(nuevo);
        }
        return persona!=null;
    }

    /*
G) obtenerPorBarrio, que retorne (no muestre por consola) a todas las personas que vivan en
un barrio determinado por parámetro.
     */
    public ArrayList<Persona> obtenerPorBarrio(String barrio) {
        ArrayList<Persona> listaBarrio = new ArrayList<Persona>();
        
        for (Persona persona : personas) {
            if (persona.getBarrio().equals(barrio)) {
                listaBarrio.add(persona);
            }
        }
        
        return listaBarrio;
    }

    /*
H) vaciar, que elimina a todas las personas de la colección, una por una. (Sin usar el método
clear de la clase ArrayList).
     */
    public void vaciar() {
        while (!estaVacio()) {
            personas.remove(0);
        }
    }

    private boolean estaVacio() {
        return personas.isEmpty();
    }

}
