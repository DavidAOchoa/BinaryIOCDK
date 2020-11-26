/*
 * Filename:            cdk.cc
 * Date:                11/25/2020
 * Author:              David Ochoa
 * Email:               dao170000@utdallas.edu
 * Version:             1.0
 * Copyright:           2020, All Rights Reserved
 *
 * Description:
 *
 *      Build and display a small text based GUI matrix using curses
 *      and the CDK.
 */

#include "header.h"

void setArgs(fstream fileStream, BinaryFileHeader binHeader)
{
  char* magicNumber = reinterpret_cast<char*>(&binHeader.magicNumber);
  int size = sizeof(binHeader.magicNumber);
  fileStream.read(magicNumber, size);

  char* versionNumber = reinterpret_cast<char*>(&binHeader.versionNumber);
  size = sizeof(binHeader.versionNumber);
  fileStream.read(versionNumber, size);

  char* numRecords = reinterpret_cast<char*>(&binHeader.numRecords);
  size = sizeof(binHeader.numRecords);
  fileStream.read(numRecords, size);

}

string createTag(BinaryFileHeader binHeader, string arg)
{
  ostringstream stringstream;
  stringstream.str("");
  if (arg == "magic")
    {
      string magic;
      stringstream << std::hex << binHeader.magicNumber;
      magic = "Magic: 0x" + boost::to_upper_copy<std::string>(stringstream.str());
      return magic;
    }
  else if (arg == "version")
    {
      string version;
      stringstream << std::dec << binHeader.versionNumber;
      version = "Version: " + stringstream.str();
      return version;
    }
  else if (arg == "records")
    {
      string records;
      stringstream << std::dec << binHeader.numRecords;
      records = "Records: " + stringstream.str();
      return records;
    }
  return "void";
}

string writeOut(BinaryFileRecord binRecord, string arg)
{
  ostringstream stringstream;
  if(arg == "length")
    {
      string length;
      stringstream << strlen(binRecord.stringBuffer);
      length = "strlen: " + stringstream.str();
      return length;
    }
  else if(arg == "buffer")
    {
      string buffer;
      stringstream << binRecord.stringBuffer;
      buffer = stringstream.str();
      return buffer;
    }
  return "void";
}
