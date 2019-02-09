/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package arraylists;

import java.util.ArrayList;

/**
 *
 * @author huw
 */
public class ArrayLists {

    public static void main(String[] args) {
        ArrayList aList;
        ArrayList<String> stringList;
        ArrayList<Integer> intList;
        aList = new ArrayList();
        aList.add("hello");
        aList.add(20);
        System.out.println(aList.get(0));
        System.out.println(aList.get(1));

        
        intList = new ArrayList<>();
        intList.add(100);
        intList.add(200);
        // intList.add("hello");
        System.out.println(intList.get(0));
        System.out.println(intList.get(1));
        
        stringList = new ArrayList<>();
        stringList.add("hello");
        // stringList.add(20);
        stringList.add("20");
        System.out.println(stringList.get(0));
        System.out.println(stringList.get(1));
        System.out.println("stringList size = " + stringList.size());
        stringList.remove(0);
        System.out.println("Now stringList size = " + stringList.size());
        System.out.println(stringList.get(stringList.size() - 1));

    }

}
