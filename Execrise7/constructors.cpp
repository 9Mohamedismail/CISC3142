#include <iostream>
using namespace std;

class Sample {
    private:
        int x;
        double y;
    public :
        // Write the definition of the constructor 1 so that the private member variables are initialized to 0.
        Sample() { 
            this->x = 0;
            this->y = 0;
        }
        /* Write the definition of the constructor 2 so that the private member variable x 
        is initialized according to the value of the parameter, and the privatemember variable y is initialized to 0.*/
        Sample(int a) { 
            this->x = a;
            this->y = 0;
        } 
        /*Write the definition of the constructors 3 and 4 so that the private member variables are initialized 
        according to the values of the parameters.*/
        Sample(int a, int b) {
            this->x = a;
            this->y = b;
        }     
        Sample(int a, double b){
            this->x = a;
            this->y = b;
        }
};