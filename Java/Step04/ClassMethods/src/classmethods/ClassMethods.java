/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */

package classmethods;

/**
 *
 * @author huw
 */
public class ClassMethods {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String s;
        int x;
        int total;        
        s = "200";
        x = 5;  
        total = x * Integer.valueOf(s);
        System.out.println(String.format("%d * %s = %d", x, s, total));    
    }
    
}
