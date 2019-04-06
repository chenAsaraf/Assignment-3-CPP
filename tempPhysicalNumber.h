#pragma once
#include <iostream>
#include <stdexcept>
#include "Unit.h"

using  std::cout;
using std::abs;

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
                   // cout << "in length dimension" << endl;
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
                //cout << "exception cout" << endl;
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
        //the += operator 
        friend void operator+=(PhysicalNumber a ,const PhysicalNumber& other) {
            if(notEquals(_dimension, other._dimension)){
                cout << "exception cout" << endl;
                throw std::invalid_argument("error, the dimension is not equals and you're fired.");
            }          
            switch (other._unit)
            {
               case Unit::KM:
                  if(a._unit::KM)
                     a._amount=a._amount+other._amount;
                  if(a._unit::M)
                     a._amount=a._amount+(1000*other._amount);
                  if(a._unit::CM)
                     a._amount=a._amount+(100000*other._amount);
                  break;

               case Unit::M:
                  if(a._unit::KM)
                     a._amount=a._amount+(1000*other._amount);
                  if(a._unit::M)
                     a._amount=a._amount+other._amount;
                  if(a._unit::CM)
                     a._amount=a._amount+(0.01*other._amount);
                  break;

               case Unit::cm:
                  if(a._unit::KM)
                     a._amount=a._amount+(100000*other._amount);
                  if(a._unit::M)
                     a._amount=a._amount+(100*other._amount);
                  if(a._unit::CM)
                     a._amount=a._amount+other._amount;
                  break;

               case Unit::TON:
                  if(a._unit::TON)
                     a._amount=a._amount+other._amount;
                  if(a._unit::KG)
                     a._amount=a._amount+(1000*other._amount);
                  if(a._unit::G)
                     a._amount=a._amount+(1000000*other._amount);
                  break;

               case Unit::KG:
                  if(a._unit::TON)
                     a._amount=a._amount+(1000*other._amount);
                  if(a._unit::KG)
                     a._amount=a._amount+other._amount;
                  if(a._unit::G)
                     a._amount=a._amount+(0.001*other._amount);
                  break;

               case Unit::G:
                  if(a._unit::TON)
                     a._amount=a._amount+(1000000*other._amount);
                  if(a._unit:KG)
                     a._amount=a._amount+(1000*other._amount);
                  if(a._unit::G)
                     a._amount=a._amount+other._amount;
                  break;

               case Unit::HOUR:
                  if(a._unit::HOUR)
                     a._amount=a._amount+other._amount;
                  if(a._unit::MIN)
                     a._amount=a._amount+(60*other._amount);
                  if(a._unit::SEC)
                     a._amount=a._amount+(3600*other._amount);
                  break;
                  
               case Unit::MIN:  
                  if(a._unit::HOUR)
                     a._amount=a._amount+(60*other._amount);
                  if(a._unit::MIN)
                     a._amount=a._amount+other._amount;
                  if(a._unit::SEC)
                     a._amount=a._amount+(0.16667*other._amount);
                  break;
               case Unit::SEC:
                  if(a._unit::HOUR)
                     a._amount=a._amount+(3600*other._amount);
                  if(a._unit:MIN)
                     a._amount=a._amount+(60*other._amount);
                  if(a._unit::SEC)
                     a._amount=a._amount+other._amount;
                  break;
               default:
                  break;
            }
        }

        //the =- operator:
         friend void operator-=(PhysicalNumber a ,const PhysicalNumber& other) {
            if(notEquals(_dimension, other._dimension)){
                cout << "exception cout" << endl;
                throw std::invalid_argument("error, the dimension is not equals and you're fired.");
            }          
            switch (other._unit)
            {
               case Unit::KM:
                  if(a._unit::KM)
                     a._amount=a._amount-other._amount;
                  if(a._unit::M)
                     a._amount=a._amount-(1000*other._amount);
                  if(a._unit::CM)
                     a._amount=a._amount-(100000*other._amount);
                  break;

               case Unit::M:
                  if(a._unit::KM)
                     a._amount=a._amount-(1000*other._amount);
                  if(a._unit::M)
                     a._amount=a._amount-other._amount;
                  if(a._unit::CM)
                     a._amount=a._amount-(0.01*other._amount);
                  break;

               case Unit::cm:
                  if(a._unit::KM)
                     a._amount=a._amount-(100000*other._amount);
                  if(a._unit::M)
                     a._amount=a._amount-(100*other._amount);
                  if(a._unit::CM)
                     a._amount=a._amount-other._amount;
                  break;

               case Unit::TON:
                  if(a._unit::TON)
                     a._amount=a._amount-other._amount;
                  if(a._unit::KG)
                     a._amount=a._amount-(1000*other._amount);
                  if(a._unit::G)
                     a._amount=a._amount-(1000000*other._amount);
                  break;

               case Unit::KG:
                  if(a._unit::TON)
                     a._amount=a._amount-(1000*other._amount);
                  if(a._unit::KG)
                     a._amount=a._amount-other._amount;
                  if(a._unit::G)
                     a._amount=a._amount-(0.001*other._amount);
                  break;

               case Unit::G:
                  if(a._unit::TON)
                     a._amount=a._amount-(1000000*other._amount);
                  if(a._unit:KG)
                     a._amount=a._amount-(1000*other._amount);
                  if(a._unit::G)
                     a._amount=a._amount-other._amount;
                  break;

               case Unit::HOUR:
                  if(a._unit::HOUR)
                     a._amount=a._amount-other._amount;
                  if(a._unit::MIN)
                     a._amount=a._amount-(60*other._amount);
                  if(a._unit::SEC)
                     a._amount=a._amount-(3600*other._amount);
                  break;
                  
               case Unit::MIN:  
                  if(a._unit::HOUR)
                     a._amount=a._amount-(60*other._amount);
                  if(a._unit::MIN)
                     a._amount=a._amount-other._amount;
                  if(a._unit::SEC)
                     a._amount=a._amount-(0.16667*other._amount);
                  break;
               case Unit::SEC:
                  if(a._unit::HOUR)
                     a._amount=a._amount-(3600*other._amount);
                  if(a._unit:MIN)
                     a._amount=a._amount-(60*other._amount);
                  if(a._unit::SEC)
                     a._amount=a._amount-other._amount;
                  break;
               default:
                  break;
            }
        }
        //the unary+
        const PhysicalNumber& operator+(const double other) {
           return PhysicalNumber((this->_amount)+other, this->_unit);
        }
        //the unary-
        const PhysicalNumber& operator-(const double other) {
           return PhysicalNumber((this->_amount)-other, this->_unit);
           }
        
        
        
    }; //end of PhysicalNumber
    
}//end of namespace ariel
