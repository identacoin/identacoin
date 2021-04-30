#include "testmode.h"

#include "cryptopp/cryptlib.h"
#include "cryptopp/rijndael.h"
#include "cryptopp/modes.h"
#include "cryptopp/files.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hex.h"

#include <iostream>
#include <string>

void Test::runTest()
{

    using namespace CryptoPP;

    AutoSeededRandomPool prng;
    HexEncoder encoder(new FileSink(std::cout));

    SecByteBlock key(AES::DEFAULT_KEYLENGTH);
    SecByteBlock iv(AES::BLOCKSIZE);

    std::string s1("A16ByteString456");
    SecByteBlock b1((const byte*)s1.data(), s1.size());

    prng.GenerateBlock(key, key.size());
    prng.GenerateBlock(iv, iv.size());

    std::string plain = "rock";
    std::string cipher, recovered;

    std::cout << "plain text: " << plain << " : " << AES::DEFAULT_KEYLENGTH << std::endl;

    CBC_Mode<AES>::Encryption e;
    e.SetKeyWithIV(b1, b1.size(), iv);

   
    
        
       

        StringSource s(plain, true,
                       new StreamTransformationFilter(e,
                                                      new StringSink(cipher)) // StreamTransformationFilter
        );                                                                    // StringSource        

            

        std::cout << "key: ";
        encoder.Put(b1, b1.size());
        encoder.MessageEnd();
        std::cout << std::endl;

        std::cout << "iv: ";
        encoder.Put(iv, iv.size());
        encoder.MessageEnd();
        std::cout << std::endl;

        std::cout << "cipher text: ";
        encoder.Put((const byte *)&cipher[0], cipher.size());
        encoder.MessageEnd();
        std::cout << std::endl;

        CBC_Mode<AES>::Decryption d;
        d.SetKeyWithIV(b1, b1.size(), iv);

        StringSource s2(cipher, true,
                       new StreamTransformationFilter(d,
                                                      new StringSink(recovered)) // StreamTransformationFilter
        );                                                                       // StringSource

        std::cout << "recovered text: " << recovered << std::endl;
    /*
    catch (const Exception &e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }*/
}