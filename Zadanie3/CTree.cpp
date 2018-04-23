#include "stdafx.h"
#include "CTree.h"





CTree::CTree() 
{
	root = new CNode;
	d_evaluation_result = 0;
}//CTree::CTree() 

CTree::~CTree() 
{
	delete root;
	
}//CTree::~CTree() 


void CTree::freeNode(CNode* Root)	//postorder delete
{
	if (Root!= NULL)
	{
		for (int i = 0; i < Root->getChildrensSize(); i++)
		{
			freeNode(Root->getChildren(i));
		}//for (int i = 0; i < Root->getChildrensSize(); i++)

		//cout << Root->getValue()<<" ";
		//delete Root;

	}//	if (Root!= NULL)
}//void CTree::freeNode(CNode* Root)



CTree::CTree(CTree &otherTree) 
{
	root = new CNode(*(otherTree.getRoot()));
	d_evaluation_result = otherTree.d_evaluation_result;
	
	for (int i = 0; i < otherTree.getVariableSize(); i++)
	{
		variables.push_back(otherTree.getOneVariable(i));

	}//for (int i = 0; i < otherTree.getVariableSize(); i++)
}//CTree::CTree(CTree &otherTree)


void CTree::printLeaves(CNode *Root)
{
	/*
	if (Root != NULL)
	{
		for (int i = 0; i < Root->getChildrensSize(); i++)
		{
			printLeaves(Root->getChildren(i));
		}

		cout << Root->getValue() << " ";
	}

	/*/
	
	if (Root != NULL)
	{
		
		if (Root->getChildrensSize() == 0)
		{
			cout << Root->getValue();
		}

		for (int i = 0; i < Root->getChildrensSize(); i++)
		{
			printLeaves(Root->getChildren(i));
		}
	
		
	}
	
}


void CTree::setRoot(CNode *Root) 
{
	root = Root;
}//void CTree::setRoot(CNode *Root)


CNode * CTree::getRoot() 
{
	return root;
}//CNode * CTree::getRoot() 


string CTree::preOrder(CNode* currentRoot,string& sResult) 
{
	
	sResult = sResult + currentRoot->getValue()+ VAL_S_SPACE;
	//cout << currentRoot->getValue() << " ";
	if (!(currentRoot->getChildrens().empty())) 
	{
		for (int i = 0; i < currentRoot->getChildrens().size(); i++) 
		{
			preOrder(currentRoot->childrens[i],sResult);
		}//for (int i = 0; i < currentRoot->getChildrens().size(); i++)

	}//if (!(currentRoot->getChildrens().empty())) 

	return sResult;
}//string CTree::preOrder(CNode* currentRoot,string& sResult) 

void CTree::deleteWithPostOrder(CNode *currentRoot) 
{
	string s_result = VAL_S_EMPTY;
	if (!(currentRoot->childrens.empty())) 
	{
		for (int i = 0; i < currentRoot->childrens.size(); i++) 
		{
			preOrder(currentRoot->childrens[i],s_result);
		}//for (int i = 0; i < currentRoot->childrens.size(); i++) 
	}//if (!(currentRoot->childrens.empty())) 
	//cout<< currentRoot->getValue();
	//delete currentRoot;
}//void CTree::deleteWithPostOrder(CNode *currentRoot) 













CNode * CTree::lastChildrenInTree(CNode *root) 
{
	CNode *node=new CNode();
	while (!root->childrens.empty()) 
	{
		root = root->getLastChild();
		node = root;
	}//while (!root->childrens.empty())
	return node;
}//CNode * CTree::lastChildrenInTree(CNode *root) 



