//
// Created by User on 2020-02-19.
//

#ifndef CPPASS2_VOLIMAGE_H
#define CPPASS2_VOLIMAGE_H

#include <vector>


class VolImage {
    private: // private members
        int width, height, numm; // width and height of image stack, and memory used in bytes.
        int memory;
        std::vector<unsigned char **> slices; // data for each slice, in order

    public: // public members
        VolImage(char* baseName); // default constructor - define in .cpp
        ~VolImage(); // destructor - define in .cpp file
        VolImage(const VolImage& oldVolImage);

        // populate the object with images in stack and
        // set member variables define in .cpp
        bool readImages(std::string baseName);

        // compute difference map and write out; define in .cpp
        void diffmap(int sliceI, int sliceJ, std::string output_prefix);

        // extract slice sliceId and write to output - define in .cpp
        void extract(int sliceId, std::string output_prefix);

        // number of bytes uses to store image data bytes //and pointers (ignore vector<> container, dims etc)
        int volImageSize(void); // define in .cpp

        void export_images(std::string out);
};

#endif //CPPASS2_VOLIMAGE_H
