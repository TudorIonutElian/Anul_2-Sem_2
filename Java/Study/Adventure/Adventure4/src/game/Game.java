/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */
package game;

import java.util.*;     // required for ArrayList
import gameobjects.Actor;
import gameobjects.Room;
import gameobjects.Thing;
import gameobjects.ThingHolder;
import gameobjects.ThingList;
import gameobjects.Treasure;
import globals.Direction;

/**
 *
 * @author huw
 */
public class Game implements java.io.Serializable {

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
        // -- add some things to an object
        ThingList rm0list = new ThingList();
        rm0list.add(new Treasure("carrot", "It is a very crunchy carrot", 1));

        ThingList rm1list = new ThingList();
        rm1list.add(new Treasure("sausage", "It is a plump pork sausage", 10));

        ThingList rm2list = new ThingList();
        rm2list.add(new Treasure("paper", "Someone has written a message on the scrap of paper using a blunt pencil. It says 'This space is intentionally left blank'", 1));
        rm2list.add(new Treasure("pencil", "This pencil is so blunt that it can no longer be used to write.", 1));

        ThingList rm3list = new ThingList();
        rm3list.add(new Treasure("ring", "It is a ring of great power.", 500));
        rm3list.add(new Treasure("wombat", "It's a cuddly little wombat. It is squeaking gently to itself.", 700));

        ThingList rm4list = new ThingList();
        rm4list.add(new Treasure("sign", "The sign says: 'Do not feed the wombat!'", 2));

        ThingList rm5list = new ThingList();
        rm5list.add(new Treasure("toad", "It is a slimy toad that keeps saying 'greep-greep! greep-greep!'", 20));
        rm5list.add(new Treasure("sword", "It is a silver Elvish sword (glowing gently)", 400));

        ThingList playerlist = new ThingList();

        // Add Rooms to the map
        //                 Room( name,   description,                                           N,        S,      W,      E,  treasures )
        map.add(new Room("Field", "It is an open field west of a white house", Direction.NOEXIT, 2, Direction.NOEXIT, 1, rm0list));
        map.add(new Room("White house", "It is a small white house next to a field", Direction.NOEXIT, Direction.NOEXIT, 0, Direction.NOEXIT, rm1list));
        map.add(new Room("Gold room", "It is a huge room made of solid gold", 0, 4, Direction.NOEXIT, 3, rm2list));
        map.add(new Room("Troll room", "It is a gloomy room that smells of troll", Direction.NOEXIT, 5, 2, Direction.NOEXIT, rm3list));
        map.add(new Room("Dark cave", "It is a vast underground cavern", 2, Direction.NOEXIT, Direction.NOEXIT, 5, rm4list));
        map.add(new Room("Flowery meadow", "It is a lovely meadow full of flowers - butterflies flit from bloom to bloom", 3, Direction.NOEXIT, 4, Direction.NOEXIT, rm5list));
        // create player and place in Room 0 (i.e. the Room at 0 index of map )
        player = new Actor("player", "You are a loveable game-player", playerlist, map.get(0)); // ! No need to coerce to (Room)
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

    private void transferOb(Thing t, ThingList fromlist, ThingList tolist) {
        fromlist.remove(t);
        tolist.add(t);
    }

    public String takeOb(String obname) {
        String retStr = "";
        Thing t = player.getRoom().getThings().thisOb(obname);
        if (obname.equals("")) {
            obname = "nameless object"; // if no object specified
        }
        if (t == null) {
            retStr = "There is no " + obname + " here!\n";
        } else {
            transferOb(t, player.getRoom().getThings(), player.getThings());
            retStr = obname + " taken!\n";
        }
        return retStr;
    }

    public String dropOb(String obname) {
        String retStr = "";
        Thing t = player.getThings().thisOb(obname);
        if (obname.equals("")) {
            retStr = "You'll have to tell me which object you want to drop!\n"; // if no object specified
        } else if (t == null) {
            retStr = "You haven't got one of those!\n";
        } else {
            transferOb(t, player.getThings(), player.getRoom().getThings());
            retStr = obname + " dropped!\n";
        }
        return retStr;
    }
    
    
}
