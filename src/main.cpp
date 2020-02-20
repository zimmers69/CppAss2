//
// Created by User on 2020-02-20.
//

#include <iostream>
#include "main.h"

int main(int argc, char* argv[]){

    if (argc == 2){
        ZMMALE001::processEverything();
    } else if (argc == 5) {
        ZMMALE001::extractImage(argv[4], argv[5]);
    } else if (argc == 6) {
        ZMMALE001::diffImage(argv[3], argv[4], argv[5]);
    } else {
        std::cerr << "Incorrect use of program." << std::endl;
        std::cerr << "Usage: volimage <imageBase> [-d i j output_file_name] [-x i output_file_name]" << std::endl;
        exit(1);
    }
}

void ZMMALE001::diffImage(char* &i, char* &j, char* &output_name) {
    std::cout << "hey diff";
}

void ZMMALE001::extractImage(char* &imageNum, char* &output_name) {
    std::cout << "hey extract";
}

void ZMMALE001::processEverything() {
    std::cout << "hey errthing";
}
