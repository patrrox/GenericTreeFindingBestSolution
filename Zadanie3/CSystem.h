#pragma once
using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include "CTree.h"
#include "CNode.h"
#include "CInterface.h"



const string VAL_S_MENU = "-----MENU-----";
const string VAL_S_ENTER = "enter";
const string VAL_S_VARS = "vars";
const string VAL_S_PRINT = "print";
const string VAL_S_COMP = "comp";
const string VAL_S_JOIN = "join";
const string VAL_S_EXIT = "exit";


class CSystem
{
public:
	CSystem();
	~CSystem();
	vector<string> CSystem::getInputToVector();
	void getMenu();
	void start();

private:

	CTree* tree;
};



