#include "ephemeralkey.h"

EphemeralKey::EphemeralKey() {
    
    using namespace CryptoPP;

    AutoSeededRandomPool prng;

    this->key = SecByteBlock(AES::DEFAULT_KEYLENGTH);
    this->iv = SecByteBlock(AES::BLOCKSIZE);

    prng.GenerateBlock(this->key, this->key.size());
    prng.GenerateBlock(this->iv, this->iv.size());

}

CryptoPP::SecByteBlock EphemeralKey::getKey() {
    return this->key;
}

CryptoPP::SecByteBlock EphemeralKey::getIV() {
    return this->iv;
}
