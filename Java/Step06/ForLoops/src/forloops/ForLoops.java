/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package forloops;

/**
 *
 * @author huw
 */
public class ForLoops {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String s;

        System.out.println("--- Ten integers ---");
        for (int i = 1; i <= 10; i++) {
            System.out.println(i);
        }

        System.out.println("\n--- \"Hello world \" ---");
        s = "Hello world";
        for (int i = 0; i < s.length(); i++) {
            System.out.printf("'%c' ", s.charAt(i));
        }
        System.out.println();
    }

}
