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
        String[] somewords = {"one", "two", "three"};
        
        System.out.println("--- for i = 0 to 9 --- ");
        for (int i = 0; i < 10; i++) {
            System.out.println(i);
        }
        
        System.out.println("--- for i = 20 to 11 --- ");
        for (int i = 20; i != 10; i--) {
            System.out.println(i);
        }
        
        System.out.println("--- for i = 0 to somewords.length-1 --- ");
        for (int i = 0; i < somewords.length; i++) {
            System.out.println(i + " : " + somewords[i]);
        }
        
        System.out.println("--- for each word in somewords --- ");
        for (String word:somewords){
            System.out.println(word);
        }
    }

}
