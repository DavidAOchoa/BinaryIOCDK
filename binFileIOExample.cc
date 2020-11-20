/*
 * File:   	      	binFileIOExample.cc
 * Date:                11/16/2020
 * Author:              Stephen Perkins
 * Email:               stephen.perkins@utdallas.edu
 * Version:             1.0
 * Copyright:           2020, All Rights Reserved
 *
 * Description:
 *
 *  	Tiny project to Perform Binary File IO and display results
 */

/*

 * Author: Stephen Perkins
 * Email:  stephen.perkins@utdallas.edu
 *

 */


#include <iostream>
#include <fstream>
#include <cstring> 	// for memset()

/*
 *  This header file described here:  http://www.cplusplus.com/reference/cstdint/
 *  REQUIRES C++ Version 11 comiler support (-std=c++11).
 */

#include <cstdint>

using namespace std;

//
// Record with fields

class BinaryFileRecord
{
public:
  uint8_t 	mysmall_unsigned_8bit;
  char		someLetter_char;
  uint64_t	mylarge_unsigned_64bit;
};	

/*


  ofstream binOutfile;
  ifstream binInfile;
  
  cout << endl;
  cout << "Max value of data type uint8_t is: " << UINT8_MAX << endl;
  cout << "Max value of data type uint64_t is: " << UINT64_MAX << endl;
  cout << endl;

  BinaryFileRecord *myRecord = new BinaryFileRecord();

  // Fill with junk values

  myRecord->mysmall_unsigned_8bit = 255;     		// Hex value:  0xFF

  myRecord->someLetter_char = 'Z';			// Ascii value as Hex: 0x5A

  myRecord->mylarge_unsigned_64bit = 0xDEADBEEF;	// Hex format

  // Write out this single record
  cout << "Writing record to file: binaryfile.bin" << endl;

  binOutfile.open("binaryfile.bin", ios::out | ios::binary);

  // should check for errors here.  Keeping it simple...

  binOutfile.write((char *) myRecord, sizeof(BinaryFileRecord));

  // Done... clean up
  binOutfile.close();
  cout << "Finished writing record to file: binaryfile.bin" << endl;
  cout << endl;

  // Stop and view this file with the 'hexdump' utility.  Try to understand
  // why bytes are not in the order you might expect.

  // Just to prove it works... clear the record
  cout << "Clearing the Record to prove Read works" << endl;
  cout << endl;
  memset(myRecord, 0, sizeof(BinaryFileRecord));

  // Read in the single record
  cout << "Reading record to file: binaryfile.bin" << endl;

  binInfile.open ("binaryfile.bin", ios::in | ios::binary);

  // should check for errors here.  Keeping it simple...

  binInfile.read((char *) myRecord, sizeof(BinaryFileRecord));

  // Done... clean up
  binInfile.close();
  cout << "Finished reading record to file: binaryfile.bin" << endl;
  cout << endl;

  // Display Results
  cout << "Displaying Results with no extra formatting" << endl;
  cout << endl;
  cout << "mysmall_unsigned_8bit: |" << myRecord->mysmall_unsigned_8bit << "|" << endl;
  cout << "someLetter_char: |" << myRecord->someLetter_char << "|" << endl;
  cout << "mylarge_unsigned_64bit: |" << myRecord->mylarge_unsigned_64bit << "|" << endl;
  cout << endl;

  // Lets try better formatting
  cout << "Displaying Results with extra formatting" << endl;
  cout << endl;
  cout << "mysmall_unsigned_8bit: |" << unsigned(myRecord->mysmall_unsigned_8bit) << "|" << endl;
  cout << "someLetter_char: |" << myRecord->someLetter_char << "|" << endl;
  cout << "mylarge_unsigned_64bit: |0x" << std::hex << std::uppercase << myRecord->mylarge_unsigned_64bit << std::dec << std::nouppercase << "|" << endl;
  cout << endl;


  // Clean up and exit
  cout << "Done... cleaning up" << endl;
  delete myRecord;
*/
 
