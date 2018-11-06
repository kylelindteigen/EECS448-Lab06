/**
*	@file Test.h
* 	@author John Gibbons
*	@date 2015.11.17
*
*/
#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include "LinkedListOfInts.h"
using namespace std;

class Test
{
public:

	Test();

	void TestLinkedListOfInts();
private:

	bool TestIsEmpty();

	bool TestSize();

	bool TestSearch();

	bool TestAddBack();

	bool TestAddFront();

	bool TestRemoveBack();

	bool TestRemoveFront();

};

#endif
