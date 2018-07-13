class Rectangle
{
    // initialize the variable
    double width = 1.0;
    double height = 1.0;
    
    // create a Rectangle object
    Rectangle()
    {
        this(1.0,1.0);
    }

    Rectangle(double w, double h)
    {
        width = w;
        height = h;
    }

    double setWidth(double newWidth)
    {
        width = newWidth;
        return width;
    }
    double setHeight(double newHeight)
    {
        height = newHeight;
        return height;
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

public class Ex6
{
    public static void main( String[] args)
    {
        double rectangleWidth;
        double rectangleHeight;
        double rectangleArea;
        double rectanglePerimeter;
        
        System.out.println("\n" + "Rectangle 1:");
        Rectangle rectangle1 = new Rectangle();
        rectangleWidth = rectangle1.getWidth();
        rectangleHeight = rectangle1.getHeight();
        rectangleArea = rectangle1.getArea();
        rectanglePerimeter = rectangle1.getPerimeter();
        System.out.println("The width is " + rectangleWidth);
        System.out.println("The height is " + rectangleHeight);
        System.out.println("The area is " + rectangleArea);
        System.out.println("The perimeter is " + rectanglePerimeter + "\n");


        System.out.println("Rectangle 2:");
        Rectangle rectangle2 = new Rectangle(3.5, 12);
        rectangleWidth = rectangle2.getWidth();
        rectangleHeight = rectangle2.getHeight();
        rectangleArea = rectangle2.getArea();
        rectanglePerimeter = rectangle2.getPerimeter();
        System.out.println("The width is " + rectangleWidth);
        System.out.println("The height is " + rectangleHeight);
        System.out.println("The area is " + rectangleArea);
        System.out.println("The perimeter is " + rectanglePerimeter + "\n");
    }
}