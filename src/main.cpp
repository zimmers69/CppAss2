//
// Created by User on 2020-02-20.
//

#include <iostream>
//#include <stdlib.h>
#include "main.h"
#include "volimage.h"

using std::string, std::stoi;
int main(int argc, char* argv[]){

    if (argc == 2){
        std::cout << "no args.\n";
        VolImage images(argv[1]);
        images.noargs();
    } else if (argc == 5) {
        if (string(argv[2]).compare("-x") == 0) {
            VolImage images(argv[1]);
            images.extract(stoi(argv[3]), string(argv[4]));
        } else if (string(argv[2]).compare("-g") == 0){
            VolImage images(argv[1]);
            images.gextract(stoi(argv[3]), string(argv[4]));
        }
    } else if (argc == 6) {
        VolImage images(argv[1]);
        images.diffmap(stoi(argv[3]), stoi(argv[4]), string(argv[5]));
    } else {
        std::cerr << "Incorrect use of program." << std::endl;
        std::cerr << "Usage: volimage <imageBase> [-d i j output_file_name] [-x i output_file_name]" << std::endl;
        exit(1);
    }
}

void ZMMALE001::diffImage(char* &i, char* &j, char* &output_name, VolImage &images) {
    std::cout << "hey diff";
}

void ZMMALE001::extractImage(char* &imageNum, char* &output_name, VolImage &images) {
    std::cout << "hey extract";
}

