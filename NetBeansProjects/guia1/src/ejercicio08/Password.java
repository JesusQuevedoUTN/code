package ejercicio08;

public class Password {

    static final int MINIMO_CAMBIAR_CONTRA = 6;
    static final int MINIMO_SEGURIDAD = 8;
    static final int LONGITUD_POR_DEFECTO = 10;
    private String contrasenia;

    
    /*▪ Password() {…} 
    Crea un password cuyo valor se crea automáticamente.*/
    public Password() {
        this.contrasenia = generarAleatorio(LONGITUD_POR_DEFECTO);
    }
    
    /*▪ Password(String) {…}
    Crea un password cuyo valor viene dado por parámetro.*/
    public Password(String contrasenia) {
        this.contrasenia = contrasenia;
    }

    /*▪ boolean esFuerte() {…}
    Devuelve si la password es fuerte o no. Una password es fuerte cuando tenga al menos 8 caracteres.*/
    public Boolean esFuerte() {
        return contrasenia.length() >= MINIMO_SEGURIDAD;
    }

    /*▪ boolean nuevoValor(String) {…}
    Establece como nuevo valor de password el recibido como parámetro, siempre y cuando su 
    longitud sea mayor o igual a 6, si no, lo deja como estaba. Devuelve si se pudo o no establecer 
    el valor.*/
    public Boolean nuevoValor(String contra) {
        boolean x = false;
        if (contra.length() >= MINIMO_CAMBIAR_CONTRA) {
            this.contrasenia = contra;
            x = true;
        }
        return x;
    }

    /*▪ String generarAleatorio(int) {…}
    Devuelve una cadena que representa un valor de password aleatorio cuya longitud coincida 
    con el parámetro recibido. Si el parámetro es menor que 6, devuelve null.
    Además, deben poder crearse passwords con o sin valor inicial, por ello es que la clase contará con 
    un constructor sobrecargado: */
    private String generarAleatorio(int longitud) {
        StringBuilder contraAleatoria = new StringBuilder();
        int n; 
        char c; 
        
        if (longitud >= MINIMO_CAMBIAR_CONTRA) {
            for (int i = 0; i < longitud; i++) {
                //NO TENGO NI PUTA IDEA DE COMO RANDOMIZAR LA CONCHA DE LA LORAAAAAA
                n = (int) (Math.random() * (127 - 32)) + 32;
                c = (char) n;
                contraAleatoria.append(c);
            }
        }
        return contraAleatoria.toString();
    }
    
    public void mostrar(){
        System.out.println(contrasenia);
    }

}