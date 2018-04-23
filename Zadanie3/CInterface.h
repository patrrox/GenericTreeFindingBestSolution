#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "CTree.h"
#include <cstdlib>
#include<stdlib.h>
#define _USE_MATH_DEFINES


void enter(CTree &tree, vector<string> &inputVector);
void print(CTree &tree, vector<string> &inputVector);





bool isMathOperation(string str);
CTree join(CTree &mainTree, vector<string> &inputVector);



void comp(CTree &tree, vector<string> &inputVector);


bool isNumber(string str);
int findValuefromVariable(string sName, CTree &tree);
double calculateValue(CNode *currentRoot, CTree &tree);

void vars(CTree &tree);

bool putVariableToVector(string & sVariable, CTree &tree);