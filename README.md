# CppAss2-Assignment2
***
Program has several functions in the arguments.
For example:
./volimage MRI
./volimage MRI -x 5 mri-x-out
./volimage MRI -g 51 mri-g-out 
./volimage MRI -d 2 51 mri-d-out
will perform the 3 functions (amount of images and bytes, extract, row selection, diffence)

## Files and Folders
* **main.cpp** - Driver class for the program. Checks for valid arguments and carries out necessary functions specified in the arguments.
* **volimage.cpp** - Implementation class for the volimage function.
* **/data**: Folder includes the raw images with the .data file. Files to be used by the program must be copied into this folder.
* **/data_out**: Folder where the out puts are stored after each proccess
