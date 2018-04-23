//
// Created by thamian on 10.06.17.
//

#include "File.h"

void File::load(std::string path) {
    fstream.close();
    fstream.open(path);
}

bool File::isOpen() {
    return (bool) fstream;
}

void File::backToBeginning() {
    fstream.clear();
    fstream.seekg(0);
}

long File::getPosition() {
    return fstream.tellg();
}

int File::get() {
    int get;
    fstream >> get;
    return get;
}

void File::close() {
    fstream.close();
}
