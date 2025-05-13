package ejercicio13;

import java.time.LocalDate;

public class Fecha {

    final private int NAVIDAD = 2512;
    private int year;
    private int month;
    private int day;

    //CONSTRUCTS
    public Fecha(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public Fecha() {
        this(LocalDate.now().getDayOfMonth(), LocalDate.now().getMonthValue(), LocalDate.now().getYear());
    }

    //GETTERS
    public int getYear() {
        return year;
    }

    public int getMonth() {
        return month;
    }

    public int getDay() {
        return day;
    }

    //ATRIBUTES
    public Boolean esNavidad() {
        return month + day * 100 == NAVIDAD;
    }

    public void sumarMes(int x) {
        if (month + x <= 12) {
            month = month + x;
        }
    }

    public int getEdad() {
        return LocalDate.now().getYear() - year;
    }

    //OVERRIDE
    @Override
    public String toString() {
        return "Fecha: " + year + "/" + month + "/" + day;
    }

}
