package ejercicio07;
import java.util.ArrayList;

// Autor: Chisus
// Fecha de creación: 04/06/2025
public class Test7 {

    public static void main(String[] args) {
        // Crear materias
        Materia m1 = new Materia("Programación", 8);
        Materia m2 = new Materia("Matemática", 7);
        Materia m3 = new Materia("Sistemas", 9);
        Materia m4 = new Materia("Base de Datos", 6);
        Materia m5 = new Materia("Inglés", 10);
        Materia m6 = new Materia("Estadística", 5);

        // Agrupar materias para cada alumno
        ArrayList<Materia> materiasA1 = new ArrayList<>();
        materiasA1.add(m1);
        materiasA1.add(m2);
        materiasA1.add(m3);
        materiasA1.add(m4);
        materiasA1.add(m5);

        ArrayList<Materia> materiasA2 = new ArrayList<>();
        materiasA2.add(m1);
        materiasA2.add(m2);
        materiasA2.add(m3);

        ArrayList<Materia> materiasA3 = new ArrayList<>();
        materiasA3.add(m1);
        materiasA3.add(m2);
        materiasA3.add(m3);
        materiasA3.add(m4);
        materiasA3.add(m6);

        // Crear alumnos
        Alumno a1 = new Alumno("Lucía Morales", "lucia@example.com");
        a1.addMateriasAprobadas(materiasA1); // Promedio: 8.0, 5 materias

        Alumno a2 = new Alumno("Carlos Ruiz", "carlos@example.com");
        a2.addMateriasAprobadas(materiasA2); // Promedio: 8.0, 3 materias

        Alumno a3 = new Alumno("Marina Torres", "marina@example.com");
        a3.addMateriasAprobadas(materiasA3); // Promedio: 7.0, 5 materias

        // Lista de alumnos y materias (aunque la lista de materias en Carrera no se usa)
        ArrayList<Alumno> alumnos = new ArrayList<>();
        alumnos.add(a1);
        alumnos.add(a2);
        alumnos.add(a3);

        ArrayList<Materia> materias = new ArrayList<>();
        materias.add(m1);
        materias.add(m2);
        materias.add(m3);
        materias.add(m4);
        materias.add(m5);
        materias.add(m6);

        // Crear carrera
        Carrera carrera = new Carrera(alumnos, materias);

        // Obtener candidatos con promedio mínimo 7
        ArrayList<ListaAlumnos> candidatos = carrera.obtenerCandidatos(7.0);

        // Mostrar resultados
        System.out.println("Candidatos encontrados:");
        for (ListaAlumnos la : candidatos) {
            System.out.println("- Nombre: " + la.getNombre() + " | Mail: " + la.getMail());
        }
    }
}
