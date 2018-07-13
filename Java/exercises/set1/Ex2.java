import java.util.Scanner;
class Ex2
{
  public static void main(String[] args)
  {
    int seconds = 0;
    int minutes = 0;
    int hours = 0;

    Scanner input = new Scanner(System.in);
    System.out.print("Enter the number of seconds: ");
    seconds = input.nextInt();

    minutes = seconds/60;
    hours = minutes/60;
    minutes = minutes%60;
    seconds = seconds%60;

    System.out.printf("%d hours, %d minutes and %d seconds\n", hours,minutes,seconds);
  }
}
