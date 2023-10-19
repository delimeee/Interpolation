#include "PolynomLag.cpp"
#define PI 3.141592653589793238462643383

int main(){
    Polynom p1 {1, 2, 3};
    Polynom p2 {2, 4, 5};
    p1.multiply(p2);
    p1.print();
}
