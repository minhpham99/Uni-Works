public class BankAccount {
    private int id;
    private int balance;
    private String name;

    //Constructors
    public BankAccount(int id, String name) { this(id, name, 0); }

    public BankAccount(int id, String name, int balance) {
        this.id = id;
        this.name = name;
        this.balance = balance;
    }

    // for setting the balance after calculate interest, deposit/withdraw, etc
    public void setBalance(int newBalance) { balance = newBalance; }

    // methods to access private fields
    public int getId() { return id; }

    public String getName() {
    return name;
  }

    public int getBalance() {
    return balance;
  }

    // deposit method
    public void deposit(int depositAmount) {
        if(depositAmount < 0) {
            throw new IllegalArgumentException("Invalid deposit amount");
        }
        balance = balance + depositAmount;
    }

    // withdraw method
    public void withdraw(int withdrawAmount) {
        if (withdrawAmount < 0 || withdrawAmount > balance) {
            throw new IllegalArgumentException("Invalid withdraw amount");
        }
        balance = balance - withdrawAmount;
    }

    // override toString
    public String toString() {
        String fullAccount;
        fullAccount = id + ", " + name + ", " + balance;
        return fullAccount;
    }
}