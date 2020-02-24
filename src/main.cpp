//
// Created by User on 2020-02-20.
//

#include <iostream>
#include "main.h"
#include "volimage.h"

int main(int argc, char* argv[]){

    if (argc == 2){
        std::cout << "processing everything.\n";
        VolImage images(argv[1]);
        ZMMALE001::processEverything(images);
    } else if (argc == 5) {
        VolImage images(argv[1]);
        ZMMALE001::extractImage(argv[3], argv[4], images);
    } else if (argc == 6) {
        VolImage images(argv[1]);
        ZMMALE001::diffImage(argv[2], argv[3], argv[4], images);
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

void ZMMALE001::processEverything(VolImage &images) {

    images.export_images("out");

}
