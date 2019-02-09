/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */

package printtest;

import static java.lang.System.out;

/**
 *
 * @author huw
 */
public class PrintTest {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) { 
        System.out.print("\tHello ");
        System.out.print("world\n");
        System.out.println("Hello\tworld");
        System.out.println("Hello world again");
        System.out.printf("There are %d bottles standing on the %s.\n", 20, "wall" );    
        
    }
    
}
