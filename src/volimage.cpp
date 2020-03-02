//
// Created by User on 2020-02-19.
//
#include <iostream>
#include <fstream>
#include "volimage.h"
#include <string>

using ZMMALE001::VolImage;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::vector;
using std::string;
using std::to_string;

bool VolImage::readImages(std::string baseName) {

    for (int n = 0; n < numm; ++n) {
//        cout << "image " + std::to_string(n) << endl;
        string fname  = "data/" + baseName + std::to_string(n) + ".raw";
        ifstream image_fs(fname, ios::binary);

        unsigned char** image = (unsigned char**) new char** [this->height];
        for (int i = 0; i < height; ++i) {
            image[i] = (unsigned char*) new char*[width];
            for (int j = 0; j < width; ++j) {
               image[i][j] = (unsigned char) char(image_fs.get());
                memory++;
            }
            memory+= sizeof(image[i]);
        }
        memory+= sizeof(image);
        slices.push_back(image);
        image_fs.close();
    }
    memory += sizeof(this->width) + sizeof(this->height);
//    std::cout << "done\n";
    return true;
}

VolImage::VolImage(char* baseName){
    slices = vector<unsigned char**>(0);
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
    for (int i = 0; i <slices.size() ; ++i) {
        for (int j = 0; j <height ; ++j) {
            for (int k = 0; k < width; ++k) {
                slices[i][j][k] = 0;
            }
            delete[] slices[i][j];
        }
        delete[] slices[i];
    }
    slices.clear();
}

void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix) {
    // file names
    string filename = "data_out/" +  output_prefix + ".raw", outDatName = "data_out/" + output_prefix + ".dat";
    // create the .dat file
    ofstream outDat(outDatName);
    outDat << to_string(width) + " " + to_string(height) + " 1" << endl;
    outDat.close();

    // create output file
    ofstream out(filename,  ios::binary);
    // find the difference and write to the file
    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            unsigned char c = (unsigned char)(abs((float)slices[sliceI][row][col] - (float)slices[sliceJ][row][col])/2);
            out.write((const char *) &c, sizeof(char));
        }
    }
    out.close();
}

void VolImage::extract(int sliceId, std::string output_prefix) {

    ofstream header_fs("data_out/" + output_prefix + ".data");
    header_fs << width << " " << height << " 1";
    header_fs.close();
    string filename = "data_out/" + output_prefix + ".raw";
    writeSlice(slices[sliceId], filename, width, height);
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

void VolImage::noargs() {
    cout << "Number of Images = ";
    cout << this->numm << endl;
    cout << "Number of bytes required = ";
    cout << this->memory << endl;

}

void VolImage::writeSlice(unsigned char ** slice, std::string fname, int w, int h) {
    ofstream out_fs(fname, ios::binary);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            out_fs.write((const char*) &slice[i][j], sizeof(char));
        }
    }
    out_fs.close();

}

void VolImage::gextract(int row, std::string output_prefix) {

    string filename = "data_out/" + output_prefix + ".raw", outDatName = "data_out/" + output_prefix + ".data";
    // create the .data file
    ofstream outDat(outDatName);
    outDat << to_string(width) + " " + to_string(slices.size()) + " 1" << endl;
    outDat.close();
    // create new slice
    unsigned char ** newSlice = new unsigned char *[width];
    // find the difference and store to a new 2d array
    for (int s = 0; s < slices.size(); s++){
        newSlice[s] = slices[s][row];
    }
    // write to the raw file
    writeSlice(newSlice, filename, width, numm);

    //clear memory used by newSlice
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++) newSlice[i][j] = 0;
        delete [] newSlice[i];
    }
    delete [] newSlice;
}
