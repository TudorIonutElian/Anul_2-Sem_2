/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package monsters;

/**
 *
 * @author huw
 */
public class Troll extends Monster{    
    
    @Override
    public String saySomething() {
        return "Ugh, ugh, ugh!\n";
    }
        
    public String saySomething(String thingToSay) {
        return "Ugh, ugh, " + thingToSay +"!\n";
    }
}
