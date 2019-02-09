/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */

package myclasses;

/**
 *
 * @author huw
 */
public class MyObject {
    private static int obcount = 0;
    private int obnumber;
    
    public MyObject() {
        obcount = obcount + 1;
        obnumber = obcount;
    }
    
    public static String numberOfObjects() {
        return "There are " + obcount + " objects.\n";
    }
    
    public String objectInfo() {
        return "This is object number " + obnumber + " from a total of "+
                + obcount + " objects.\n";
    }
    
    public int getObnumber() {
        return obnumber;
    }
}

