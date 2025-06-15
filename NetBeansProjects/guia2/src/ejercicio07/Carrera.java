package ejercicio07;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Carrera {

    private ArrayList<Alumno> alumnos;
    private ArrayList<Materia> materias;

    public Carrera(ArrayList<Alumno> alumnos, ArrayList<Materia> materias) {
        this.alumnos = alumnos;
        this.materias = materias;
    }

    public ArrayList<ListaAlumnos> obtenerCandidatos(double promedio) {
        ArrayList<ListaAlumnos> candidatos = new ArrayList<ListaAlumnos>();
        final int MAXIMO = 20;
        final int MINIMO = 5;
        int i = 0, cantidadDeAlumnosCandidatos = 0;

        while (i < alumnos.size() && cantidadDeAlumnosCandidatos < MAXIMO) {
            Alumno a = alumnos.get(i);
            if (a.promedio() >= promedio && a.cantidadDeMateriasAprobadas(MINIMO)) {
                candidatos.add(a.getLista());
            }
            i++;
        }
        return candidatos;
    }

}
