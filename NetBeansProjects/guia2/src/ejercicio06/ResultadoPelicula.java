package ejercicio06;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public enum ResultadoPelicula {
    CLIENTE_INEXISTENTE,
    CONTENIDO_INEXISTENTE,
    CLIENTE_DEUDOR,
    CONTENIDO_NO_DISPONIBLE,
    ALQUILER_OK;

    static ResultadoPelicula obtenerResultado(Cliente clienteABuscar, Pelicula peliculaAVer) {
        ResultadoPelicula resultado = null;

        if (clienteABuscar == null) {
            resultado = ResultadoPelicula.CLIENTE_INEXISTENTE;
        } else if (peliculaAVer == null) {
            resultado = ResultadoPelicula.CONTENIDO_INEXISTENTE;
        } else if (clienteABuscar.esDeudor()) {
            resultado = ResultadoPelicula.CLIENTE_DEUDOR;
        } else if (peliculaAVer.esEstreno() && !clienteABuscar.esPremiun()) {
            resultado = ResultadoPelicula.CONTENIDO_NO_DISPONIBLE;
        } else {
            resultado = ResultadoPelicula.ALQUILER_OK;
        }
        return resultado;
    }
}
