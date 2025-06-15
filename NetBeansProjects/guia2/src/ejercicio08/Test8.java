
package ejercicio08;

// Autor: Chisus
// Fecha de creación: 17/05/2025
public class Test8 {

    public static void main(String[] args) {
        //ANALISIS
        //hay un droide, tiene nombre y piezas, cuantas? no sé
        //droide encuenta droide
        //droide guarda su direccion
        //droide analiza la lista de partes sanas
        //droide cambia sus piezas con la de ese otro droide, ahora el otro tiene el roto
        Droide arturitu = new Droide("R2D2");
        Droide citripio = new Droide("C3P0");
        Droide bibieit = new Droide("BB8");

        cargarDroides(arturitu, citripio, bibieit);
        arturitu.registrarDroideRoto(citripio);
        arturitu.registrarDroideRoto(bibieit);

        System.out.println("+ + + MISION 001 + + +");
        mostrarEstados(arturitu, citripio, bibieit);

        //MOSTRAR ESTADO
        System.out.println("+ + + AUTOREPARACION DE " + arturitu.getNombre() + " EN PROCESO + + +");
        System.out.println("ESTADO: " + arturitu.autoRepararse());
        System.out.println("+ + + AUTOREPARACION FINALIZADA + + +");

        System.out.println("");
        mostrarEstados(arturitu, citripio, bibieit);
    }

    static void cargarDroides(Droide arturitu, Droide citripio, Droide bibieit) {
        //ARTUR Y CITRI SUFRIERON UN ACCIDENTE EN UNA MISIÓN, SE ROMPIERON, DE PASO
        //BIBIEIT SE ROMPIÓ UNA PIEZA QUE NECESITA Y CITRI LA OTRA PARA QUE
        //REQUIERA DE AMBOS

        //LE AGREGAMOS PIEZAS A ARTUR, ES UN ROBOT MUY COMPLETO
        arturitu.agregarPiezaNoOperativa(new Pieza(TipoDePieza.SENSOR_DE_PROXIMIDAD) );
        arturitu.agregarPiezaNoOperativa(new Pieza(TipoDePieza.BATERIA_DE_LITIO) );
        arturitu.agregarPiezaNoOperativa(new Pieza(TipoDePieza.VISOR_NOCTURNO) ); 
        arturitu.agregarPiezaOperativa(new Pieza(TipoDePieza.DISCO_DE_ALMACENAMIENTO) );

        //CITRI DEBE TENER SUS PROPIAS PIEZAS, NO LE HACE FALTA SENSOR PERO SI UN MODULO DE TRADUCCION
        citripio.agregarPiezaOperativa(new Pieza( TipoDePieza.VISOR_NOCTURNO) );
        citripio.agregarPiezaOperativa(new Pieza( TipoDePieza.BATERIA_DE_LITIO) );
        citripio.agregarPiezaOperativa(new Pieza( TipoDePieza.DISCO_DE_ALMACENAMIENTO) );
        citripio.agregarPiezaNoOperativa(new Pieza( TipoDePieza.MODULO_DE_IDIOMAS) );
        citripio.agregarPiezaNoOperativa(new Pieza( TipoDePieza.SENSOR_DE_PROXIMIDAD) );
        //BIBI ES UN ROBOT SIMPLE, APENAS SI TIENE PIEZAS
        bibieit.agregarPiezaOperativa(new Pieza( TipoDePieza.SENSOR_DE_PROXIMIDAD) );
        bibieit.agregarPiezaOperativa(new Pieza( TipoDePieza.VISOR_NOCTURNO) );
        bibieit.agregarPiezaNoOperativa(new Pieza( TipoDePieza.BATERIA_DE_LITIO) );
    }

    static void mostrarEstados(Droide arturitu, Droide citripio, Droide bibieit) {
        arturitu.estado();
        System.out.println("");
        citripio.estado();
        System.out.println("");
        bibieit.estado();
        System.out.println("");
    }

}
