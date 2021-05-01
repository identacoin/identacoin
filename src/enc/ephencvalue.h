#include "enc.h"
#include "ephemeralkey.h"
#include <string>

class EphEncValue {

    private:
        EphemeralKey key;
        std::string plain;
        std::string encrypted;
        CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption e;
        CryptoPP::CBC_Mode<CryptoPP::AES>::Decryption d;

        void encrypt();
        void decrypt();

    public: 
        EphEncValue(EphemeralKey key);
        std::string setPlain(std::string plainText);
        std::string setEncrypted(std::string encText);
        std::string getPlain();
        std::string getEncrypted();
};