package ejercicio09;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public enum Resultado {

    VEHICULO_NO_HABILITADO,
    VEHICULO_YA_ESTACIONADO,
    NO_ESTACIONA_ADEUDA,
    INGRESO_OK;

    static Resultado deEstacionar(Vehiculo coche) {
        Resultado estado = null;
        if (coche == null) {
            estado = Resultado.VEHICULO_NO_HABILITADO;
        } else if (coche.estaEstacionado()) {
            estado = Resultado.VEHICULO_YA_ESTACIONADO;
        } else if (coche.tieneDeuda()) {
            estado = Resultado.NO_ESTACIONA_ADEUDA;
        } else {
            estado = Resultado.INGRESO_OK;
        }
        return estado;
    }

}
