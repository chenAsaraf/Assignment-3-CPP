#include <iostream>
#include <stdexcept>
#include "PhysicalNumber.h"

using namespace std;
using ariel::Dimension, ariel::PhysicalNumber;

bool ariel::notEquals(const Dimension& alpha ,const Dimension& beta){
    if(alpha!=beta) return true;
}

//Construcotr of Physical Number:
ariel::PhysicalNumber::PhysicalNumber(float amount, Unit some_unit){
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

/*~ Operators: ~*/

//Output operator:
ostream& ariel::operator<< (ostream& os, const PhysicalNumber& num) {
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
    return os << num._amount << '[' << printUnit << ']';
}

//Input operator, example: istringstream input("700[kg]"); input >> a;
istream& ariel::operator>> (istream& is, PhysicalNumber& num){
    is>> num._amount; //need to correct
    return is;
}

//Addition (connection) operator:
const PhysicalNumber ariel::PhysicalNumber::operator+ (const PhysicalNumber& other) {
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

//Addition operator:
PhysicalNumber& ariel::operator+= (const PhysicalNumber& other) {
    if(notEquals(_dimension, other._dimension)){
        cout << "exception cout" << endl;
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    }  
    float toAdd = other._amount;
    switch (other._unit){
        case Unit::KM:  a._amount = _amount + _km(toAdd);
        case Unit::M:   a._amount = _amount + _m(toAdd);
        case Unit::CM:  a._amount = _amount + _cm(toAdd);
        case Unit::SEC: a._amount = _amount + _sec(toAdd);
        case Unit::MIN: a._amount = _amount + _min(toAdd);
        case Unit::HOUR:a._amount = _amount + _hour(toAdd);
        case Unit::G:   a._amount = _amount + _g(toAdd);
        case Unit::KG:  a._amount = _amount + _kg(toAdd);
        case Unit::TON: a._amount = _amount + _ton(toAdd);
    }
    return *a;
}

//Subtraction operator:
const PhysicalNumber ariel::PhysicalNumber::operator- (const PhysicalNumber& other) {
    if(notEquals(_dimension, other._dimension)){
        cout << "exception cout" << endl;
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    }
    else{
        float minus = other._amount;
        switch(other._unit) {
            case Unit::KM:  return PhysicalNumber(_amount - _km(minus), _unit);
            case Unit::M:   return PhysicalNumber(_amount - _m(minus), _unit);
            case Unit::CM:  return PhysicalNumber(_amount - _cm(minus), _unit);
            case Unit::SEC: return PhysicalNumber(_amount - _sec(minus), _unit);
            case Unit::MIN: return PhysicalNumber(_amount - _min(minus), _unit);
            case Unit::HOUR:return PhysicalNumber(_amount - _hour(minus), _unit);

            case Unit::G:   return PhysicalNumber(_amount - _g(minus), _unit);
            case Unit::KG:  return PhysicalNumber(_amount - _kg(minus), _unit);
            case Unit::TON: return PhysicalNumber(_amount - _ton(minus), _unit);
        }
    }
}

//Decreasing operator:
PhysicalNumber& ariel::operator-= (const PhysicalNumber& other) {
    if(notEquals(_dimension, other._dimension)){
        cout << "exception cout" << endl;
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    }  
    float toSub = other._amount;
    switch (other._unit){
        case Unit::KM:  a._amount = _amount - _km(toSub);
        case Unit::M:   a._amount = _amount - _m(toSub);
        case Unit::CM:  a._amount = _amount - _cm(toSub);
        case Unit::SEC: a._amount = _amount - _sec(toSub);
        case Unit::MIN: a._amount = _amount - _min(toSub);
        case Unit::HOUR:a._amount = _amount - _hour(toSub);
        case Unit::G:   a._amount = _amount - _g(toSub);
        case Unit::KG:  a._amount = _amount - _kg(toSub);
        case Unit::TON: a._amount = _amount - _ton(toSub);
    }
    return *a;
}

//Overloaded minus (-) operator
PhysicalNumber operator- () {
    _amount = -_amount;
    return PhysicalNumber(_amount, _unit);
}

//Overloaded plus (+) operator
PhysicalNumber operator+ () {
    _amount = +_amount;
    return PhysicalNumber(_amount, _unit);
}
 

//Equals operator:    
bool operator== (const PhysicalNumber& b) {
    // this implementation can cause problems with
     // double precision (== for doubles)
    if(notEquals(_dimension, other._dimension)){
        cout << "exception cout" << endl;
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    }
    else{
        switch(b._unit){
        case Unit::KM:  return (_amount == _km(b.amount)); 
        case Unit::M:   return (_amount == _m(b.amount));
        case Unit::CM:  return (_amount == _cm(b.amount));
        case Unit::SEC: return (_amount == _sec(b.amount));
        case Unit::HOUR:return (_amount == _hour(b.amount));
        case Unit::G:   return (_amount == _g(b.amount));
        case Unit::KG:  return (_amount == _kg(b.amount));
        case Unit::TON: return (_amount == _ton(b.amount));
    }
    cout << "arrived at a place that was not suppose to" << endl;
    return false;
}
 
//Greater then operator:
bool operator> (const PhysicalNumber& b) {
    if(notEquals(_dimension, other._dimension)){
        cout << "exception cout" << endl;
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    }
    else{
        switch(b._unit){
        case Unit::KM:  return (_amount > _km(b.amount)); 
        case Unit::M:   return (_amount > _m(b.amount));
        case Unit::CM:  return (_amount > _cm(b.amount));
        case Unit::SEC: return (_amount > _sec(b.amount));
        case Unit::HOUR:return (_amount > _hour(b.amount));
        case Unit::G:   return (_amount > _g(b.amount));
        case Unit::KG:  return (_amount > _kg(b.amount));
        case Unit::TON: return (_amount > _ton(b.amount));
    }
    cout << "arrived at a place that was not suppose to" << endl;
    return false;
}

//Smaller then oerator:
bool operator< (const PhysicalNumber& b) {
    if(notEquals(_dimension, other._dimension)){
        cout << "exception cout" << endl;
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    }
    else{
        switch(b._unit){
        case Unit::KM:  return (_amount < _km(b.amount)); 
        case Unit::M:   return (_amount < _m(b.amount));
        case Unit::CM:  return (_amount < _cm(b.amount));
        case Unit::SEC: return (_amount < _sec(b.amount));
        case Unit::HOUR:return (_amount < _hour(b.amount));
        case Unit::G:   return (_amount < _g(b.amount));
        case Unit::KG:  return (_amount < _kg(b.amount));
        case Unit::TON: return (_amount < _ton(b.amount));
    }
    cout << "arrived at a place that was not suppose to" << endl;
    return false;
}

//Greater or equal operator:
bool operator>= (const PhysicalNumber& b) {
   return ((this>b) || (this==b));
} 

//Small or equal operator:
bool operator<= (const PhysicalNumber& b) {
   return ((this<b) || (this==b));
} 

/*~ Conversion functions: ~*/

float ariel::PhysicalNumber::_km(float kilometre){
    switch(this->_unit){
        case Unit::KM: return kilometre;
        case Unit::M: return kilometre*1000;
        case Unit::CM: return kilometre*100000;
    }
    cout << "arrived at a place that was not suppose to" << endl;
    return 0;
}

float ariel::PhysicalNumber::_m(float metre){
    switch(this->_unit){
        case Unit::KM: return metre/100;
        case Unit::M:  return metre;
        case Unit::CM: return metre*100;
    }
    cout << "arrived at a place that was not suppose to" << endl;
    return 0;
}

float ariel::PhysicalNumber::_cm(float centimetre){
    switch(this->_unit){
        case Unit::KM: return centimetre/100000;
        case Unit::M:  return centimetre/100;
        case Unit::CM: return centimetre;
    }
    cout << "arrived at a place that was not suppose to" << endl;
    return 0;
}

float ariel::PhysicalNumber::_sec(float seconds){
    switch(this->_unit){
        case Unit::SEC: return seconds;
        case Unit::MIN: return seconds/60;
        case Unit::HOUR:return seconds/3600;
    }
    cout << "arrived at a place that was not suppose to" << endl;
    return 0;
}

float ariel::PhysicalNumber::_min(float minute){
    switch(this->_unit){
        case Unit::SEC: return minute*60;
        case Unit::MIN: return minute;
        case Unit::HOUR:return minute/60;
    }
    cout << "arrived at a place that was not suppose to" << endl;
    return 0;
}

float ariel::PhysicalNumber::_hour(float hour){
    switch(this->_unit){
        case Unit::SEC: return hour*3600;
        case Unit::MIN: return hour*60;
        case Unit::HOUR:return hour;
    }
    cout << "arrived at a place that was not suppose to" << endl;
    return 0;
}

float ariel::PhysicalNumber::_g(float gram){
    switch(this->_unit){
        case Unit::G:  return gram;
        case Unit::KG: return gram/1000;
        case Unit::TON:return gram/1000000;
    }
    cout << "arrived at a place that was not suppose to" << endl;
    return 0;
}

float ariel::PhysicalNumber::_kg(float kilogram){
    switch(this->_unit){
        case Unit::G:  return kilogram/1000;
        case Unit::KG: return kilogram;
        case Unit::TON:return kilogram/1000;
    }
    cout << "arrived at a place that was not suppose to" << endl;
    return 0;
}

float ariel::PhysicalNumber::_ton(float tons){
    switch(this->_unit){
        case Unit::G:  return tons*1000000;
        case Unit::KG: return tons*1000;
        case Unit::TON:return tons;
    }
    cout << "arrived at a place that was not suppose to" << endl;
    return 0;
}
