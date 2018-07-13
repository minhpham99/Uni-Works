import java.util.Scanner;
class Ex3
{
    public static void main(String[] args)
    {
      double x1 = 0;
      double x2 = 0;
      double y1 = 0;
      double y2 = 0;
      double distanceX = 0;
      double distanceY = 0;
      double distance = 0;

      Scanner input = new Scanner(System.in);

      System.out.print("Enter x1 and y1: ");
      x1 = input.nextDouble();
      y1 = input.nextDouble();

      System.out.print("Enter x2 and y2: ");
      x2 = input.nextDouble();
      y2 = input.nextDouble();

      distanceX = Math.pow((x2 - x1),2);
      distanceY = Math.pow((y2 - y1), 2);

      distance = Math.sqrt((distanceX + distanceY));
      System.out.printf("The distance between two coordinates is %.3f", distance);
    }
}
