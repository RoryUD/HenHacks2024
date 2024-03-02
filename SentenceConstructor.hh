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
 */

class SentenceConstructor
{
	
};

class WordBlock
{
public: 
	WordBlock(string, int);		//Full constructor 
	WordBlock(string); 			//Just sentence constructor 
	void setContent(string);
	void setPlaceOrder(int);
	string getContent();
	int getPlaceOrder();
	
private:
	int placeOrder;
	string content;
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

#endif