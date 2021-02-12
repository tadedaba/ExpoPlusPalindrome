#include <iostream>
#include <fstream>
using namespace std;

// Define a constant for the number of lines to read
#define NUM_READ_LINES 4

int main() {
	// Array of line numbers each line being no more than 100 chars
	char thearray[NUM_READ_LINES][100];
	int counter = 0;

	// Open our file
	ifstream inFile("C:\\Users\\Taddie\\file.dat",ifstream::in);

	// If we can read/write great
	if (inFile.good()) {

		// Read throuthe file and load into array
		while (!inFile.eof() && (counter < NUM_READ_LINES) {
			inFile.getline(thearray[counter],100);
			counter++;
		}

		// Loop through the array which we just put together
		for (int i = 0; i < counter; i++) {
			cout << thearray[i] << endl;
		}
	}

	inFile.close();	

	return 0;
}
