/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package arrays;


/**
 *
 * @author huw
 */
public class Arrays {

    public static void main(String[] args) {
        int intarray[] = {0, 1, 2, 3, 4};
        double doublearray[] = {1.2, 2.3, 3.4, 4.5};
        char chararray[] = {'H', 'e', 'l', 'l', 'o'};
        String[] stringarray = {"I", "wandered", "lonely", "as", "a", "cloud"};
        
        System.out.printf("--- intarray - length = %d ---\n", intarray.length);
        for (int i = 0; i < intarray.length; i++) {
            System.out.printf("%d\n", intarray[i]);
        }
        
        System.out.printf("--- doublearray - length = %d ---\n", doublearray.length);
        for (int i = 0; i < doublearray.length; i++) {
            System.out.printf("%f\n", doublearray[i]);
        }
        
        System.out.printf("--- chararray - length = %d ---\n", chararray.length);
        for (int i = 0; i < chararray.length; i++) {
            System.out.printf("%c\n", chararray[i]);
        }
        
        System.out.printf("--- stringarray - length = %d ---\n", stringarray.length);
        for (int i = 0; i < stringarray.length; i++) {
            System.out.printf("%s\n", stringarray[i]);
        }
    }

}
