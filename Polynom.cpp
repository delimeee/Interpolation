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

    Polynom(std::initializer_list<double> list){
        for(auto& item : list) {
            this->polynom.push_back(item);
        }
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
        int thisSize = this->getDegree() + 1;
        int otherSize = polynom.getDegree() + 1;
        for(size_t i = 0; i < newDegree + 1; ++i){
            resultCoefficient = 0.0;
            for(size_t j = 0; j <= i; ++j){
                if(j < thisSize && (i - j) < otherSize){
                    resultCoefficient += this->polynom[j] * polynom.polynom[i - j];
                }
            }
            newPolynom.polynom[i] = resultCoefficient;
        }
        *this = newPolynom;
        this->print();
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

    void clear(){
        for(size_t i = 0; i < this->getDegree() + 1; ++i)
        this->polynom[i] = 0;
    }

    void print(){
        for(size_t i = 0; i < this->getDegree() + 1; ++i){
            cout << this->polynom[i] << " "; 
        }
    }
};