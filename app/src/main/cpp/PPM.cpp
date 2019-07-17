/************************************************/
/* PPM.cpp, (c) Rene Puchinger          */
/************************************************/

#include "PPM.h"
#include <iostream>

PPM::PPM() {
    enc = NULL;  // encoder
    dec = NULL;  // decoder
    
    std::cout << "\nPPM implementation\n(c) 2007 Rene Puchinger\n\n";
}

std::string PPM::run(std::string option, std::string in) {
	if (option == "c") {
        enc = new ARI_encoder;
		std::string out = "";
		StringInputStream* sin = new StringInputStream(in);
		StringOutputStream* sout = new StringOutputStream(&out);
		SimpleBitOutputStream* bout = new SimpleBitOutputStream(sout);
		enc->encode(sin, bout);
		std::cout << "File compressed successfully." << std::endl;
		if (sin) delete sin;
		if (sout) delete sout;
		if (bout) delete bout;
		return out;
	} else if (option == "d") {
        dec = new ARI_decoder;
		std::string out = "";
		StringInputStream* sin = new StringInputStream(in);
		SimpleBitInputStream* bin = new SimpleBitInputStream(sin);
		StringOutputStream* sout = new StringOutputStream(&out);
		dec->decode(bin, sout);
		std::cout << "File decompressed successfully." << std::endl;
		if (sin) delete sin;
		if (bin) delete bin;
		if (sout) delete sout;
		return out;
	}
}

PPM::~PPM() {
	if (enc)
		delete enc;
	if (dec)
		delete dec;
}
