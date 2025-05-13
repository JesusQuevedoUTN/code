package ejercicio07;

/**
* Un robot con NOMBRE
* permita atender llamadas telefónicas

Robot :
    ▪ saludar(): void
    Emite por consola un saludo diciendo: "Hola, mi nombre es ___. ¿En qué puedo ayudarte?".
    ▪ saludar(Persona): void
    Emite por consola un saludo diciendo: "Hola ___, mi nombre es ___. ¿En qué puedo 
    ayudarte?".
  */
public class Test{
    public static void main(String[] args) {
        Robot Baba = new Robot("bababot");
        
        Baba.mostrar();
        Baba.saludar();
        Baba.saludar("Mosu");
    }
    
}
