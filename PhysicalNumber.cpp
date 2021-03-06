#include <iostream>
#include <stdexcept>
#include "PhysicalNumber.h"

using namespace std;
using ariel::Dimension, ariel::PhysicalNumber;

bool ariel::notEquals(const Dimension& alpha ,const Dimension& beta){
    if(alpha!=beta) return true;
    return false;
}

ariel::PhysicalNumber::PhysicalNumber(double amount, Unit some_unit){
    _unit = some_unit;
    _amount = amount;
}

ostream& ariel::operator<<(ostream& os, const PhysicalNumber& num) {
    return os<<num._amount<<type[int(num._unit)];
}

    //Input operator, example: istringstream input("700[kg]"); input >> a;
istream& ariel::operator>> (istream& is, PhysicalNumber& num){
   std::string helper;
   if (!(is>>num._amount)) throw std::runtime_error("the input is not valid");
   else is>>helper;
   int i = 0;
   bool b = false;
   while (i<9) {
       i++;
       if(helper.compare(type[i])==0)
       {
           num._unit=Unit(i);
           i = 9;
           b = true;
       }
   }
   if(!b) throw runtime_error("the input is not valid");
   return is;
}

const PhysicalNumber ariel::PhysicalNumber::operator+(const PhysicalNumber& other) {
        if ((int(other._unit)/3)!=(int(this->_unit))/3) throw std::runtime_error("different units");
        
        double curr_yahas = yahas[int(other._unit)]/yahas[int(this->_unit)];
        return PhysicalNumber(other._amount*curr_yahas+this->_amount,this->_unit);
}
const PhysicalNumber ariel::PhysicalNumber::operator-(const PhysicalNumber& other) {
    if ((int(other._unit)/3)!=(int(this->_unit))/3) throw std::runtime_error("different units");
        
        double curr_yahas = yahas[int(other._unit)]/yahas[int(this->_unit)];
        return PhysicalNumber(other._amount*curr_yahas-this->_amount,this->_unit);
}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other){
    if ((int(other._unit)/3)!=(int(this->_unit))/3) throw std::runtime_error("different units");
        
        double curr_yahas = yahas[int(other._unit)]/yahas[int(this->_unit)];
        this->_amount = other._amount*curr_yahas+this->_amount;
        return *this;
}

PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other){
    if ((int(other._unit)/3)!=(int(this->_unit))/3) throw std::runtime_error("different units");
        
        double curr_yahas = yahas[int(other._unit)]/yahas[int(this->_unit)];
        this->_amount = other._amount*curr_yahas-this->_amount;
        return *this;
}

//the unary+
const PhysicalNumber ariel::PhysicalNumber::operator+() {
    return PhysicalNumber(this->_amount, this->_unit);
}
//the unary-
const PhysicalNumber ariel::PhysicalNumber::operator-() {
    return PhysicalNumber(-1*(this->_amount), this->_unit);
}

bool ariel::operator==(const PhysicalNumber& first,const PhysicalNumber& second){
    if ((int(first._unit)/3)!=(int(second._unit))/3) return false;
    return ((first._amount * yahas[int(first._unit)] == (second._amount * yahas[int(second._unit)])));
}

bool ariel::operator!=(const PhysicalNumber& first,const PhysicalNumber& second) {
    if ((int(first._unit)/3)!=(int(second._unit))/3) return true;
    return ((first._amount * yahas[int(first._unit)] != (second._amount * yahas[int(second._unit)])));
}

bool ariel::operator>(const PhysicalNumber& first,const PhysicalNumber& second){
    double x,y;
    x = first._amount * yahas[int(first._unit)];
    y = second._amount * yahas[int(second._unit)];
    if(x>y) return true;
    return false;
}

bool ariel::operator<(const PhysicalNumber& first,const PhysicalNumber& second){
    double x,y;
    x = first._amount * yahas[int(first._unit)];
    y = second._amount * yahas[int(second._unit)];
    if(x<y) return true;
    return false;
}

bool ariel::operator>=(const PhysicalNumber& first,const PhysicalNumber& second){
    double x,y;
    x = first._amount * yahas[int(first._unit)];
    y = second._amount * yahas[int(second._unit)];
    if(x>=y) return true;
    return false;
}

bool ariel::operator<=(const PhysicalNumber& first,const PhysicalNumber& second){
    double x,y;
    x = first._amount * yahas[int(first._unit)];
    y = second._amount * yahas[int(second._unit)];
    if(x<=y) return true;
    return false;
}

const PhysicalNumber PhysicalNumber::operator++(int){
    PhysicalNumber a(this->_amount,this->_unit);
    this->_amount= this->_amount+1;
    return a;
}

const PhysicalNumber PhysicalNumber::operator--(int){
    PhysicalNumber a(this->_amount,this->_unit);
    this->_amount= this->_amount-1;
    return a;
}

PhysicalNumber& PhysicalNumber::operator++(){
    this->_amount = this->_amount + 1;
    return *this;
}

PhysicalNumber& PhysicalNumber::operator--(){
    this->_amount = this->_amount - 1;
    return *this;
}