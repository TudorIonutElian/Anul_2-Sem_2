/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package globals;

/**
 *
 * @author huw
 */

public enum Direction {
    NORTH, 
    SOUTH, 
    EAST, 
    WEST;
    /*
        NOEXIT has an integer value which is convenient when initializing the
        'Exit' fields in Room objects. All valid exists indicate a Room number
        whereas NOEXIT is -1.
    */
    public static final int NOEXIT = -1;
};