// Cerealdriver.cpp
// Created by Ryan Taylor
// This prgram test the Cereal class which reads in a list of cereal boxes from a text file and
// allows you to add, remove and print Cereal box object. At the end it will exit and save to a new file.

#include<iostream> // for cout
#include <fstream>	//ifstream
#include<string>
#include <list>
#include <iomanip>

using namespace std;

#include "Cereal.h"

list<Cereal> cerList;
list<Cereal>::iterator spot;
list<Cereal>::iterator endL;
list<Cereal>::iterator tempElement;


int main() {

    cout<<"Welcome to my inventory control program."<<endl;
    cout<<"Opening Inventory.txt"<<endl;

    ifstream afile;
    afile.open("Inventory.txt");
    string fileName = "Inventory.txt";
    Cereal programUse;
    int selection;
    bool loop = true, found = true;

    //checking if file is open
    if (!afile.is_open()) {
        cerr << "unable to open " << fileName << endl;
    }
    else {//read entire file and output to screen

        while (!afile.eof()) {  // eof returns true if we have tried to read and nothing is left
            afile>>programUse;
            cerList.push_front(programUse);
        }
        cerList.sort();
    }
    afile.close();

    cout<<fileName<<" opened and read successfully."<<endl;


    do{
        cout<<"Please make a selection:\n"
                "1) Add a box of cereal to the inventory\n"
                "2) Remove a box of cereal from inventory\n"
                "3) Delete all cereal boxes with expired dates\n"
                "4) Print the updated inventory list\n"
                "5) Quit and save the updated inventory list to a file"<<endl;
        cin>>selection;
        switch(selection){
            case 1:
                cout<<"Please enter a new cereal that is space seperated in the form Brand UPC MONTH_EXPIRES DAY_EXPIRES YEAR_EXPIRES";
                cin>>programUse;
                cerList.push_front(programUse);
                cerList.sort();
                break;
            case 2:
                cout<<"Please enter the UPC of the cereal you would like to remove:"<<endl;
                int upcRemove;
                cin>>upcRemove;
                spot = cerList.begin();
                found = true;
                while(found){
                    if((*spot).getUpc()==upcRemove){
                        tempElement = spot;
                        cerList.erase(spot);
                        found = false;
                    }else{
                        spot++;
                    }
                }
                cout<<"Removed " << (*tempElement).getBrand()<<endl;
                break;
            case 3:
                spot = cerList.begin();
                endL = cerList.end();
                endL--;
                int date, input;
                cout<<"The box with the newest expiration date in inventory is: "<<endl;
                cout<<*endL<<endl;
                cout<<"The box with the oldest expiration date in inventory is: "<<endl;
                cout<<*spot<<endl;
                cout<<"Enter the date to remove expired boxes.\n"
                        "Enter month day year(4 digit) : "<<endl;
                cin>>input;
                date = input*100;
                cin>>input;
                date = date+input;
                cin>>input;
                date = date+(input*10000);
                cout << date << endl;
                found = true;
                while(found) {
                    spot = cerList.begin();
                    if (cerList.empty()) {
                        found = false;
                    }else if((*spot).getFunctionalDate()<date){
                        tempElement = spot;
                        cerList.erase(spot);
                        cout<<"Removed " << *tempElement<<endl;
                    }else{
                        found = false;
                    }

                }

                break;
            case 4:
                cout<<"Inventory List Is:\n"<<endl;
                cout<<left<<setw(14)<<setfill(' ')<<"Brand"<<left<<setw(7)<<setfill(' ')<<"UPC"<<right<<setw(3)<<setfill(' ')<<"MONTH"<<right<<setw(3)<<setfill(' ')<<"DAY"<<right<<setw(5)<<setfill(' ')<<"YEAR"<<endl;
                spot = cerList.begin();
                if(cerList.empty()){
                    cout << "List is empty" << endl;
                }
                for(int i = 0; i < cerList.size(); i++){
                    cout<<*spot<<endl;
                    spot++;
                }
                break;
            case 5:
                string fileOutName;
                cout<<"Please enter the name of the file to save as: "<<endl;
                cin>>fileOutName;
                loop = false;
                spot = cerList.begin();
                if(cerList.empty()){
                    cout<<"List is empty, nothing to save."<<endl;
                }else{
                        ofstream fout;
                        fout.open(fileOutName);

                        for(int i = 0; i < cerList.size(); i++){
                            if(i > 0){
                                fout<<'\n';
                            }

                            fout<<*spot;
                            spot++;
                        }


                    cout<<"List is saved."<<endl;
                    fout.close();
                }
                cout<<"Thank you for using my program"<<endl;


                break;

        }
    }while(loop);
}
