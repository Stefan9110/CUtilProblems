#ifndef PROBLBAC_FILEAPI_H
#define PROBLBAC_FILEAPI_H

#define STRING_BUFFER 2048

#include <fstream>
#include <cstring>

using namespace std;

ifstream file_in;
ofstream file_out;
bool initialised = false;
const char *input_folder = "";

void initialiseFiles(const char *in, const char *out) {
    file_in.open((new string())->append(input_folder).append(in).c_str());
    file_out.open((new string())->append(input_folder).append(out).c_str());
    initialised = true;
}

void initialiseFiles(const char *name) {
    initialiseFiles((new string(name))->append(".in").c_str(), (new string(name))->append(".out").c_str());
}

void setInputFolder(const char *input) {
    input_folder = input;
}

void closeFiles() {
    if (!initialised) return;
    file_in.close();
    file_out.close();
    initialised = false;
}

char *readFromFile() {
    if (!initialised) return nullptr;
    char *arr = new char[STRING_BUFFER];
    file_in.getline(arr, STRING_BUFFER);
    return arr;
}

template<class T>
T readFromFile() {
    T result;
    file_in >> result;
    return result;
}

template<class T>
void writeToFile(T obj) {
    if (!initialised) return;
    file_out << obj;
}

void writeToFile(char *arr) {
    if (!initialised) return;
    file_out << arr;
}

#endif
