/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package game;

import java.util.*;     // required for ArrayList
import gameobjects.Actor;
import gameobjects.Room;
import globals.Direction;

/**
 *
 * @author huw
 */
public class Game  {
    
    private ArrayList<Room> map; // the map - an ArrayList of Rooms    
    private Actor player;  // the player - provides 'first person perspective'

    // TODO: Add serialization to save/load game
    /**
     * ****** THE MAP ******* 
     *  For reference, here is a simple 'picture' of the
     *  map showing how the rooms are connected:
     *
     * room0 -- room1 
     *   | 
     * room2 -- room3 
     *   |        |
     * room4 -- room5
     *
     ************************
     */
    public Game() {
        this.map = new ArrayList<Room>(); // TODO: Make map a Generic list of Room
        // --- construct a new adventure ---
        // Add Rooms to the map
        //                 Room( name,   description,                                           N,        S,      W,      E )
        map.add(new Room("room0", "You are standing in an open field west of a white house", Direction.NOEXIT, 2, Direction.NOEXIT, 1));
        map.add(new Room("room1", "White House", Direction.NOEXIT, Direction.NOEXIT, 0, Direction.NOEXIT));
        map.add(new Room("room2", "Gold room", 0, 4, Direction.NOEXIT, 3));
        map.add(new Room("room3", "Troll room", Direction.NOEXIT, 5, 2, Direction.NOEXIT));
        map.add(new Room("room4", "Dark cave", 2, Direction.NOEXIT, Direction.NOEXIT, 5));
        map.add(new Room("room5", "Troll room", 3, Direction.NOEXIT, 4, Direction.NOEXIT));
        // create player and place in Room 0 (i.e. the Room at 0 index of map )
        player = new Actor("player", "a loveable game-player", map.get(0)); // ! No need to coerce to (Room)
    }

    // access methods
    // map
    ArrayList getMap() {
        return map;
    }

    void setMap(ArrayList<Room> aMap) { // typed to Room!
        map = aMap;
    }

    // player
    public Actor getPlayer() {
        return player;
    }

    public void setPlayer(Actor aPlayer) {
        player = aPlayer;
    }

    // move a Person (typically the player) to a Room
    private void moveActorTo(Actor p, Room aRoom) {
        p.setRoom(aRoom);
    }

    // move an Actor in direction 'dir'
    private int moveTo(Actor anActor, Direction dir) {
        // return: Constant representing the room number moved to
        // or NOEXIT
        //
        // try to move any Person (typically but not necessarily player)
        // in direction indicated by dir
        Room r = anActor.getRoom();
        int exit;

        switch (dir) {
            case NORTH:
                exit = r.getN();
                break;
            case SOUTH:
                exit = r.getS();
                break;
            case EAST:
                exit = r.getE();
                break;
            case WEST:
                exit = r.getW();
                break;
            default:
                exit = Direction.NOEXIT; // noexit - stay in same room
                break;
        }
        if (exit != Direction.NOEXIT) {
            moveActorTo(anActor, map.get(exit));
        }
        return exit;
    }

    public int movePlayerTo(Direction dir) {
        // return: Constant representing the room number moved to
        // or NOEXIT (see moveTo())
        //    
        
        return moveTo(player, dir);
    }

}
