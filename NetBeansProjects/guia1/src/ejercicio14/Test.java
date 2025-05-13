package ejercicio14;

public class Test {

    public static void main(String[] args) {
        MaquinaDeCafe mdc = new MaquinaDeCafe("Oster");

        System.out.println("Otro dia, otro cafe");
        mdc.servirCafe(TipoDeCafe.LATTE);
        System.out.println("eh????");
        mdc.servirCafe(TipoDeCafe.LATTE);

        System.out.println("Ah si, olvide encenderlo");
        mdc.encender();
        System.out.println("Listo, hora de hacer cafe para la familia");

        mdc.servirCafe(TipoDeCafe.LATTE);
        mdc.servirCafe(TipoDeCafe.LATTE);
        mdc.servirCafe(TipoDeCafe.EXPRESSO);
        mdc.servirCafe(TipoDeCafe.LAGRIMA);
        System.out.println("Cierto, hay que rellenarlo, cuanto queda?");

        mdc.mostrarEstado();
        System.out.println("mmmm le pondre 3");
        mdc.llenarLeche(3);

        System.out.println("Ahora si deberia estar");
        mdc.mostrarEstado();
        System.out.println("excelente");
        
        mdc.servirCafe(TipoDeCafe.LATTE);
        
        mdc.romper();
        mdc.servirCafe(TipoDeCafe.EXPRESSO);
        System.out.println("Carajo y ahora?");

        mdc.mostrarEstado();
        System.out.println("Agh, ok tu ganas");
        mdc.arreglar();
        System.out.println("Veamos");
        
        mdc.mostrarEstado();
        System.out.println("Listo, cafe para toda la familia, veamos como quedo");

        mdc.mostrarEstado();
        mdc.apagar();
        
        System.out.println("Te amo, cafe, digo familia, si eso, familia");
    }
}
