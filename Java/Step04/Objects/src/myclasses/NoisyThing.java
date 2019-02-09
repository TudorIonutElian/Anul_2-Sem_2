/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */

package myclasses;

public class NoisyThing extends Thing {
    private String noise;
    private int volume;
    
    public NoisyThing(String aName, String aDescription, String aNoise, int aVolume) {
        super(aName, aDescription);        
        this.noise = aNoise;
        this.volume = aVolume;
    }

    /**
     * @return the noise
     */
    public String getNoise() {
        return noise;
    }

    /**
     * @param noise the noise to set
     */
    public void setNoise(String noise) {
        this.noise = noise;
    }

    /**
     * @return the volume
     */
    public int getVolume() {
        return volume;
    }

    /**
     * @param volume the volume to set
     */
    public void setVolume(int volume) {
        this.volume = volume;
    }
    
}
