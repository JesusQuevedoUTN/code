package ejes;

/**
 *
 * @author jesus
 */
public class Ascensor {
    static int piso;
    public Ascensor(int i){
        this.piso = i;
    }
    
    public void tomarAscensor(){
        if (piso>0) {
        System.out.println("Usted subio " + piso + " pisos");
        }
        else if(piso<0){
            System.out.println("Usted bajo " + piso + " pisos");
        }
        else{
            System.out.println("Bien, se quedo en el mismo lugar");
        }
    }
}
