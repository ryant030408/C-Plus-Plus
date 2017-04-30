// Cereal.h
// Created by Ryan Taylor on 4/25/17.
// Header for Cereal class

#ifndef PROJECT4_CEREAL_H
#define PROJECT4_CEREAL_H


class Cereal {

private:
    //Variables
    string brand;
    int upc;
    int month, day, year;


public:
    //Constructors
    Cereal();
    Cereal(string brandIn, int upcIn, int monthIn, int dayIn, int yearIn);
    //Accessor
    string getBrand() const;
    int getUpc() const;
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    int getFunctionalDate() const;
    //Setters/Mutators
    void setBrand(string brandIn);
    void setUpc(int upcIn);
    void setMonth(int monthIn);
    void setDay(int dayIn);
    void setYear(int yearIn);
    //Overloaded Stream Operators
    friend ostream& operator <<(ostream& outputStream, const Cereal& info);
    friend istream& operator >>(istream& inputStream, Cereal& info);
    //Override Comparison Operators
    bool operator<(const Cereal& cer2) const;
    bool operator>(const Cereal& cer2) const;


};


#endif //PROJECT4_CEREAL_H
