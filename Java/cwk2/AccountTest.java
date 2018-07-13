import java.util.*;

public class AccountTest {
    public static void main(String[] args) {

        int i, deposit = 0, withdraw = 0;

        // list containing different objects
        List<BankAccount> accounts = new ArrayList<>();
        System.out.println("----------------------------------TEST PROGRAM FOR SAVING AND STUDENT ACCOUNTS------------------------------\n");
        System.out.println("Checking the exception of saving accounts");
        // create saving account objects and add to list
        try {
            // print the details out each time to see which is the invalid account object
            SavingsAccount sav1 = new SavingsAccount(1, "Minh", 8000, 3.5);
            System.out.println(sav1.toString() + "\n");
            accounts.add(sav1);

            SavingsAccount sav2 = new SavingsAccount(2, "Tom", 3500, 4.5);
            System.out.println(sav2.toString() + "\n");
            accounts.add(sav2);

            SavingsAccount sav3 = new SavingsAccount(3, "Alex", 2500, 1.5);
            System.out.println(sav3.toString() + "\n");
            accounts.add(sav3);

            // this object should not be create and add to the list
            SavingsAccount sav4 = new SavingsAccount(4, "Lisa", 11000,2.0);
            System.out.println(sav4.toString() + "\n");
            accounts.add(sav4);
        } catch (IllegalArgumentException f) {
            System.out.println("Account should not exceed 10,000");
        }

        // create student account objects and add to list
        StudentAccount stu1 = new StudentAccount(1, "Adam");
        StudentAccount stu2 = new StudentAccount(2, "Beth", 400);
        StudentAccount stu3 = new StudentAccount(3, "Michael", 50);

        accounts.add(stu1);
        accounts.add(stu2);
        accounts.add(stu3);

        System.out.println("LIST OF ALL BANK ACCOUNTS");
        System.out.println("--------------------------------");
        // print list
        for (i = 0; i < accounts.size(); i++) {
            System.out.println(accounts.get(i).toString());
            System.out.println("***********************");
        }

        // Test deposit methods
        System.out.println("\nDEPOSIT");
        // this amount will cause an error in the first account
        deposit = 3000;
        System.out.println("Deposit amount: " + deposit + "\n");
        for (i = 0; i < accounts.size(); i++) {
            try {
                accounts.get(i).deposit(deposit);
                System.out.println(accounts.get(i).toString());
                System.out.println("***********************");
            } catch (IllegalArgumentException e) {
                System.out.println("Invalid deposit amount");
            }
        }

        // Test withdraw methods
        System.out.println("\nWITHDRAW");
        // this amount will cause an error in the last account
        withdraw = 3300;
        System.out.println("Withdraw amount: " + withdraw + "\n");
        for (i = 0; i < accounts.size(); i++) {
            try {
                accounts.get(i).withdraw(withdraw);
                System.out.println(accounts.get(i).toString());
                System.out.println("***********************");
            } catch (IllegalArgumentException e) {
                System.out.println("Invalid withdraw amount, overdraft should not exceed 250");
            }
        }

        System.out.println("END OF TEST\n\n");

    }
}