/************************************************/
/* StringIOStream.h, (c) BrothersCo             */
/************************************************/

#ifndef STRINGIOSTREAM_H
#define STRINGIOSTREAM_H

#include "IOStream.h"
#include <string>

class StringInputStream: public InputStream {
    std::string str;
    unsigned long string_pos;
public:
    StringInputStream(std::string str);
    ~StringInputStream();
    int get_char();
    long get_size();
};

class StringOutputStream: public OutputStream {
    std::string* str;
public:
    StringOutputStream(std::string* str);
    ~StringOutputStream();
    void put_char(int c);
    void flush();
};

#endif