//
// Created by User on 2020-02-19.
//
#include <iostream>
#include <fstream>
#include "volimage.h"
#include <vector>
#include <string>


using namespace std;

bool VolImage::readImages(std::string baseName) {

    for (int n = 0; n < numm; ++n) {
        std::cout << "image " + std::to_string(n) << endl;
        std::ifstream image_fs(baseName + std::to_string(n) + ".raw", ios::in | ios::binary);
        unsigned char ** image = new unsigned char* [this->height];

        for (int i = 0; i < height; ++i) {
            image[i] = new unsigned char [width];
            for (int j = 0; j < width; ++j) {
                image_fs >> image[i][j];
                memory++;
            }
        }
        slices.push_back(image);
        image_fs.close();
    }
    memory += sizeof(this->width) + sizeof(this->height);
    std::cout << "done\n";
    return true;
}

VolImage::VolImage(char* baseName){
    std::cout << "constructor\n";
    memory = 0;
    std::string temp = std::string(baseName);
    std::cout << "reading images\n";

    string header_fname = "data/" + temp + ".data";
    ifstream header_fs(header_fname);
    int w, h, num;
    header_fs >> w;
    header_fs >> h;
    header_fs >> num;
    header_fs.close();
    width = w, height = h, numm = num;
    this->readImages(temp);
}

VolImage::~VolImage() {
    width = 0;
    height = 0;
    memory = 0;
    for (int i = 0; i <height ; ++i) {
        for (int j = 0; j <width ; ++j) {
            delete slices[i][j];
        }
    }
}

void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix) {
    // todo
}

void VolImage::extract(int sliceId, std::string output_prefix) {
    //todo
}

int VolImage::volImageSize() {
    return memory;
}

VolImage::VolImage(const VolImage &oldVolImage) : width(oldVolImage.width), height(oldVolImage.height){
//    this->width = oldVolImage.width;
//    this->height = oldVolImage.height;

    for (int i = 0; i <height ; ++i) {
        slices[i] = new unsigned char *[width];
        for (int j = 0; j <width ; ++j) {
            slices[i][j]= oldVolImage.slices[i][j];
        }
    }
}

void VolImage::export_images(std::string out) {

    std::cout << "now exporting\n";

    ofstream header_fs("data_out/" + out + ".data");
    header_fs << width << " " << height << " " << numm;
    header_fs.close();

    for (int n = 0; n < numm; ++n) {
        std::cout << "image number " + std::to_string(n) << std::endl;
        ofstream image_fs("data_out/" + out + std::to_string(n) + ".raw", ios::out | ios::binary);
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                image_fs << slices[n][i][j];
            }
        }
        image_fs.close();
    }
}
