/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package gameobjects;

/**
 *
 * @author huw
 */
public class Treasure extends Thing {
    /*
    This is a very simple example of a subclass of the Thing class.
    Treasure adds on an int value and a get accessor but not a set
    accessor since the value of each Treasure never varies - it is
    set just once when the object is constructed.
    */

    private int value;

    public Treasure(String aName, String aDescription, int aValue) {
        super(aName, aDescription); // init superclass
        this.value = aValue;
    }

    /**
     * @return the value
     */
    public int getValue() {
        return value;
    }

}
