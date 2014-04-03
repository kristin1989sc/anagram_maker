#ifndef ANAGRAMMAKER_H
#define ANAGRAMMAKER_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

#include <fstream>
using namespace std;

class AnagramMaker {
public:
	AnagramMaker(const std::string &dictionaryFile);
	~AnagramMaker(){};
	unsigned int findAnagrams(const string &input, const bool &print) const;

private:

	struct gram{
		string word;
		int count;
		char letters[26];

		gram(int c, string w){
			count= c;
			word= w;

			for(int i=0;i<26;i++){// initiallizes each spot in the array to 0
				letters[i]= 0;
			}

			char length = word.length();
			for(int i=0; i<length;i++){ // increments the spots in the array for each letter
				char x= w[i];
				int index= x;
				index= index- 'a';
				letters[index]+= 1;
			}
		}
		gram(){}
	};
	vector<gram> wordVec;
	bool lessThan(const gram &Inputstruct, const gram &it) const;
	unsigned int SubPrint(const string &SOFAR, const gram &Inputstruct, const vector<gram>::const_iterator &myIt, const bool &print) const;
};

#endif
