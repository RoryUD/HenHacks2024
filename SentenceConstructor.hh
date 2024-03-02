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
	SentenceConstructor(); 			//Constructors
	void setSize(int);
	int getSize();
	void addBlock(WordBlock);		//Appends word
	string getSentenceAsString(); 	//Gets all blocks in a row as full sentence
	bool isInOrder();				//Validates the proper order 
	void swapBlocks(int, int);		//Swaps two blocks
private:
	int size;						//How many blocks are in the sentence 
	vector<WordBlock> words; 		//Vector array of blocks 
};
//Constructors
SentenceConstructor::SentenceConstructor()
{
	size = 0;
}
//Setters and Getters
void SentenceConstructor::setSize(int num){ size = num;}
int SentenceConstructor::getSize(){ return size;}
/* Adds word to end of sentece block, increases size by 1
 */
void SentenceConstructor::addBlock(WordBlock word)
{
	words.push_back(word);
	setSize(size+1);
}
/* Gets all the block parts into one full string
 * Adds a space in between each block
 */
string SentenceConstructor::getSentenceAsString()
{
	string fullSentence;
	for(int i = 0; i<size; i++)
	{
		fullSentence.append(words[i].getContent());
		fullSentence.append(" ");
	}
	fullSentence.pop_back();
	return fullSentence;
}
/* Validates all the blocks are in the right order
 * If sentence is empty, return true
 * Assumes first block is at 0
 */
bool SentenceConstructor::isInOrder()
{
	bool isInOrder = true;
	for(int i = 0; i<size; i++)
	{
		if(words[i].getPlaceOrder() != i)
		{
			isInOrder = false;
		}
	}
	return isInOrder;
}
/* Takes two block numbers and swaps their place 
 * Checks to make sure the numbers are different and the blocks exists
 */
void SentenceConstructor::swapBlocks(int blockOrderOne, int blockOrderTwo)
{
	int firstBlockLocation = -1;
	int secondBlockLocation = -1;
	//Gets the location of the two blocks in the array 
	for(int i = 0; i<size; i++)
	{
		if(words[i].getPlaceOrder() == blockOrderOne)
		{
			firstBlockLocation = i;
		}
		if(words[i].getPlaceOrder() == blockOrderTwo)
		{
			secondBlockLocation = i;
		}
	}
	//If given bad indexes, or the same index, do nothing 
	if(firstBlockLocation == secondBlockLocation || firstBlockLocation == -1 || secondBlockLocation == -1)
	{
		return;
	}
	//Swaps the blocks 
	WordBlock temp = words[firstBlockLocation];
	words[firstBlockLocation] = words[secondBlockLocation];
	words[secondBlockLocation] = temp;
}

#endif