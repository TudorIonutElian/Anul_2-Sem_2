/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package logicaloperators;

/**
 *
 * @author huw
 */
public class LogicalOperators {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int age;
        int number_of_children;
        double salary;

        age = 25;
        number_of_children = 1;
        salary = 20000.00;

        if ((age <= 30) && (salary >= 30000.00)) {
            System.out.print("You are a rich young person\n");
        } else {
            System.out.print("You are not a rich young person\n");
        }

        if ((age <= 30) || (salary >= 30000.00)) {
            System.out.print("You are either rich or young or both\n");
        } else {
            System.out.print("You are not neither rich nor young\n");
        }

        if ((age <= 30) && (salary >= 30000.00) && (number_of_children != 0)) {
            System.out.print("You are a rich young parent\n");
        } else {
            System.out.print("You are not a rich young parent\n");
        }

    }

}
