package tree;

import java.util.TreeSet;

public class Tree {

    public static void main(String[] args) {
        TreeSet<Integer> tr = new TreeSet<>();
        tr.add(8);
        tr.add(13);
        tr.add(22);
        tr.add(45);
        tr.add(22);
        tr.add(17);
        tr.add(13);
        tr.add(11);
        tr.add(14);
        tr.add(5);
        System.out.println(tr);

        Integer i = 125743;
        System.out.println(i.toString().length());
        int j = 125743;
        System.out.println((int) (Math.ceil(Math.log10(j))));


    }
}
