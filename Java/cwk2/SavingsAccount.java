public class SavingsAccount extends BankAccount {
    private double interestRate;

    // constructor with reference to the BankAccount class
    public SavingsAccount(int id, String name, int balance, double interestRate) {
        super(id, name, 0);
        setInterestRate(interestRate);
        this.deposit(balance);
    }

    // getters and setters of interest rate
    public void setInterestRate(double accountInterest) {
        if (accountInterest <= 0) {
            throw new IllegalArgumentException("Invalid interest rate");
        }

        interestRate = accountInterest;
    }
    
    public double getInterest() {
        return interestRate;
    }

    // calculate and applied the interest to the balance
    public void setAccountInterest() {
        // get the current balance and interest rate
        int currentBalance = getBalance();
        double interestPercent = getInterest();

        // initialise and calculate the balance
        int interestAmount = 0;
        interestAmount = (int)(currentBalance * interestPercent)/100;

        // add interest to the balance
        currentBalance += interestAmount;

        // reset the balance to the new amount
        setBalance(currentBalance);
    }

    // override toString and deposit method
    @Override

    // override to identify a saving account
    public String toString() {
        String fullAccount;

        int id = getId();
        String name = getName();
        int balance = getBalance();

        fullAccount = "Saving account no. " + id + "\nName: " + name + "\nBalance: " + balance + "\nInterest rate: " + interestRate;

        return fullAccount;
    }

    // deposit for saving account
    public void deposit(int depositAmount) {
        int currentBalance = getBalance();

        if(depositAmount < 0) {
            throw new IllegalArgumentException("Invalid deposit amount");
        }

        currentBalance = currentBalance + depositAmount;

        if (currentBalance >= 10000) {
            throw new IllegalArgumentException("Amount allowed in account is exceeded");
        }
        // reset the balance to the new amount if <= 10,000
        setBalance(currentBalance);
    }      
}