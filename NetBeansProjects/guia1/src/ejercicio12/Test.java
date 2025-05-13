package ejercicio12;

public class Test {

    public static void main(String[] args) {
        String titulo = "Danzando sobre la luna";
        String cuerpo = "Este es un texto de prueba que estoy haciendo para probar la eficacia de este tipo de ejercicios";
        Documento poema = new Documento(titulo, cuerpo);

        ImpresoraMonocromatica epson = new ImpresoraMonocromatica();
        epson.encender();
        epson.recargarBandeja(5);
        epson.imprimir(poema);
        epson.apagar();
        epson.imprimir(poema);
    }
}
