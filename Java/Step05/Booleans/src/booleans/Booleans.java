/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */

package booleans;

/**
 *
 * @author huw
 */
public class Booleans {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       boolean happy;
       boolean rich;
       double income;
       boolean wonTheLottery;
       
       happy = true;
       rich = false;
       income = 25000;
       wonTheLottery = true;
       
       if (!rich) {
           System.out.print("Test 1: You are not rich so you can't be happy!\n");
       }
       
       if ((income > 100000 ) || (wonTheLottery)) {
           System.out.print("Test 2: You are rich so you must be happy!\n");
       }
    
       if ((((income > 100000 ) || (wonTheLottery)) && happy) || (rich && happy)){
           System.out.print("Test 3: You are rich and happy!\n");
       }
    }
       
}
