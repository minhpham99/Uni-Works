
class Rectangle
{
    // initialize the variable
    private double width = 1.0;
    private double height = 1.0;
    
    // create a Rectangle object
    Rectangle()
    {
        this(1.0,1.0);
    }
    Rectangle(double w, double h)
    {
        width = w;
        height = h;
        if(width <=0 || height <=0) throw new IllegalArgumentException("Invalid value for dimension!");
    }
    // return different values of the Rectangle
    double getWidth()
    {
        return width;
    }
    double getHeight()
    {
        return height;
    }
    double getArea()
    {
        double area = width*height;
        return area;
    }
    double getPerimeter()
    {
        double perimeter = (width + height) * 2.0;
        return perimeter;
    }
}

public class Ex8
{
    public static void main( String[] args)
    {
        double rectangleWidth = 0.0;
        double rectangleHeight = 0.0;
        double rectangleArea;
        double rectanglePerimeter;
        
        System.out.println("\n" + "Rectangle 1:");
        try {
            Rectangle rectangle1 = new Rectangle(7.0, -8);
            rectangleWidth = rectangle1.getWidth();
            rectangleHeight = rectangle1.getHeight();
            rectangleArea = rectangle1.getArea();
            rectanglePerimeter = rectangle1.getPerimeter();
            System.out.println("The width is " + rectangleWidth);
            System.out.println("The height is " + rectangleHeight);
            System.out.println("The area is " + rectangleArea);
            System.out.println("The perimeter is " + rectanglePerimeter + "\n");
        } catch (IllegalArgumentException e) {
            System.out.println("Invalid value");
        }
    }
}