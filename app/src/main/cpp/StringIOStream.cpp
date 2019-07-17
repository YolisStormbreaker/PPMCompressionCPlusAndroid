/************************************************/
/* StringIOStream.cpp, (c) BrothersCo           */
/************************************************/

#include "StringIOStream.h"

StringInputStream::StringInputStream(std::string str) {
    this->str = str;
    this->string_pos = 0;
}

StringInputStream::~StringInputStream() {}

int StringInputStream::get_char() {
    if(string_pos < str.length()) {
        return str.at(string_pos++);
    } else {
        return EOF;
    }
}

long StringInputStream::get_size() {
    return (long) str.length();
}



StringOutputStream::StringOutputStream(std::string* str) {
    this->str = str;
}

StringOutputStream::~StringOutputStream() {
    flush();
}

void StringOutputStream::put_char(int c) {
    *str += (char) c;
}

void StringOutputStream::flush() {};