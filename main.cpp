#include <iostream>
#include <cstdlib>
#include "SentenceConstructor.hh"

using namespace std;

int main(int argc, char* argv[])
{
	//Test Blocks
	/*
	WordBlock test0 = WordBlock("A",0);
	WordBlock test1 = WordBlock("B",1);
	WordBlock test2 = WordBlock("C",2);
	WordBlock test3 = WordBlock("D",3);
	WordBlock test4 = WordBlock("E",4);
	SentenceConstructor testSentence1 = SentenceConstructor();
	testSentence1.addBlock(test0);
	testSentence1.addBlock(test1);
	testSentence1.addBlock(test2);
	testSentence1.addBlock(test3);
	testSentence1.addBlock(test4);
	cout << testSentence1.getSentenceAsString() << endl;
	if (testSentence1.isInOrder())
	{
		cout << "Is In Order!" << endl;
	}
	else
	{
		cout << "Is Not In Order!" << endl;
	}
	testSentence1.swapBlocks(0,4);
	cout << testSentence1.getSentenceAsString() << endl;
	if (testSentence1.isInOrder())
	{
		cout << "Is In Order!" << endl;
	}
	else
	{
		cout << "Is Not In Order!" << endl;
	}
	*/

	//Actual Setences
	/*
	int swap1;
	int swap2;
	
	WordBlock sentence1Word0 = WordBlock("A good computer scientist", 0);
	WordBlock sentence1Word1Bad = WordBlock("does his or her", 1);
	WordBlock sentence1Word1Ok = WordBlock("does their", 1);
	WordBlock sentence1Word1Good = WordBlock("does the", 1);
	WordBlock sentence1Word2 = WordBlock("job efficently.", 2);
	SentenceConstructor sentence1 = SentenceConstructor();
	sentence1.addBlock(sentence1Word0);
	sentence1.addBlock(sentence1Word1Bad);
	sentence1.addBlock(sentence1Word2);
	while(!sentence1.isInOrder())
	{
		cout << "Current Sentence: " << sentence1.getSentenceAsString() << endl;
		cout << "Input first block you want to swap: " <<endl;
		cin >> swap1;
		cout << "Input second block you want to swap: " <<endl;
		cin >> swap2;
		sentence1.swapBlocks(swap1, swap2);
	}
	*/
	
	return 1;
}