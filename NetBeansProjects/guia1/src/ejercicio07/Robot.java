package ejercicio07;
/*
    ▪ saludar(): void
    Emite por consola un saludo diciendo: "Hola, mi nombre es ___. ¿En qué puedo ayudarte?".
    ▪ saludar(Persona): void
    Emite por consola un saludo diciendo: "Hola ___, mi nombre es ___. ¿En qué puedo ayudarte?".
*/
public class Robot {
    private String modelo;
    
    public Robot(String nombre){
        this.modelo = nombre;
    }

    public String getNombre() {
        return modelo;
    }
    
    public void saludar(){
        saludar("");
    }
    
    public void saludar(String nombre){
        
        System.out.println("Hola" + (nombre.isEmpty()? "": " "+ nombre)+ ", mi nombre es " + modelo +". En que puedo ayudarte?");
    }
    
    public void mostrar(){
        System.out.println(toString());
    }
    
    @Override
    public String toString(){
        return "Robot: " + modelo;
    }
}
