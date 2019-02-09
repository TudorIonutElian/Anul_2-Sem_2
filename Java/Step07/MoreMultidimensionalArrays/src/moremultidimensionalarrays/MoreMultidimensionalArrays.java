/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package moremultidimensionalarrays;

/**
 *
 * @author huw
 */
public class MoreMultidimensionalArrays {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int[][] intgrid = {
            {1, 2, 3},
            {4, 5, 6, 7},
            {8, 9},
            {10, 11, 12, 13, 14, 15}
        };

        // get length (number of nested arrays) of 'outer' array
        int numrows = intgrid.length;

        System.out.printf("There are %d rows.\n", numrows);
        /*
         * NOTE: I have calculated the length of both the numrows variable
         * and (at each turn though the outer loop) the index variable
         * so that my code can deal with two-dimensional arrays with any
         * number of 'rows' and nested arrays with any number of items.
         */
        for (int row = 0; row < numrows; row++) {
            System.out.printf("--- row %d --- \n", row);
            for (int index = 0; index < intgrid[row].length; index++) {
                System.out.printf("index[%d], value=%d\n", index, intgrid[row][index]);
            }
        }
    }
}
