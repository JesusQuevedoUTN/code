package ejercicio11;

/*
11) Utilizando las clases generadas hasta ahora, codificá en Java la siguiente situación:

Una cuenta bancaria de tipo caja de ahorros
* le pertenece a Fulano Gomez
* * nacido el 16/04/1990 

otra de tipo cuenta corriente 
* le pertenece a Mengana Torres, 
* * nacida el 23/11/1991

Ambos están casados 
* viven juntos en Av. Triunvirato 
* * 3174
* * * Villa Ortúzar.

Fulano y Mengana se mudan 
* ¿Hay que cambiar el domicilio de cada uno o basta con cambiar uno de los dos?*/
public class Test {

    public static void main(String[] args) {
        //Clases
        Fecha fechaFulano = new Fecha(16, 04, 1990);
        Fecha fechaMengana = new Fecha(23, 11, 1991);
        CuentaBancaria cuentaFulano = new CuentaBancaria(1234567890, "Caja de Ahorros");
        Domicilio domicilioGomez = new Domicilio("Avenida Triunviraro", 3174, "Villa Ortuzar");
        
        //Personas
        Persona fulano = new Persona("Fulano", "Gomez", fechaFulano);
        Persona mengana = new Persona("Mengana", "Torress", fechaMengana);
        
        //Set titulaes
        cuentaFulano.setTitular(fulano);
        fulano.setCasa(domicilioGomez);
        mengana.setCasa(domicilioGomez);

        
        //Mostrar
        mostrar(fulano, domicilioGomez);
        System.out.println("");
        mostrar(mengana, domicilioGomez);
        
        //Prueba
        domicilioGomez.setNuevaDireccion("Crovara", 0, "La Matanza");
        System.out.println("");
        System.out.println("");
        
        //Mostrar
        mostrar(fulano, domicilioGomez);
        System.out.println("");
        mostrar(mengana, domicilioGomez);
    }

    static void mostrar(Persona persona, Domicilio domicilio) {
        System.out.println(persona.toString() + "\n" + domicilio.toString());
    }

}
