import java.io.FileNotFoundException;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.*;
import java.util.*;
import java.io.*;
import java.lang.*;
/**
 * A sequence of air pollution measurements.
 *
 * <p>Created for COMP1721 Coursework 1.</p>
 *
 * @author Minh Hien Pham
 */
public class PollutionDataset {
    private Measurement mRecords;
    private List<Measurement> dataRecords;
  
    // default constructor
    public PollutionDataset() {
      dataRecords = new ArrayList<Measurement>();
    }

    // read the file and add the records
    public void readCSV(String filename) throws FileNotFoundException {
      dataRecords.clear();

      try {
        Scanner input = new Scanner(new File(filename));
        //skip first line
        input.nextLine();
        input.useDelimiter(",");
        while(input.hasNext()) {
          String csvRecords = input.nextLine();
          Measurement mRecords = new Measurement(csvRecords);
          dataRecords.add(mRecords);
        }
      input.close();
      }
      catch(FileNotFoundException e) {
        throw new FileNotFoundException();
      }
    }

    // add a new measurement to the dataset
    public void add(Measurement m) {
      dataRecords.add(m);
    }

    // return the size of the record list
    public int size() {
      int recordCount = dataRecords.size();

      if (dataRecords.isEmpty()) return 0;
      else return recordCount;
    }

    // return measurement at given index
    public Measurement get(int index) {
      // check for empty list
      if (dataRecords.isEmpty()) throw new DataException("List is empty");
      else {
        try {
          return dataRecords.get(index);
        }
        catch(DataException e) {
          throw new DataException("Invalid index");
        } 
      }
    }

    // return measurement with max NO2 level
    public Measurement maxLevel() {
      // check for empty list
      if (dataRecords.isEmpty()) throw new DataException("List is empty");
      // initalise variables
      int max = 0;
      int records = 0;
      Measurement compareRecords = null;
      Measurement maxRecords = null;
      int i;

      for (i = 0; i < dataRecords.size(); i++) {
        compareRecords = dataRecords.get(i);
        records = compareRecords.getLevel();
        if (records > max){
          max = records;
          maxRecords = compareRecords;
        }
      }
      return maxRecords; 
    }

    // return measurement with min NO2 level
    public Measurement minLevel() {
      // check for empty list
      if (dataRecords.isEmpty()) throw new DataException("List is empty");
      // declare and initalise variables
      int min = 1000;
      Measurement minRecords = null;
      Measurement compareRecords = null;
      int records;
      int i;

      for (i = 0; i < dataRecords.size(); i++) {
        compareRecords = dataRecords.get(i);
        records = compareRecords.getLevel();
        // ignore records with no level data
        if (records != -1) {
          if (records < min) {
            min = records;
            minRecords = compareRecords;
          }
        }
      }
      return minRecords; 
    }

    // return the average NO2 level
    public double meanLevel() {
      // check for empty list
      if (dataRecords.isEmpty()) throw new DataException("List is empty");  
      // declare initalise variables
      Measurement recordFull = null;
      double levelSum = 0.0;
      double levelAverage = 0.0;
      double levelSize = 0.0;
      int i;  

      for (i = 0; i < dataRecords.size(); i++) {
        recordFull = get(i);
        if (recordFull.getLevel() !=-1) {
          levelSum += recordFull.getLevel();
          levelSize++;
        }
      levelAverage = levelSum/levelSize;
      }
      return levelAverage;
    }

    // return the day that the level breaches the EU rules (if it does)
    public LocalDate dayRulesBreached() {
      // check if the list is empty
      if (dataRecords.isEmpty()) throw new DataException("List is empty");
      // declare and initalise variables
      int i;
      Measurement recordFull = null;
      LocalDate breachedDay = null;
      int hourlyLevel = 0;
      int breachedLevel = 0;
      int quarterHour = 0;
      int recordLevel = 0;

      for (i = 0; i < dataRecords.size(); i++) {
        recordFull = dataRecords.get(i);  
        recordLevel = recordFull.getLevel(); 
        quarterHour++;
        // sum up the amount in one hour block 
        if (quarterHour == 4) {
          quarterHour = 0;
          hourlyLevel = 0;
        } 
        // ignore level with no data
        if (recordLevel !=-1) {
          hourlyLevel += recordLevel;
        }
        if (hourlyLevel > 200) {
          breachedLevel++;
        }
        if (breachedLevel > 18) {
          breachedDay = recordFull.getTime().toLocalDate();
          return breachedDay;
        }
      }    
      return breachedDay; 
    }
}