//
// Created by Ryan Taylor on 4/4/17.
//

#ifndef PROJECT3_POLYNOMIAL_H
#define PROJECT3_POLYNOMIAL_H


class Polynomial {

private:

    //Variables
    int degreeOfFunction;
    char listOfCoffs[100];

    //Methods
    int findPower();
    double converToDouble(char coeff);


public:

    //Constructor
    Polynomial();
    Polynomial(char numbers[100]);

    //Accessor
    int getPower() const;
    double getCoeff(int degreeOf) const;

    //Mutator
    void setAllCoeff(char input[]);

    //Overloaded math operators
    const Polynomial operator +(const Polynomial& poly2)const;
    const Polynomial operator -(const Polynomial& poly2)const;

    //Overloaded inputstream outputstream oeprators
    friend ostream& operator <<(ostream& outputStream, const Polynomial& mathprint);
    friend istream& operator >> (istream& inputStream, Polynomial& mathprint);

    //Member Functions
    double evaluate(double slvX);
    Polynomial derivative();
    double findRoot(double guess);
    double toDouble(string input, bool neg) const;
    string toString(double value) const;




};


#endif //PROJECT3_POLYNOMIAL_H
