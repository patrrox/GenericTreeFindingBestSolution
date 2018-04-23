#include "stdafx.h"
#include "CNode.h"


CNode::CNode() 
{
	s_value = S_EMPTY;
	parent = NULL;
	//cout << "utworzono CNode"<<endl;
}//CNode::CNode()

CNode::~CNode() 
{
	for (int i = 0; i < childrens.size(); i++)
	{
		delete childrens[i];
		//cout << "usunieto: " << childrens[i] << endl;

	}//for (int i = 0; i < childrens.size(); i++)

}//CNode::~CNode() 

CNode:: CNode(CNode &otherNode)
{
	parent = NULL;
	CNode* node;
	for (int i = 0; i < otherNode.getChildrensSize(); i++)
	{
		node = new CNode(*(otherNode.getChildren(i)));
		node->parent = this;
		childrens.push_back(node);
	}//for (int i = 0; i < otherNode.getChildrensSize(); i++)

	s_value=otherNode.getValue();
	

}//CNode:: CNode(CNode &otherNode)


void CNode::setParent(CNode *nodeParent) 
{
	parent = nodeParent;
}//void CNode::setParent(CNode *nodeParent)


void CNode::setValue(string sValue) 
{
	s_value = sValue;
}//void CNode::setValue(string sValue) 


string CNode::getValue()
{
	return s_value;
}//string CNode::getValue()


CNode * CNode::getLastChild() 
{
	return childrens.back();
}//CNode * CNode::getLastChild() 

		

int CNode::getNumberOfChildrens() 
{
	return childrens.size();
}//int CNode::getNumberOfChildrens() 


int CNode::getNumberOfArguments() 
{
	if (s_value == VAL_SIN || s_value == VAL_COS) return I_1;
	else if (s_value == VAL_PLUS || s_value == VAL_MINUS || s_value == VAL_MULTIPLYING || s_value == VAL_DIVISION)	return I_2;
	else return 0;
}//int CNode::getNumberOfArguments() 


void CNode::addChild() 
{
	CNode *child = new CNode;
	childrens.push_back(child);
	child->setParent(this);
}//void CNode::addChild() 


CNode * CNode::getParent() 
{
	return parent;
}//CNode * CNode::getParent() 


vector<CNode*> CNode::getChildrens()
{
	return childrens;
}//vector<CNode*> CNode::getChildrens()


CNode *CNode::getChildren(int iIndex)
{
	return childrens[iIndex];
}//CNode *CNode::getChildren(int iIndex)


void CNode:: deleteChildren(int iIndex)
{
	//delete  childrens[iIndex];																		
	childrens.erase(childrens.begin() + iIndex);													
}//void CNode:: deleteChildren(int iIndex)


void CNode::addTreetoTree(CNode *root) 
{
	childrens.back() = root;									
}//void CNode::addTreetoTree(CNode *root) 


int CNode ::getChildrensSize()
{
	return childrens.size();
}//int CNode ::getChildrensSize()




 // Zadanie 4





void CNode::create(int level)
{
	int i_randomType = generateType();
	while  ( (level >= I_2)&&(i_randomType == I_0) )  i_randomType = generateType();

	if (i_randomType == I_0)			//operacja
	{
		this->setValue(generateOperation());
		int  i_children;
		i_children = getNumberOfArguments();	

		level++;

		for (int i_child = 0; i_child < i_children; i_child++)
		{
			this->addChild();
			childrens.at(i_child)->create(level);
		}//for (int i_child = 0; i_child < i_children; i_child++)
	}//if (i_randomType == 0)

	if (i_randomType == I_1)			//sta³a
	{
		this->setValue(generateVariable());
	}//if (i_randomType == 1)

	if (i_randomType == I_2)			//liczba
	{
		this->setValue(to_string(generateNumber()));
	}//if (i_randomType == 2)
}//void CNode::create(int level)


int CNode::generateType()
{
	

	int i_random = rand() % I_3;  // 0 - operacja, 1 - sta³a, 2 - liczba

	//if (i_random == 3)i_random = 0;

	return i_random;
}//int CNode::generateType()

string CNode::generateOperation()
{
	string s_operator_array[I_10] = { VAL_PLUS,VAL_MINUS,VAL_MULTIPLYING,VAL_DIVISION,VAL_PLUS,VAL_MINUS,VAL_MULTIPLYING,VAL_DIVISION,VAL_SIN,VAL_COS };
	int i_random = rand() % I_10;
	return s_operator_array[i_random];
}//string CNode::generateOperation()


int CNode::generateNumber()
{
	int i_random = (rand() % I_4) + I_2;
	return i_random;
}//int CNode::generateNumber()


string CNode::generateVariable()
{
	string s_operator_array[I_2] = { S_x,S_y };
	
	int i_random = rand() % I_2;
	return s_operator_array[i_random];
}//string CNode::generateVariable()




bool CNode::isMath()
{
	if (s_value == VAL_PLUS || s_value == VAL_MINUS || s_value == VAL_MULTIPLYING || s_value == VAL_DIVISION || s_value == VAL_SIN || s_value == VAL_COS)return true;
	else return false;
}//bool isMathOperation(string str)