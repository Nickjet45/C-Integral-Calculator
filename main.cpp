#include <vector>
#include "Integral.hpp"
#include <iostream>

//Function to accept the equation of the integral from the users
std::string getEquation(){
    std::string integralEquation;
    std::cout << "What is the equation of your integral? "
        << "Write 2x squared as 2x^2 ";

    std::getline(std::cin, integralEquation);
    return integralEquation;
}

//Turns the string into an array of characters

void convertArray(std::string oldEquation, char newEquation[]){
    for(int i = 0; i < oldEquation.size(); i++){
        newEquation[i] = oldEquation[i];
    }
}

//Outputs the equation entered by the user to ensure that the program read the message in properly

void verifyEquation(char equation[], int sizeOfArray){
    char userResponse;
    std::cout << "For your equation you entered: ";
    for(int i = 0; i < sizeOfArray; i++){
        std::cout << equation[i];
    }
    //Tells the program to output to a new line
    std::cout << std::endl;
}

//Calculates the amount of terms based off of the number of plusses and minuses in the equation
//The number of terms will be 1 more than the sum of all plusses and minuses
int getNumTerms(char equation[], int sizeOfArray){
    int numOfTerms = 0;
    for(int i  = 0; i < sizeOfArray; i++){
        if(equation[i] == '+' || equation[i] == '-'){
            numOfTerms++;
        }
    }
    //The number of terms is 1 more than the sum of all plus and minus
    return (numOfTerms + 1);
}


int main(){
    std::string equatioOfintegral;
    int sizeOfArray, numberOfTerms, currentIndex = 0;
    //Gets the equation from the user
    equatioOfintegral = getEquation();

    //Sets the size of the array to be equal to the size of the string that was filled
    sizeOfArray = equatioOfintegral.size();
    //Declaration of the array of characters that will hold the integral, with it's max size being based on the equation entered by the user
    char *pEquation;
    pEquation = new char[sizeOfArray];

    //Copies the equation into the pointer array
    convertArray(equatioOfintegral, pEquation);

    //Verifies that the equation the program currently has, is what the user entered
    verifyEquation(pEquation, sizeOfArray);

    //Stores the number of terms within the equation in numberOfTerms

    numberOfTerms = getNumTerms(pEquation, sizeOfArray);

    std::cout << "The number of terms entered was: " << numberOfTerms;

    //Creation of objects based off of the number of terms found

    equationTerm *Terms;
    char *SignsOfEquation;

    Terms = new equationTerm[numberOfTerms];

    //Creates an array of characters to store the signs of the equation
    //The number of signs is 1 minus the number of terms
    SignsOfEquation = new char[numberOfTerms - 1];

    //Loops over the size of the array, to know when to stop
    for(int i = 0; i < sizeOfArray; i++){
        //Uses the variable currentIndex to keep track of which object the program should be filling up

        //If the current element being indexed is '^' than the next element in the array is the exponent of the term
        if(pEquation[i] == '^'){
            std::string holder = "";
            holder += pEquation[i+1];
            Terms[currentIndex].storeExponent(holder);
        }

        //If the current term being indexed is a space, than there is no need to store it in the object, therefore skip it
        if(pEquation[i] == ' '){
            i++;
        }

        //If the current element being indexed is a + or minus, than the program has finished filling up X term and should indicate it by increasing
        //The variabel currentIndex
        if(pEquation[i] == '+' || pEquation[i] == '-'){
            SignsOfEquation[currentIndex] = pEquation[i];
            currentIndex++;
        }
        //Else the program should store what it has indexed into the program
        else{
            Terms[currentIndex].storeTerm(pEquation[i]);
        }
    }

    //Outputs to a new line to allow the program to properly display information
    std::cout << std::endl;

    std::cout << "The integral is: ";
    //Loop over the number of terms that the program calculated earlier
    for(int i = 0; i < numberOfTerms; i++){

        //If the current loop is less than the total number of terms - 1(which is the amount of signs found), than the program has not yet ended
        //Therefore it should find the integral of said equation and output it
        if(i < (numberOfTerms - 1)){
            Terms[i].findIntegral();
            std::cout << " " << SignsOfEquation[i] << " ";
        }
        else{
        //Else the program should find the last integral, output it, and than determine whether the program must output an x alongside the + C
            std::string placeHolder = Terms[i].getEquation();
            //Loop over the size of the last term, if the term has x in it than find the derivative as usual and add + C, and exit the program
            //Must exit the program, as the first for loop will run if it is simply broken
            //Else the array is something such as: 10, which's derivative is 10x, therefore append x + C to the integral
            for(int k = 0; k < placeHolder.size(); k++){
                if(placeHolder[k] == 'x'){
                    Terms[i].findIntegral();
                    std::cout << " + C";
                    delete[] pEquation, Terms, SignsOfEquation;
                    exit(1);
                }
            }
            Terms[i].findIntegral();
            std::cout << "x + C";
        }
    }

    //Deletes the pointers created to ensure that the memory is returned
    delete[] pEquation, Terms, SignsOfEquation;

}