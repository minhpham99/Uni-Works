import java.sql.Date;
import java.sql.Time;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.io.*;
import java.util.*;
/**
 * A single measurement of NO<sub>2</sub> level.
 *
 * <p>Created for COMP1721 Coursework 1.</p>
 *
 * @author Minh Hien Pham
 */
public class Measurement {
    // Use this when parsing measurement time
    private LocalDateTime Time;
    private int level;
    private static DateTimeFormatter FORMAT = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm");
    
    // parse the measurements
    public Measurement(String record) {
        String[] tempRecord = record.split(",");
        // check for the lenght of the recor
        if(tempRecord.length > 3 || tempRecord.length < 2) throw new DataException("Invalid measurment");
        // check if level is null
        else if (tempRecord.length == 2) level = -1;
        // parse the level
        else level = Integer.parseInt(tempRecord[2]);
        // parse the time
        Time = LocalDateTime.parse(tempRecord[0] + " "+ tempRecord[1], FORMAT);
    }
    
    // return fields
    public LocalDateTime getTime() {
        return Time;
    }
    public int getLevel() {
        return level;
    }
    
    // return string representation of measurement
    public String toString() {
        String fullRecord;
        // check for level and concantenante all the strings
        if (level == -1) fullRecord = Time + ", " + "no data";
        else fullRecord = Time + ", "+ level +" "+ "\u00b5g/"+"m\u00b3";
        
        return fullRecord;
    }
}
