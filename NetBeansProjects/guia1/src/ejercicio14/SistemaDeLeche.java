package ejercicio14;

public class SistemaDeLeche {

    private int medidorDeLiquido = 5;

    public boolean servirLeche(TipoDeCafe cafe) {
        boolean sePuedeServir = medidorDeLiquido - cafe.getCantLeche() >= 0;
        if (sePuedeServir) {
            descontarLeche(cafe);
        }
        return sePuedeServir;
    }

    public void descontarLeche(TipoDeCafe cafe) {
        this.medidorDeLiquido = this.medidorDeLiquido - cafe.getCantLeche();
    }

    public int getLeche() {
        return medidorDeLiquido;
    }

    public void llenarLeche(int x) {
        this.medidorDeLiquido = this.medidorDeLiquido + x;
        if (this.medidorDeLiquido > 5) {
            this.medidorDeLiquido = 5;
        }
    }

}
