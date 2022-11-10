#include <iostream>
using namespace std;

class Rectangle {
    private:
    float length;
    float width;
    float areaRec;
    float perimeterRec;
    
    public:

    void setlength(float l) {
        this->length = l;
    }

    void setwidth(float w) {
        this->width = w;
    }

    float perimeter() {
        cout << "Perimeter: " << 2 * (this->length + this->width)<< endl;
        return perimeterRec;
    }

    float area() {
        this->areaRec = this->width * this->length;
        cout << "Area: " << this->areaRec << endl;
        return areaRec;
    }

    void show() {
        cout << "Length: " << this->length << endl;
        cout << "Width: " << this->width << endl;
    }

    int sameArea(Rectangle rec) {
        // sameArea returns 1 if the two Rectangles have the same area, and returns 0 if they don't.
        if (this->areaRec == rec.area()) {
             cout << "The Rectangles do have the same area. (The result is: ";
            return 1;
        } else {
            cout << "The Rectangles do not have the same area. (The result is: ";
            return 0;
        }
    }

};

int main () {

    // Write main function to create two rectangle objects. 
    Rectangle recOne;
    Rectangle recTwo;

    // Set the length and width of the first rectangle to 5 and 2.5. 
    recOne.setlength(5);
    recOne.setwidth(2.5);

    // Set the length and width of the second rectangle to 5 and 18.9.
    recTwo.setlength(5);
    recTwo.setwidth(18.9);

    // Display each rectangle and its area and perimeter.
    cout << "First Rectangle: "  << endl;
    recOne.show();
    recOne.perimeter();
    recOne.area();

    cout << "\nSecond Rectangle: "  << endl;
    recTwo.show();
    recTwo.perimeter();
    recTwo.area();

    // Check whether the two Rectangles have the same area and print a message in dicating the result.
    cout << recOne.sameArea(recTwo) << ")" << endl;

    // Set the length and width of the first rectangle to 15 and 6.3.
    recOne.setlength(15);
    recOne.setwidth(6.3);

    // Display each Rectangle and its area and perimeter again.
    cout << "\nFirst Rectangle: "  << endl;
    recOne.show();
    recOne.perimeter();
    recOne.area();

    cout << "\nSecond Rectangle: "  << endl;
    recTwo.show();
    recTwo.perimeter();
    recTwo.area();

    //Again, check whether the two Rectangles have the same area and print a message indicating the result.
    cout << recOne.sameArea(recTwo) << ")";
}