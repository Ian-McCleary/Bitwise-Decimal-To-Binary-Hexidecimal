/* course csci 247
convert.c
Name; Ian McCleary
*/

#include <stdio.h>
#include <iostream>

#define INT_SIZE sizeof(int) * 8


//forward declarations
void convertToHexidecimal(char* str);
void convertToBinary(char* str);

//main function
//The first parameter is the conversion -x or -b. The the lines are used to type decimal numbers.
//Ex: ".\convert -x 23 54 2 65"
//This funciton handles the parsing of the first parameter and each new line.
//Inputed decimals are converted from std::string to char*
//Code editor throwing errors on std::string and std::getline...include standard library might not be working properly in my environment. 
int main(int argc, char* argv[]){
     if(std::string(argv[1]) == "-x"){
        std::string line; 
        while (std::getline(std::cin, line)){
            char *cstr = &line[0];
            convertToHexidecimal(cstr);
        }
    } else if(std::string(argv[1]) == "-b"){
        std::string line; 
        while (std::getline(std::cin, line)){
            char *cstr = &line[0];
            convertToBinary(cstr);
        }
        
    } else {
        printf("%s\n", "Error, the first argument must be -x or -b");
        return(1);
    }
    return(0);
}

//method for converting decimal to hexidecimal
//takes char* as input argument
void convertToHexidecimal(char* str){
    long num = strtol(str,NULL,10);
    long int remainder,quotient;
    quotient = num;
    char hexArr[INT_SIZE];
    int i=1;
    int temp;

    while (quotient != 0){
        temp = quotient % 16;

        if (temp < 10){
            temp = temp + 48;
        } else {
            temp = temp + 55;
        }
        hexArr[i++] = temp;
        quotient = quotient / 16;
    }
    //print the new hexidecimal in reverse order
    printf("%s", "0x");
    for (int j = i-1; j>0; j--){
        printf("%c", hexArr[j]);
    }
    std::cout << "\n";
}

//method for converting decimal to binary
//Iteration loop gets least significant bit and then performs right shift to get next bit in sequence. 
//accepts char* as only argument
void convertToBinary(char* str){
    int index;
    int holder[INT_SIZE];

    //convert string argument from stdin to long
    long num = strtol(str,NULL,10);
    //printf("\n%d\n", num);

    index = INT_SIZE - 1;
    while (index >= 0){
        holder[index] = num & 1;
        index--;
        num >>= 1;
    }
    //print the new binary array.
    for(int i=0; i<INT_SIZE; i++){
        printf("%d", holder[i]);
    }
    std::cout << "\n";
}