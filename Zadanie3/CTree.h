#pragma once
# include "CNode.h"
#include <string>
#include <vector>
#include <iostream>
#include "CVariable.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "CFunction.h"



using namespace std;

const string VAL_S_EMPTY = "";
const string VAL_S_SPACE = " ";
const string VAL_S_A = "a";
const string VAl_S_1 = "1";
const string VAL_S_x = "x";
const char VAL_C_SEMICOLON = ';';

const char VAR_C_SPACE = ' ';

const int VAL_I_96 = 96;
const int VAL_I_123 = 123;
const int VAL_I_64 = 64;
const int VAL_I_91 = 91;
const int VAL_I_180 = 180;

const int VAL_I_1 = 1;
const int VAL_I_0 = 0;
const int VAL_I_3 = 3;
const double VAL_D_PI = 3.14;

class CTree {



public:
	CTree();
	CTree(CTree &otherTree);
	~CTree();
	CNode *getRoot();
	void setRoot(CNode *Root);
	
	
	void addVariable(CVariable cVariable);
	int getVariableSize();
	vector <CVariable> getVariables();
	CVariable getOneVariable(int iIndex);
	void setValueToVariable(int iIndex, int iValue);


	string preOrder(CNode* currentRoot, string& sResult);
	void deleteWithPostOrder(CNode *currentRoot);
	CNode * lastChildrenInTree(CNode *root);


	CTree operator+(CTree &otherTree);
	void operator=(CTree &otherTree);



	void repair(bool &bIfRepair);
	void setValueWhenEmpty(CNode *curren, bool &bIfRepairt);
	void addChildrenToTreeWhenRepair(CNode *current);


	void freeNode(CNode* Root);

	void printLeaves(CNode *Root);


	void deleteVaraible(string sName, CTree& otherTree);



	void generateTree();
	CNode * generateTreeToMutation();

	


	void mutationTree();		
	void crossingTree(CTree & otherTree);
	void addAllNodeToVector(CNode* currentRoot,vector<CNode*>& NodeVector);



	bool isMathOperation(string str);
	bool isNumber(string str);
	double calculateValue(CNode *currentRoot, double dValueX, double dValueY);

	void setEvaluationResult(double dEvaluationResult);
	double getEvaluationResult();

	void calcFitness(vector <CFunction> & function_vector);

	void cutTree(int iMax, int ilevel, CNode* currentRoot);



private:
	CNode *root;
	vector <CVariable>variables;
	double d_evaluation_result;

};

