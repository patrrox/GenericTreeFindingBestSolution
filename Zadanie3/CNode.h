#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>


const string VAL_SIN = "sin";
const string VAL_COS = "cos";
const string VAL_PLUS = "+";
const string VAL_MINUS = "-";
const string VAL_MULTIPLYING = "*";
const string VAL_DIVISION = "/";

const string S_x = "x";
const string S_y = "y";
const string S_EMPTY = "";
const int I_0 = 0;
const int I_1 = 1;
const int I_2 = 2;
const int I_3 = 3;
const int I_4 = 4;
const int I_10 = 10;
const string LACK_OF_ACCESS = "lack of access";


class CNode {


public:
	CNode();
	~CNode();
	CNode(CNode &otherNode);
	

	CNode * getLastChild();
	int getNumberOfArguments();
	void setParent(CNode *nodeParent);
	void setValue(string sValue);
	void addChild();
	string getValue();
	CNode * getParent();

	int getNumberOfChildrens();					
	int getChildrensSize();




	vector<CNode*> getChildrens();
	CNode* getChildren(int iIndex);
	void deleteChildren(int iIndex);
	void addTreetoTree(CNode *root);

	void create(int level);





	int generateType();
	string generateOperation();
	int generateNumber();
	string generateVariable();
	bool CNode::isMath();
	
private:
	friend class CTree;
	CNode *parent;
	vector<CNode*> childrens;
	string s_value;
	
};