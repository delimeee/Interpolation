#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

class Grid {
    private:

     vector<double> arguments;

     vector<double> values;

    public:
     
     Grid(int N){
        if(N > 0){
            arguments.reserve(N);
            values.reserve(N);
            for(int i = 0; i < arguments.capacity(); ++i){
                arguments.push_back(i*(6.0/(N - 1)));
                values.push_back(exp(sin(arguments.back())));
            }
        }
        else throw "Argument must be greatger than 0";
     }

     void print(){
        cout << "x values: ";
        for(int i = 0; i < this->arguments.size(); ++i)
            cout << this->arguments[i] << " ";

        cout << "\n" << "y values: ";
        for(int i = 0; i < this->values.size(); ++i)
            cout << this->values[i] << " ";
    }

    int size(){
        return this->arguments.size();
    }

    double getArgument(int i){
        if(i >= 0 && i < this->arguments.size()) return this->arguments[i];
        else throw "Out of bounds";
    }

    double getValue(int i){
        if(i >= 0 && i < this->values.size()) return this->values[i];
        else throw "Out of bounds";
    }

};