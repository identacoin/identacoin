#include "enc.h"

#ifndef __IC_EPHEMERAL_KEY__
#define __IC_EPHEMERAL_KEY__

class EphemeralKey {

    private: 
        CryptoPP::SecByteBlock key;
        CryptoPP::SecByteBlock iv;

    public:
        EphemeralKey();

        CryptoPP::SecByteBlock getKey();
        CryptoPP::SecByteBlock getIV();

};

#endif