//
// Created by thamian on 10.06.17.
//

#ifndef P3_FILE_H
#define P3_FILE_H


#include <fstream>

class File {
    std::fstream fstream;

public:
    void load(std::string path);
    void close();
    bool isOpen();
    void backToBeginning();
    long getPosition();
    int get();
};


#endif //P3_FILE_H
