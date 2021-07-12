#include "Integral.hpp"
#include <iostream>

//Updates the stored value of term with the character being passed through
void equationTerm::storeTerm(char currentChar){
    fullTerm += currentChar;
}

//Stores the found exponent into the member variable exponent
void equationTerm::storeExponent(std::string foundExponent){
    exponent = std::stoi(foundExponent);
}

//Returns the equation as a string to allow the program to evulate it

std::string equationTerm:: getEquation(){
    return fullTerm;
}

//Outputs the equation of the current object being indexed

void equationTerm::outputEquation(){
    std::cout << fullTerm;
}

//Finds the integral of the current equation
void equationTerm::findIntegral(){
    std::string exponentOfintegral = std::to_string(exponent + 1);
    for(int i = 0; i < fullTerm.size(); i++){
        //If the current term being read in is a 1, check to see if it's 1/x and if so the integral is ln(x)
        if((fullTerm[i]) == '1' && (fullTerm[i+1] == '/') && (fullTerm[i+2] == 'x')){
            integral+= "ln|x|";
            break;
        }

        //If the term being read in is e, than the derivative is 1/exponent * e^exponent
        if(fullTerm[i] == 'e'){
            //Removes the additional 1 from the exponent
            exponentOfintegral = std::to_string(exponent);
            integral+= "1/" + exponentOfintegral + " *e^" + exponentOfintegral + "x";
            break;
        }

        //If the current term being read in is an x, and the after it is not '^', which indicates that the term has an exponent
        //Than the term is simply numX, and so the integral of it is x^2/2
        //And this is the last term that the program needs to find, so break the loop
        if(fullTerm[i] == 'x'){
            if(fullTerm[i+1] != '^'){
                integral+= "x^" + exponentOfintegral + "/" + exponentOfintegral;
                break;
            }
        }
        //If the current term being read in is '^', than the term after it must be old exponent + 1, and it should be divided by old exponent + 1
        //To find it's integral
        if(fullTerm[i] == '^'){
            integral += ('^' + exponentOfintegral + "/" + exponentOfintegral);
            break;
        }
        //And if the term being read in isn't ^, than it's a number that should be repeated character for character
        else{
            integral += fullTerm[i];
        }
    }

    std::cout << integral;
}