CTree CTree::operator+(CTree& otherTree) 
{
	CTree sumTree = CTree(*this);
	CNode* nodeToRemove = (sumTree).lastChildrenInTree((sumTree).root);
	
	int i_index = 0;
	while (nodeToRemove->getParent()->getChildren(i_index) != nodeToRemove) 
	{
		i_index++;
	}//while (nodeToRemove->getParent()->getChildren(i_index) != nodeToRemove) 

	

	string ss = nodeToRemove->getParent()->getChildren(i_index)->getValue();
	//cout <<"taki:"<< ss;
	deleteVaraible(ss,sumTree);

	nodeToRemove->getParent()->deleteChildren(i_index);
	nodeToRemove->getParent()->addChild();
	nodeToRemove->getParent()->addTreetoTree(otherTree.root);



	
	for (int i = 0; i < otherTree.getVariableSize(); i++)
	{
		bool b_true=true;
		for (int j = 0; j < sumTree.getVariableSize(); j++)
		{
			if (otherTree.getOneVariable(i).getName() == sumTree.getOneVariable(j).getName())
			{
				b_true = false;
			}//if (otherTree.getOneVariable(i).getName() == sumTree.getOneVariable(j).getName())
		}//for (int j = 0; j < sumTree.getVariableSize(); j++)
		if (b_true)
		{
			sumTree.addVariable(otherTree.getOneVariable(i));
		}//if (b_true)
	}//for (int i = 0; i < otherTree.getVariableSize(); i++)

	return sumTree;
}//CTree CTree::operator+(CTree& otherTree) 



void CTree::operator=(CTree &otherTree) 
{
	if (root != NULL)
	{
		delete root;
	}//if (root != NULL)

	root = new CNode(*(otherTree.getRoot()));

	 for (int i = 0; i < otherTree.getVariableSize();i++)
	 {
		 variables.push_back(otherTree.getOneVariable(i));
	 }//for (int i = 0; i < otherTree.getVariableSize();i++)
																						
}//void CTree::operator=(CTree &otherTree) 




void CTree :: deleteVaraible(string sName, CTree& otherTree)
{
	bool b_q=true;
	int i_index;
	for (int i = 0; i < otherTree.getVariableSize();i++)
	{
		if (otherTree.getOneVariable(i).getName() == sName)
		{
			b_q = false;
			i_index = i;
		}//if (variables[i].getName() == sName)
	}//for (int i = 0; i < variables.size();i++)
	if (b_q == false)
	{
	//	cout << "wchodzi";
		(otherTree.variables).erase((otherTree.variables).begin() + i_index);
		
	}//if (b_q == false)
	
	
}//void CTree :: deleteVaraible(string sName)




void CTree::repair(bool &bIfRepair) 
{
	//bool b_if_rapair = true;
	addChildrenToTreeWhenRepair(this->root);	
	setValueWhenEmpty(this->root, bIfRepair);
}//void CTree::repair(bool &bIfRepair) 

void CTree::setValueWhenEmpty(CNode *current,bool &bIfRepair) 
{
	if (current->getValue().compare(VAL_S_EMPTY) == 0)
	{
		current->setValue(VAl_S_1);
		//cout << "dodano wartosc domyslna: " << current->getValue() << endl;
		bIfRepair = false;
	}//if (current->getValue().compare("") == 0) 
	if (!(current->childrens.empty())) 
	{
		for (int i = 0; i <(current->childrens.size()); i++) 
		{
			setValueWhenEmpty(current->childrens[i],bIfRepair);
		}//for (int i = 0; i <(current->childrens.size()); i++)
	}//if (!(current->childrens.empty())) 
}//void CTree::setValueWhenEmpty(CNode *current,bool &bIfRepair) 



void CTree::addChildrenToTreeWhenRepair(CNode *current) ////dodaje odpowiedni¹ iloœæ dzieci
{ 
	while (current->getNumberOfArguments() != current->getChildrensSize()) 
	{				
		current->addChild();
		//cout << "dodano dziecko do: " << current->getValue() << endl;
		reverse(current->childrens.begin(), current->childrens.end());										//dodalem
		
	}//while (current->getNumberOfArguments() != current->getChildrensSize()) 
	//current->childrens
	if (!(current->childrens.empty())) 
	{
		for (int i = 0; i < (current->childrens.size()); i++) 
		{
			addChildrenToTreeWhenRepair(current->childrens[i]);
		}//for (int i = 0; i < (current->childrens.size()); i++) 
	}//if (!(current->childrens.empty()))
}//void CTree::addChildrenToTreeWhenRepair(CNode *current)







void CTree :: addVariable(CVariable cVariable)
{
	variables.push_back(cVariable);
}//void CTree :: addVariable(CVariable cVariable)

int CTree ::getVariableSize()
{
	return variables.size();
}//int CTree ::getVariableSize()

