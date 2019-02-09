/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package labelbreak;

import java.util.Arrays;

/**
 *
 * @author huw
 */
public class LabelBreak {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int[][] grid = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20}
        };
       

        outerloop:
        for (int row = 0; row < 4; row++) {            
            System.out.printf("--- row %d : %s --- \n",
                    row, Arrays.toString(grid[row]));
            innerloop:
            for (int column = 0; column < 5; column++) {
                System.out.printf("column[%d] = %d\n", column, grid[row][column]);
                if (column == 2) {
                    break outerloop;  // try changing to innerloop
                }
            }
        }
    }

}
