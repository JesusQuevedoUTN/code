package ejes;

public class Main {

    public static void main(String[] args) {
        //1
        //Punto
        Punto coordenadas = new Punto(1, 2);
        System.out.println("Coordenada en el punto " + coordenadas.mostrar());
        System.out.println("");
        
        //2
        //Circulo
        Punto centro = new Punto(5, 7);
        Circle circulo1 = new Circle(centro, 8);
        circulo1.mostrar();
        
        Circle circulo2 = new Circle(centro, 0);
        circulo2.mostrar();
        System.out.println("");
        
        //3
        //Triangulo
        Punto arista1 = new Punto(4, 4);
        Punto arista2 = new Punto(5, 5);
        Punto arista3 = new Punto(6, 9);
        Triangulo triangulo1 = new Triangulo(arista1, arista2, arista3);
        triangulo1.mostrar();
        
        Triangulo triangulo2 = new Triangulo(arista1, arista1, arista3);
        triangulo2.mostrar();
        System.out.println("");
        
        //4
        //NumeroFraccionario
        DosEnteros fraccion = new DosEnteros(2 , 5);
        fraccion.mostrar();
        System.out.println("");
        
        //5
        //CuentaCorriente
        Guita cuentaCorriente = new Guita(555 , 275);
        cuentaCorriente.cantidadDeGuita();
        System.out.println("");
        
        //6
        //Ascensor
        Ascensor subir = new Ascensor(1);
        subir.tomarAscensor();
        Ascensor bajar = new Ascensor(-5);
        bajar.tomarAscensor();
        Ascensor quieto = new Ascensor(0);
        bajar.tomarAscensor();
    }
}
