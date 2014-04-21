#include <iostream>
#include <string>
#include <vector>

//Singleton Class StringManip - Library with helper functions that add functionality to String class.

class StringManip{
private:
	static bool instanceFlag; //Flag to check if an instance of the library is already created.
	static StringManip* single; //Address of the library instance, once created;
	StringManip(){}//Private Constructor
public:
	static StringManip* getInstance();//Function to create instance if it doesn't exist, else return address of instance.
	~StringManip(){}//Destructor 

	void chomp (std::string &str1);//A "Trim" function, removes trailing endline characters.
	void chomp (std::string &str1, std::string &sub);//A "Filter" function that filters substring from strings.

	std::string toSentence (std::string* strArray, int n);//Function that takes in a string array and outputs the elements in a sentence structure.
	std::string toSentence (std::string* strArray, int n, std::string modifier);//Function that takes in a string array and outputs the elements in a sentence structure, given a specific modifier.

	void toUpper(std::string& in);//Toupper function for strings, used in StringManip::capitalize.
	void toLower(std::string& in);//Tolower function for strings, used in StringManip::capitalize.
	std::string capitalize (std::string str1);//Given a string, capitalizes the first character lowercases everything else.

	std::string replaceOccurences(std::string completeString, const std::string oldStr, const std::string newStr);

	std::vector<std::string> explode(std::string completeString, std::string delim);
	std::string implode(std::vector<std::string> stringArray, std::string joiner);

	bool isURL(std::string url);
	std::string protocolInString(std::string url);

	int wordCount(std::string completeString);
	int wordCount(std::string completeString, std::string delim);
};