vector <CVariable> CTree::getVariables()
{
	return variables;
}//vector <CVariable> CTree::getVariables()

CVariable CTree::getOneVariable(int iIndex)
{
	return variables[iIndex];
}//CVariable CTree::getOneVariable(int iIndex)

void CTree::setValueToVariable(int iIndex, int iValue)
{
	variables[iIndex].setValue(iValue);
}//void CTree::setValueToVariable(int iIndex, int iValue)





//Zadanie 4




void CTree :: mutationTree()
{
	vector <CNode*> nodes_vector;
	addAllNodeToVector(root, nodes_vector);

	if (nodes_vector.size() == VAL_I_1)
	{
		if (root->s_value != VAL_S_EMPTY)
		{
			delete root;
		}//if (root->s_value != "")
		root = generateTreeToMutation();
	}//if (nodes_vector.size() == 1)
	else
	{
		int i_random_one = 0;
		if (nodes_vector.size() > I_4)
		{
			i_random_one = (rand() % (nodes_vector.size() - (nodes_vector.size()/ I_2)) + 1);
		}
		else
		{
			i_random_one = (rand() % (nodes_vector.size() - 1) + 1);
		}		
		CNode * Node_one = nodes_vector[i_random_one];
		CNode *pc_parent;
		pc_parent = Node_one->parent;
		delete Node_one;

		for (int ii = 0; ii < pc_parent->childrens.size(); ii++)
		{
			if (pc_parent->childrens.at(ii) == Node_one)
			{
				pc_parent->childrens.erase(pc_parent->childrens.begin() + ii);
			}//if (pc_parent->childrens.at(ii) == Node_one)
		}//for  (int  ii = 0; ii < pc_parent->childrens.size(); ii++)

		Node_one = generateTreeToMutation();
		Node_one->setParent(pc_parent);
		pc_parent->childrens.push_back(Node_one);
	}//else if (nodes_vector.size() == 1)
}//void CTree :: mutationTree()


void CTree :: crossingTree(CTree & otherTree)
{
	vector <CNode*> nodes_vector_one;
	vector <CNode*> nodes_vector_two;
	addAllNodeToVector(root, nodes_vector_one);
	addAllNodeToVector(otherTree.getRoot(), nodes_vector_two);

	if (nodes_vector_one.size() == VAL_I_1 && nodes_vector_two.size() == VAL_I_1)
	{
		CNode * root_one = root;
		CNode * root_two = otherTree.getRoot();
		root = root_two;
		otherTree.setRoot(root_one);
	}//if (nodes_vector_one.size() == 1 && nodes_vector_two.size() == 1)
	else
	{
		if (nodes_vector_one.size() == VAL_I_1)
		{
			int i_random_two = rand() % (nodes_vector_two.size()-1)+1;
			CNode * node_two = nodes_vector_two[i_random_two];
			CNode * node_two_parent = node_two->parent;

			for (int ii = 0; ii < node_two_parent->childrens.size(); ii++)
			{
				if (node_two_parent->childrens.at(ii) == node_two)
				{
					node_two_parent->childrens.erase(node_two_parent->childrens.begin() + ii);
				}//if (node_two_parent->childrens.at(ii) == node_two)
			}//for (int ii = 0; ii < node_two_parent->childrens.size(); ii++)

			CNode * root_copy = root;
			root_copy->setParent(node_two_parent);
			node_two_parent->childrens.push_back(root_copy);
			root = node_two;
		}//if (nodes_vector_one.size() == VAL_I_1)
		else
		{
			if (nodes_vector_two.size() == VAL_I_1)
			{
				int i_random_one = rand() % (nodes_vector_one.size() - VAL_I_1) + VAL_I_1;
				CNode * node_one = nodes_vector_one[i_random_one];
				CNode * node_one_parent = node_one->parent;

				for (int ii = 0; ii < node_one_parent->childrens.size(); ii++)
				{
					if (node_one_parent->childrens.at(ii) == node_one)
					{
						node_one_parent->childrens.erase(node_one_parent->childrens.begin() + ii);
					}
				}

				CNode * root_copy = otherTree.getRoot();
				root_copy->setParent(node_one_parent);
				node_one_parent->childrens.push_back(root_copy);
				otherTree.setRoot(node_one);
			}//if (nodes_vector_two.size() == VAL_I_1)
			else
			{
				int i_random_one = rand() % (nodes_vector_one.size() - VAL_I_1) + VAL_I_1;
				int i_random_two = rand() % (nodes_vector_two.size() - VAL_I_1) + VAL_I_1;

				CNode * node_one = nodes_vector_one[i_random_one];
				CNode * node_two = nodes_vector_two[i_random_two];

				CNode * node_one_parent = node_one->parent;
				CNode * node_two_parent = node_two->parent;

				for (int ii = 0; ii < node_one_parent->childrens.size(); ii++)
				{
					if (node_one_parent->childrens.at(ii) == node_one)
					{
						node_one_parent->childrens.erase(node_one_parent->childrens.begin() + ii);
					}//if (node_one_parent->childrens.at(ii) == node_one)
				}//for (int ii = 0; ii < node_one_parent->childrens.size(); ii++)

				for (int ii = 0; ii < node_two_parent->childrens.size(); ii++)
				{
					if (node_two_parent->childrens.at(ii) == node_two)
					{
						node_two_parent->childrens.erase(node_two_parent->childrens.begin() + ii);
					}//if (node_two_parent->childrens.at(ii) == node_two)
				}//for (int ii = 0; ii < node_two_parent->childrens.size(); ii++)
				node_two->setParent(node_one_parent);
				node_one_parent->childrens.push_back(node_two);

				node_one->setParent(node_two_parent);
				node_two_parent->childrens.push_back(node_one);
			} //else if (nodes_vector_two.size() == VAL_I_1)
		}//else if (nodes_vector_one.size() == VAL_I_1) 
	}// else if (nodes_vector_one.size() == 1 && nodes_vector_two.size() == 1)
	
}//void CTree :: crossingTree(CTree & otherTree)


