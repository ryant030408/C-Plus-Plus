//
// Created by Ryan Taylor on 4/4/17.
//


#include<iostream> // for cout
#include <cstring>
#include <cctype>
#include <cmath>
#include <sstream>

using namespace std;

#include "Polynomial.h"

Polynomial::Polynomial() {
    listOfCoffs;
    degreeOfFunction = 0;

}

Polynomial::Polynomial(char numbers[100]) {
    strcpy(listOfCoffs, numbers);
    degreeOfFunction = findPower();
}

int Polynomial::getPower() const {
    return degreeOfFunction;
}

double Polynomial::getCoeff(int degreeOf) const {
//    string temp ="";

    double answer = 0;
    char basic;

    int spaceCounter = 0;
    int counter = 0, tempCounter = 0;

    bool neg = false;
    int start = -1;
    int length = 0;

    char temp[100];

    while(spaceCounter<degreeOf){
        if(isspace(listOfCoffs[counter])){
            spaceCounter++;
        }
        counter++;
    }
    while(!(isspace(listOfCoffs[counter])) && listOfCoffs[counter]!='\0') {
        if (listOfCoffs[counter] == '-') {
            neg = true;
            counter++;
        }else{
            temp[tempCounter] = listOfCoffs[counter];
            tempCounter++;
            counter++;
        }
    }
    temp[tempCounter] = '\0';
    string temp2 = temp;
    answer = toDouble(temp2, neg);

    return answer;
}

void Polynomial::setAllCoeff(char input[100]) {
    strcpy(listOfCoffs, input);
    degreeOfFunction = findPower();
}

const Polynomial Polynomial::operator+(const Polynomial &poly2) const {

    char addition[100];
    string str;
    int counter = 0;
    double one(0), two(0), temp(0);
    int largest;
    if(getPower()>poly2.getPower()){
        largest = getPower();
    }else{
        largest = poly2.getPower();
    }
    for(int i = 0; i <= largest; i++){
        if(getCoeff(counter)!='\0'){
            one = getCoeff(counter);
        }else{
            one = 0;
        }
        if(poly2.getCoeff(counter)!='\0'){
            two = poly2.getCoeff(counter);
        }else{
            two = 0;
        }
        temp = one+two;
        str.append(toString(temp));

        if(counter != largest){
            str.append(" ");
        }
        counter++;
    }
    strcpy(addition, str.c_str());

    return Polynomial(addition);
}

const Polynomial Polynomial::operator-(const Polynomial &poly2) const {
    char subtraction[100];
    string str;
    int counter = 0;
    double one(0), two(0), temp(0);
    int largest;
    if(getPower()>poly2.getPower()){
        largest = getPower();
    }else{
        largest = poly2.getPower();
    }
    for(int i = 0; i <= largest; i++){
        if(getCoeff(counter)!='\0'){
            one = getCoeff(counter);
        }else{
            one = 0;
        }
        if(poly2.getCoeff(counter)!='\0'){
            two = poly2.getCoeff(counter);
        }else{
            two = 0;
        }
        temp = one-two;
        str.append(toString(temp));

        if(counter != largest){
            str.append(" ");
        }
        counter++;
    }
    strcpy(subtraction, str.c_str());

    return Polynomial(subtraction);
}

ostream &operator<<(ostream &outputStream, const Polynomial &mathprint) {
    bool cont = true;
    double coeff;
    int counter(0), end(mathprint.getPower());

    while(cont){
        coeff = mathprint.getCoeff(counter);
        if(counter == 0){
            outputStream<<coeff;
        }else if(coeff<0){
            outputStream<<coeff;
        }else if(coeff>0){
            outputStream<<'+'<<coeff;
        }
        if(counter==1){
            outputStream<<'x';
        }else if(counter > 1){
            outputStream<<"x^"<<counter;
        }
        if(counter == end){
            cont = false;
        }
        counter++;

    }

    return outputStream;
}

istream &operator>>(istream &inputStream, Polynomial &mathprint) {
    char answer[100];
    for(int i = 0; i < 100; i++){
        if(inputStream.peek()=='+'){
            inputStream.get();
            answer[i] = ' ';
        }else if(inputStream.peek()=='x'){
            inputStream.get();
            while (inputStream.peek()== '^'){
                inputStream.get();
                while(isdigit(inputStream.peek())){
                    inputStream.get();
                }
            }
        }else if(isdigit(inputStream.peek())){
            answer[i] = inputStream.get();
        }else if(inputStream.peek() == '-'){
            if(i == 0){
                answer[i] = inputStream.get();
            }else{
                answer[i] = ' ';
                i = i+1;
                answer[i] = inputStream.get();
            }
        }
    }
    mathprint.setAllCoeff(answer);

    return inputStream;
}

double Polynomial::evaluate(double slvX) {
    double answer = getCoeff(0);

    for(int i=1; i <= getPower();i++){
        answer = answer + (getCoeff(i)*pow(slvX,i));
    }


    return answer;
}

Polynomial Polynomial::derivative() {
    char answer[100];
    string str;
    for(int i = 1; i <= getPower(); i++){
        str.append(toString(getCoeff(i) * i));
        if(i != getPower()){
            str.append(" ");
        }
    }
    strcpy(answer, str.c_str());


    return Polynomial(answer);
}

double Polynomial::findRoot(double guess) {
    double xOne, xTwo, answer;
    Polynomial temp

    xOne = guess - (evaluate(guess)/)


    return 0;
}

int Polynomial::findPower() {
    int degree = 0;
    for(int i = 0; i < 100; i++){
        if(listOfCoffs[i] == '\0'){
            return degree;
        }
        if(isspace(listOfCoffs[i])){
            degree++;
        }
    }
    return degree;
}

double Polynomial::toDouble(string input, bool neg) const {
    double answer = atof(input.c_str());
    if(neg){answer = answer*-1;}
    return answer;
}

string Polynomial::toString(double value) const{
    stringstream ss;
    ss << value;
    string str = ss.str().c_str();
    return str;
}