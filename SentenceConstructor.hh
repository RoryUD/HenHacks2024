#ifndef SENTENCECONSTRUCTOR_HH
#define SENTENCECONSTRUCTOR_HH

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std; 

/*
 * To Do:
 * 		Break string into blocks
 * 		Make blocks be moveable (drag and drop)
 * 		Have word bank of moveable blocks
 * 		Create 10 ish sentences
 * 		Front end stuff 
 * 		
 *  	g++ main.cpp SentenceConstructor.hh -o main
 * 		main
 
all: main

main: SentenceConstructor.hh main.cpp
	g++ -std=c++11 main.cpp -o main

clean: 
	/bin/rm -rf *.o *~ main
 
 */

class WordBlock
{
public: 
	WordBlock(string, int);		//Constructors
	WordBlock(string); 			//
	void setContent(string);	//Getters and Setters
	void setPlaceOrder(int);
	string getContent();
	int getPlaceOrder();
	
private:
	int placeOrder;				//Where the block should be in the sentence
	string content;				//What sentence part / word the block contains
};
//Constructors
WordBlock::WordBlock(string sentence)
{
	content = sentence;
	placeOrder = -1;
}
WordBlock::WordBlock(string sentence, int order)
{
	content = sentence;
	placeOrder = order;
}
//Setters and Getters
void WordBlock::setContent(string sentence){ content = sentence;}
void WordBlock::setPlaceOrder(int num){ placeOrder = num;}
string WordBlock::getContent(){ return content;}
int WordBlock::getPlaceOrder(){ return placeOrder;}

class SentenceConstructor
{
public:
	SentenceConstructor(int); 	//Constructors
	void setSize(int);
	int getSize();
private:
	int size;					//How many blocks are in the sentence 
	vector<vector<WordBlock>> words;
};
//Constructors
SentenceConstructor::SentenceConstructor(int num)
{
	size = num;
	words = vector<vector<WordBlock>>(size);
}
//Setters and Getters
void SentenceConstructor::setSize(int num){ size = num;}
int SentenceConstructor::getSize(){ return size;}



#endif