void CTree::generateTree()
{
	if (root->s_value != VAL_S_EMPTY)delete root;
	int i_level = 0;
	root->create(0);
}//void CTree::generateTree()

CNode* CTree :: generateTreeToMutation()
{
	CNode * newNode = new CNode();
	int i_level = 0;
	newNode->create(0);

	return newNode;
}//CNode* CTree :: generateTreeToMutation()


void CTree::addAllNodeToVector(CNode* currentRoot,vector<CNode*>& NodeVector)
{
	NodeVector.push_back(currentRoot);
	if (!(currentRoot->getChildrens().empty()))
	{
		for (int i = 0; i < currentRoot->getChildrens().size(); i++)
		{
			addAllNodeToVector(currentRoot->childrens[i],NodeVector);
		}//for (int i = 0; i < currentRoot->getChildrens().size(); i++)
	}//if (!(currentRoot->getChildrens().empty()))
}//void CTree::addAllNodeToVector(CNode* currentRoot,vector<CNode*>& NodeVector)




bool CTree :: isMathOperation(string str)
{
	if (str == VAL_PLUS || str == VAL_MINUS || str == VAL_MULTIPLYING || str == VAL_DIVISION || str == VAL_SIN || str == VAL_COS)return true;
	else return false;
}//bool isMathOperation(string str)



