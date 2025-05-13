package ejercicio03;

public class CuentaBancaria {

    
    private int CBU;
    private String tipo;
    private String TIPO_AHORRO              = "Ahorro";
    private String TIPO_CUENTA_CORRIENTE    = "Cuenta Corriente";
    private String TIPO_CREDITO             = "Credito";
    private String TIPO_DEBITO              = "Debito";
    private double saldo;

    //CONSTRUCT
    public CuentaBancaria(int CBU, String tipo) {
        this.CBU    = CBU;
        this.tipo   = tipo;
    }

    //GETTER
    public int getCBU() {
        return CBU;
    }

    public double getSaldo() {
        return saldo;
    }

    
    //ATRIBUTE
    public void depositarDinero(double dinero) {
        saldo = saldo + dinero;
    }

    public void extraerDinero(double dinero) {
        if (dinero < getSaldo() || tipo == TIPO_CUENTA_CORRIENTE) {
            saldo = saldo - dinero;
        }
    }

    public int ultimosDigitos() {
        return CBU%1000;
    }
    
    //OVERRIDE
    @Override
    public String toString(){
        return "CBU: " + CBU + "\nTipo de cuenta: " + tipo + "\nSaldo Actual: " + saldo;
    }
}
