// Cereal.cpp
// Created by Ryan Taylor on 4/25/17.
//

#include<iostream> // for cout
#include <cstring>
#include <cctype>
#include <iomanip>
#include<string>
#include <list>

using namespace std;

#include "Cereal.h"


/**
 * Default Constructor
 * Sets brand to unknown and upc and date to 0
 */
Cereal::Cereal() {
    brand = "unknown";
    upc = 000000;
    month = 0, day = 0, year = 0;
}
/**
 * Constructor
 * @param brandIn
 * @param upcIn
 * @param monthIn
 * @param dayIn
 * @param yearIn
 */
Cereal::Cereal(string brandIn, int upcIn, int monthIn, int dayIn, int yearIn) {
    brand = brandIn;
    upc = upcIn;
    month = monthIn;
    day = dayIn;
    month = monthIn;
    year = yearIn;

}

//Accessors

/**
 * Gets Brand
 * @return Brand name in string
 */
string Cereal::getBrand() const {
    return brand;
}
/**
 * Gets UPC
 * @return 6 Digit UPC int
 */
int Cereal::getUpc() const {
    return upc;
}
/**
 * Gets Expiration Month
 * @return 2 Digit Month value for Expiration int
 */
int Cereal::getMonth() const {
    return month;
}
/**
 * Gets Expiration Day
 * @return 2 Digit Day value for Expiration int
 */
int Cereal::getDay() const {
    return day;
}
/**
 * Gets Expiration Year
 * @return 4 Digit Year value for Expiration int
 */
int Cereal::getYear() const {
    return year;
}
/**
 * Gets a full workable date integer
 * @return Combination of year month and day
 */
int Cereal::getFunctionalDate() const {
    return (year*10000)+(month*100)+day;
}

//Setters/Mutators

/**
 * Sets a new brand name
 * @param brandIn string for new brand name
 */
void Cereal::setBrand(string brandIn) {
    brand = brandIn;
}
/**
 * Sets new upc value
 * @param upcIn 6 digit int of new upc
 */
void Cereal::setUpc(int upcIn) {
    upc = upcIn;
}
/**
 * Sets new month of expiration
 * @param monthIn 2 digit int for month
 */
void Cereal::setMonth(int monthIn) {
    month = monthIn;
}
/**
 * Sets new day of expiration
 * @param dayIn 2 digit int for day
 */
void Cereal::setDay(int dayIn) {
    day = dayIn;
}
/**
 * Sets new year of expiration
 * @param yearIn 4 digit year
 */
void Cereal::setYear(int yearIn) {
    year = yearIn;
}

//Overloaded Stream Operators

/**
 * Sends Cereal object to output or to file
 * @param outputStream Output stream working with
 * @param info Cereal object reading from
 * @return Stream
 */
ostream &operator<<(ostream &outputStream, const Cereal &info) {
    int brandSpaceWidth(14), yearSpaceWidth(5), mon_daySpaceWidth(3), upcWidth(7);
    char seperator = ' ';

    outputStream<<left<<setw(brandSpaceWidth)<<setfill(seperator)<<info.getBrand();
    outputStream<<left<<setw(upcWidth)<<setfill(seperator)<<info.getUpc();
    outputStream<<right<<setw(mon_daySpaceWidth)<<setfill(seperator)<<info.getMonth();
    outputStream<<right<<setw(mon_daySpaceWidth)<<setfill(seperator)<<info.getDay();
    outputStream<<right<<setw(yearSpaceWidth)<<setfill(seperator)<<info.getYear();

    return outputStream;
}

/**
 * Will accept input from a file or user input
 * @param inputStream Stream in of file or user
 * @param info Cereal object in
 * @return Inputstream
 */
istream &operator>>(istream &inputStream, Cereal &info) {
    string brand;
    int upc, month, day, year;
    inputStream>>brand;
    inputStream>>upc;
    inputStream>>month;
    inputStream>>day;
    inputStream>>year;

    info.setBrand(brand);
    info.setUpc(upc);
    info.setMonth(month);
    info.setDay(day);
    info.setYear(year);

    return inputStream;
}

//Overloaded Comparison Operators

/**
 * Compares two Cereal objects expiration dates
 * @param cer2 Cereal to test against
 * @return If Cereal object called on expires sooner returns true
 */
bool Cereal::operator<(const Cereal &cer2) const{
    return getFunctionalDate() < cer2.getFunctionalDate();
}
/**
 * Compares two Cereal objects expiration dates
 * @param cer2 Cereal to test against
 * @return If Cereal object called on expires later returns true
 */
bool Cereal::operator>(const Cereal &cer2) const{
    return getFunctionalDate() > cer2.getFunctionalDate();
}

