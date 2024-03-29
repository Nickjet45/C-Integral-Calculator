#ifndef INTEGRAL_H
#define INTEGRAL_H
#include <string>
//Declaration of class to store the term and the exponential value of said term

class equationTerm{
    public:
        void storeTerm(char currentChar);
        void storeExponent(std::string exponent);
        void findIntegral();
        void outputEquation();
        std::string getEquation();
    
    private:
        std::string fullTerm = "", integral = "";
        int exponent;
};



#endif