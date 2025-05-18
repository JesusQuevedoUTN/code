package ejercicio08;

// Autor: Chisus
// Fecha de creación: 17/05/2025

public class Test {
    /*
    Hace mucho tiempo, en una galaxia muy lejana, había muchos droides que formaban parte de la 
    existencia cotidiana de todos. Algo particular unía a todos esos droides: la capacidad que tenían de 
    auto repararse. Ante algún desperfecto, podían reemplazar la o las piezas que no estaban 
    funcionando por otras (con el mismo nombre) para seguir operando.
    Para esto, cada droide llevaba un registro detallado de las piezas que lo componían, manteniéndolas 
    por separado entre piezas operativas y no operativas. Cada una de estas piezas tiene un nombre 
    (String) que es el mismo en todos los droides (por ejemplo, “Batería de litio”, “Sensor de proximidad”, 
    “Visor nocturno”, etc). 
    Siempre que un droide encontraba a otro droide fuera de servicio (luego de batallas o simplemente 
    por el uso) lo registraba para así, de ser necesario, usar las piezas sanas de éste para repararse. 
    Al necesitar una pieza buscaba entre los droides rotos que tenía registrados, chequeando si 
    encontraba entre ellos las piezas sanas que necesitaba. De encontrarlas, reemplazaba sus piezas no 
    operativas por las operativas encontradas en los otros droides.
    Basado en el enunciado descripto, realizá:
    A) El diagrama de clases que lo modelice, con sus relaciones, atributos y métodos.
    B) La implementación del método autoRepararse de la clase Droide, que no recibe 
    parámetros. Debe intentar reemplazar sus piezas no operativas por las piezas operativas que 
    pudiera encontrar en alguno de los otros droides. Cada vez que una pieza se reemplaza la 
    pieza no operativa original se descarta. Este método devuelve alguno de estos resultados:
    ▪ COMPLETAMENTE_OPERATIVO: cuando todas las piezas del droide están 
    operativas.
    ▪ REPARACION_PARCIAL: cuando quedan algunas piezas no operativas, pero alguna 
    se pudo reemplazar.
    ▪ REPARACION_IMPOSIBLE: cuando no se logre reparar ninguna de las piezas no 
    operativas que pudiera tener
    */
    public static void main(String[] args) {
        //hay un droide, tiene nombre y piezas, cuantas? no sé, sinceramente
        //droide encuenta droide
        //droide guarda su direccion
        //droide analiza la lista de partes sanas
        //droide cambia sus piezas con la de ese otro droide, ahora el otro tiene el roto       
        Droide arturitu = new Droide("R2D2");
        Droide citripio = new Droide("C3P0");
        Droide bibieit = new Droide("BB8");
        
        //
        //USADO EL CHATGPT DE HERRAMIENTA PARA ARMAR ESTA PARTE DEL MAIN
        //
        
        //LE AGREGAMOS PIEZAS A ARTUR
        arturitu.agregarPiezaOperativa(TipoDePieza.SENSOR_DE_PROXIMIDAD);
        arturitu.agregarPiezaOperativa(TipoDePieza.BATERIA_DE_LITIO);
        arturitu.agregarPiezaOperativa(TipoDePieza.VISOR_NOCTURNO);
        arturitu.agregarPiezaOperativa(TipoDePieza.DISCO_DE_ALMACENAMIENTO);

        //CITRI DEBE TENER SUS PROPIAS PIEZAS, NO LE HACE FALTA SENSOR PERO SI UN MODULO DE TRADUCCION
        citripio.agregarPiezaOperativa(TipoDePieza.VISOR_NOCTURNO);
        citripio.agregarPiezaOperativa(TipoDePieza.BATERIA_DE_LITIO);
        citripio.agregarPiezaOperativa(TipoDePieza.DISCO_DE_ALMACENAMIENTO);
        citripio.agregarPiezaOperativa(TipoDePieza.MODULO_DE_IDIOMAS);

        //BIBI ES UN ROBOT SIMPLE, APENAS SI TIENE PIEZAS
        bibieit.agregarPiezaOperativa(TipoDePieza.SENSOR_DE_PROXIMIDAD);
        bibieit.agregarPiezaOperativa(TipoDePieza.VISOR_NOCTURNO);

        //ARTUR Y CITRI SUFRIERON UN ACCIDENTE EN UNA MISIÓN, SE ROMPIERON
        arturitu.dañarPieza(TipoDePieza.SENSOR_DE_PROXIMIDAD);
        arturitu.dañarPieza(TipoDePieza.BATERIA_DE_LITIO);
        citripio.dañarPieza(TipoDePieza.MODULO_DE_IDIOMAS);
        bibieit.dañarPieza(TipoDePieza.BATERIA_DE_LITIO);

        //REGISTRAR BOTS
        arturitu.registrarDroideRoto(citripio);
        arturitu.registrarDroideRoto(bibieit);
        
        //MOSTRAR ESTADO
        System.out.println(arturitu.getNombre());
        System.out.println( "ESTADO:" + arturitu.autoRepararse() );
        }

        
    }

    
}
