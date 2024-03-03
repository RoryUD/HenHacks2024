#include <iostream>
#include <cstdlib>
#include "SentenceConstructor.hh"

using namespace std;

void validatesString(SentenceConstructor sentence, int targetSize)
{
	int num1;
	int num2;
	bool inOrder;
	bool noBad;
	bool noBadOrOk;
	bool properSize;
	int decision;
	while(!sentence.isInOrder() || !sentence.containedNoBad() || sentence.getSize() != targetSize)
	{
		//Gets bools to print 
		inOrder = sentence.isInOrder();
		noBad = sentence.containedNoBad();
		noBadOrOk = sentence.containedNoBadOrOk();
		properSize = sentence.getSize() == targetSize;
		cout << "Current Sentence: " << sentence.getSentenceAsString() << endl;
		cout << "Word Bank: " << sentence.getWordBankAsString() << endl;
		cout << "In Order: " << inOrder << " 	No Bad: "<< noBad << " 		Proper Size: " << properSize << endl;
		cout << "0: Swap 2 Blocks" << endl << "1: Remove a block" << endl << "2: Add a block from word bank" << endl << "3: Swap blocks in bank and sentence" << endl;
		cin >> decision;
		if(decision == 0)
		{
			cout << "Input first block you want to swap: " << endl;
			cin >> num1;
			cout << "Input second block you want to swap: " << endl;
			cin >> num2;
			sentence.swapBlocks(num1, num2);
		}
		else if(decision == 1)
		{
			cout << "Input block to remove" << endl;
			cin >> num1;
			if(num1 >= sentence.getSize() || num1 < 0)
			{
				cout << "Index out of bounds!" << endl;
			}
			else
			{
				sentence.removeBlock(sentence.getWordAtIndex(num1));
			}
		}
		else if(decision == 2)
		{
			if(sentence.getWordBankSize() <= 0)
			{
				cout << "No words in bank!" << endl;
			}
			else
			{
				cout << "Input block to add" << endl;
				cin >> num1;
				if(num1 >= sentence.getWordBankSize() || num1 < 0)
				{
					cout << "Index out of bounds!" << endl;
				}
				else
				{
					WordBlock temp = sentence.getWordAtIndexInBank(num1);
					sentence.removeBlockFromBank(temp);
					sentence.addBlock(temp);
				}
			}
		}
		else if(decision == 3)
		{
			cout << "Input block in sentence you want to swap: " << endl;
			cin >> num1;
			cout << "Input block in bank you want to swap: " << endl;
			cin >> num2;
			sentence.swapBlockFromBank(num1, num2);
		}
		num1 = -1;
		num2 = -1;
	}
	cout << endl;
	cout << sentence.getSentenceAsString() << endl;
}

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
	int targetSize;
	//Intro text
	// cout << "" << endl;
	cout << "This site is designed to teach you about gendered langauge!" << endl;
	cout << "You can move parts of sentences around to rewrite a give sentence to not include gendered language." << endl;
	cout << "This first sentence is about removing gendered pronouns without having to rewrite the sentence fully." << endl;
	cout << "Here is the first sentence:" << endl;
	cout << "---------------------------" << endl;
	//Setence 1
	/*
				A good computer scientist 
				does his or her
				does their
				does ones
				does the
				job efficently
	*/
	targetSize = 3;
	WordBlock sentence1Word0 = WordBlock("A good computer scientist", 0);
	WordBlock sentence1Word1Bad = WordBlock("does his or her", 1, 0);
	WordBlock sentence1Word1Ok = WordBlock("does their", 1, 1);
	WordBlock sentence1Word1Ok2 = WordBlock("does ones", 1, 2);
	WordBlock sentence1Word1Good = WordBlock("does the", 1, 2);
	WordBlock sentence1Word2 = WordBlock("job efficently.", 2);
	SentenceConstructor sentence1 = SentenceConstructor();
	sentence1.addBlock(sentence1Word0);
	sentence1.addBlock(sentence1Word1Bad);
	sentence1.addBlockToBank(sentence1Word1Ok);
	sentence1.addBlockToBank(sentence1Word1Ok2);
	sentence1.addBlockToBank(sentence1Word1Good);
	sentence1.addBlock(sentence1Word2);
	validatesString(sentence1, targetSize);
	cout << "Completed Sentence 1!" << endl;
	//Sentence 2 
	/*
	As you can see, you can remove gendered language in various ways
	This next example is when a singular person is talking about multiple people
	In this case, it is best to use they/them/their to refer to just a single group
	
	A pet owner
	Pet owners
	should treat
	their pets
	his or her pets
	well.
	
	*/
	cout << "As you can see, you can remove gendered language in various ways" << endl;
	cout << "This next example is when a singular person is talking about multiple people" << endl;
	cout << "In this case, it is best to use they/them/their to refer to just a single group" << endl;
	cout << "---------------------------" << endl;
	targetSize = 4;
	WordBlock sentence2Word0Bad = WordBlock("A pet owner",0,0);
	WordBlock sentence2Word0Good = WordBlock("Pet owners",0,2);
	WordBlock sentence2Word1 = WordBlock("should treat",1);
	WordBlock sentence2Word2Good = WordBlock("their pets",2,2);
	WordBlock sentence2Word2Bad = WordBlock("his or her pets",2,0);
	WordBlock sentence2Word3 = WordBlock("well.",3);
	SentenceConstructor sentence2 = SentenceConstructor();
	sentence2.addBlock(sentence2Word0Bad);
	sentence2.addBlock(sentence2Word1);
	sentence2.addBlock(sentence2Word2Bad);
	sentence2.addBlock(sentence2Word3);
	sentence2.addBlockToBank(sentence2Word0Good);
	sentence2.addBlockToBank(sentence2Word2Good);
	validatesString(sentence2, targetSize);
	cout << "Completed Sentence 2!" << endl;
	//Sentence 3
	targetSize = 0;
	
	return 1;
}