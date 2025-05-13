package ejercicio12;

public class Documento {

    private String titulo;
    private String cuerpo;
    private Fecha fecha;

    public Documento(String titulo, String cuerpo, Fecha fecha) {
        this.titulo = titulo;
        this.cuerpo = cuerpo;
        this.fecha = fecha;
    }

    public Documento(String titulo, String cuerpo) {
        this(titulo, cuerpo, new Fecha());
    }

    public String getFecha() {
        return this.fecha.getDay() + "/" + this.fecha.getMonth() + "/" + this.fecha.getYear();
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getCuerpo() {
        return cuerpo;
    }

    public void setCuerpo(String cuerpo) {
        this.cuerpo = cuerpo;
    }

    public void imprimir() {
        System.out.println(getFecha() + "\t**" + getTitulo() + "**");
        System.out.println(getCuerpo());
    }

}
