package ejercicio11;

public class Test_3_11 {
    public static void main(String[] args) {

        // Crear clientes
        Cliente cliente1 = new Cliente("Gómez", "Lucía", 1134567890, "lucia@gmail.com");
        Cliente cliente2 = new Cliente("Pérez", "Tomás", 1145678901, "tomasp@gmail.com");

        // Crear inmobiliarias
        Inmobiliaria inmo1 = new Inmobiliaria("InmoSur", "contacto@inmosur.com", 3.5, "Av. Libertador 999");
        Inmobiliaria inmo2 = new Inmobiliaria("Altos del Norte", "info@altosnorte.com", 4.0, "Callao 123");

        // Crear inmuebles
        Inmueble depto1 = new Inmueble("Depto Av. Rivadavia", "80 m2", "3", 100000);
        Inmueble depto2 = new Inmueble("Casa en Boedo", "120 m2", "4", 150000);
        Inmueble depto3 = new Inmueble("PH en Almagro", "90 m2", "3", 120000);

        // Asignar interesados a los inmuebles
        depto1.agregarInteresado(cliente1);
        depto1.agregarInteresado(inmo1);

        depto2.agregarInteresado(cliente1);
        depto2.agregarInteresado(cliente2);
        depto2.agregarInteresado(inmo2);

        depto3.agregarInteresado(inmo1);
        depto3.agregarInteresado(inmo2);

        // Asignar inmuebles a las inmobiliarias (aunque no afecta el ejercicio actual)
        inmo1.agregarInmueble(depto1);
        inmo1.agregarInmueble(depto3);

        inmo2.agregarInmueble(depto2);
        inmo2.agregarInmueble(depto3);

        // Simular cambios de precio
        System.out.println(">>> Cambio de precio del depto 1:");
        depto1.setPrecio(95000);

        System.out.println("\n>>> Cambio de precio del depto 2:");
        depto2.setPrecio(140000);

        System.out.println("\n>>> Cambio de precio del depto 3:");
        depto3.setPrecio(115000);
    }
}