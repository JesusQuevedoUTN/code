package ejercicio01;

import java.util.ArrayList;

/*
    Métodos más comunes de ArrayList

    add(Elemento) agrega al final
    add(index, Elemento) agrega en la posición index, corriendo lo demás un lugar a la derecha
    remove(index): Remueve por posicion, retorna el objeto borrado
    remove(Elemento): Remueve por referencia, retorna bollean si pudo o no
    get(index): Devuelve el elemento en la posicion index.
    set(index, Elemento): Reemplaza al elemento en la posición index.
    size(): Retorna la cantidad de elementos de la lista
    isEmpty(): Devuelve si está o no vacía.
    contains(Elemento): Retorna si está o no en la lista
 */
public class Test {

    public static void main(String[] args) {
        Agenda agenda = new Agenda();
        
        System.out.println(agenda.cantPersonas()); // Deberían ser 0

        agenda.agregarPersona("123", "Juan", "Perez", new Domicilio("Callao", 352, "Balvanera"));
        agenda.agregarPersona("234", "Lucía", "González", new Domicilio("Corrientes", 1234, "Almagro"));
        agenda.agregarPersona("345", "Martín", "Ramírez", new Domicilio("Santa Fe", 987, "Palermo"));
        agenda.agregarPersona("456", "Carla", "Fernández", new Domicilio("Rivadavia", 4500, "Caballito"));
        agenda.agregarPersona("654", "Rocío", "Paredes", new Domicilio("Medrano", 1150, "Almagro"));
        agenda.agregarPersona("567", "Santiago", "López", new Domicilio("Avenida La Plata", 650, "Boedo"));
        agenda.agregarPersona("678", "María", "Juárez", new Domicilio("Defensa", 300, "San Telmo"));
        agenda.agregarPersona("543", "Leandro", "Sosa", new Domicilio("Yatay", 900, "Almagro"));
        agenda.agregarPersona("789", "Federico", "Silva", new Domicilio("Avenida del Libertador", 3200, "Núñez"));
        agenda.agregarPersona("890", "Valentina", "Moreno", new Domicilio("Thames", 850, "Villa Crespo"));
        agenda.agregarPersona("901", "Julián", "Castro", new Domicilio("Av. Independencia", 2100, "Monserrat"));
        agenda.agregarPersona("012", "Florencia", "Medina", new Domicilio("Av. San Juan", 1700, "Constitución"));
        agenda.agregarPersona("432", "Ana", "Benítez", new Domicilio("Bulnes", 1450, "Almagro"));
        agenda.agregarPersona("321", "Diego", "Ortiz", new Domicilio("José María Moreno", 120, "Parque Chacabuco"));
        // DNI REPETIDO, no debería agregarse:
        agenda.agregarPersona("123", "Fake", "Fake", new Domicilio("José María Moreno", 120, "Parque Chacabuco")); 
        
        System.out.printf("Hay %d personas en la agenda\n", agenda.cantPersonas()); // Deberían ser 14
        
        System.out.println( agenda.buscarPersona("012") ); // Retorna a Florencia Medina
        System.out.println( agenda.buscarPersona("999") ); // Retorna null
        
        System.out.println(agenda.devolverUltimo()); // Retorna a Diego Ortiz
        
        System.out.println(agenda.modificarDomicilio("012", new Domicilio("Nueva calle", 987, "Almagro")));
        
        System.out.println( agenda.buscarPersona("012") ); // Retorna a Florencia Medina (con nuevo domicilio)
        
        mostrarLista(agenda.obtenerPorBarrio("Almagro"));
        
        Persona borrada = agenda.removerPersona("890"); // Chau Valentina Moreno 
        System.out.printf("Se borró a %s", borrada.nombreCompleto());
        
        //agenda.listarPersonas(); // Deberían ser 13
        
        agenda.vaciar();
        
        System.out.printf("Hay %d personas en la agenda", agenda.cantPersonas()); // Deberían ser 0
        
        agenda.listarPersonas();
        
        
        
    }
    
    public static void mostrarLista(ArrayList<Persona> lista) {
        System.out.println("----------- Mostrando lista ----------");
        for (Persona p : lista) {
            System.out.println(p);
        }
        System.out.println("-----------  Fin  de lista  ----------");
    }
}