/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package writelist;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author huw
 */
public class WriteList {

    /**
     * This is adapted from code in Oracle's tutorial on
     * Exception-handling here:
     * http://docs.oracle.com/javase/tutorial/essential/exceptions/index.html
     */
    public static void main(String[] args) {
        PrintWriter out = null;
        List<Integer> list;
        final int SIZE = 10;
        list = new ArrayList<Integer>(SIZE);

        String fileName;
        fileName = "OutFile.txt";
        // fileName = "x:\\OutFile.txt";

        for (int i = 0; i < SIZE; i++) {
            list.add(new Integer(i));
        }

        try {
            System.out.println("Entering" + " try statement");
            out = new PrintWriter(new FileWriter(fileName));
            for (int i = 0; i < SIZE; i++) {
                out.println("Value at: " + i + " = " + list.get(i));
            }
        } catch (IndexOutOfBoundsException e) {
            System.err.println("Caught IndexOutOfBoundsException: "
                    + e.getMessage());
        } catch (IOException e) {
            System.err.println("Caught IOException: " + e.getMessage());
        } finally {
            if (out != null) {
                System.out.println("Closing PrintWriter");
                out.close();
            } else {
                System.out.println("PrintWriter not open");
            }
        }
    }

}
