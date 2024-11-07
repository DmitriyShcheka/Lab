/*

*/

#include "bmp_reader.h"
#include <iostream>

int main(int argc, char* argv[]) {
    // Check heving two arguments
    if (argc < 2) {
        std::cout << "Using: " << argv[0] << " <path to BMP file>" << "\n"; // If the file path is not specified
        return 0;
    }

    BMP_File* bmp_file = Load_BMP_File(argv[1]); // Create array for BMP imagine
    
    if (!bmp_file) {
        std::cerr << "Failed to load BMP file." << "\n";
        return -1;
    } else {
        std::cout << "BMP File read succesful." << "\n";
    }
    
    std::cout << "BMP file size:" << bmp_file->bmp_header.file_size << " byte" << "\n";
    std::cout << "First task completed: file size printed." << "\n";
    
    BMP_File* new_bmp_file_1 = flip_BMP_90_contra_clockwise(bmp_file);
    Save_BMP_File(new_bmp_file_1, "image_contra_clockwise.bmp"); // Save new file 1
    std::cout << "Second task completed: file flip contra clockwise." << "\n";
    Free_BMP_File(new_bmp_file_1);
    
    BMP_File* new_bmp_file_2 = flip_BMP_90_clockwise(bmp_file);
    Save_BMP_File(new_bmp_file_2, "image_clockwise.bmp"); // Save new file 2
    std::cout << "Third task completed: file flip clockwise." << "\n";
    Free_BMP_File(new_bmp_file_2);

    return 0;
}















