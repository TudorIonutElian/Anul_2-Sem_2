/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package gameobjects;

/**
 *
 * @author huw
 */
public class Actor extends Thing {

    private Room room; // the Room where the Person is at present

    public Actor(String aName, String aDescription, Room aRoom) {
        super(aName, aDescription); // init super class
        this.room = aRoom;
    }

    public void setRoom(Room aRoom) {
        this.room = aRoom;
    }

    public Room getRoom() {
        return this.room;
    }
}
