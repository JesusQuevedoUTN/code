package ejercicio08;

// Autor: Chisus
// Fecha de creación: 17/05/2025
public class Test {

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
        arturitu.agregarPiezaOperativa(TipoDePieza.SENSOR_DE_PROXIMIDAD, Estado.ROTO);
        arturitu.agregarPiezaOperativa(TipoDePieza.BATERIA_DE_LITIO, Estado.IRREPARABLE);
        arturitu.agregarPiezaOperativa(TipoDePieza.VISOR_NOCTURNO, Estado.GASTADO);
        arturitu.agregarPiezaOperativa(TipoDePieza.DISCO_DE_ALMACENAMIENTO, Estado.SANO);

        //CITRI DEBE TENER SUS PROPIAS PIEZAS, NO LE HACE FALTA SENSOR PERO SI UN MODULO DE TRADUCCION
        citripio.agregarPiezaOperativa(TipoDePieza.VISOR_NOCTURNO, Estado.SANO);
        citripio.agregarPiezaOperativa(TipoDePieza.BATERIA_DE_LITIO, Estado.SANO);
        citripio.agregarPiezaOperativa(TipoDePieza.DISCO_DE_ALMACENAMIENTO, Estado.SANO);
        citripio.agregarPiezaOperativa(TipoDePieza.MODULO_DE_IDIOMAS, Estado.ROTO);
        citripio.agregarPiezaOperativa(TipoDePieza.SENSOR_DE_PROXIMIDAD,Estado.IRREPARABLE);
        //BIBI ES UN ROBOT SIMPLE, APENAS SI TIENE PIEZAS
        bibieit.agregarPiezaOperativa(TipoDePieza.SENSOR_DE_PROXIMIDAD, Estado.SANO);
        bibieit.agregarPiezaOperativa(TipoDePieza.VISOR_NOCTURNO, Estado.SANO);
        bibieit.agregarPiezaOperativa(TipoDePieza.BATERIA_DE_LITIO, Estado.DANIADO);
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
