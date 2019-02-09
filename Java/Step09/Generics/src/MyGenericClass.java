/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */

/**
 *
 * @author huw
 */
public class MyGenericClass<T> {

    private T someData;

    public MyGenericClass(T aValue) {
        someData = aValue;
    }

    public String describe() {
        return this.getClass() + " <"
                + someData.getClass() + ">  " + someData.toString() + "\n";
    }

    /**
     * @return the someData
     */
    public T getSomeData() {
        return someData;
    }

    /**
     * @param someData the someData to set
     */
    public void setSomeData(T someData) {
        this.someData = someData;
    }
}
