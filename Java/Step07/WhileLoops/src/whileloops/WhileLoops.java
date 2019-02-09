/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package whileloops;

/**
 *
 * @author huw
 */
public class WhileLoops {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int intarray[] = {1, 2, 3, 4, 5};
        int i;

        System.out.printf("--- for loop ---\n");
        for (i = 0; i < 5; i++) {
            System.out.printf("%d\n", intarray[i]);
        }

        System.out.printf("--- while loop (i = 0) ---\n");
        i = 0;
        while (i < 5) {
            System.out.printf("%d\n", intarray[i]);
             i++;
        }

        System.out.printf("--- do..while loop (i = 0) ---\n");
        i = 0;
        do {
            System.out.printf("%d\n", intarray[i]);
            i++;
        } while (i < 5);

        System.out.printf("--- while loop (i = 2) ---\n");
        i = 2;
        while (i < 2) {
            System.out.printf("%d\n", intarray[i]);
            i++;
        }

        System.out.printf("--- do..while loop (i = 2) ---\n");
        i = 2;
        do {
            System.out.printf("%d\n", intarray[i]);
            i++;
        } while (i < 2);
                        
    }

}
