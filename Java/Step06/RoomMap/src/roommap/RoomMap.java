/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package roommap;

import java.util.HashMap;

/**
 *
 * @author huw
 */
public class RoomMap {

    public static void main(String[] args) {
        HashMap <String, Room>map;
        map = new HashMap<>();
        
        String aKey;
        Room aValue;
                
        // --- construct a new adventure ---
        // Add Rooms to the map        
          // map.put(0, new Room( -1, 2, -1, 1));   // won't work: integer key
          // map.put("Cave", "A dark cavern");      // won't work: string value
        map.put("Dark Cave", new Room( -1, 2, -1, 1));
        map.put("Troll Room", new Room(-1, -1, 0, -1));
        map.put("Dragon's Lair", new Room(0, 4, -1, 3));
        map.put("Twisty Maze", new Room(-1, 5, 2, -1));
        map.put("White House", new Room(2, -1, -1, 5));
        map.put("Narrow Passage", new Room(3, -1, 4, -1));
        
        aKey = "Troll Room";
        aValue = map.get(aKey);
        
        System.out.println( "First let's get a specific Room... ");
        System.out.println(String.format(
                    "%s\thas exits: \tN = %d \tS = %d \tW = %d \tE = %d\n", 
                    aKey, aValue.n, aValue.s, aValue.w, aValue.e )); 
        
        System.out.println( "Now let's look at all Rooms in the map... ");
        for( String key: map.keySet()){
            Room r;
            r = map.get(key);
            System.out.println(String.format(
                    "%s\thas exits: \tN = %d \tS = %d \tW = %d \tE = %d", 
                    key, r.n, r.s, r.w, r.e )); 
        }
    }

  
    public static class Room {

        private int n, s, w, e;       

        public Room(int aN, int aS, int aW, int aE) {            
            this.n = aN;
            this.s = aS;
            this.w = aW;
            this.e = aE;
        }

    // --- accessor methods ---
        // n
        public int getN() {
            return n;
        }

        public void setN(int aN) {
            this.n = aN;
        }

        // s
        public int getS() {
            return s;
        }

        public void setS(int aS) {
            this.s = aS;
        }

        // e
        public int getE() {
            return e;
        }

        public void setE(int aE) {
            this.e = aE;
        }

        // w
        public int getW() {
            return w;
        }

        void setW(int aW) {
            this.w = aW;
        }
       
    }
}
