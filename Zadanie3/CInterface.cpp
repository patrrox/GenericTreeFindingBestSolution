

#include "stdafx.h"
#include "CInterface.h"


void enter(CTree &tree, vector<string> &inputVector)
{
																											
	CNode *currentNode = tree.getRoot();
	bool b_isOK = true;
	int i = 1;

	while (i <inputVector.size() && b_isOK)																	//do dlugosci wektora i isOK jest true
	{
		
		bool q = putVariableToVector(inputVector[i], tree);
																													//std::cout << inputVector[i] << std::endl;
		if (currentNode->getValue().compare(VAL_S_EMPTY) == 0)														// sprawdzenie czy node jest pusty
		{
			currentNode->setValue(inputVector[i]);
																											//std::cout << "---> " << currentNode->getValue() << std::endl;
			if (isMathOperation(inputVector[i])) 
			{
				currentNode->addChild();																	//dodanie dziecka
																											//std::cout << "dodalem dziecko i przekazalem mu current" << std::endl;
				currentNode = currentNode->getLastChild();													// przekazanie kontroli
				i++;
			}//if (isMathOperation(inputVector[i])) 
			else 
			{
				if (currentNode == tree.getRoot()) 
				{
					b_isOK = false;
				}//(currentNode == tree.getRoot()) 
				else 
				{
					//
					currentNode = currentNode->getParent();
				}//else (currentNode == tree.getRoot()) 

			}//else if (isMathOperation(inputVector[i])) 

		}//if (currentNode->getValue().compare(VAL_S_EMPTY) == 0)
		else 
		{
			if (currentNode->getNumberOfArguments() == currentNode->getNumberOfChildrens()) 
			{
				if (currentNode == tree.getRoot()) 
				{
					b_isOK = false;
				}//if (currentNode == tree.getRoot()) 
				else 
				{
					//
					currentNode = currentNode->getParent();
				}//else if (currentNode == tree.getRoot()) 

			}//if (currentNode->getNumberOfArguments() == currentNode->getNumberOfChildrens()) 
			else 
			{
				currentNode->addChild();
				currentNode = currentNode->getLastChild();
				i++;
			}//else if (currentNode->getNumberOfArguments() == currentNode->getNumberOfChildrens()) 

		}//else if (currentNode->getValue().compare(VAL_S_EMPTY) == 0)

	}//while (i <inputVector.size() && b_isOK)	

	bool b_if_repair=true;
	tree.repair(b_if_repair);				//naprawa


	if (!b_if_repair||isNumber(inputVector[1]))
	{
		cout << "poprawiono drzewo, teraz wyglada tak: "<<endl;
		print(tree, inputVector);
		//cout << endl;
	}//if (!b_if_repair||isNumber(inputVector[1]))

}//void enter(CTree &tree, vector<string> &inputVector)


void print(CTree &tree, vector<string> &inputVector)
{
	string s_result= VAL_S_EMPTY;
	tree.preOrder(tree.getRoot(), s_result);
	cout <<s_result<< endl;

	cout << "ostatnie liscie to: " << endl;
	tree.printLeaves(tree.getRoot());

}//void print(CTree &tree, vector<string> &inputVector)







CTree join(CTree &mainTree, vector<string> &inputVector) 
{
	CTree otherTree, sumTree;

	enter(otherTree,inputVector);
	//print(otherTree, inputVector);
	sumTree = mainTree + sumTree;	


	//print(sumTree, inputVector);
	return sumTree;
}//CTree join(CTree &mainTree, vector<string> &inputVector) 








bool isMathOperation(string str) 
{
	if (str == VAL_PLUS || str == VAL_MINUS || str == VAL_MULTIPLYING || str == VAL_DIVISION || str == VAL_SIN || str == VAL_COS)return true;
	else return false;
}//bool isMathOperation(string str)

bool putVariableToVector(string & sVariable, CTree &tree)
{
	bool b_q = true;
	if (!isMathOperation(sVariable)&& !isNumber(sVariable))
	{
		bool b_h = true;
		for (int i = 0; i < sVariable.size(); i++)					//poprawianie
		{
			
			char c_help = sVariable[i];
			string s_help;
			s_help.push_back(c_help);
			if (!(((c_help > VAL_I_96) && (c_help < VAL_I_123)) || ((c_help > VAL_I_64) && (c_help < VAL_I_91)) || isNumber(s_help)))
			{
				//cout << "bledna zmienna" << endl;
				b_h = false;
				if (sVariable.size() == 1) sVariable = VAL_S_A;
				if (sVariable.size() != 1)
				{
					sVariable.erase(sVariable.begin() + i);
				}//if (sVariable.size() != 1)

			}//if (!(((c_help > 96) && (c_help < 123)) || ((c_help > 64) && (c_help < 91)) || isNumber(s_help)))
			
		}//for (int i = 0; i < sVariable.size(); i++)
		if (b_h == false)cout << "bledna zmienna, zmieniono na: " << sVariable << endl;
		


		bool b_m = true;
		for (int i = 0; i < tree.getVariableSize(); i++)
		{
			if (sVariable == tree.getOneVariable(i).getName())			//czy sie znajduje
			{
				//cout << "znaleziono";
				b_m = false;
			}//if (sVariable == tree.getOneVariable(i).getName())

		}//for (int i = 0; i < tree.getVariableSize(); i++)
		if (b_m)
		{
			

			CVariable variable(sVariable);
			tree.addVariable(variable);
			//cout << "dodano: " << sVariable << endl;
		}//if (b_m==true)

	}//if (!isMathOperation(sVariable)&& !isNumber(sVariable))
	else
	{
	//	cout << " nie dodano bo operator lub liczba";
	}//else if (!isMathOperation(sVariable)&& !isNumber(sVariable))

	return b_q;

}//bool putVariableToVector(string & sVariable, CTree &tree)





