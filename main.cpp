#include <iostream>
#include <cstdlib>
#include "SentenceConstructor.hh"

using namespace std;

int main(int argc, char* argv[])
{
	//Test Blocks
	/*
	cout << "Start of Tests!" << endl;
	WordBlock test0 = WordBlock("A",0,2);
	WordBlock test1 = WordBlock("B",1,2);
	WordBlock test2 = WordBlock("C",2,2);
	WordBlock test3 = WordBlock("D",3,2);
	WordBlock test4 = WordBlock("E",4,2);
	WordBlock test5 = WordBlock("F",5,0);
	SentenceConstructor testSentence1 = SentenceConstructor();
	testSentence1.addBlock(test0);
	testSentence1.addBlock(test1);
	testSentence1.addBlock(test2);
	testSentence1.addBlock(test3);
	testSentence1.addBlock(test4);
	testSentence1.addBlock(test5);
	cout << "Sentence: " << testSentence1.getSentenceAsString() << endl;
	if (testSentence1.isInOrder())
	{
		cout << "Is In Order!" << endl;
	}
	else
	{
		cout << "Is Not In Order!" << endl;
	}
	if (testSentence1.containedNoBad())
	{
		cout << "Contains No Bads!" << endl;
	}
	else
	{
		cout << "Contains Bads!" << endl;
	}
	testSentence1.swapBlocks(0,4);
	cout << "Swapped 0 and 4th blocks!" << endl;
	testSentence1.removeBlock(test5);
	cout << "Removed 5th block" << endl;
	cout << "Sentence: " << testSentence1.getSentenceAsString() << endl;
	if (testSentence1.isInOrder())
	{
		cout << "Is In Order!" << endl;
	}
	else
	{
		cout << "Is Not In Order!" << endl;
	}
	if (testSentence1.containedNoBad())
	{
		cout << "Contains No Bads!" << endl;
	}
	else
	{
		cout << "Contains Bads!" << endl;
	}
	cout << "Word Bank: " << testSentence1.getWordBankAsString() << endl;
	cout << "End of Tests!" << endl;
	
	//*/
	//Actual Setences
	/*
	int num1;
	int num2;
	int decision;
	int targetSize = 3;
	
	WordBlock sentence1Word0 = 		WordBlock("A good computer scientist", 0);
	WordBlock sentence1Word1Bad = 	WordBlock("does his or her", 1, 0);
	WordBlock sentence1Word1Ok = 	WordBlock("does their", 1, 1);
	WordBlock sentence1Word1Ok2 = 	WordBlock("does ones", 1, 2);
	WordBlock sentence1Word1Good = 	WordBlock("does the", 1, 2);
	WordBlock sentence1Word2 = 		WordBlock("job efficently.", 2);
	SentenceConstructor sentence1 = SentenceConstructor();
	sentence1.addBlock(sentence1Word0);
	sentence1.addBlock(sentence1Word1Bad);
	sentence1.addBlockToBank(sentence1Word1Ok);
	sentence1.addBlockToBank(sentence1Word1Ok2);
	sentence1.addBlockToBank(sentence1Word1Good);
	sentence1.addBlock(sentence1Word2);
	while(!sentence1.isInOrder() || !sentence1.containedNoBad() || sentence1.getSize() != targetSize)
	{
		cout << "Current Sentence: " << sentence1.getSentenceAsString() << endl;
		cout << "Word Bank: " << sentence1.getWordBankAsString() << endl;
		if (sentence1.isInOrder())
		{
			cout << "Is In Order! 	";
		}
		else
		{
			cout << "Is Not In Order! 	";
		}
		if (sentence1.containedNoBad())
		{
			cout << "Contains No Bads! 		";
		}
		else
		{
			cout << "Contains Bads! 	";
		}
		if (sentence1.getSize() == targetSize)
		{
			cout << "Right Size!" << endl;;
		}
		else
		{
			cout << "Wrong Size!" << endl;
		}
		cout << "0: Swap 2 Blocks" << endl << "1: Remove a block" << endl << "2: Add a block from word bank" << endl;
		cin >> decision;
		if(decision == 0)
		{
			cout << "Input first block you want to swap: " << endl;
			cin >> num1;
			cout << "Input second block you want to swap: " << endl;
			cin >> num2;
			sentence1.swapBlocks(num1, num2);
		}
		else if(decision == 1)
		{
			cout << "Input block to remove" << endl;
			cin >> num1;
			if(num1 >= sentence1.getSize())
			{
				cout << "Index out of bounds!" << endl;
			}
			else
			{
				sentence1.removeBlock(sentence1.getWordAtIndex(num1));
			}
		}
		else if(decision == 2)
		{
			if(sentence1.getWordBankSize() <= 0)
			{
				cout << "No words in bank!" << endl;
			}
			else
			{
				cout << "Input block to add" << endl;
				cin >> num1;
				if(num1 < sentence1.getWordBankSize())
				{
					WordBlock temp = sentence1.getWordAtIndexInBank(num1);
					sentence1.removeBlockFromBank(temp);
					sentence1.addBlock(temp);
				}
				else
				{
					cout << "Index out of bounds!" << endl;
				}
			}
		}
		num1 = -1;
		num2 = -1;
	}
	cout << sentence1.getSentenceAsString() << endl;
	cout << "Completed Sentence 1!" << endl;
	//*/
	
	return 1;
}