#include <iostream>
#include "strObj.h"

//Flag to check if an instance of the library is already created.
bool strManip::instanceFlag = false;

//Address of the library instance, once created;
strManip* strManip::single = NULL;

//Function to create instance if it doesn't exist, else return address of instance.
strManip* strManip::getInstance(){
    if(!instanceFlag)
    {
        single = new strManip(); //Creaing new and only instance.
        instanceFlag = true;
        return single;
    }
    else
    {
        return single; //Returning address of existing instance.
    }
}

//A "Trim" function, removes trailing endline characters.
void strManip::chomp (std::string &str1){
std::string::size_type pos = str1.find_last_not_of("\n \t");
if(pos != std::string::npos)
  str1 = str1.substr(0, pos+1);
}

//A "Filter" function that filters substring from strings.
void strManip::chomp (std::string &str1, std::string &sub){
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
std::string strManip::toSentence (std::string* strArray, int n){
std::string final = "";
for (int i = 0; i < n-1; i++)
	final += strArray[i] + ", ";	
final += "and " + strArray[n-1]; //Appends "and" + last element to final string.
return final;
}

//Function that takes in a string array and outputs the elements in a sentence structure, given a specific modifer.
std::string strManip::toSentence (std::string* strArray, int n, std::string modifier){
std::string final = "";
for (int i = 0; i < n-1; i++)
	final += strArray[i] + ", ";	
final += modifier + " " + strArray[n-1]; //Appends specified modifier + last element to final string.
return final;
}

//Toupper function for strings, used in strManip::capitalize.
void strManip::toUpper(std::string& in){
	int i=0;
	char c;
	while (in[i]){
		c=in[i];
		c=toupper(c);
		in[i]=c;
		i++;
	}
}

//Tolower function for strings, used in strManip::capitalize.
void strManip::toLower(std::string& in){
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
std::string strManip::capitalize (std::string str1){
	std::string head, tail;
	head = str1[0];
	tail = (str1.substr(1,std::string::npos));
	toUpper(head);
	toLower(tail);
	std::string final = head + tail;
	return final;
}