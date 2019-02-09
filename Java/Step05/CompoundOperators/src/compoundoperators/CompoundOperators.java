/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package compoundoperators;

/**
 *
 * @author huw
 */
public class CompoundOperators {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int a;
        int b;

        a = 10;
        b = 2;
        a = a + b;
        System.out.println(a);
        a += b;
        System.out.println(a);
        a = a - b;
        System.out.println(a);
        a -= b;
        System.out.println(a);
        a = a * b;
        System.out.println(a);
        a *= b;
        System.out.println(a);
        a = a / b;
        System.out.println(a);
        a /= b;
        System.out.println(a);

    }

}
