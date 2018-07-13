import java.util.Scanner;
class Ex1
{
  public static void main(String[] args)
  {
      double distanceKm = 0.0;
      double distanceMiles = 0.0;

      Scanner input = new Scanner(System.in);
      System.out.print("Enter distance in kilometers: ");
      distanceKm= input.nextDouble();

      distanceMiles = distanceKm * 0.625;
      System.out.printf("The distance in miles is %.3f\n", distanceMiles);
  }
}
