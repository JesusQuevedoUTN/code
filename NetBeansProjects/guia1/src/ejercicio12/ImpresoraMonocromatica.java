package ejercicio12;

/*
12) Desarrollar la clase ImpresoraMonocromatica. Sus atributos serán si
está o no encendida, la cantidad de hojas actualmente en su bandeja y el
nivel de tinta negra. Inicialmente, toda impresora está apagada, sin hojas y
con nivel de tinta en 100.
Debe responder a los siguientes métodos:
 */
public class ImpresoraMonocromatica {

    private final int CARACTERES_POR_HOJA = 200;
    private final int CAPACIDAD_DE_LA_TINTA = 50;
    private final int HOJAS_MAXIMA = 35;
    private final int TINTA_MAXIMA = 100;
    private boolean encendida;
    private int cantidadDeHojas;
    private int nivelDeTintaNegra = 100;
    private int restanteDelNivel = 50;
    Documento documento;

    /*
▪ void imprimir(Documento) {…}
formato:
Fecha **Titulo**
Cuerpo
* Al hacerlo, se descuenta 1 punto de nivel de tinta por cada 50 caracteres del cuerpo impresos
y se resta 1 hoja de la cantidad en bandeja por cada 20 caracteres del cuerpo impreso. Se
debe verificar antes de imprimir que se cuente con nivel de tinta y cantidad de hojas
suficientes.
     */
    public void imprimir(Documento documento) {
        if (puedeImprimir(documento)) {
            documento.imprimir();
        }
    }

    /* void recargarBandeja(int) {…}
Suma a la bandeja una cantidad de hojas. El máximo de la bandeja es de 35 hojas. Se debe
verificar no excederse de tal valor. Si el parámetro es negativo, la bandeja se deja como está.*/
    public void recargarBandeja(int cantidadDeHojas) {
        if (((this.cantidadDeHojas + cantidadDeHojas) <= HOJAS_MAXIMA) && (cantidadDeHojas >= 0)) {
            this.cantidadDeHojas = this.cantidadDeHojas + cantidadDeHojas;
        }
    }

    public void recargarTinta(int Tinta) {
        if (((this.nivelDeTintaNegra + Tinta) <= TINTA_MAXIMA) && (Tinta >= 0)) {
            this.nivelDeTintaNegra = this.nivelDeTintaNegra + Tinta;
        }
    }

    private boolean puedeImprimir(Documento documento) {
        int hojasNecesarias;
        int hojas;
        boolean imprime = encendida && alcanzanLasHojas(documento) && alcanzaElNivelDeTinta(documento);
        if (imprime) {
            restarHojasyNivelesDeTinta(documento);
        }
        return imprime;
    }

    //ALCANZA?
    private boolean alcanzanLasHojas(Documento documento) {
        boolean alcanza = (this.cantidadDeHojas - (contarCaracteres(documento) / CARACTERES_POR_HOJA)) >= 1;
        if (!alcanza) {
            System.out.println("ERROR. Faltan hojas");
        }
        return alcanza;
    }

    private boolean alcanzaElNivelDeTinta(Documento documento) {
        boolean alcanza = (this.nivelDeTintaNegra - (contarCaracteres(documento) / CAPACIDAD_DE_LA_TINTA)) >= 1;
        if (!alcanza) {
            System.out.println("ERROR. Falta tinta");
        }
        return alcanza;
    }

    //CONTAR
    private int contarCaracteres(Documento documento) {
        return documento.getFecha().length() + documento.getTitulo().length() + documento.getCuerpo().length();
    }
    
    //DESCONTAR
    private void restarHojasyNivelesDeTinta(Documento documento){
        this.nivelDeTintaNegra = this.nivelDeTintaNegra - contarCaracteres(documento) / CAPACIDAD_DE_LA_TINTA;
        this.cantidadDeHojas = this.cantidadDeHojas - contarCaracteres(documento) / CARACTERES_POR_HOJA;
    }

    //ENCENDER Y APAGAR
    public void encender() {
        this.encendida = true;
    }

    public void apagar() {
        this.encendida = false;
    }

}
