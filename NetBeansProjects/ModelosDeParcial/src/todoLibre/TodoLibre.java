package todoLibre;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class TodoLibre {

    private ArrayList<Usuario> usuarios;
    private ArrayList<OrdenDeCompra> ordenesAEnviar;

    public TodoLibre(ArrayList<Usuario> usuarios, ArrayList<OrdenDeCompra> ordenesAEnviar) {
        this.usuarios = usuarios;
        this.ordenesAEnviar = ordenesAEnviar;
    }

    public double porcentajeDeOrdenesEnComuna() {
        int i = 0;
        for (OrdenDeCompra o : ordenesAEnviar) {
            if (o.mismoComuna()) {
                i++;
            }
        }
        return i * 100 / ordenesAEnviar.size();
    }

    public int enviogratis() {
        int total = 0;
        for (OrdenDeCompra o : ordenesAEnviar) {
            if (o.envioGratis()) {
                total++;
            }
        }
        return total;
    }

}
