// Rational.cpp
// Created by Ryan Taylor on 3/27/17.
//
#include<iostream> // for cout
using namespace std;

#include "Rational.h"

//Constructors

/**
 * Creates default rational number with 0 numerator and 1 denominator
 */
Rational::Rational(): denominator(1), numerator(0){}
/**
 * Creates a rational number with user inputted values
 * @precondition Denominator cannot be zero
 * @param num Numerator
 * @param den Denominator
 */
Rational::Rational(int num, int den){
    checker(den);
    denominator = den;
    numerator = num;
}

//Accessors

/**
 * Get numerator of Rational called from
 * @return Numerator int
 */
int Rational::getNumerator() const {return numerator;}
/**
 * Gets denominator of Rational called from
 * @return Denominator int
 */
int Rational::getDenominator() const {return denominator;}

//Mutators

/**
 * Sets numerator of Rational called from
 * @param numerator Int that is set to this Rationals numerator
 */
void Rational::setNumerator(int numerator) { Rational::numerator = numerator;}
/**
 * Sets denominator of Rational being called from
 * @precondition Denominator cannot be zero
 * @param denominator Int that is set to this Rationals denominator
 */
void Rational::setDenominator(int denominator) {
    if(checker(denominator)){
        Rational::denominator = denominator;
    }
}

//Overridden comparison oeprators

/**
 * Overrides < operator for Rational
 * @param rat2 Second Rational to test against
 * @return A true or false value based on equality
 */
bool Rational:: operator <(const Rational& rat2){
    Rational temp = rat2;
    return (value()<temp.value());
}
/**
 * Overrides <= operator for Rational
 * @param rat2 Second Rational to test against
 * @return A true or false value based on equality
 */
bool Rational:: operator <=(const Rational& rat2){
    Rational temp = rat2;
    return((value()<temp.value()) || (value()==temp.value()));
}
/**
 * Overrides > operator for Rational
 * @param rat2 Second Rational to test against
 * @return A true or false value based on equality
 */
bool Rational:: operator >(const Rational& rat2){
    Rational temp = rat2;
    return (value() > temp.value());
}
/**
 * Overrides >= operator for Rational
 * @param rat2 Second Rational to test against
 * @return A true or false value based on equality
 */
bool Rational:: operator >=(const Rational& rat2){
    Rational temp = rat2;
    return((value()>temp.value()) || (value()==temp.value()));
}
/**
 * Overrides == operator for Rational
 * @param rat2 Second Rational to test against
 * @return A true or false value based on equality
 */
bool Rational:: operator ==(const Rational& rat2){
    Rational temp = rat2;
    return(value()==temp.value());
}

//Overridden math operators

/**
 * Overrides + operator for Rational
 * @param rat2 Second Rational to add to
 * @return A Rational object with a new value
 */
const Rational Rational::operator +(const Rational& rat2) {
    Rational temp((numerator*rat2.denominator)+(rat2.numerator*denominator), denominator*rat2.denominator);
    temp.reduce();
    return temp;
}
/**
 * Overrides - operator for Rational
 * @param rat2 Second Rational to subtract with
 * @return A Rational object with a new value
 */
const Rational Rational::operator -(const Rational& rat2) {
    Rational temp;
    int num = ((numerator*rat2.denominator)-(rat2.numerator*denominator));
    int den = denominator*rat2.denominator;
    if(checker(den)){
        temp.setNumerator(num);
        temp.setDenominator(den);
    }
    temp.reduce();
    return temp;
}
/**
 * Overrides * operator for Rational
 * @param rat2 Second Rational to multiply
 * @return A Rational object with a new value
 */
const Rational Rational::operator *(const Rational& rat2) {
    Rational temp(numerator*rat2.numerator, denominator*rat2.denominator);
    return temp;
}
/**
 * Overrides / operator for Rational
 * @param rat2 Second Rational to divide by
 * @return A Rational object with a new value
 */
const Rational Rational::operator /(const Rational& rat2) {
    Rational temp(rat2.numerator, rat2.denominator);
    temp.invert();
    temp.setNumerator(numerator*temp.numerator);
    temp.setDenominator(denominator*temp.denominator);
    return temp;
}

//Memeber Functions

/**
 * Inverts numerator and denominator of Rational called by
 * @precondition Denominator cannot be zero after invert
 */
void Rational::invert(){
    int temp;
    if(checker(numerator)){
        temp = denominator;
        Rational::denominator = numerator;
        Rational::numerator = temp;
    }
}
/**
 * Returns value of greatest common divisor of a Rational object
 * @return The greatest common divisor
 */
int Rational::gcd() {
    int larger, smaller, temp;

    if(denominator>numerator){
        larger = denominator;
        smaller = numerator;
    } else{
        larger = numerator;
        smaller = denominator;
    };
    while (smaller != 0) {
        temp = larger;
        larger = smaller;
        smaller = temp % smaller;
    }
    return larger;
}
/**
 * Reduces a Rational object to lowest terms
 */
void Rational::reduce() {
    int temp = gcd();
    numerator = numerator/abs(temp);
    denominator = denominator/abs(temp);
}
/**
 * Gets value of Rational in double form
 * @return double representing denominator divided by numerator
 */
double Rational::value() {
    return((double)numerator/(double)denominator);
}
/**
 * Checks to see if variable passed is equal to zero for denominator
 * @param check The int to check if equal to zero
 * @return If check doesnt equal zero a true value is returned
 * @exception inavlid_argument thrown if passed variable is equal to zero
 */
bool Rational::checker(int check){
    if(check == 0){
        throw invalid_argument("Denominator cannot be zero");
    }
    return true;
}

//Input Output stream overrides

/**
 * Overrides << operator for cout to print a readable version of a Rational object
 * @param outputStream Current outputStream being used
 * @param ratIn Rational object being converted and printed to console
 * @return Sends reaadable version of Rational object to output stream
 */
ostream &operator<<(ostream &outputStream, const Rational& ratIn) {
    int num = ratIn.numerator;
    int den = ratIn.denominator;

    if(num > den){
        outputStream << num/den << ' ';
        if(num%den == 0){
            return outputStream;
        }else{
            num = num%den;
        }
    }
    outputStream << num << '/' << den;


    return outputStream;
}
/**
 * Creates a new Rational object using inputStream with Rational formatting
 * @param inputStream Current inputStream
 * @param ratIn Rational object being influenced
 * @return Adds values taken in to passed Rational
 */
istream &operator>>(istream &inputStream, Rational& ratIn) {

    int num;
    char op;
    int den;
    inputStream >> num;
    inputStream >> op;
    inputStream >> den;

    if(den != 0){
        ratIn.setNumerator(num);
        ratIn.setDenominator(den);
    }else{
        throw invalid_argument("Denominator cannot be zero");
    }

    return inputStream;
}
