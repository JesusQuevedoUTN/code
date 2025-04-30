package perros;

public class Perro {

    private String ladrido;

    public Perro(String s) {
        ladrido = s;
    }

    public void ladrar() {
        System.out.println(ladrido);
    }
}
