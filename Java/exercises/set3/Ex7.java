class BankAccount
{
  private int id;
  private int balance;
  private String name;

  BankAccount(int id, String name)
  {
    this(id, name, 20000);
  }
  BankAccount(int newId, String newName, int newBalance)
  {
    id = newId;
    name = newName;
    balance = newBalance;
  }
  int getId()
  {
    return id;
  }
  String getName()
  {
    return name;
  }
  int getBalance()
  {
    return balance;
  }
  boolean deposit(int amount)
  {
    if(amount > 0)
    {
      balance = balance + amount;
      return true;
    }
    else return false;
  }
  boolean withdraw(int amount)
  {
    if(amount > 0 && amount <= balance)
    {
      balance = balance - amount;
      return true;
    }
    else return false;
  }
}

public class Ex7
{
   public static void main( String[] args)
   {
      int accountId = 0;
      String accountName;
      int accountBalance = 0;
      boolean accountWithdraw;
      boolean accountDeposit;
 
      BankAccount account1 = new BankAccount(1, "Minh");
      accountId = account1.getId();
      accountName = account1.getName();
      accountBalance = account1.getBalance();
      accountWithdraw = account1.withdraw(2500);
      accountDeposit = account1.deposit(4000);
      // re assign the accountBalance variable
      accountBalance = account1.getBalance();

      System.out.println("\nID:" + accountId);
      System.out.println("Name: " + accountName);
      System.out.println("Balance: £" + accountBalance + "\n");
   } 
}
