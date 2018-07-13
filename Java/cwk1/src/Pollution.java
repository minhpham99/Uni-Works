import java.util.*;
import java.io.*;
import java.time.*;
import java.lang.*;

/**
 * A program to print resutls required.
 *
 * <p>Created for COMP1721 Coursework 1.</p>
 *
 * @author Minh Hien Pham
 */

public class Pollution {
    public static void main(String[] args) {

        Measurement record, maxRecord, minRecord;
        PollutionDataset dataList = new PollutionDataset();
        double meanRecord = 0.0;
        int recordNumber = 0;
        LocalDate dayBreached = null;
        String dataRecord = null;
        
        // error handling
        if (args.length == 0) {
            System.out.println("No file input!");
            System.exit(0);
        } 

        // read and process data from csv file
        try {
            dataList.readCSV(args[0]);

            // print out necessary results
            recordNumber = dataList.size();
            System.out.println(recordNumber + " " + "records process");

            maxRecord = dataList.maxLevel();
            System.out.println("Max: " + maxRecord);

            minRecord = dataList.minLevel();
            System.out.println("Min: " + minRecord);

            meanRecord = dataList.meanLevel();
            System.out.printf("Average: %.2f \u00b5g/m\u00b3\n",meanRecord);

            // check if the amount of NO2 is breached
            if (dataList.dayRulesBreached() != null)
            {
                dayBreached = dataList.dayRulesBreached();
                System.out.println("The amount of NO\u2082 has breached at " + dayBreached);
            }
            else System.out.println("The amount of NO\u2082 has not breached");
            
        }
        // catch the exception 
        catch (FileNotFoundException e) {
            System.out.println("File not found!");
        }
    }
}