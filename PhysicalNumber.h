#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "Unit.h"

using namespace std::cout, std::abs;

namespace ariel{
    
    enum class Dimension: int{
        Length,
        Time,
        Weight
        }; 
    
    bool notEquals(const Dimension& alpha ,const Dimension& beta){
        if(alpha!=beta) return true;
    }
    
    
    
    
    class PhysicalNumber{

       public:
       
       //for now public- later should be getters & setters
        Unit _unit;
        float _amount;
        Dimension _dimension; //maby should implement in other way
        
        // Constructor:
        PhysicalNumber(float amount, Unit some_unit){
            switch(some_unit){
                case Unit::KM: Dimension::Length; 
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
        
        friend ostream& operator<<(ostream& os, const PhysicalNumber& num);
        friend istream& operator>> (istream& is, PhysicalNumber& num);
        
        bool IsKM() const { return _unit == Unit::KM; }
        bool IsM() const { return _unit == Unit::M; }
        bool IsCM() const { return _unit == Unit::CM; }
        bool IsSEC() const { return _unit == Unit::SEC; }
        bool IsMIN() const { return _unit == Unit::MIN; }
        bool IsHOUR() const { return _unit == Unit::HOUR; }
        bool IsG() const { return _unit == Unit::G; }
        bool IsKG() const { return _unit == Unit::KG; }
        bool IsTON() const { return _unit == Unit::TON; }
        
        
        const PhysicalNumber operator+(const PhysicalNumber& other) {
            if(notEquals(_dimension, other._dimension)){
                cout << "exception cout" << endl;
                throw std::invalid_argument("error, the dimension is not equals and you're fired.");
            }
            else{
                float toAdd = other._amount;
                switch(other._unit) {
                    case Unit::KM:  return PhysicalNumber(_amount + _km(toAdd), _unit);
                    case Unit::M:   return PhysicalNumber(_amount + _m(toAdd), _unit);
                    case Unit::CM:  return PhysicalNumber(_amount + _cm(toAdd), _unit);
                    case Unit::SEC: return PhysicalNumber(_amount + _sec(toAdd), _unit);
                    case Unit::MIN: return PhysicalNumber(_amount + _min(toAdd), _unit);
                    case Unit::HOUR:return PhysicalNumber(_amount + _hour(toAdd), _unit);
                    case Unit::G:   return PhysicalNumber(_amount + _g(toAdd), _unit);
                    case Unit::KG:  return PhysicalNumber(_amount + _kg(toAdd), _unit);
                    case Unit::TON: return PhysicalNumber(_amount + _ton(toAdd), _unit);
                }
           }
        }
    
        
        float _km(float kilometre){
            switch(this->_unit){
                case Unit::KM: return kilometre;
                case Unit::M: return kilometre*1000;
                case Unit::CM: return kilometre*100000;
            }
            cout << "arrived at a place that was not suppose to" << endl;
            return 0;
        }
        
        float _m(float metre){
            switch(this->_unit){
                case Unit::KM: return metre/100;
                case Unit::M:  return metre;
                case Unit::CM: return metre*100;
            }
            cout << "arrived at a place that was not suppose to" << endl;
            return 0;
        }
        
        float _cm(float centimetre){
            switch(this->_unit){
                case Unit::KM: return centimetre/100000;
                case Unit::M:  return centimetre/100;
                case Unit::CM: return centimetre;
            }
            cout << "arrived at a place that was not suppose to" << endl;
            return 0;
        }
        
        float _sec(float seconds){
            switch(this->_unit){
                case Unit::SEC: return seconds;
                case Unit::MIN: return seconds/60;
                case Unit::HOUR:return seconds/3600;
            }
            cout << "arrived at a place that was not suppose to" << endl;
            return 0;
        }
        
        float _min(float minute){
            switch(this->_unit){
                case Unit::SEC: return minute*60;
                case Unit::MIN: return minute;
                case Unit::HOUR:return minute/60;
            }
            cout << "arrived at a place that was not suppose to" << endl;
            return 0;
        }
        
        float _hour(float hour){
            switch(this->_unit){
                case Unit::SEC: return hour*3600;
                case Unit::MIN: return hour*60;
                case Unit::HOUR:return hour;
            }
            cout << "arrived at a place that was not suppose to" << endl;
            return 0;
        }
        
        float _g(float gram){
            switch(this->_unit){
                case Unit::G:  return gram;
                case Unit::KG: return gram/1000;
                case Unit::TON:return gram/1000000;
            }
            cout << "arrived at a place that was not suppose to" << endl;
            return 0;
        }
        
        float _kg(float kilogram){
            switch(this->_unit){
                case Unit::G:  return kilogram/1000;
                case Unit::KG: return kilogram;
                case Unit::TON:return kilogram/1000;
            }
            cout << "arrived at a place that was not suppose to" << endl;
            return 0;
        }
        
        float _ton(float tons){
            switch(this->_unit){
                case Unit::G:  return tons*1000000;
                case Unit::KG: return tons*1000;
                case Unit::TON:return tons;
            }
            cout << "arrived at a place that was not suppose to" << endl;
            return 0;
        }
        
        
        
    }; //end of PhysicalNumber
    
    //Output operator
    ostream& operator<<(ostream& os, const PhysicalNumber& num) {
        string printUnit = "";
        switch(num._unit){
            case Unit::KM: printUnit = "[km]"; 
            case Unit::M: printUnit = "[m]";
            case Unit::CM: printUnit = "[cm]";
            case Unit::SEC: printUnit = "[sec]";
            case Unit::HOUR: printUnit = "[hour]";
            case Unit::G: printUnit = "[g]";
            case Unit::KG: printUnit = "[kg]";
            case Unit::TON: printUnit = "[ton]";
            default: printUnit = "[deafult]"; //need to correct, case of cout << a+b << endl;
            }
            return os << num.amount << '[' << printUnit << ']';
    }
    
     //Input operator, example: istringstream input("700[kg]"); input >> a;
    istream& operator>> (istream& is, PhysicalNumber& num){
    is>> num._amount; //need to correct
    return is;
    }
 
    
}//end of namespace ariel
