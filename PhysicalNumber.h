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
        double _amount;
        Dimension _dimension; //maby should implement in other way
        
        // Constructor:
        PhysicalNumber(double amount, Unit some_unit);
        
        friend ostream& operator<<(ostream& os, const PhysicalNumber& num);
        friend istream& operator>> (istream& is, PhysicalNumber& num);
        
        const PhysicalNumber operator+(const PhysicalNumber& other);
        const PhysicalNumber operator-(const PhysicalNumber& other);
        PhysicalNumber& operator+=(const PhysicalNumber& x);
        PhysicalNumber& operator-=(const PhysicalNumber& x);
        const PhysicalNumber operator+();
        const PhysicalNumber operator-();    
        


        friend bool operator==(const PhysicalNumber& first,const PhysicalNumber& second);// Implement at .cpp file
		friend bool operator!=(const PhysicalNumber& first,const PhysicalNumber& second);
		friend bool operator>(const PhysicalNumber& first,const PhysicalNumber& second);
		friend bool operator<(const PhysicalNumber& first,const PhysicalNumber& second); // Implement at .cpp file
		friend bool operator>=(const PhysicalNumber& first,const PhysicalNumber& second);
		friend bool operator<=(const PhysicalNumber& first,const PhysicalNumber& second);

        //these are the situaltion where we do number++
        const PhysicalNumber operator++(int);
        const PhysicalNumber operator--(int);
        //these are the situaltion where we do ++number
        PhysicalNumber& operator++();
        PhysicalNumber& operator--();
    }; //end of PhysicalNumber
    
    //Output operator
    ostream& operator<< (ostream& os, const PhysicalNumber& num);
    
     //Input operator, example: istringstream input("700[kg]"); input >> a;
    istream& operator>> (istream& is, PhysicalNumber& num);

}//end of namespace ariel
