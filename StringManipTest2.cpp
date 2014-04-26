#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include "StringManip.h"

int main(){
	//Testing library contruction.
	StringManip *lib;
	lib = StringManip::getInstance();
	std::cout << "Address of instance of first library: " << lib << std::endl;
	StringManip *lib2;
	lib2 = StringManip::getInstance();
	std::cout << "Address of instance of second library: " << lib2 << std::endl << std::endl;
	assert(lib == lib2);

	//while (true){
		int choice;
		std::cout << "Pick a function to be applied on your string." << std::endl;
		std::cout << "1.  chomp(string) " << std::endl;
		std::cout << "2.  chomp(string, substring) " << std::endl;
		std::cout << "3.  toSentence(array, size)" << std::endl;
		std::cout << "4.  toSentence(array, size, modifier)" << std::endl;
		std::cout << "5.  capitalize(string)" << std::endl;
		std::cout << "6.  replaceOccurences(string, oldString, current)" << std::endl;
		std::cout << "7.  explode(string, delimiter) & implode (stringArray, joiner)" << std::endl;
		//std::cout << "8.  implode(stringArray, joiner)" << std::endl;
		std::cout << "8.  isURL(string) & protocolInString(string)" << std::endl;
		//std::cout << "9.  protocolInString(string)" << std::endl;
		std::cout << "9.  wordCount(string, *optional* delimiter)" << std::endl;
		std::cout << "10. Quit" << std::endl;
		std::cout << std::endl;
		std::cout << "Your choice:" << std::endl;
		std::cin >> choice;
		switch (choice){
			case 1:
			{
				std::string x;
				std::cout << "Enter your string." << std::endl;
				std::cin >> x;
				lib -> chomp(x);
				std::cout << "Your chomped string is " << x << std::endl;
				break;
			}
			case 2:
			{
				std::string x;
				std::string y;
				std::cout << "Enter your string." << std::endl;
				std::cin >> x;
				std::cout << "Enter your substring to be removed." << std::endl;
				std::cin >> y;
				lib -> chomp(x,y);
				std::cout << "Your chomped string is " << x << std::endl;
				break;
			}
			case 3:
			{
				int size;
				std::cout << "Enter the size of your array." << std::endl;
				std::cin >> size;
				std::string* list = new std::string[size];
				std::cout << "Enter array elements." << std::endl;
				for (int i = 0; i < size; i++){
					std::string str;
					std::cout << i << ". ";
					std::cin >> str;
					list[i] = str;
				}
				std::cout << "Your sentence is: " << std::endl;
				std::cout << lib->toSentence (list, size) << std::endl;
				delete [] list;
				break;
			}
			case 4:
			{
				int size;
				std::cout << "Enter the size of your array." << std::endl;
				std::cin >> size;
				std::string* list = new std::string[size];
				std::cout << "Enter array elements." << std::endl;
				for (int i = 0; i < size; i++){
					std::string str;
					std::cout << i << ". ";
					std::cin >> str;
					list[i] = str;
				}
				std::string mod;
				std::cout << "Enter your custom sentence joiner." << std::endl;
				std::cin >> mod;
				std::cout << "Your sentence is: " << std::endl;
				std::cout << lib->toSentence (list, size, mod) << std::endl;
				delete [] list;
				break;
			}
			case 5:
			{
				//Having issues with getLine, program skips that line.
				std::string strX;
				std::cout << "Enter your string to be properly capitalized: " << std::endl;
				//std::getline(std::cin, strX);
				std::cin >> strX;
				std::cout << "Your capitalized string is: " << std::endl;
				std::cout << lib->capitalize(strX) << std::endl << std::endl;
				break;
			}
			case 6:
			{
				std::string final;
				std::string old;
				std::string current;
				std::cout << "Enter your base string." << std::endl;
				std::cin >> final;
				std::cout << "Enter the substring to be replace." << std::endl;
				std::cin >> old;
				std::cout << "Enter the substring to replace with." << std::endl;
				std::cin >> current;
				std::cout << "Your replaced string is:" << std::endl;
  				std::cout << lib->replaceOccurences(final, old, current) << std::endl;
				break;
			}
			case 7:
			{
				std::string delim;
				std::string str;
				std::cout << "Enter your delimiter." << std::endl;
				std::cin >> delim;
				std::cout << "Enter your base string." << std::endl;
				std::cin >> str;
				std::vector<std::string> test = lib->explode(str, delim);
				std::cout << "Your exploded string: " << std::endl;
				for(std::vector<std::string>::iterator it = test.begin(); it != test.end(); ++it) {
    				std::cout << *it << " ";
    			}
    			std::cout << std::endl << std::endl;
    			std::cout << "Implode Test" << std::endl;
    			std::string joiner;
    			std::cout << "Enter your joiner." << std::endl;
    			std::cin >> joiner;
    			std::cout << "Your imploded string: " << std::endl;
				std::cout << lib->implode(test, joiner) << std::endl;
				break;
			}
			case 8:
			{
				std::string theURL;
				std::cout << "Enter your string for URL check." << std::endl;
				std::cin >> theURL;
				if (lib -> isURL(theURL)){
					std::cout << "Your string is a valid URL." << std::endl;
					std::cout << "The protocol of the URL is " << lib -> protocolInString(theURL) << std::endl;
				}
				else
					std::cout <<"Your string is not a valid URL." << std::endl;
				break;
			}
			case 9:
			{
				std::string str = "Hello, this is a string.";
				std::cout << str << std::endl;
				std::cout << "The word count of the string is: " << lib -> wordCount(str) << std::endl;
				break;
			}
			
			case 10:
			{
				break;
			}
			default:
			{
				std::cout << "Please enter an integer from 1 to 10." << std::endl;
				break;
			}
		}
	//}
}