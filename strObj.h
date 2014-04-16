#include <iostream>
#include <string>

//Singleton Class strManip - Library with helper functions that add functionality to String class.

class strManip{
private:
	static bool instanceFlag; //Flag to check if an instance of the library is already created.
	static strManip* single; //Address of the library instance, once created;
	strManip(){}//Private Constructor
public:
	static strManip* getInstance();//Function to create instance if it doesn't exist, else return address of instance.
	~strManip(){}//Destructor 
	void chomp (std::string &str1);//A "Trim" function, removes trailing endline characters.
	void chomp (std::string &str1, std::string &sub);//A "Filter" function that filters substring from strings.
	std::string toSentence (std::string* strArray, int n);//Function that takes in a string array and outputs the elements in a sentence structure.
	std::string toSentence (std::string* strArray, int n, std::string modifier);//Function that takes in a string array and outputs the elements in a sentence structure, given a specific modifier.
	void toUpper(std::string& in);//Toupper function for strings, used in strManip::capitalize.
	void toLower(std::string& in);//Tolower function for strings, used in strManip::capitalize.
	std::string capitalize (std::string str1);//Given a string, capitalizes the first character lowercases everything else.
};

