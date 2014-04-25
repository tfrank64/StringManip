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

	//Testing chomp.
	;std::string x = "test\n"; 	
	std::string y = "te";//Substring to be removed.
	lib->chomp (x,y);
	lib->chomp (x);//Removing trailing endlines.
	std::cout << x  << std::endl << std::endl;

	//Testing toSentence.
	std::string* list = new std::string[3];
	list[0] = "Milk";
	list[1] = "Cheese";
	list[2] = "Bacon";
	std::string mod = "or";
	std::cout << lib->toSentence (list, 3) << std::endl;
	std::cout << lib->toSentence (list, 3, mod) << std::endl << std::endl;
	delete [] list;

	//Testing capitalize.
	std::string s = "hello, thIs Is A StRiNg.";
	std::cout << lib->capitalize(s) << std::endl << std::endl;

	// Testing replaceing occurences of a word in a string
	std::string final = "beepfreepleepkeepmeeep";
	const std::string old = "ee";
	const std::string current = "?";
    std::cout << "replaceOccurences: " << lib->replaceOccurences(final, old, current) << std::endl << std::endl;

    // Testing separting string into an array
    std::vector<std::string> test = lib->explode("My,name,is,taylor", ",");
    for(std::vector<std::string>::iterator it = test.begin(); it != test.end(); ++it) {
    	std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "word count: " << lib->wordCount(s) << std::endl;
	std::cout << "imploded: " << lib->implode(test, "-") << std::endl;

	// Testing url validation methods
	std::string theURL = "https://docs.google.com/a/acu.edu/document/d/1q8Z_VAMSqz8pyo_jR0_hJXbIjgj-ZUKZXjarDbE_JBQ/edit";
	std::cout << "For this URL: " << theURL << std::endl;
	std::cout << "isURL Valid? " << lib->isURL(theURL) << std::endl;
	std::cout << "What is the protocol: " << lib->protocolInString(theURL) << std::endl;
}