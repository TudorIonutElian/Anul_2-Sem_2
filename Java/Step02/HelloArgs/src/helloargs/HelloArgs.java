/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */

package helloargs;

/**
 *
 * @author huw
 */
public class HelloArgs {

    /* This program displays any 
       arguments that were passed to it */

    public static void main(String[] args) {
        System.out.println("Hello.");
        if (args.length == 0){      // display args, if any were given
            System.out.println("You didn't enter any commandline arguments.");
        }else for (String arg : args) {
            System.out.println(arg);
        }
    }
    
}
