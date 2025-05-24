package ejercicio03;

// Autor: Chisus
// Fecha de creación: 20/05/2025
class Evaluacion {

    private Tipo examen;
    private int nota;

    public Evaluacion(Tipo examen, int nota) {
        this.examen = examen;
        this.nota = nota;
    }

    //GETTER
    public Tipo getTipoDeExamen() {
        return examen;
    }

    public int getNota() {
        return nota;
    }

}
