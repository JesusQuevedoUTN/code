package ejercicio07;

import java.util.ArrayList;

/**
* Código generado por la app UXFtoJava by Charly Cimino
* @see https://github.com/CharlyCimino/uxf-to-java
*/
public class Alumno {

    private String nombre;
    private String mail;
    private ArrayList<Materia> materiasAprobadas;

    public Alumno(String nombre, String mail) {
        this.nombre = nombre;
        this.mail = mail;
        this.materiasAprobadas = new ArrayList<>();
    }

    public double promedio(){
        double total = 0;
        if (materiasAprobadas.size() > 0) {
            for (Materia m : materiasAprobadas) {
                total = total + m.getNotaFinal();
            }
            total = total/materiasAprobadas.size();
        }
        return total;
    }

    public ArrayList<Materia> getMateriasAprobadas() {
        return materiasAprobadas;
    }
    
    public ListaAlumnos getLista(){
        ListaAlumnos x = new ListaAlumnos(this.nombre, this.mail);
        return x;
    }
    
    public void addMateriasAprobadas(ArrayList<Materia> materias){
        this.materiasAprobadas.addAll(materias);
    }

    boolean cantidadDeMateriasAprobadas(int min) {
        return this.materiasAprobadas.size()>=min;        
    }
    
}