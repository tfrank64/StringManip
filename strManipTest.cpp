#include <iostream>
#include <string>
#include "strObj.h"

int main(){
	//Testing library contruction.
	strManip *lib;
	lib = strManip::getInstance();
	std::cout << "Address of instance of first library: " << lib << std::endl;
	strManip *lib2;
	lib2 = strManip::getInstance();
	std::cout << "Address of instance of second library: " << lib2 << std::endl;
	//Testing chomp.
	std::string x = "test\n"; 	
	std::string y = "te";//Substring to be removed.
	lib->chomp (x,y);
	lib->chomp (x);//Removing trailing endlines.
	std::cout << x  << std::endl;
	//Testing toSentence.
	std::string* list = new std::string[3];
	list[0] = "Milk";
	list[1] = "Cheese";
	list[2] = "Bacon";
	std::string mod = "or";
	std::cout << lib->toSentence (list, 3) << std::endl;
	std::cout << lib->toSentence (list, 3, mod) << std::endl;
	delete [] list;
	//Testing capitalize.
	std::string s = "hello, thIs Is A StRiNg.";
	std::cout << lib->capitalize(s) << std::endl;
}