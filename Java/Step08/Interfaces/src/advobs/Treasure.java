/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package advobs;

import myinterfaces.ValuableItem;

/**
 *
 * @author huw
 */
public class Treasure extends Thing implements ValuableItem {

    private String description;
    private int treasureValue;

    public Treasure(String aName, String aDescription, int aValue) {
        // constructor
        super(aName);
        this.description = aDescription;
        this.treasureValue = aValue;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String aDescription) {
        this.description = aDescription;
    }

    @Override
    public int value() {
        return treasureValue;
    }

    @Override
    public void addValue(int aValue) {
        treasureValue += aValue;
    }

    @Override
    public void deductValue(int aValue) {
        treasureValue -= aValue;
    }

}
