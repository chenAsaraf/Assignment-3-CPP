#pragma once
#include <iostream>
#include <stdexcept>
#include "Unit.h"

using namespace std::cout, std::abs;

namespace ariel{
    
    enum class Dimension: int{
        Length,
        Time,
        Weight
        }; 
    
    bool notEquals(const Dimension& alpha ,const Dimension& beta){
        if(alpha==beta) return true;
    }
    
    
    
    class PhysicalNumber{

       public:
       
       //for now public- later should be getters & setters
        Unit _unit;
        int _amount;
        Dimension _dimension; //maby should implement in other way
        
        // Constructor:
        PhysicalNumber(int amount, Unit some_unit){
            switch(some_unit){
                case Unit::KM:{
                   Dimension::Length; 
                    cout << "in length dimension" << endl;
                } 
                case Unit::M: Dimension::Length;
                case Unit::CM: Dimension::Length;
                case Unit::SEC: Dimension::Time;
                case Unit::HOUR: Dimension::Time;
                case Unit::G: Dimension::Weight;
                case Unit::KG: Dimension::Weight;
                case Unit::TON: Dimension::Weight;
            }
            _unit = some_unit;
            _amount = amount;
        }
        
        
        
        const PhysicalNumber& operator+(const PhysicalNumber& other) {
            if(notEquals(_dimension, other._dimension)){
                cout << "exception cout" << endl;
                throw std::invalid_argument("error, the dimension is not equals and you're fired.");
            }
           switch(other._unit) {
             case Unit::KM:
                 return PhysicalNumber(_amount+other._amount, _unit);
             case Unit::M: 
                 return PhysicalNumber(_amount+other._amount, _unit);
             case Unit::CM:  return PhysicalNumber(_amount+other._amount, _unit);
             case Unit::SEC:  return PhysicalNumber(_amount+other._amount, _unit);
             case Unit::MIN:  return PhysicalNumber(_amount+other._amount, _unit);
             case Unit::HOUR:  return PhysicalNumber(_amount+other._amount, _unit);
             case Unit::G:  return PhysicalNumber(_amount+other._amount, _unit);
             case Unit::KG:  return PhysicalNumber(_amount+other._amount, _unit);
             case Unit::TON:  return PhysicalNumber(_amount+other._amount, _unit);
           }
        }
        
        
        
        
    }; //end of PhysicalNumber
    
}//end of namespace ariel
