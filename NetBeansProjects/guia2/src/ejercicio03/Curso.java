package ejercicio03;

// Autor: Chisus
import java.util.ArrayList;

// Fecha de creación: 20/05/2025
public class Curso {

    private char codigo;
    private String titulo;
    private int horas;
    private ArrayList<Alumno> alumnos;

    /*
    C) La implementación del método buscarAlumnosPorEncimaDe de la clase Curso, que recibe 
    como parámetro un valor que representa un promedio, debiendo crear y devolver una lista 
    de aquellos alumnos que hayan realizado al menos 2 evaluaciones y cuyo promedio de notas 
    supere al promedio enviado por parámetro.}
     */
    public Curso(char codigo, String titulo, int horas) {
        this.codigo = codigo;
        this.titulo = titulo;
        this.horas = horas;
        this.alumnos = new ArrayList<Alumno>();
    }

    public ArrayList<Alumno> buscarAlumnosPorEncimaDe(double valor) {
        ArrayList<Alumno> resultado = new ArrayList<Alumno>();
        
        if (!alumnos.isEmpty()) {
            for (Alumno alumno : alumnos) {
                if (alumno.calcularPromedio()>valor) {
                    resultado.add(alumno);
                }
            }
        }
        return resultado;
    }

    void agregarAlumno(Alumno alumno) {
        this.alumnos.add(alumno);
    }

}