double CTree :: calculateValue(CNode *currentRoot, double dValueX,double dValueY)
{
	if (isMathOperation(currentRoot->getValue()))
	{
		if (currentRoot->getValue() == VAL_PLUS)
		{
			return calculateValue(currentRoot->getChildren(VAL_I_0), dValueX,dValueY) + calculateValue(currentRoot->getChildren(VAL_I_1), dValueX, dValueY);
		}//if (currentRoot->getValue() == VAL_PLUS) 
		else if (currentRoot->getValue() == VAL_MINUS)
		{
			return calculateValue(currentRoot->getChildren(VAL_I_0), dValueX, dValueY) - calculateValue(currentRoot->getChildren(VAL_I_1), dValueX, dValueY);
		}//else if (currentRoot->getValue() == VAL_MINUS) 
		else if (currentRoot->getValue() == VAL_MULTIPLYING)
		{
			return calculateValue(currentRoot->getChildren(VAL_I_0), dValueX, dValueY) * calculateValue(currentRoot->getChildren(VAL_I_1), dValueX, dValueY);
		}//else if (currentRoot->getValue() == VAL_MULTIPLYING) 
		else if (currentRoot->getValue() == VAL_DIVISION)
		{
			return calculateValue(currentRoot->getChildren(VAL_I_0), dValueX, dValueY) / calculateValue(currentRoot->getChildren(VAL_I_1), dValueX, dValueY);
		}//else if (currentRoot->getValue() == VAL_DIVISION)
		else if (currentRoot->getValue() == VAL_SIN)
		{
			return sin(calculateValue(currentRoot->getChildren(VAL_I_0), dValueX, dValueY) * (VAL_D_PI / VAL_I_180));
		}//else if (currentRoot->getValue() == VAL_SIN) 
		else  if (currentRoot->getValue() == VAL_COS)
		{
			return cos(calculateValue(currentRoot->getChildren(VAL_I_0), dValueX, dValueY) * (VAL_D_PI / VAL_I_180));
		}//else  if (currentRoot->getValue() == VAL_COS) 
	}//if (isMathOperation(currentRoot->getValue())) 
	else
	{
		if (isNumber(currentRoot->getValue()))
		{
			return stoi(currentRoot->getValue());
		}//if (isNumber(currentRoot->getValue())) 
		else
		{
			if (currentRoot->getValue() == VAL_S_x)
			{
				return dValueX;
			}//if (currentRoot->getValue() == "x")
			else
			{
				return dValueY;
			}//else if (currentRoot->getValue() == "x")
			
		
		}//if (isNumber(currentRoot->getValue()))

	}//else if (isMathOperation(currentRoot->getValue())) 

}//double calculateValue(CNode *currentRoot, CTree &tree) 


bool CTree :: isNumber(string str)
{
	char* p;
	strtol(str.c_str(), &p, I_10);
	return *p == 0;
}//bool isNumber(string str)


void CTree :: setEvaluationResult(double dEvaluationResult)
{
	d_evaluation_result = dEvaluationResult;
}//void CTree :: setEvaluationResult(double dEvaluationResult)

double CTree::getEvaluationResult()
{
	return d_evaluation_result;
}//double CTree::getEvaluationResult()



void CTree :: calcFitness(vector <CFunction> & function_vector)
{
	double d_fit = 0;
	double d_calc_val = 0;

	for (int j = 0; j < function_vector.size(); j++)
	{
		d_calc_val = calculateValue(root, function_vector[j].getX(), function_vector[j].getY());
		//cout << "wyliczona wartosc: " << d_calc_val << endl;
		d_calc_val = d_calc_val - function_vector[j].getResult();
		d_fit = d_fit + (d_calc_val*d_calc_val);
		//cout << "pol wynik: " << d_fit<<endl;
		d_calc_val = 0;
	}//for (int j = 0; j < function_vector.size(); j++)
	 //cout << "wynik" << d_fit<<endl;
	setEvaluationResult(d_fit);
	d_fit = 0;
}// void CTree :: calcFitness(vector <CFunction> & function_vector)





void CTree :: cutTree(int iMax, int ilevel, CNode* currentRoot)
{
	//NodeVector.push_back(currentRoot);
	//cout << currentRoot->getValue() << " ";

//	ilevel++;
	//cout << ilevel;

	if (ilevel == iMax)
	{
		cout <<"obecny: "<< currentRoot->getValue() << endl;
		if (currentRoot->isMath())
		{
			currentRoot->setValue("1");
		}
		//currentRoot->setValue("1");

		CNode * node_one_parent = currentRoot->parent;
		//cout << "ojciec to: " << node_one_parent->getValue() << endl;
		node_one_parent->childrens.erase(node_one_parent->childrens.begin() );
		node_one_parent->childrens.erase(node_one_parent->childrens.begin() );
	}

	else
	{

		if (!(currentRoot->getChildrens().empty()))
		{
			ilevel++;
			cout << ilevel;

			for (int i = 0; i < currentRoot->getChildrens().size(); i++)
			{
				cutTree(iMax, ilevel, currentRoot->childrens[i]);
				//addAllNodeToVector(currentRoot->childrens[i], NodeVector);
			}//for (int i = 0; i < currentRoot->getChildrens().size(); i++)
		}//if (!(currentRoot->getChildrens().empty()))
	}
}
