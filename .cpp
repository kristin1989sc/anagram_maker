#include "AnagramMaker.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
using namespace std;

AnagramMaker::AnagramMaker(const string &dictionaryFile){
	string line;
	ifstream myfile (dictionaryFile);
	if (myfile.is_open()){
		while(!myfile.eof()){
			getline(myfile,line);
			gram dicwordformat(line.length(), line);
			wordVec.push_back(dicwordformat);
		}
		myfile.close();
	}
}

unsigned int AnagramMaker::findAnagrams(const string &input, const bool &print) const{
	gram inputStruct (input.length(), input);
	int num = SubPrint("", inputStruct,  wordVec.begin(), print);
	return num;
}

bool AnagramMaker::lessThan(const gram &Inputstruct, const gram &it) const{
	for(int i=0;i<26;i++){
		if(it.letters[i] > Inputstruct.letters[i]){return false;}
	}
	return true;
}

unsigned int AnagramMaker::SubPrint(const string &SOFAR, const gram &Inputstruct, const vector<gram>::const_iterator &myIt, const bool &print) const{
	vector<gram>::const_iterator it;
	it=myIt;
	gram update;
	unsigned int counter = 0;
	
	while(it!=wordVec.end()){ // looping through the dictionary

		if(lessThan(Inputstruct, *it)){ // if you can subtract the two words then do this

			for(unsigned int i=0; i <26;i++){ // update the counts and then set my new remaining input 
				update.count=Inputstruct.count - it->count;
				update.letters[i] = Inputstruct.letters[i]- it->letters[i]; // the actual subtraction
			}

			if(update.count!=0){
				counter = counter + SubPrint (SOFAR + " " + it->word, update, it, print); // keep going
			}
			else {
				counter++;
				if(print){
					cout << SOFAR +" " + it->word << endl;
				}
			}
		}
		it++;
	}
	return counter;
}
