import java.util.*;
import java.io.*;
import java.lang.*;

class BankAccount {
    private int id;
    private int balance;
    private String name;
    private List<BankAccount> accounts;

    BankAccount(int newId, String newName, int newBalance) {
        id = newId;
        name = newName;
        balance = newBalance;
    }

    int getId() {
    return id;
  }

    String getName() {
    return name;
  }

    int getBalance() {
    return balance;
  }

    // method to add to the list
    public void add(BankAccount b) { accounts.add(b); }

    boolean deposit(int amount) {
        if(amount > 0)
        {
            balance = balance + amount;
            return true;
        }
        else return false;
    }

    boolean withdraw(int amount) {
        if(amount > 0 && amount <= balance)
        {
            balance = balance - amount;
            return true;
        }
        else return false;
    }

    // override the toString method
    public String toString() {
        String fullAccount;
        fullAccount = id + "," + name + "," +balance;
        return fullAccount;
    }
}

public class Ex9 {
   public static void main( String[] args) {
       int i = 0, accountId = 0, accountBalance = 0;
       String accountName = null;
       ArrayList<BankAccount> accountList = new ArrayList<>();

       // clears the list
       accountList.clear();

       try {
           // read file
           Scanner input = new Scanner(new File("accountList.txt"));
           while(input.hasNext()) {
               String fileContents = input.nextLine();
               String[] tempAccount = fileContents.split(",");

               // parse the splitted string into different variables
               // error handlings
               try {
                   accountId = Integer.parseInt(tempAccount[0]);
                   accountName = tempAccount[1];
                   accountBalance = Integer.parseInt(tempAccount[2]);
                   // make new object out of each line and add to the list
                   BankAccount acc1 = new BankAccount(accountId, accountName, accountBalance);
                   accountList.add(acc1);
               } catch (ArrayIndexOutOfBoundsException e) {
                   System.out.println("Not enough arguments");
               }


               // print the list
               for (; i < accountList.size(); i++) {
                   System.out.println(accountList.get(i).toString());
               }
            }
            input.close();
        } catch(FileNotFoundException e) {
           // if file is not found, e.g wrong name
           System.out.println("File does not exist\n");
       }
   } 
}
