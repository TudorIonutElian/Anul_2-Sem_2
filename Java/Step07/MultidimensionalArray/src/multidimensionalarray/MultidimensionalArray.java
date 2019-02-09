/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package multidimensionalarray;

import java.util.Arrays;

/**
 *
 * @author huw
 */
public class MultidimensionalArray {

    /**
     * @param args the command line arguments
     */
    @SuppressWarnings("empty-statement")
    public static void main(String[] args) {

        int[][] grid = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20}
        };

        System.out.printf("%d\n", grid[1][2]);

        for (int row = 0; row < 4; row++) {
            System.out.printf("row %d : %s\n", row, Arrays.toString(grid[row]));
        }

        for (int row = 0; row < 4; row++) {
            System.out.printf("--- row %d : %s --- \n",
                    row, Arrays.toString(grid[row]));
            for (int column = 0; column < 5; column++) {
                System.out.printf("column[%d] = %d\n", column, grid[row][column]);
               /* // uncomment the code below to see how to break out of the inner 'for' loop
                 // If I were to put a break here it would break out of the INNER 'for'
                 // loop only
                 if (column == 2) {
                 break;
                 }
                 // */
            }
        }

    }

}
