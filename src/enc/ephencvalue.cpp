#include "ephencvalue.h"

EphEncValue::EphEncValue(EphemeralKey key)
{
    this->key = key;
    this->e.SetKeyWithIV(key.getKey(), key.getKey().size(), key.getIV());
    this->d.SetKeyWithIV(key.getKey(), key.getKey().size(), key.getIV());
}

void EphEncValue::encrypt() 
{
    CryptoPP::StringSource s(this->plain, true,
                   new CryptoPP::StreamTransformationFilter(this->e,
                                                  new CryptoPP::StringSink(this->encrypted)) // StreamTransformationFilter
    );
}

void EphEncValue::decrypt()
{

    CryptoPP::StringSource s2(this->encrypted, true,
                    new CryptoPP::StreamTransformationFilter(this->d,
                                                   new CryptoPP::StringSink(this->plain)) // StreamTransformationFilter
    );
}

std::string EphEncValue::setPlain(std::string plainText)
{
    this->plain = plainText;
    this->encrypted = std::string();
    this->encrypt();
    return this->getEncrypted();
}

std::string EphEncValue::setEncrypted(std::string encText)
{
    this->encrypted = encText;
    this->plain = std::string();
    this->decrypt();
    return this->getPlain();
}

std::string EphEncValue::getPlain()
{
    return this->plain;
}

std::string EphEncValue::getEncrypted()
{
    return this->encrypted;
}
