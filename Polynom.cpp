#include<vector>
#include<iostream>

using namespace::std;

class Polynom {
    private:
     
     vector<double> polynom;
    
    public:

    Polynom(){
        polynom.push_back(0);
     }

    Polynom(int degree){
        polynom.reserve(degree + 1);
        for(size_t i = 0; i < polynom.capacity(); ++i)
        polynom.push_back(0);
    }

    Polynom(vector<double> vector){
        this->polynom = vector;
    }

    ~Polynom(){
        delete &(this->polynom);
        delete this;
    }

     int getDegree(){
        return this->polynom.size() - 1;
    }

    double calculateValue(double x){
        double value = 0;
        for(size_t i = 1; i < this->getDegree() + 1; ++i){
            value += polynom[i] * (x, i);
        }
        return value;
    }

    void multiply(Polynom &polynom){
        int newDegree = this->getDegree() + polynom.getDegree();
        Polynom newPolynom = Polynom(newDegree);

        double resultCoefficient;
        for(size_t i = 0; i < newDegree + 1; ++i){
            resultCoefficient = 0.0;
            for(size_t j = 0; j <= i; ++j){
                if(j < this->getDegree() + 1 && (i - j) < polynom.getDegree() + 1){
                    resultCoefficient += this->polynom[j] * polynom.polynom[i - j];
                }
            }
            newPolynom.polynom[i] = resultCoefficient;
        }
        *this = newPolynom;
    }

    void multiply(double k){
        for(int i = 0; i < this->getDegree() + 1; ++i)
        this->polynom[i] *= k;
    }
    
    void add(Polynom &other){
        int maxSize = 0;
        if(this->getDegree() >= other.getDegree()){ 
            for(size_t i = 0; i < other.getDegree() + 1; ++i)
            this->polynom[i] += other.polynom[i];
        }
        else {   
            this->polynom.reserve(other.getDegree() + 1);
            for(size_t i = 0; i < this->getDegree() + 1; ++i)
            this->polynom[i] += other.polynom[i];
            for(size_t i = this->getDegree() + 1; i < other.getDegree() + 1; ++i)
            this->polynom.push_back(other.polynom[i]);
        }
    }

    void print(){
        for(size_t i = 0; i < this->getDegree() + 1; ++i){
            cout << this->polynom[i] << " "; 
        }
    }
};