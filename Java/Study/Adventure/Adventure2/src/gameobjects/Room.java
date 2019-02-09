/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package gameobjects;

/**
 *
 * @author huw
 */

// NOTE: I may extend the class hierarchy Thing->ThingHolder->Room
public class Room extends Thing {

    private int n, s, w, e;

    public Room(String aName, String aDescription, int aN, int aS, int aW, int aE) {
        super(aName, aDescription); // init superclass
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
