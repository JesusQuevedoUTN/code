package ejercicio03;

// Autor: Chisus
import java.util.ArrayList;

// Fecha de creación: 20/05/2025
public class Alumno {

    private String nombre;
    private String DNI;
    private ArrayList<Evaluacion> evaluacionesRendidas;

    public Alumno(String nombre, String DNI) {
        this.nombre = nombre;
        this.DNI = DNI;
        this.evaluacionesRendidas = new ArrayList<Evaluacion>();
    }

    /*
    La implementación del método calcularPromedio de la clase Alumno, que debe calcular el 
    promedio de dicho alumno entre todas las evaluaciones que haya rendido.
     */
    public double calcularPromedio() {
        double promedio = 0;
        int sumatoria = 0, i = 0;
        for (Evaluacion evaluacionesRendida : evaluacionesRendidas) {
            sumatoria = sumatoria + evaluacionesRendida.getNota();
            i++;
        }
        promedio = (double)sumatoria/i;
        return promedio;
    }

    //SETTER
    public void setNota(Tipo examen, int nota) {
        if (nuevaNota(examen)) {
            this.evaluacionesRendidas.add(new Evaluacion(examen, nota));
        }
    }

    public String getNombre() {
        return nombre;
    }

    public String getDNI() {
        return DNI;
    }

    public ArrayList<Evaluacion> getEvaluacionesRendidas() {
        return evaluacionesRendidas;
    }

    //PRIVATE
    private boolean nuevaNota(Tipo examen) {
        int i = 0;
        while (i < evaluacionesRendidas.size() && evaluacionesRendidas.get(i).getTipoDeExamen() != examen) {
            i++;
        }
        return i == evaluacionesRendidas.size();
    }

}
