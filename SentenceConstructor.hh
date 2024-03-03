#ifndef SENTENCECONSTRUCTOR_HH
#define SENTENCECONSTRUCTOR_HH

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std; 

/* 	To Do:
 * 	Back End:
 * 		Create around 5 sentences
 * 	Front End:
 * 		Make multiple drag / drop areas with corrosponding reset buttons  
 * 		Give guidance and example text before every widgit list 
 * 		Make it look pretty 
 * 	Compiler Call: 
 *  	g++ main.cpp SentenceConstructor.hh -o main
 * 		main
 */

class WordBlock
{
public: 
	WordBlock(string, int, int);//Constructors
	WordBlock(string, int);
	WordBlock(string); 			
	void setContent(string);	//Getters and Setters
	void setPlaceOrder(int);
	void setBadOkGood(int);
	string getContent();
	int getPlaceOrder();
	int getBadOkGood();
	
private:
	int placeOrder;				//Where the block should be in the sentence
	int badOkGood;				//0 = good, 1 = ok, 2 = bad
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
	badOkGood = -1;
}
WordBlock::WordBlock(string sentence, int order, int status)
{
	content = sentence;
	placeOrder = order;
	badOkGood = status;
}
//Setters and Getters
void WordBlock::setContent(string sentence){ content = sentence;}
void WordBlock::setPlaceOrder(int num){ placeOrder = num;}
void WordBlock::setBadOkGood(int num){ badOkGood = num;}
string WordBlock::getContent(){ return content;}
int WordBlock::getPlaceOrder(){ return placeOrder;}
int WordBlock::getBadOkGood(){ return badOkGood;}

class SentenceConstructor
{
public:
	SentenceConstructor(); 					//Constructors
	void setSize(int);						//Getters and Setters
	void setWordBankSize(int);
	int getSize();
	int getWordBankSize();
	WordBlock getWordAtIndex(int);			//Gets block at given index
	WordBlock getWordAtIndexInBank(int);	//Gets block at given index
	
	void addBlock(WordBlock);				//Appends wordBlock to the end
	void removeBlock(WordBlock); 			//Removes the given word block 
	void addBlockToBank(WordBlock); 		//Adds block to the word bank
	void removeBlockFromBank(WordBlock); 	//Removes block from the word bank
	void swapBlocks(int, int);				//Swaps two blocks in sentence
	void swapBlockFromBank(int, int);		//Swaps block from sentence and bank
	
	string getSentenceAsString(); 			//Gets all blocks in a row as full sentence
	string getWordBankAsString(); 			//Gets all word bank blocks numbered in string
	
	bool isInOrder();						//Validates the proper order 
	bool containedNoBad(); 					//Validates no words are bad 
	bool containedNoBadOrOk(); 				//Validates no words are bad or ok 
private:
	int size;								//How many blocks are in the sentence 
	vector<WordBlock> words; 				//Vector array of blocks 
	int wordBankSize;						//How many blocks are in the word bank 
	vector<WordBlock> wordBank; 			//Vector array of word bank blocks 
};
//Constructors
SentenceConstructor::SentenceConstructor()
{
	size = 0;
	wordBankSize = 0;
}
//Setters and Getters
void SentenceConstructor::setSize(int num){ size = num;}
void SentenceConstructor::setWordBankSize(int num){ wordBankSize = num;} 
int SentenceConstructor::getSize(){ return size;}
int SentenceConstructor::getWordBankSize(){ return wordBankSize;}
WordBlock SentenceConstructor::getWordAtIndex(int index) { return words[index];}
WordBlock SentenceConstructor::getWordAtIndexInBank(int index) { return wordBank[index];}

/* Adds word to end of sentece block, increases size by 1
 */
void SentenceConstructor::addBlock(WordBlock word)
{
	words.push_back(word);
	setSize(size+1);
}
/* Removes a given wordBlock and adds it to the word bank 
 * Compares based on the sentence content (make sure no duplicates when making blocks)
 */
void SentenceConstructor::removeBlock(WordBlock word)
{
	if(size <= 0)
	{
		return;
	}
	for(int i = 0; i<size; i++)
	{
		if(words[i].getContent() == word.getContent())
		{
			words.erase(words.begin()+i);
			setSize(size-1);
			addBlockToBank(word);
		}
	}
}
/* Adds word to end of Word Bank, increases size by 1
 */
void SentenceConstructor::addBlockToBank(WordBlock word)
{
	wordBank.push_back(word);
	setWordBankSize(wordBankSize+1);
}
/* Removes a word from the word bank
 * Reduces the word bank size by 1 as well
 */
void SentenceConstructor::removeBlockFromBank(WordBlock word)
{
	if(wordBankSize <= 0)
	{
		return;
	}
	for(int i = 0; i<wordBankSize; i++)
	{
		if(wordBank[i].getContent() == word.getContent())
		{
			wordBank.erase(wordBank.begin()+i);
			setWordBankSize(wordBankSize-1);
		}
	}
}
/* Takes the index of two blocks and swaps them
 */
void SentenceConstructor::swapBlocks(int blockOne, int blockTwo)
{
	//If given bad indexes, or the same index, do nothing 
	if(blockOne == blockTwo || blockOne >= size || blockTwo >= size || blockOne < 0 || blockTwo < 0)
	{
		return;
	}
	//Swaps the blocks 
	WordBlock temp = words[blockOne];
	words[blockOne] = words[blockTwo];
	words[blockTwo] = temp;
}
/* Swaps a block from sentence and from bank
 */
void SentenceConstructor::swapBlockFromBank(int sentenceLocation, int bankLocation)
{
	if(sentenceLocation >= size || bankLocation >= wordBankSize || bankLocation < 0 || sentenceLocation < 0)
	{
		return;
	}
	WordBlock temp = words[sentenceLocation];
	words[sentenceLocation] = wordBank[bankLocation];
	wordBank[bankLocation] = temp;
}

/* Gets all the block parts into one full string
 * Adds a space in between each block
 */
string SentenceConstructor::getSentenceAsString()
{
	if(size <= 0)
	{
		return "";
	}
	string fullSentence;
	for(int i = 0; i<size; i++)
	{
		fullSentence.append(words[i].getContent());
		fullSentence.append(" ");
	}
	fullSentence.pop_back();
	return fullSentence;
}
/* Gets the word bank as a string
 * Adds a space in between each word, and numbers the words
 */
string SentenceConstructor::getWordBankAsString()
{
	if(wordBankSize <= 0)
	{
		return "";
	}
	string fullSentence;
	for(int i = 0; i<wordBankSize; i++)
	{
		fullSentence.append(to_string(i)+". ");
		fullSentence.append(wordBank[i].getContent());
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
/* Checks that the sentence has no "bad" words 
 * bad means badOkGood = 0
 */
bool SentenceConstructor::containedNoBad()
{
	bool allNotBad = true;
	for(int i = 0; i<size; i++)
	{
		if(words[i].getBadOkGood() == 0)
		{
			allNotBad = false;
		}
	}
	return allNotBad;
}
/* Checks that the sentence has no "bad" or "ok" words 
 * bad means badOkGood = 0, ok means badOkGood = 1
 */
bool SentenceConstructor::containedNoBadOrOk()
{
	bool allNotBadOrOk = true;
	for(int i = 0; i<size; i++)
	{
		if(words[i].getBadOkGood() == 0 || words[i].getBadOkGood() == 1)
		{
			allNotBadOrOk = false;
		}
	}
	return allNotBadOrOk;
}

#endif