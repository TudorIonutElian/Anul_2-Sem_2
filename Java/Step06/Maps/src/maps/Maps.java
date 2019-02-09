/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package maps;

import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author huw
 */
public class Maps {

    public static void main(String[] args) {
        Map hmap;
        hmap = new HashMap();
        hmap.put("sword", "A glittering Elvish sword");
        hmap.put("ring", "A golden ring of great power");
        hmap.put("wombat", "A small burrowing creature (asleep)");
        hmap.put(10, "A mysterious number");
        hmap.put("five", 5);
        
        System.out.println(hmap.get("ring"));
        System.out.println(hmap.get(10));
        System.out.println(hmap.get("five"));
        
        hmap.remove("ring");
        System.out.println(hmap.get("ring"));
        
        System.out.println(hmap.values());
        System.out.println(hmap.keySet());
        
        for( Object key: hmap.keySet() ){
            System.out.println("Object with key (" + key + ") has the value: " 
                    + hmap.get(key));
        }
    }

}
