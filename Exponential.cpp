/*
This Program can perform the following tasks.
 1. It can calculate the power of any number raised to positive integers.
 	*** To chieve this the program requests the user to enter the base 
 	    number followed by another request to enter a non-negative intiger.
 	    if the user enters a negative integer, the program anounces it and exit.
 	    the program also consider 0 to the power of zero is undefined. ***
 2. It can receive a character from the user, serach a file for the presence of 
 	an alphanumeric character, and display a message 
 	whether the character is found in the file or not. The program will not 
 	search and return the right output if the user enter a string. 
 	*** If the user enter a string, the program may run or crush but will not work
 	    correctly. At times, it may search the array for the first character in the
 	    string and return the result. ***
 3. It can accept a word or phrase with number of characters not exceeding 80
 	convert the all the characters to lower case, remove all the whitespaces 
 	from the words entered, and tell whether the word(s) is a palindrome or not.
 	*** If the user enters a non-alphabetic characters, the program may output
 		an unexpected result. The program is designed to work correctly with 
 		alphabetic characters. ***
 	NOTE: to make running the program convinient for the user, the program uses infinite
		  loop with switch() statment. The user can choose what to perform next. If the user 
		  wishes to exit, an exit condition is specified.  
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;
#define MAX 100
#define MAXLEN 80

double exp (double, int);		//function prototype for power computation.

//class for the character search in a file.
class FileStream{
	int i , count;			//integer variables for looping operation. 
	char array[MAX];		//array to hold the characters read from the file. 
	char a[MAX];			//array to hold characters for character counting.
	public:
		void readFile(char [], int);			//function prototype for file reading.
		int getnumOfChars(int);					//function prototype for chars counting.
		bool present(char [], int, int, char);	//function prototype for recursive search.
};
//class to perform palindrome operation.
class Palindrome{
	
	char charArr[MAXLEN];	//array to hold the texts entered by the user.
	char arrayToLower[MAXLEN]; // array to hold chars converted to lower case. 
	char whiteSpaceRemoved[MAXLEN];	//an array to hold the characters without white spaces.
	int len, n, m, i, t;
	public:
		//Function prototype definition
		void getPalindrome (char [], int, char); 	//gets the characters entered by the user
		void toLowerCase(char [], int);	//to convert all the characters to lowercase. 
		void removeWhiteSpaces(char [], int);	//performs the removal of white spaces.
		int getHigh(char [], int);	//gets the size of array.
		bool compare( char [], int, int);	// compares the unreversed charachters to its counterpart.
};
int main(int argc, const char * argv[]){
	char array[MAX], arr[MAXLEN];
	char ch;
	int num, choice, high;
	double x, result;
	bool found, out;
	
	FileStream f;	//object for the class FileStream.
	Palindrome pal;	// object for the class Palindrome.
	//lists of available choices.
	cout << " Choose an action to perform from the list below" <<endl;
	cout << " Enter the number of your choice:" <<endl;
	cout << " =================================" << endl;
	cout << "  1. Compute power of a number.\n"
		 << "  2. Search a character in an array.\n"
		 << "  3. Check if a word is a Palindrome.\n"
		 << "  4. Exit the program.\n";
	cout << " =================================" << endl;
	cin >> choice;
	while(choice){	//loop while the user is entering a choice. 
		switch(choice){
			case 1:
				cout << " Enter the base number: ";
				cin >> x;
				cout << " Now enter a nonnegative integer exponent(power):";
				cin >> num;
				if(x == 0 && num == 0)	// zero to the power of zero is undefined
					cout << " Zero to the power of itself is undefined."<<endl;
				else if (num < 0){		//The program work for posetive exp only.
					cout << " The exponent cannot be a negative number."<< endl;
					cout << " Please try again by running the program." << endl;
					cout << " =======================================" << endl;
				}
				else{
					result = exp(x, num);	// function call
					cout << " "<< x << " to the power of "<< num <<" is "<< result<<endl;
				}
				break;
			case 2:
				cout << " Enter the character you want to search: ";
				cin >> ch;
				f.readFile(arr, MAX);
				num = f.getnumOfChars(num)-1;	// array size.
				found = f.present(array, 0, num, ch); // result of recursion function.  
				if(found == true){
					cout << " ==============================================="<< endl;
					cout << " Character " << ch << " present in the array" << endl;
				}
				else{
					cout << " ==============================================="<< endl;
					cout << " Character " << ch << " not found in the array" << endl;
				}
				break;
			case 3:
				pal.getPalindrome(arr, MAXLEN, ch); //call the function to get chars from users.
				pal.toLowerCase(arr, MAXLEN);		//convert chars to lower case.
				pal.removeWhiteSpaces(arr, MAXLEN); // remove whitespaces from the chars
	
				high = pal.getHigh(arr, MAXLEN)- 1;   //array size
				//compare the characters with its counterpart and return true or false.  
				
    			if(high > MAXLEN){
					cout << " ====================================================" << endl;	
    				cout << " Word length (phrase) cannot be more than 80 characters." << endl;
    				cout << " Please run the program with appropariate word length." << endl;
				}
				else{
					out = pal.compare(arr, 0, high); //recursive comparison output
					if(out == true){
						cout << " ====================================" << endl;
    					cout << " The word you entered is a palindrome" << endl;
					}
					else{
						cout << " ========================================" << endl;
    					cout << " The word you entered is not a palindrome" << endl;
					}
    			}
    			break;
    		default:
    			cout << " Thank you!\nSee you next time" << endl;
    			exit(0);
		}
		cout << " \nEnter the number of your choice:" <<endl;
		cout << " =================================" << endl;
		cout << "  1. Compute power of a number.\n"
			 << "  2. Search a character in an array.\n"
			 << "  3. Check if a word is a Palindrome.\n"
			 << "  4. Exit the program.\n";
		cout << " =================================" << endl;
		cin >> choice;
	}
	return 0;
}
// function to perform power operation.
double exp (double x, int n){
	if(x == 0)
		return 0;
	else if(n == 0)
		return 1;
	else 
		return x * exp(x, n-1);
}
//function to read the characters from file.
void FileStream::readFile(char array[], int n){
	int count;
	char ch;
	ifstream file("C:\\Users\\taded\\file.dat");
	if (!file)
		cout << " File not found!" << endl;
	else{
		count = 0;
		while (!file.eof()){
			file.get(ch);
			array[count] = ch;
			count++;
		}
		array[count-1] = '\0';
		file.close();
		cout << " The following characters are read from the file." <<endl;
		cout << " ===============================================" << endl;
		cout << array << endl;
	}	
}
//function to count the characters in the file
int FileStream::getnumOfChars(int num){
	int count;
	char ch;
	ifstream file("C:\\Users\\taded\\file.dat");
	if (!file)
		cout << " File not found!" << endl;
	else{
		count = 0;
		while (!file.eof()){
			file.get(ch);
			array[count] = ch;
			count++;
		}
		array[count-1] = '\0';
		file.close();
	return count;
	}
}
//function to perform recursive search.
bool FileStream::present(char a[], int low, int high, char k){
	a = array;
	//cout << "\n" << a << endl;
	if(low > high)		//file has one character only.
		return false;
	else if((a[low] == k) || (a[high] == k))
		return true;
	else
		return present(a, low+1, high-1, k);
}
//function to get characters from the user
void Palindrome::getPalindrome(char charArr [], int, char ch){
	i = 0;
	cout << " Enter a word or a phrase." << endl;
	cout << " ========================" << endl;
    cin.get();	// to get each characters one at a time.
    ch = cin.get();
    while(ch != '\n'){	//check if loop reached the end of the texts entered. 
        charArr[i] = ch;
        i++;
        ch = cin.get();
    }
    charArr[i] = '\0';
    len = i;	//get the total number of character input.
    cout << " ====================================" << endl;
    cout << " The word you entered is:\n" << charArr << endl;
}
//This function converts all upper case letters to lower case. 
void Palindrome::toLowerCase(char charArr[], int){
	for(n = 0; n < strlen(charArr); n++){
		arrayToLower[n] = tolower(charArr[n]);
	}
	arrayToLower[n] = '\0';
}
//This function removes all the white spaces from the string.
void Palindrome::removeWhiteSpaces(char charArr[], int){
	charArr = arrayToLower;
	m = 0;
	for (n = 0; charArr[n]; n++){
		if (charArr[n] != ' ') 
            whiteSpaceRemoved[m++] = charArr[n]; 
	}
	whiteSpaceRemoved[m] = '\0'; 
    cout << " The word after all the whitespaces removed is:\n" << whiteSpaceRemoved << endl;
}
int Palindrome::getHigh(char a [], int high){
	a = whiteSpaceRemoved;
	for (i = 0; a[i]; i++)
		a[i] = whiteSpaceRemoved[i];
	high = i;
	return high;
}
bool Palindrome::compare(char arr[], int low, int high){
	arr = whiteSpaceRemoved;
	if(low == high){
		return true;
	}
	else{
		if(arr[low] != arr[high])
			return false;
		else 
			return compare(arr, low+1, high-1);
		}
}
