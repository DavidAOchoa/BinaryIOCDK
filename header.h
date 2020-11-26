/*
 * Filename:            header.h
 * Date:                11/25/2020
 * Author:              David Ochoa
 * Email:               dao170000@utdallas.edu
 * Version:             1.0
 * Copyright:           2020, All Rights Reserved
 *
 * 
 */


#ifndef _PROGRAM6_
#define _PRGRAM6_


#include <iostream> 
#include <boost/lexical_cast.hpp> // for lexical_cast() 
#include <string> // for string 
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include "cdk.h"

#define BINARYFILE "/scratch/perkins/cs3377.bin"

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

string createTag(BinaryFileHeader, std::string);
string writeOut(BinaryFileRecord, std::string);

#endif /*_PROGRAM6_*/