void comp(CTree &tree, vector<string> &inputVector)
{
	int i_index = 1;

	if (inputVector.size() - 1 != tree.getVariableSize())
	{
		cout << "nie udana bo niezgadza sie ilosc zmiennych"<<endl;
	}//if (inputVector.size() - 1 != tree.getVariableSize())
	else
	{
		while (i_index < inputVector.size())
		{
			//cout << "taki int: " << atoi(inputVector[i_index].c_str());

			//tree.getVariables()[i_index - 1].setValue(atoi(inputVector[i_index].c_str()));
			tree.setValueToVariable(i_index - 1, atoi(inputVector[i_index].c_str()));
			i_index++;
		}//while (i_index < inputVector.size())
	
		cout << "wartosc wynosi: " << calculateValue(tree.getRoot(), tree)<<endl;
	
	}//else if (inputVector.size() - 1 != tree.getVariableSize())

}//void comp(CTree &tree, vector<string> &inputVector)



double calculateValue(CNode *currentRoot, CTree &tree) 
{
	if (isMathOperation(currentRoot->getValue())) 
	{
		if (currentRoot->getValue() == VAL_PLUS) 
		{
			return calculateValue(currentRoot->getChildren(0),tree) + calculateValue(currentRoot->getChildren(1),tree);
		}//if (currentRoot->getValue() == VAL_PLUS) 
		else if (currentRoot->getValue() == VAL_MINUS) 
		{
			return calculateValue(currentRoot->getChildren(0), tree) - calculateValue(currentRoot->getChildren(1), tree);
		}//else if (currentRoot->getValue() == VAL_MINUS) 
		else if (currentRoot->getValue() == VAL_MULTIPLYING) 
		{
			return calculateValue(currentRoot->getChildren(0), tree) * calculateValue(currentRoot->getChildren(1), tree);
		}//else if (currentRoot->getValue() == VAL_MULTIPLYING) 
		else if (currentRoot->getValue() == VAL_DIVISION) 
		{
			return calculateValue(currentRoot->getChildren(0), tree) / calculateValue(currentRoot->getChildren(1), tree);
		}//else if (currentRoot->getValue() == VAL_DIVISION)
		else if (currentRoot->getValue() == VAL_SIN) 
		{
			return sin(calculateValue(currentRoot->getChildren(0), tree) * (3.14 / 180));
		}//else if (currentRoot->getValue() == VAL_SIN) 
		else  if (currentRoot->getValue() == VAL_COS) 
		{
			return cos(calculateValue(currentRoot->getChildren(0), tree) * (3.14 / 180));
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
			return findValuefromVariable(currentRoot->getValue(),tree);
		}//else if (isNumber(currentRoot->getValue())) 

	}//else if (isMathOperation(currentRoot->getValue())) 

}//double calculateValue(CNode *currentRoot, CTree &tree) 


bool isNumber(string str) 
{
	char* p;
	strtol(str.c_str(), &p, 10);
	return *p == 0;
}//bool isNumber(string str)





int findValuefromVariable(string sName, CTree &tree)
{
	int i_val = 1;
	for (int i = 0; i < tree.getVariableSize(); i++)
	{
		if (tree.getVariables()[i].getName() == sName)
		{
			i_val = tree.getVariables()[i].getValue();
		}//if (tree.getVariables()[i].getName() == sName)
	}//for (int i = 0; i < tree.getVariableSize(); i++)

	//cout << "wartosc do liczenia: " << sName << "wartosc to: " << i_val << endl;

	return i_val;
}//int findValuefromVariable(string sName, CTree &tree)


void vars(CTree &tree)
{
	for (int i = 0; i < tree.getVariableSize(); i++)
	{
		cout << tree.getOneVariable(i).getName()<< VAL_S_SPACE;
	}//for (int i = 0; i < tree.getVariableSize(); i++)
	cout << endl;
}//void vars(CTree &tree)

