package ejercicio02;

import java.util.ArrayList;
import java.util.List;

public class Inmobiliaria {

    private ArrayList<Propiedad> propiedades;

    public Inmobiliaria() {
        this.propiedades = new ArrayList<Propiedad>();
    }

    void agregarPropiedad(Propiedad p1) {
//        if (!existe(p1)) {
//            propiedades.add(p1);
//        }
        propiedades.add(p1);
    }

//    private boolean existe(Propiedad casona){
//        //mientras no encuentre ni la casa ni la direccion a la vez
//        int i = 0;
//        
//        while( i<propiedades.size() && !comparar(casona.getCalle(), propiedades.get(i).getCalle()) && casona.getAltura()!= propiedades.get(i).getAltura() ){
//            i++;
//        }
//        return i==propiedades.size();
//    }
//    private boolean existe(Propiedad casona) {
//        int i = 0;
//        for (Propiedad p : propiedades) {
//
//            if (casona.getCalle().equals(p.getCalle()) && casona.getAltura() == p.getAltura()) {
//                i++;
//            }
//        }
//        return i == propiedades.size(); // no existe
//    }

    public double promedioDePrecio() {
        double promedio = 0;
        for (Propiedad propiedad : propiedades) {
            promedio = promedio + propiedad.getPrecio();
        }
        return propiedades.isEmpty() ? 0 : promedio / propiedades.size();
    }

    public int cantidadDePropiedadesSegunTipo(TipoDeInmoviliaria tipo) {
        int cant = 0;
        for (Propiedad propiedad : propiedades) {
            if (propiedad.getTipo() == tipo) {
                cant++;
            }
        }
        return cant;
    }

    public ArrayList<Propiedad> propiedadesMasEconomicas() {
        ArrayList<Propiedad> listaBarrio = new ArrayList<Propiedad>();

        for (Propiedad propiedad : propiedades) {
            if (propiedad.getPrecio() <= promedioDePrecio()) {
                listaBarrio.add(propiedad);
            }
        }
        return listaBarrio;
    }

}
