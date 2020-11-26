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
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;


int main()
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  fstream fileStream;
  
  BinaryFileHeader binHeader;
  BinaryFileRecord binRecord;

  fileStream.open(BINARYFILE, ios::in | ios::binary);

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
  
   
  char* magicNumber = reinterpret_cast<char*>(&binHeader.magicNumber);
  int size = sizeof(binHeader.magicNumber);
  fileStream.read(magicNumber, size);
  
  char* versionNumber = reinterpret_cast<char*>(&binHeader.versionNumber);
  size = sizeof(binHeader.versionNumber);
  fileStream.read(versionNumber, size);

  char* numRecords = reinterpret_cast<char*>(&binHeader.numRecords);
  size = sizeof(binHeader.numRecords);
  fileStream.read(numRecords, size);
  

  string magic = createTag(binHeader, "magic");
  string version = createTag(binHeader, "version");
  string records = createTag(binHeader, "records");
  stringstream stream;
  int numOfRecords = 0;
  stream << size;
  stream >> numOfRecords;
 
  setCDKMatrixCell(myMatrix, 1, 1, magic.c_str());
  setCDKMatrixCell(myMatrix, 1, 2, version.c_str());
  setCDKMatrixCell(myMatrix, 1, 3, records.c_str());
  int count = 0;
  while(count < numOfRecords)
    {
      ostringstream myStream;
      int size = sizeof(binRecord);
      fileStream.read(reinterpret_cast<char*>(&binRecord), size);
      
      
      string length = writeOut(binRecord, "length");
      string buffer = writeOut(binRecord, "buffer");
      
      setCDKMatrixCell(myMatrix, count+2, 1, length.c_str());
      setCDKMatrixCell(myMatrix, count+2, 2, buffer.c_str());  
      count++;
    }


  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  /*
   * Dipslay a message
   */
 
  drawCDKMatrix(myMatrix, true);    /* required  */

  /* so we can see results */
  sleep (10);


  // Cleanup screen
  endCDK();
}
