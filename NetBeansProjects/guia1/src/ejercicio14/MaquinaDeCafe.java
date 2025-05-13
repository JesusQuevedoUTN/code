package ejercicio14;

public class MaquinaDeCafe {

    private final double TEMPERATURA = 70;
    private String marca;
    private SistemaDeAgua moduloDeAgua;
    private SistemaDeLeche moduloDeLeche;
    private boolean encendida;

    //CONSTRUCT
    public MaquinaDeCafe(String marca) {
        this.marca = marca;
        moduloDeAgua = new SistemaDeAgua();
        moduloDeLeche = new SistemaDeLeche();
    }

    //METODOS
    public void servirCafe(TipoDeCafe cafe) {
        if (encendida) {
            if (elModuloEstaSano() && alcanzaLaLeche(cafe)) {
                moduloDeLeche.descontarLeche(cafe);
                moduloDeAgua.encenderMotor(TEMPERATURA);
                System.out.println("El cafe " + cafe.name() + " se ha servido correctamente");
                moduloDeAgua.apagarMotor();
            }
        } else {
            System.out.println("...");
        }
    }

    private boolean elModuloEstaSano() {
        return moduloDeAgua.estaSano();
    }

    private boolean alcanzaLaLeche(TipoDeCafe cafe) {
        boolean alcanza = moduloDeLeche.getLeche() - cafe.getCantLeche() >= 0;
        if (!alcanza) {
            System.out.println("ERROR. falta leche");
        }
        return alcanza;
    }

    public void llenarLeche(int x) {
        this.moduloDeLeche.llenarLeche(x);
    }

    public void encender() {
        this.encendida = true;
    }

    public void apagar() {
        this.encendida = false;
    }

    public void romper() {
        moduloDeAgua.romperSistema();
    }

    public void arreglar() {
        moduloDeAgua.repararSistema();
    }

    public void mostrarEstado() {
        if (encendida) {
            System.out.println("\n- - - - - - - - - - - - -");
            System.out.println("Marca: " + this.marca);
            System.out.println("Nivel de leche: " + moduloDeLeche.getLeche());
            if (moduloDeAgua.estaSano()) {
                System.out.println("Sistema de agua: En orden");
            } else {
                System.out.println("Sistema de agua: Necesita mantenimiento");
            }
            System.out.println("- - - - - - - - - - - - -\n");

        } else {
            System.out.println("...");
        }
    }
}
