/************************************************/
/* PPM.h, (c) Rene Puchinger            */
/*                                              */
/* sample artihmetic compression program        */
/************************************************/

#ifndef PPM_H
#define PPM_H

#include "SimpleBitIOStream.h"
#include "StringIOStream.h"
#include "ARI.h"
#include <string>

class PPM {
	enum { ENCODE, DECODE, IDLE } state;
	ARI_encoder* enc;
	ARI_decoder* dec;
public:
	PPM();
	~PPM();
	std::string run(std::string option, std::string in);
};

#endif
