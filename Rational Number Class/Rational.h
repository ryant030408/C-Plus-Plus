// Rational.h
// Created by Ryan Taylor on 3/27/17.
//

#ifndef PROJECT2_RATIONAL_H
#define PROJECT2_RATIONAL_H

class Rational{
private:
    //Variables
    int numerator, denominator;

    //Checks for proper implementation
    bool checker(int check);

public:
    //Constructors
    Rational();
    Rational(int num, int den);

    //Accessors
    int getDenominator() const;
    int getNumerator() const;

    //Mutators
    void setNumerator(int numerator);
    void setDenominator(int denominator);

    //Overloaded comparison member operators
    bool operator<(const Rational& rat2);
    bool operator<=(const Rational& rat2);
    bool operator>(const Rational& rat2);
    bool operator>=(const Rational& rat2);
    bool operator ==(const Rational& rat2);

    //Overloaded math operators
    const Rational operator +(const Rational& rat2);
    const Rational operator -(const Rational& rat2);
    const Rational operator *(const Rational& rat2);
    const Rational operator /(const Rational& rat2);

    //Overloaded inputstream outputstream oeprators
    friend ostream& operator <<(ostream& outputStream, const Rational& amount);//TODO Fix for negatives
    friend istream& operator >> (istream& inputStream, Rational& amount);//TODO Fix neg

    //Extra memeber function
    void invert();
    void reduce();
    double value();
    int gcd();
};

#endif //PROJECT2_RATIONAL_H
