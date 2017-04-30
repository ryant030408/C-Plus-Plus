#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#include "Polynomial.h"

int main() {
    char ints[] = "1 2 3 4 5";
    char ints3[] = "2 0 4 5 6";
    char ints4[] = "1 2 3 3";
    Polynomial one(ints3);

//    cout<<one<<endl; // <<override
//    cout<<one.getCoeff(3)<<endl; //Get coeff
//    cout<<one.getPower()<<endl; //Get power
//
//    char newInts[] = "3.4 -3 4 5.5";
//    one.setAllCoeff(newInts); //Set coeffs
//    cout<<one<<endl;
//    cout<<one.getCoeff(0)<<endl;
//    cout<<one.getPower()<<endl;

    Polynomial two(ints);
    Polynomial three(ints3);

    Polynomial four = two-three;//+ Override
//    Polynomial four = two+three;//- Override
    cout<<one<<endl;

//    Polynomial five;
//    cin>>five;

//    cout<<five;

    Polynomial six(ints4);
//    cout<<six.evaluate(-1)<<endl;

    cout<<six.derivative()<<endl;







    return 0;
}