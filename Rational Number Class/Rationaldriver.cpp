// Rationaldriver.cpp
// Created by Ryan Taylor on 3/29/17.
// This program tests the Rational class. It will take two rational numbers in and give options
// that test all of the methods within the class.
//

#include <iostream>
using namespace std;
#include "Rational.h"

int main(){
    //Rational numbers used in driver
    Rational one;
    Rational two;
    Rational temp;
    //Boolean value to run while loops
    bool loop = true;
    //Int for selecting choice and a value placeholder for ints
    int selection, demVal, numVal;
    //Intro to program, gives rules
    cout<<"Hello, welcome to my the rational number class. Please enter two rational numbers in the form \"a/b\" where"
            " b does not equal 0."<<endl;
    //Tries to take in values for two rational numbers, will repeat if 0 is attempted to be entered as denominator
    do {
        //catches invalid_argument
        try {
            cout << "Please enter your first rational number: " << endl;
            cin >> one;
            cout << "Please enter your second rational number: " << endl;
            cin >> two;
            loop=false;
        }catch(invalid_argument){ //Catches 0 error thrown in class
            cout<<"Denominator cannot be zero"<<endl;
        }
    } while (loop);
    loop=true;//Resets loop bool for next do while loop
    do{
        //Takes selection in for our switch statement
        cout<<"\nMake a selection to test the class"<<endl;
        cout<<"1: Math Operators"
                "\n2: Equality Operators"
                "\n3: Reduce"
                "\n4: Invert"
                "\n5: GCD"
                "\n6: Get Values"
                "\n7: New Rational Numbers"
                "\n8: Change Numerators and Denominators Individually"
                "\n9: View Rational Numbers"
                "\n10: Exit" <<endl;

        cin>>selection;//Inputted from console
        //Catches invalid_argument
        try{
            switch(selection){
                case 1://Outputs all overriden math operators on both Rationals
                    temp=one+two;
                    cout<<one<<" + "<<two<<" = "<<temp<<endl;
                    temp=one-two;
                    cout<<one<<" - "<<two<<" = "<<temp<<endl;
                    temp=one*two;
                    cout<<one<<" * "<<two<<" = "<<temp<<endl;
                    temp=one/two;
                    cout<<one<<" / "<<two<<" = "<<temp<<endl;
                    break;
                case 2://Outputs results of all overridden equality operators
                    for(int i = 0; i < 5; i++){
                        switch(i){
                            case 0:
                                if(one>two){
                                    cout<<one<<" is greater than " <<two<<endl;
                                }else{
                                    cout<<one<<" is not greater than " <<two<<endl;
                                };
                                break;
                            case 1:
                                if(one<two){
                                    cout<<one<<" is less than " <<two<<endl;
                                }else{
                                    cout<<one<<" is not less than " <<two<<endl;
                                };
                                break;
                            case 2:
                                if(one>=two){
                                    cout<<one<<" is greater or equal to " <<two<<endl;
                                }else{
                                    cout<<one<<" is not greater or equal to " <<two<<endl;
                                };
                                break;
                            case 3:
                                if(one<=two){
                                    cout<<one<<" is less or equal to " <<two<<endl;
                                }else{
                                    cout<<one<<" is not less or equal to " <<two<<endl;
                                };
                                break;
                            case 4:
                                if(one==two){
                                    cout<<one<<" is equal to " <<two<<endl;
                                }else{
                                    cout<<one<<" is not equal to " <<two<<endl;
                                };
                                break;
                        }

                    }
                    break;
                case 3://Outputs reduced versions of Rational objects
                    cout<<one<<" reduced is ";
                    one.reduce();
                    cout<<one<<endl;
                    cout<<two<<" reduced is ";
                    two.reduce();
                    cout<<two<<endl;
                    break;
                case 4://Inverts Rationals, invert() uses checker() and will throw invalid_argument if a 0 for denominator is attempted
                    temp = one;
                    temp.invert();
                    cout<<one<<" inverted is ";
                    cout<<temp<<endl;
                    temp = two;
                    temp.invert();
                    cout<<two<<" inverted is ";
                    cout<<temp<<endl;
                    break;
                case 5://Outputs GCD of both Rationals
                    cout<<"GCD of "<<one<<" is "<<one.gcd()<<endl;
                    cout<<"GCD of "<<two<<" is "<<two.gcd()<<endl;
                    break;
                case 6://Outputs double values of both Rationals
                    cout<<"Value of "<<one<<" is "<<one.value()<<endl;
                    cout<<"Value of "<<two<<" is "<<two.value()<<endl;
                    break;
                case 7://Allows user to redefine both Rationals, entered as they were at the beggining of the program and outputs changed Rationals
                    cout<<"Please enter your first rational number: "<<endl;
                    cin>>one;
                    cout<<"Please enter your second rational number: "<<endl;
                    cin>>two;
                    break;
                case 8://Allows user to individually define numerator and denominator and outputs changed Rationals
                    cout<<"Please enter your first rational number numerator: "<<endl;
                    cin>>numVal;
                    cout<<"Please enter your first rational number denominator: "<<endl;
                    cin>>demVal;
                    one.setDenominator(demVal);
                    one.setNumerator(numVal);
                    cout<<"Please enter your second rational number numerator: "<<endl;
                    cin>>numVal;
                    cout<<"Please enter your second rational number denominator: "<<endl;
                    cin>>demVal;
                    two.setDenominator(demVal);
                    two.setNumerator(numVal);
                    cout<<"First rationals numerator is "<<one.getNumerator()<<" and its denominator is " << one.getDenominator()
                            <<" making a rational numner of " <<one<<endl;
                    cout<<"Second rationals numerator is "<<two.getNumerator()<<" and its denominator is " << two.getDenominator()
                            <<" making a new rational number of "<<two<<endl;
                    break;
                case 9://Outputs current value of both Rationals in rational or mixed form
                    cout<<"First rational number is "<<one<<endl;
                    cout<<"Second rational number is "<<two<<endl;
                    break;
                case 10://Exits the program
                    loop=false;
            }

        }catch(invalid_argument){//Catches invalid_arguments
            cout<<"Denominator cannot be zero"<<endl;
        }
    }while(loop);
    return 0;
}