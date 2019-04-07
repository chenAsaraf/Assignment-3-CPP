
#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "Unit.h"

using namespace std;

namespace ariel{
    
    enum class Dimension: int{
        Length,
        Time,
        Weight
        }; 
    
    bool notEquals(const Dimension& alpha ,const Dimension& beta);
    
    
    
    
    class PhysicalNumber{

       public:
       
       //for now public- later should be getters & setters
        Unit _unit;
        float _amount;
        Dimension _dimension; //maby should implement in other way
        
        // Constructor:
        PhysicalNumber(float amount, Unit some_unit);
        
        friend ostream& operator<<(ostream& os, const PhysicalNumber& num);
        friend istream& operator>> (istream& is, PhysicalNumber& num);\


        //Operators
        const PhysicalNumber operator+(const PhysicalNumber& other);
        const PhysicalNumber operator-(const PhysicalNumber& other);
        PhysicalNumber& operator+=(const PhysicalNumber& other);
        PhysicalNumber& operator-=(const PhysicalNumber& other);
        const PhysicalNumber& operator+(const double other);
        const PhysicalNumber& operator-(const double other);
        PhysicalNumber operator- ();
        PhysicalNumber operator+ ();
        bool operator== (const PhysicalNumber& b);
        bool operator> (const PhysicalNumber& b);
        bool operator< (const PhysicalNumber& b);
        bool operator>= (const PhysicalNumber& b);
        bool operator<= (const PhysicalNumber& b);
        
        //Conversions
        float _km(float kilometre);
        float _m(float metre);
        float _cm(float centimetre);
        float _sec(float seconds);
        float _min(float minute);
        float _hour(float hour);
        float _g(float gram);
        float _kg(float kilogram);
        float _ton(float tons);
        
    }; //end of PhysicalNumber
    
    //Friend operators
    ostream& operator<< (ostream& os, const PhysicalNumber& num);
    istream& operator>> (istream& is, PhysicalNumber& num);

}//end of namespace ariel
