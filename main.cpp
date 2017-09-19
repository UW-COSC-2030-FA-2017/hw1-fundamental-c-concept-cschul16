// Chris Schultz
// COSC 2030
// HW 1: C++ Concept (Classes)
// 18 September 2017

#include <iostream>
using namespace std;

class Rectangle{
// making public member functions to change dimensions and do computations
public:
    // constructor to initialize values to 0 if there are no arguments
    // a constructor function is called automatically every time an object is created
    Rectangle(){
        width = 0;
        length = 0;
    }

    // constructor with arguments
    Rectangle (double x, double y){
        width = x;
        length = y;
    }

    // function that sets the values of the height and width
    // limiting dimension setting to just height and width for brevity
    void setDims(double x, double y){
        width = x;
        length = y;
    }

    // function to return the length of the rectangle
    double getLen(){
        return length;
    }

    // function to return the width of the rectangle
    double getWid(){
        return width;
    }
   // function that computes the area of the rectangle
    int area(){
        return (length * width);
    }
// these variables are private so other parts of the program don't inadvertently
//   change the dimensions of the rectangle
private:
    double length, width;
};

// main function of the program, where the fun bits happen
int main()
{
    // creating two rectangles, one with default values and one with arguments
    Rectangle rect1;
    Rectangle rect2 (5.5, 111);
    cout << "Dimensions of Rectangle 1 are " << rect1.getLen() << " by " << rect1.getWid() << endl;
    cout << "Dimensions of Rectangle 2 are " << rect2.getLen() << " by " << rect2.getWid() << endl;

    // changing the dimensions of the first rectangle; the two are separate objects
    // so only rect1's dimensions get changed, even though they use the same class functions
    rect1.setDims(15, 0.5);
    cout << "\nNow dimensions of Rectangle 1 are " << rect1.getLen() << " by " << rect1.getWid() << endl;
    cout << "Dimensions of Rectangle 2 are still " << rect2.getLen() << " by " << rect2.getWid() << endl;

    // testing the area function for both the rectangles
    cout << "\nArea of Rectangle 1 is " << rect1.area() << endl;
    cout << "Area of Rectangle 2 is " << rect2.area() << endl;

    // will arbitrarily change the dimensions of rectangle 2 to display
    rect2.setDims(10000, 7.28375);
    cout << "Rectangle 2 has been changed" << endl;
    cout << "Area of Rectangle 2 is " << rect2.area() << endl;
    cout << "Area of Rectangle 1 is still " << rect1.area();

    // each new object (rect1, rect2) that is created from Rectangle has its own copy of the members
    // this way you can manipulate one object and not have to worry about inadvertently changing another

    return 0;
}
