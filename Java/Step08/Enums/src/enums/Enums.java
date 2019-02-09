/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package enums;

/**
 *
 * @author huw
 */
public class Enums {

    public enum Suits {

        HEARTS, DIAMONDS, CLUBS, SPADES
    };

    public enum Months {

        JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
    };

    /**
     * @param args the command line arguments
     */

    public static void showsuit( Suits suit ) {
        if ((suit == Suits.HEARTS) || (suit == Suits.DIAMONDS)) {
            System.out.printf("This card is a %s which is a red suit.\n", suit.toString() );
        }else{
            System.out.printf("This card is a %s which is a black suit.\n", suit.toString() );
        }
    }
    
    public static void showmonth(Months month) {
        String msg = "";
        System.out.print(month.toString() + " -- ");
        switch (month) {
            case DEC:
                msg = "Christmas is coming! ";
            case JAN:
            case FEB:
                msg += "Baby, it's cold outside!";
                break;
            case MAR:
            case APR:
            case MAY:
                msg = "Spring is bursting out!";
                break;
            case JUN:
                msg = "June is my favourite month!";
                break;
            case JUL:
            case AUG:
                msg = "Time to go to the beach";
                break;
            case SEP:
            case OCT:
            case NOV:
                msg = "The leaves are falling";
                break;
            default:
                msg = "I don't know what month this is";
                break;
        }
        System.out.println(msg);
    }

    public static void main(String[] args) {
        Suits card;
        card = Suits.SPADES;
        showmonth(Months.DEC);
        showmonth(Months.JAN);
        showmonth(Months.FEB);
        showmonth(Months.APR);
        showmonth(Months.JUN);
        showmonth(Months.SEP);
        showmonth(Months.OCT);        
        showsuit(Suits.CLUBS);
        showsuit(Suits.DIAMONDS);
        showsuit(Suits.HEARTS);
        showsuit(card);
        
    }

}
