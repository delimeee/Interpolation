#include "Polynom.cpp"
#include "Grid.cpp"

class PolynomLag : public Polynom {
    public:

    PolynomLag(Grid &grid): Polynom(){

        //Polynom lagPolynom = Polynom(grid.size() - 1);

        Polynom helpPolynom = Polynom();
        double coefficient;

        for(int i = 0; i < grid.size() ; ++i){

            coefficient = 0.0;
            helpPolynom.clear();

            for(int j = 0; j < grid.size(); ++j)
            if(i != j){
                Polynom pol {grid.getArgument(j), 1};
                coefficient *= grid.getArgument(i) - grid.getArgument(j);
                helpPolynom.print();
                helpPolynom.multiply(pol);
            }

            coefficient = grid.getValue(i);
            helpPolynom.multiply(coefficient);
            this->add(helpPolynom);
            
        }
    }
};