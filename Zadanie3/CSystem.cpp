#include "stdafx.h"
#include "CSystem.h"


CSystem::CSystem()
{
	tree = NULL;
}//CSystem::CSystem()


CSystem::~CSystem()
{
	if  (tree != NULL)  delete tree;
}//CSystem::~CSystem()


vector<string> CSystem :: getInputToVector() 
{
		string s_in;
		string s_to_vector = VAL_S_EMPTY;
		vector<string> vector;

		getline(cin, s_in);
		s_in += VAL_S_SPACE;

		int i = 0;
		while (i < s_in.size())
		{
			if (s_in[i] == VAR_C_SPACE) 
			{
				vector.push_back(s_to_vector);
				s_to_vector = VAL_S_EMPTY;
			}//if (s_in[i] == VAR_C_SPACE) 
			else 
			{
				s_to_vector += s_in[i];
			}//else if (s_in[i] == VAR_C_SPACE) 
			i++;
		}//while (i < s_in.size())
		return vector;
}//vector<string> CSystem :: getInputToVector() 




void CSystem :: getMenu()
{
	cout << VAL_S_MENU << endl;
	cout << VAL_S_ENTER << endl;
	cout << VAL_S_VARS << endl;
	cout << VAL_S_PRINT << endl;
	cout << VAL_S_COMP << endl;
	cout << VAL_S_JOIN << endl;
	cout << VAL_S_EXIT << endl;
}//void CSystem :: getMenu()


void CSystem::start()
{
	getMenu();
	
	vector <string> inputvector;
	inputvector.push_back(VAL_S_EMPTY);
	while (inputvector[0] != VAL_S_EXIT)
	{
		inputvector = getInputToVector();

		if (inputvector[0] == VAL_S_ENTER)
		{
			if  (tree != NULL)  delete tree;
			tree = new CTree();
			enter(*tree, inputvector);
		}//if (inputvector[0] == VAL_S_ENTER)
		if (inputvector[0] == VAL_S_VARS)vars(*tree);
		if (inputvector[0] == VAL_S_PRINT)print (*tree,inputvector);
		if (inputvector[0] == VAL_S_COMP) comp(*tree,inputvector);
		if (inputvector[0] == VAL_S_JOIN)
		{
			CTree *tree1 = new CTree();
			enter(*tree1, inputvector);
			

			CTree *newtree = new CTree();
			*newtree = *tree + *tree1;
		
			delete tree;
			tree = newtree;
		}//if (inputvector[0] == VAL_S_JOIN)
		
		/*if (inputvector[0] == VAL_S_EXIT)
		{
			delete tree;
		}//if (inputvector[0] == VAL_S_EXIT)*/
		if (inputvector[0] != VAL_S_ENTER &&inputvector[0] != VAL_S_VARS &&inputvector[0] != VAL_S_PRINT &&inputvector[0] != VAL_S_COMP &&inputvector[0] != VAL_S_JOIN &&inputvector[0] != VAL_S_EXIT) cout << "bledne dane" << endl;

	}//while (inputvector[0] != VAL_S_EXIT)

}//void CSystem::start()