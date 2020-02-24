//
// Created by User on 2020-02-20.
//

#ifndef CPPASS2_MAIN_H
#define CPPASS2_MAIN_H

#include "volimage.h"

namespace ZMMALE001 {
    void processEverything(VolImage &images);
    void extractImage(char* &imageNum, char* &output_name, VolImage &images);
    void diffImage(char* &i, char* &j, char* &output_name, VolImage &images);
}
#endif //CPPASS2_MAIN_H
