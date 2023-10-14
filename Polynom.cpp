#include "Grid.cpp"

class Polynom {
    public:
     
     vector<double> polynom;
    
    private:

    Polynom(){
        polynom.push_back(0);
     }

    Polynom(int degree){
        polynom.reserve(degree + 1);
        for(size_t i = 0; i < polynom.capacity(); ++i)
        polynom.push_back(0);
    }

    double calculateValue(double x){
        double value = 0;
        for(int i = 1; i < this->polynom.size(); ++i){
            value += polynom[i] * (x, i);
        }
        return value;
    }
};