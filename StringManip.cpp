#include <iostream>
#include "StringManip.h"

//Flag to check if an instance of the library is already created.
bool StringManip::instanceFlag = false;

//Address of the library instance, once created;
StringManip* StringManip::single = NULL;

//Function to create instance if it doesn't exist, else return address of instance.
StringManip* StringManip::getInstance() {
    if(!instanceFlag)
    {
        single = new StringManip(); //Creaing new and only instance.
        instanceFlag = true;
        return single;
    }
    else
    {
        return single; //Returning address of existing instance.
    }
}

/* StringManip Library Methods */

//A "Trim" function, removes trailing endline characters.
void StringManip::chomp (std::string &str1) {
std::string::size_type pos = str1.find_last_not_of("\n \t");
if(pos != std::string::npos)
  str1 = str1.substr(0, pos+1);
}

//A "Filter" function that filters substring from strings.
void StringManip::chomp (std::string &str1, std::string &sub) {
std::string final = "";
unsigned pos = str1.find(sub);
int n = 0;
while (n != pos)
	final += str1[n];
n += sub.length();
std::string string2 = str1.substr(n);
str1 = final + string2;
}

//Function that takes in a string array and outputs the elements in a sentence structure.
std::string StringManip::toSentence (std::string* strArray, int n) {
std::string final = "";
for (int i = 0; i < n-1; i++)
	final += strArray[i] + ", ";	
final += "and " + strArray[n-1]; //Appends "and" + last element to final string.
return final;
}

//Function that takes in a string array and outputs the elements in a sentence structure, given a specific modifer.
std::string StringManip::toSentence (std::string* strArray, int n, std::string modifier) {
std::string final = "";
for (int i = 0; i < n-1; i++)
	final += strArray[i] + ", ";	
final += modifier + " " + strArray[n-1]; //Appends specified modifier + last element to final string.
return final;
}

//Toupper function for strings, used in StringManip::capitalize.
void StringManip::toUpper(std::string& in) {
	int i=0;
	char c;
	while (in[i]){
		c=in[i];
		c=toupper(c);
		in[i]=c;
		i++;
	}
}

//Tolower function for strings, used in StringManip::capitalize.
void StringManip::toLower(std::string& in) {
	int i=0;
	char c;
	while (in[i]){
		c=in[i];
		c=tolower(c);
		in[i]=c;
		i++;
	}
}

//Given a string, capitalizes the first character lowercases everything else.
std::string StringManip::capitalize (std::string str1) {
	std::string head, tail;
	head = str1[0];
	tail = (str1.substr(1,std::string::npos));
	toUpper(head);
	toLower(tail);
	std::string final = head + tail;
	return final;
}

// Given three strings, we replace all occurences of oldStr with newStr and return the modified version
std::string StringManip::replaceOccurences(std::string completeString, const std::string oldStr, const std::string newStr) {
    size_t pos = 0;
    while((pos = completeString.find(oldStr, pos)) != std::string::npos)
    {
        completeString.replace(pos, oldStr.length(), newStr);
        pos += newStr.length();
    }
    return completeString;
}

// Given a string, we create a vector array of strings using the passed in delimeter
std::vector<std::string> StringManip::SeparateComponentsBy(std::string completeString, std::string delim) {
	std::vector<std::string> components;
    std::string token;
    size_t pos = 0;
    
    while ((pos = completeString.find(delim)) != std::string::npos)
    {
        token = completeString.substr(0, pos);
        components.push_back(token);
        completeString.erase(0, pos + delim.length());
    }
    
    components.push_back(completeString);
    return components;
}

// Validates if passed in string is some sort of URL
bool StringManip::isURL(std::string url) {
	std::string::size_type pos = url.find("://");
    if (pos != std::string::npos)
    	return true;
    return false;
}

// Returns the protocol (eg. https) for passed in, valid URL
std::string StringManip::protocolInString(std::string url) {
    std::string::size_type pos = url.find("://");
    if (pos != std::string::npos)
    {
        std::string protocol = url.substr(0, pos);
        return protocol;
    }
    return "";
}