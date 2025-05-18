package ejercicio08;
import java.util.ArrayList;

// Autor: Chisus
// Fecha de creación: 17/05/2025

public class Droide {
    private String nombre;
    private boolean servicio;
    private int usos;
    private ArrayList piezas;

    public Droide(String nombre) {
        this.nombre = nombre;
    }
    
    //METODO
    public TipoDeEstado autoRepararse()
    {
        return null;
    }
    
    public void agregarPiezaOperativa(TipoDePieza tipoDePieza) {
        
    }

    public void dañarPieza(TipoDePieza tipoDePieza) {
        
    }

    public void registrarDroideRoto(Droide citripio) {
        
    }

    //GETTER
    public String getNombre() {
        return nombre;
    }
    
    
    //PRIVATES
    private Pieza buscarPieza()
    {   
        return null;
    }
    private void cambiarPieza()
    {
        
    }
    
    private Droide registrarDroide()
    {
        return null;        
    }
    
    //TOSTRING
    @Override
    public String toString() {
        return "Droide{" + "nombre=" + nombre + ", piezas=" + piezas + '}';
    }

}