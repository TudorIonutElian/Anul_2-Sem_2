/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package unaryoperators;

/**
 *
 * @author huw
 */
public class UnaryOperators {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int a;
        int b;
        a = 10;
        a++;
        System.out.println(a);
        a--;
        System.out.println(a);
        b = ++a;
        System.out.printf("b = ++a; so a = %d and b = %d\n", a, b);
        a = 10;
        b = a++;
        System.out.printf("b = a++; so a = %d and b = %d\n", a, b);
    }

}
