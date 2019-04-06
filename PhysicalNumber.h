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


        bool IsKM() const;
        bool IsM() const;
        bool IsCM() const;
        bool IsSEC() const;
        bool IsMIN() const;
        bool IsHOUR() const;
        bool IsG() const;
        bool IsKG() const;
        bool IsTON() const;
        
        
        const PhysicalNumber operator+(const PhysicalNumber& other);
        const PhysicalNumber operator-(const PhysicalNumber& other);
        friend PhysicalNumber& operator+=(PhysicalNumber a ,const PhysicalNumber& other);
        friend PhysicalNumber& operator-=(PhysicalNumber a ,const PhysicalNumber& other);
        const PhysicalNumber& operator+(const double other);
        const PhysicalNumber& operator-(const double other);
        
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
    
    //Output operator
    ostream& operator<< (ostream& os, const PhysicalNumber& num);
    
     //Input operator, example: istringstream input("700[kg]"); input >> a;
    istream& operator>> (istream& is, PhysicalNumber& num);

}//end of namespace ariel