public class StudentAccount extends BankAccount {
    private int overdraftAmount;

    // constructor that initialise the balance to 0;
    public StudentAccount(int id, String name) {
        super(id, name);
        this.deposit(0);
    }

    // constructor with reference to the BankAccount class, initialise overdraft to 0
    public StudentAccount(int id, String name, int balance) {
        super(id, name);
        this.deposit(balance);
        overdraftAmount = 0;
    }

    // set overdraft amount
    public void setOverdraft(int amount) {
        if(amount < 0 || amount > 250) {
            throw new IllegalArgumentException("Invalid overdraft amount");
        }
        overdraftAmount = amount;
    }

    // accessing private fields
    public int getOverdraft() { return overdraftAmount; }

    // Override the toString and withdraw methods

    @Override
    // withdraw method for student account
    public void withdraw(int withdrawAmount) {
        int currentBalance = getBalance();
        // initialised variable for overdraft
        int loanAmount = 0;

        if (withdrawAmount < 0) {
            throw new IllegalArgumentException("Invalid amount");
        }
        currentBalance = currentBalance - withdrawAmount;
        // reset the balance after withdraw
        setBalance(currentBalance);

        // calculate overdraft if necessary
        if (currentBalance < 0) {
            loanAmount = Math.abs(currentBalance);
            if (Math.abs(currentBalance) > 250) {
                throw new IllegalArgumentException("Overdraft amount exceed limit");
            }
        }
        // set the overdraft amount
        setOverdraft(loanAmount);
    }

    // override to identify a student account
    public String toString() {
        String fullAccount;

        int id = getId();
        String name = getName();
        int balance = getBalance();

        fullAccount = "Student account no. " + id + "\nName: " + name + "\nBalance: " + balance + "\nOverdraft:" + overdraftAmount;
 
        return fullAccount;
    }
}