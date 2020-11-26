/*
 * Filename:            cdkexample.cc
 * Date:                11/08/2020
 * Author:              Stephen Perkins
 * Email:               stephen.perkins@utdallas.edu
 * Version:             1.0
 * Copyright:           2020, All Rights Reserved
 *
 * Description:
 *
 *      Build and display a small text based GUI matrix using curses
 *      and the CDK.
 */

#include <iostream>
#include "cdk.h"
#include "header.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
/*
 * For grins and giggles, we will define values using the C
 * Preprocessor instead of C or C++ data types.  These symbols (and
 * their values) get inserted into the Preprocessor's symbol table.
 * The names are replaced by their values when seen later in the code.
 */

#define MATRIX_ROWS 5
#define MATRIX_COLS 3
#define BOX_WIDTH 25
#define MATRIX_NAME_STRING "Binary File CDK"

using namespace std;


int main()
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  fstream fileStream;
  
  BinaryFileHeader binHeader;
  //BinaryFileRecord binRecord;

  fileStream.open(BINARYFILE, ios::in | ios::binary);

  char* magicNumber = reinterpret_cast<char*>(&binHeader.magicNumber);
  int size = sizeof(binHeader.magicNumber);
  fileStream.read(magicNumber, size);
  
  char* versionNumber = reinterpret_cast<char*>(&binHeader.versionNumber);
  size = sizeof(binHeader.versionNumber);
  fileStream.read(versionNumber, size);

  char* numRecords = reinterpret_cast<char*>(&binHeader.numRecords);
  size = sizeof(binHeader.numRecords);
  fileStream.read(numRecords, size);

  if(fileStream.fail())
    {
      cerr << "error: file failed" << endl;
      return -1;
    }

  // CDK uses offset 1 and C/C++ use offset 0.  Therefore, we create one more 
  // slot than necessary and ignore the value at location 0.
  const char 		*rowTitles[MATRIX_ROWS+1] = {"IGNORE", "a", "b", "c", "d", "e"};
  const char 		*columnTitles[MATRIX_COLS+1] = {"IGNORE", "a", "b", "c"};
  int		colWidths[MATRIX_COLS+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_COLS+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
  */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_ROWS, MATRIX_COLS, MATRIX_ROWS, MATRIX_COLS,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, colWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }
  
  // put into helper function
  ostringstream stringstream;
  string magic;
  stringstream << std::hex << binHeader.magicNumber;
  magic = "Magic: 0x" + boost::to_upper_copy<std::string>(stringstream.str());

  string version;
  stringstream.str("");
  stringstream << std::dec << binHeader.versionNumber;
  version = "Version: " + stringstream.str();
  
  string records;
  stringstream.str("");
  stringstream << std::dec << binHeader.numRecords;
  records = "Records: " + stringstream.str();
  
  
 


  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  /*
   * Dipslay a message
   */
  setCDKMatrixCell(myMatrix, 1, 1, magic.c_str());
  setCDKMatrixCell(myMatrix, 1, 2, version.c_str());
  setCDKMatrixCell(myMatrix, 1, 3, records.c_str());
  drawCDKMatrix(myMatrix, true);    /* required  */

  /* so we can see results */
  sleep (10);


  // Cleanup screen
  endCDK();
}
