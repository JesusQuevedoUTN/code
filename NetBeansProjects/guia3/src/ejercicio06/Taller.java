
import java.util.ArrayList;

public class Taller {

    /*
    La explotación del método cantServiciosPosibles que reciba como parámetro una lista
    de bicicletas y retorne a cuántas de ellas se le podrá prestar servicio según las condiciones
    planteadas por el taller.
     */
    public void cantServiciosPosibles(ArrayList<Bicicleta> bicicletas) {
        System.out.println("Bicis a las que se les puede hacer servicio:");
        for (Bicicleta b : bicicletas) {
            if (b.prestarServicios()) {
                System.out.println(b.toString());
            }
        }
    }

}
