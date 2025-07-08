package EstacionEspacial;

public class Main {

    public static void main(String[] args) {
        //CREAMOS UNA NUEVA NAVE ESPACIAL, UNA NUEVA, LA DENOMINADA, ATLANTIS
        EstacionEspacial atlantis = new EstacionEspacial("Atlantis", 5);

        //5 NAVES ESTÁN INTERESADAS EN ESTA NUEVA SEDE ESPACIAL
        Cargo nave1 = new Cargo("Baterias recargables", 120, "Neptuno", 21);
        Crusier nave2 = new Crusier(0, "Mercurio", 8);
        Cargo nave3 = new Cargo("Sustancias cosmicas", 90, "Marte", 15);
        Crusier nave4 = new Crusier(12, "Urano", 48);

        //ESTAS NUEVAS NAVES FUERON LAS PRIMERAS CLIENTAS
        atlantis.estacionarNave(nave1);
        atlantis.estacionarNave(nave2);
        atlantis.estacionarNave(nave3);
        atlantis.estacionarNave(nave4);

        //RESULTADOS
        atlantis.mostrarManifiestos();
    }
}
