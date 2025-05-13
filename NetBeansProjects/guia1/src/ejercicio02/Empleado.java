package ejercicio02;

public class Empleado {

    private final static double PORCENTAJE_DOMINIO  = 0.03; 
    private final static double PORCENTAJE_LIMITE   = 0.10; 
    private final static double COTA_SUPERIOR       = 0.04;
    private final static double PORCENTAJE_SOLTERO  = 0.04;
    
    private static String SOLTERO = "Soltero";
    
    private final int   dni;
    private String      nombre;
    private String      apellido;
    private double      salario;
    private String      estadoCivil;
    private int         cantidadDeHijos;

    //CONSTRUCTOR
    public Empleado(int dni, String nombre, String apellido,int salario, int cantidadDeHijos, String estadoCivil) {
        this.dni                = dni;
        this.nombre             = nombre;
        this.apellido           = apellido;
        this.salario            = salario;
        this.cantidadDeHijos    = cantidadDeHijos;
        this.estadoCivil        = estadoCivil;
    }
    public Empleado(int dni, String nombre, String apellido, int salario) {
        this(dni,nombre,apellido, salario, 0, SOLTERO);
    }

    //GETTER
    public double getSalario() {
        
    double  salarioReal = 0, porcentajeDeSalario = 0;
      
      porcentajeDeSalario = PORCENTAJE_DOMINIO * this.cantidadDeHijos;
      
      if(porcentajeDeSalario> PORCENTAJE_LIMITE){
        porcentajeDeSalario = PORCENTAJE_LIMITE;  
      }
        
      // salario resultante = salarioBase + 3% de salarioBase por hijo (hasta 10% de salarioBase)

      salarioReal = this.salario + this.salario * porcentajeDeSalario;
           
      // si es soltero se descuenta 4% del resultante
      if(this.estadoCivil == SOLTERO)
      {
        salarioReal *= (1 - PORCENTAJE_SOLTERO);
      }

        /*
        double salarioReal = salario;

        if(cantidadDeHijos < COTA_SUPERIOR){
            salarioReal = salarioReal * calcularDescuento(cantidadDeHijos, PORCENTAJE_DOMINIO,1);
        }
        else{
            salarioReal = salarioReal * calcularDescuento(1, PORCENTAJE_LIMITE,1);
        }
        
        if (estadoCivil == SOLTERO) {
            salarioReal = salarioReal - calcularDescuento(1, PORCENTAJE_SOLTERO,0);
        }*/
        
        return salarioReal;
    }
    
    private double calcularDescuento(int x, int y, int uno){
        return (x * y)/100 + uno;
    }

    //GETTER
    public String getNombre() {
        return nombre + " " + apellido;
    }

    //ATRIBUTOS
    public int dni() {
        return dni;
    }
    
    
    @Override
    public String toString(){
        return "Nombre " + getNombre() + "\nDNI: " + dni + "\nSalario: " + getSalario();
    }
}

