#ifndef _PROGRAM6_
#define _PRGRAM6_


#include<iostream> 
#include <boost/lexical_cast.hpp> // for lexical_cast() 
#include <string> // for string 
#include <fstream>
#include "cdk.h"

#define BINARYFILE = "cs3377.bin"

using namespace std;
const int maxRecordStringLength = 25;


class BinaryFileHeader {

 public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
  
};

class BinaryFileRecord {

 public:
  uint8_t strLength;
  char stringBuffer[maxRecordStringLength];

};



#endif /*_PROGRAM6_*/
