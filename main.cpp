#include <iostream>
#include <cstdlib>
#include "SentenceConstructor.hh"

using namespace std;

int main(int argc, char* argv[])
{
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
	return 1;
}