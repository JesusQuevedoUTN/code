package ejercicio03;

import java.util.ArrayList;

public class Test {

    public static void main(String[] args) {
        Curso curso = new Curso('A', "Programación", 120);

        Alumno juan = new Alumno("Juan", "12345678");
        Alumno ana = new Alumno("Ana", "87654321");
        Alumno lucia = new Alumno("Lucia", "11223344");

        juan.setNota(Tipo.PRIMER_EXAMEN, 7);
        juan.setNota(Tipo.SEGUNDO_EXAMEN, 6);

        ana.setNota(Tipo.PRIMER_EXAMEN, 9);
        ana.setNota(Tipo.SEGUNDO_EXAMEN, 8);
        ana.setNota(Tipo.FINAL, 10);

        lucia.setNota(Tipo.PRIMER_EXAMEN, 4); // Solo una evaluación, no entra en la búsqueda

        curso.agregarAlumno(juan);
        curso.agregarAlumno(ana);
        curso.agregarAlumno(lucia);

        System.out.println("=== Promedios ===");
        System.out.println(juan.getNombre() + ": " + juan.calcularPromedio());
        System.out.println(ana.getNombre() + ": " + ana.calcularPromedio());
        System.out.println(lucia.getNombre() + ": " + lucia.calcularPromedio());

        System.out.println("\n=== Alumnos con promedio mayor a 7 ===");
        ArrayList<Alumno> destacados = curso.buscarAlumnosPorEncimaDe(7);
        for (Alumno a : destacados) {
            System.out.println(a.getNombre() + " con promedio " + a.calcularPromedio());
        }
    }
}
