import java.io.FileNotFoundException;
import java.time.LocalDate;
import java.time.LocalDateTime;


/**
 * A sequence of air pollution measurements.
 *
 * <p>Created for COMP1721 Coursework 1.</p>
 *
 * @author YOUR NAME HERE
 */
import Measurement;
public class PollutionDataset {
    private Measurement time;
    private Measurement level;
  // TODO: add field

  public PollutionDataset() {
    // TODO: implement default constructor to initialise empty dataset
  }

  public void readCSV(String filename) throws FileNotFoundException {
    // TODO: load measurements from CSV file
  }

  public void add(Measurement m) {
    // TODO: add a new measurement to the dataset
  }

  public int size() {
    return 0;  // TODO: return number of measurements in dataset
  }

  public Measurement get(int index) {
    return null;  // TODO: return measurement at given index
  }

  public Measurement maxLevel() {
    return null;  // TODO: return measurement with max NO2 level
  }
}
public class PollutionDataset {
    // TODO: add field
  
    public PollutionDataset() {
      // TODO: implement default constructor to initialise empty dataset
    }
  
    public void readCSV(String filename) throws FileNotFoundException {
      // TODO: load measurements from CSV file
    }
  
    public void add(Measurement m) {
      // TODO: add a new measurement to the dataset
    }
  
    public int size() {
      return 0;  // TODO: return number of measurements in dataset
    }
  
    public Measurement get(int index) {
      return null;  // TODO: return measurement at given index
    }
  
    public Measurement maxLevel() {
      return null;  // TODO: return measurement with max NO2 level
    }
  }

