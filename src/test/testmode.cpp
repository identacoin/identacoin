#include "testmode.h"
#include "../enc/ephemeralkey.h"
#include "../enc/ephencvalue.h"
#include <iostream>
#include <string>

#include "../util/random.h"

void Test::runTest()
{

    EphemeralKey ephKey;
    EphEncValue value(ephKey);

    CryptoPP::HexEncoder encoder(new CryptoPP::FileSink(std::cout));

    std::string plain = "rock";
    std::string cipher, recovered;

    std::cout << "plain text: " << plain << std::endl;

    cipher = value.setPlain(plain);

    std::cout << "key: ";
    encoder.Put(ephKey.getKey(), ephKey.getKey().size());
    encoder.MessageEnd();
    std::cout << std::endl;

    std::cout << "iv: ";
    encoder.Put(ephKey.getIV(), ephKey.getIV().size());
    encoder.MessageEnd();
    std::cout << std::endl;

    std::cout << "cipher text: ";
    encoder.Put((const byte *)&cipher[0], cipher.size());
    encoder.MessageEnd();
    std::cout << std::endl;

    recovered = value.setEncrypted(cipher);

    std::cout << "recovered text: " << recovered << std::endl;

    RandNum randN(3);

    std::cout << "random num: " << (randN.generate()) << std::endl;
    std::cout << "random num: " << randN.generate() << std::endl;
    std::cout << "random num: " << randN.generate() << std::endl;
 
}