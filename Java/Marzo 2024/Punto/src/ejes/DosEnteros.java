package ejes;

public class DosEnteros{
    
    static int num1;
    static int num2;
    
    public DosEnteros(int numero1, int numero2){
        this.num1 = numero1;
        this.num2 = numero2;
    }
    
    public void mostrar(){
        System.out.println("La fraccion que dio es: " + num1 + "/" + num2 + " = " + (float)num1/num2);
    }
    
}
