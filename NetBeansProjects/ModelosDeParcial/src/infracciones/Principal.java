package infracciones;

import java.time.LocalDate;
import java.time.Month;
import java.time.Period;
import java.util.ArrayList;

public class Principal {

    public static void main(String[] args) {

        ArrayList<Reclamo> reclamos = new ArrayList<>();

        // Reclamos caducados (Mal estacionamiento de hace más de 2 años)
        reclamos.add(new Reclamo(12345678, new MalEstacionamiento(LocalDate.now().minusDays(800))));
        reclamos.add(new Reclamo(23456789, new MalEstacionamiento(LocalDate.now().minusDays(500))));
        reclamos.add(new Reclamo(34567890, new MalEstacionamiento(LocalDate.now().minusDays(370))));

        // Reclamos NO caducados (Mal estacionamiento recientes)
        reclamos.add(new Reclamo(45678901, new MalEstacionamiento(LocalDate.now().minusDays(200))));
        reclamos.add(new Reclamo(56789012, new MalEstacionamiento(LocalDate.now().minusDays(50))));
/*
        ///////////////////////////
        LocalDate fechaPasada = LocalDate.of(2024, 9, 25);
        LocalDate hoy = LocalDate.now();
        Period diferencia = Period.between(fechaPasada, hoy);
        System.out.println("Pasaron " + diferencia.getYears() + " años, " +
                           diferencia.getMonths() + " meses y " +
                           diferencia.getDays() + " días.");
        ///////////////////////////
*/      
        // Exceso de Velocidad (nunca caducan)
        reclamos.add(new Reclamo(67890123, new ExcesoDeVelocidad(LocalDate.of(2020, 1, 1))));
        reclamos.add(new Reclamo(78901234, new ExcesoDeVelocidad(LocalDate.of(2023, 12, 12))));
        reclamos.add(new Reclamo(89012345, new ExcesoDeVelocidad(LocalDate.of(2025, 7, 7))));
        reclamos.add(new Reclamo(90123456, new ExcesoDeVelocidad(LocalDate.of(2024, 12, 1))));
        reclamos.add(new Reclamo(91234567, new ExcesoDeVelocidad(LocalDate.now())));

        SistemaDeInfraccionDeTransito sistema = new SistemaDeInfraccionDeTransito(reclamos);

        // Mostrar resultados
        System.out.println("Importe total de todas las infracciones: $" + sistema.importeTotal());
        System.out.println("Cantidad de reclamos con infracciones caducadas: " + sistema.cantidadDeInfraccionesCaducadas());
    }

}
