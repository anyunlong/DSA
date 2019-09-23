public class Rectangle {
    /*
     * Define two public attributes width and height of type int.
     */
    // write your code here
    
    /*
     * Define a constructor which expects two parameters width and height here.
     */
    // write your code here
    
    /*
     * Define a public method `getArea` which can calculate the area of the
     * rectangle and return.
     */
    // write your code here
    
    public double width;
    public double height;
    
    Rectangle(double width, double height) {
        if (width<0) {
            width = 0;
        }
        if (height<0) {
            height = 0;
        }
        this.width = width;
        this.height = height;
    }
    
    int getArea() {
        return (int)(this.width * this.height);
    }
}

