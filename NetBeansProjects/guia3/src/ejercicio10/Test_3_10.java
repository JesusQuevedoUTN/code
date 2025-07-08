package ejercicio10;

// Autor: Chisus
// Fecha de creación: 20/06/2025
import java.util.ArrayList;

public class Test_3_10 {

    public static void main(String[] args) {
        // Crear métodos de ejemplo
        Metodo m1 = new Metodo("sumar", 2, 10, 1);    // calidad = 5/3 + 20/10 + 3/2 = 1.66 + 2 + 1.5 = 5.16 aprox
        Metodo m2 = new Metodo("restar", 1, 20, 3);   // calidad = 5/2 + 20/20 + 3/4 = 2.5 + 1 + 0.75 = 4.25
        Metodo m3 = new Metodo("vacío", 0, 2, 0);     // calidad = 5/1 + 20/2 + 3/1 = 5 + 10 + 3 = 18

        // Fuente de programación con esos métodos
        FuenteDeLenguajeDeProgramacion fuenteProg1 = new FuenteDeLenguajeDeProgramacion("Calculadora.java", "src/main");
        fuenteProg1.agregarMetodo(m1);
        fuenteProg1.agregarMetodo(m2);

        FuenteDeLenguajeDeProgramacion fuenteProg2 = new FuenteDeLenguajeDeProgramacion("AlgoMas.java", "src/util");
        fuenteProg2.agregarMetodo(m3);

        // Fuente de marcado
        FuenteDeLenguajeDeMarcado fuenteXML1 = new FuenteDeLenguajeDeMarcado(10, "estructura.xml", "data/"); // calidad = 450 / 10 = 45.0
        FuenteDeLenguajeDeMarcado fuenteXML2 = new FuenteDeLenguajeDeMarcado(90, "liviano.xml", "data/");    // calidad = 450 / 90 = 5.0

        // Crear programas
        Programa programa1 = new Programa(1, "Sistema A", "Lucía"); // pasó pruebas

        programa1.agregarFuente(fuenteProg1);
        programa1.agregarFuente(fuenteXML1); // mezcla de fuentes

        Programa programa2 = new Programa(2, "Sistema B", "Mosu"); // NO pasó pruebas
        programa2.agregarFuente(fuenteProg2);
        programa2.agregarFuente(fuenteXML2);

        Programa programa3 = new Programa(3, "Sistema C", "Manu"); // pasó
        programa3.agregarFuente(fuenteXML1);
        programa3.agregarFuente(fuenteXML2);

        // Crear instancia de Sophie y registrar programas
        Sophie sophie = new Sophie();
        sophie.agregarPrograma(programa1);
        sophie.agregarPrograma(programa2);
        sophie.agregarPrograma(programa3);

        // TESTEO DE C
        System.out.println("Programas con calidad por debajo de 10:");
        ArrayList<Programa> bajos = sophie.programasPorDebajoDe(10);
        for (Programa p : bajos) {
            System.out.println(" - " + p.getNombre());
        }

        // TESTEO DE D
        System.out.println("\nDetalle de método:");
        programa1.mostrarDetalleDeMetodo("sumar"); // debería mostrar info del método sumar
        programa1.mostrarDetalleDeMetodo("noExiste"); // debería avisar que no está

        // TESTEO DE E
        System.out.println("\nFuentes con calidad mayor al promedio en Programa 1:");
        ArrayList<Fuente> superiores = programa1.listadoFuentesMayoresAlPromedio(2);
        for (Fuente f : superiores) {
            System.out.println("- " + f.getNombre());
        }

        // Mostrar calidades de todo
        System.out.println("\nÍndices de calidad:");
        System.out.println("Programa 1: " + programa1.indiceCalidad());
        System.out.println("Programa 2: " + programa2.indiceCalidad());
        System.out.println("Programa 3: " + programa3.indiceCalidad());
    }
}
