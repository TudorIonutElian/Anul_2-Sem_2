
import java.util.ArrayList;

/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
/**
 *
 * @author huw
 * @param <E>
 */
public class MyList<E> extends ArrayList<E> {

    public E getLastItem() {
        return this.get(this.size() - 1);
    }
}
