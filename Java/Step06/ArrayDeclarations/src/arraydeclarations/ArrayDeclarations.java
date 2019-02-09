/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package arraydeclarations;

/**
 *
 * @author huw
 */
public class ArrayDeclarations {

    public static void main(String[] args) {
        int[] intarray;
        double[] doublearray;
        char[] chararray;
        String[] stringarray;

        intarray = new int[1];
        doublearray = new double[2];
        chararray = new char[3];
        stringarray = new String[5];

        intarray[0] = 1;

        doublearray[0] = 1.1;
        doublearray[1] = 1.2;

        chararray[0] = 'a';
        chararray[1] = 'b';
        chararray[2] = 'c';

        stringarray[0] = "I";
        stringarray[1] = "wandered";
        stringarray[2] = "lonely";
        stringarray[3] = "as";
        stringarray[4] = "a";
        // stringarray[5] = "cloud";

        System.out.println(intarray[0]);
        System.out.println(doublearray[1]);
        System.out.println(chararray[2]);
        System.out.println(stringarray[1]);

    }

}
