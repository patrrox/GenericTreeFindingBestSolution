#include "stdafx.h"
#include "CSystem4.h"


CSystem4::CSystem4()
{
	getFromFile();
}


CSystem4::~CSystem4()
{
	for (int i = 0; i < tree_vector.size(); i++)
	{
		delete tree_vector[i];
	}//for (int i = 0; i < tree_vector.size(); i++)

	for (int i = 0; i < result_vector.size(); i++)
	{
		delete result_vector[i];
	}//for (int i = 0; i < result_vector.size(); i++)
}



void CSystem4::initialization(int iNp)
{
	CTree *new_tree;
	for (int i = 0; i < iNp; i++)
	{
		new_tree = new CTree();
		new_tree->generateTree();
		tree_vector.push_back(new_tree);
	}//for (int i = 0; i < iNp; i++)
}//void CSystem4::initialization(int iNp)



void CSystem4::printTreeVector()
{
	for (int i = 0; i < tree_vector.size(); i++)
	{
		string s_result1 = VAL_S_EMPTY;
		tree_vector[i]->preOrder(tree_vector[i]->getRoot(), s_result1);
		cout << s_result1 << endl;
	}//for (int i = 0; i < tree_vector.size(); i++)
}//void CSystem4::printTreeVector()



void CSystem4::evaluation()
{
	double d_fit = 0;
	double d_calc_val = 0;
	for (int i = 0; i < tree_vector.size(); i++)
	{
		tree_vector[i]->calcFitness(function_vector);
		
		if (tree_vector[i]->getEvaluationResult() < 0.2)													//zmiana 
		{
			cout << tree_vector[i]->getEvaluationResult() << endl;
			string res;
			res = tree_vector[i]->preOrder(tree_vector[i]->getRoot(), res);
			cout << res << endl;
		}//if (tree_vector[i]->getEvaluationResult() < VAL_I_1)
		
		if (tree_vector[i]->getEvaluationResult() == 0)													//zmiana
		{
			result_vector.push_back(new CTree(*(tree_vector[i])));
		}//if (tree_vector[i]->getEvaluationResult() == VAL_I_0)
	}//for (int i = 0; i < tree_vector.size(); i++)
}//void CSystem4::evaluation()


void CSystem4::selection()
{
	vector <CTree*>tree_vector_new;
	int i_random_one;
	int i_random_two;
	CTree * newTree;

	while (tree_vector_new.size() != tree_vector.size())
	{
		i_random_one = rand() % (tree_vector.size());
		i_random_two = rand() % (tree_vector.size());

		if (tree_vector[i_random_one]->getEvaluationResult() <= tree_vector[i_random_two]->getEvaluationResult())
		{
			newTree = new CTree(*(tree_vector[i_random_one]));
			tree_vector_new.push_back(newTree);
		}//if (tree_vector[i_random_one]->getEvaluationResult() <= tree_vector[i_random_two]->getEvaluationResult())
		else
		{
			newTree = new CTree(*(tree_vector[i_random_two]));
			tree_vector_new.push_back(newTree);
		}//else if (tree_vector[i_random_one]->getEvaluationResult() <= tree_vector[i_random_two]->getEvaluationResult())
	}//while (tree_vector_new.size() != tree_vector.size())

	for (int i = 0; i < tree_vector.size(); i++)
	{
		delete tree_vector[i];
	}//for (int i = 0; i < tree_vector.size(); i++)

	 //cout << "ROZMIAR TO: " << tree_vector_new.size()<<endl;
	tree_vector = tree_vector_new;
}//void CSystem4::selection()



void CSystem4::getFromFile()
{
	int i_index = VAL_I_0;;
	double d_tab_with_value[VAL_I_3];
	double d_value;
	int i_tab_index = VAL_I_0;
	fstream file;
	string s_line;
	string  s_value;
	file.open("C://Users//Asus//source//repos//Zadanie3//text.txt", ios::in);

	if (file.good() == true)
	{
		while (!file.eof())
		{
			getline(file, s_line);
			//cout << s_line << endl;

			while (i_index <= s_line.size())
			{
				if (s_line[i_index] == VAL_C_SEMICOLON || i_index == s_line.size())
				{
					//cout << "wartosc: " ;
					d_tab_with_value[i_tab_index++] = atof(s_value.c_str());
					s_value = VAL_S_EMPTY;
				}//if (s_line[i_index] == VAL_C_SEMICOLON || i_index == s_line.size())
				else
				{
					s_value = s_value + s_line[i_index];
				}//else if (s_line[i_index] == VAL_C_SEMICOLON || i_index == s_line.size())
				i_index++;
			}//while (i_index <= s_line.size())
			 //cout << "1 - " << d_tab_with_value[0]<<endl;
			 //cout << "2 - " << d_tab_with_value[1]<<endl;
			 //cout << "3 - " << d_tab_with_value[2]<<endl;

			CFunction fun(d_tab_with_value[0], d_tab_with_value[1], d_tab_with_value[2]);
			function_vector.push_back(fun);
			//cout << "koniec linii" << endl;
			i_index = 0;
			i_tab_index = 0;
			s_value = VAL_S_EMPTY;

		}//while (!file.eof())
		file.close();
	}//if (file.good() == true)
	else
	{
		cout << LACK_OF_ACCESS;
	}// else if (file.good() == true)

	for (int i = 0; i < function_vector.size(); i++)
	{
		function_vector[i].print();
	}//for (int i = 0; i < function_vector.size(); i++)
}//void CSystem4 :: getFromFile()

void CSystem4::saveToFile()
{
	string s_line;
	string s_res;
	fstream file;

	file.open("wyniki.txt", ios::out | ios::app);

	if (file.good() == true)
	{

		for (int i = 0; i < result_vector.size(); i++)
		{

			s_res = result_vector[i]->preOrder(result_vector[i]->getRoot(), s_res);
			//cout << s_res << endl;
			file << s_res << endl;
		}//for (int i = 0;i < result_vector.size(); i++)
		file.close();
	}//if (file.good() == true)
	else
	{
		cout << LACK_OF_ACCESS;
	}//else if (file.good() == true)
}//void CSystem4 :: saveToFile()



void CSystem4::crossingAllTree()
{
	vector <CTree*>tree_vector_new;
	int i_random_crossing;
	int i_random_one;
	int i_random_two;
	int i_index = 0;

	CTree* tree_1;
	CTree* tree_2;

	while (tree_vector_new.size() != tree_vector.size())
	{
		i_random_crossing = rand() % (I_2);						//prawdopodobienstwo krzyzowania
		i_random_one = rand() % (tree_vector.size());
		i_random_two = rand() % (tree_vector.size());

		tree_1 = new CTree(*(tree_vector[i_random_one]));
		tree_2 = new CTree(*(tree_vector[i_random_two]));

		if (i_random_crossing == 0)
		{
			tree_1->crossingTree(*tree_2);
		}//if (i_random_crossing == 0)
		tree_vector_new.push_back(tree_1);
		tree_vector_new.push_back(tree_2);

	}//while (tree_vector_new.size() != tree_vector.size())

	for (int i = 0; i < tree_vector.size(); i++)
	{
		delete tree_vector[i];
	}//for (int i = 0; i < tree_vector.size(); i++)
	 //cout << "ROZMIAR TO: " << tree_vector_new.size()<<endl;

	tree_vector = tree_vector_new;


}//void CSystem4 :: crossingAllTree()


void CSystem4::mutationAllTree()
{
	int i_random_mutation;
	for (int i = 0; i < tree_vector.size(); i++)
	{
		i_random_mutation = rand() % (I_2);						//prawdopodobienstwo mutowania

		if (i_random_mutation == 0)
		{
			tree_vector[i]->mutationTree();
		}//	if (i_random_mutation == 0)
	}//for (int i = 0; i < tree_vector.size(); i++)


}//void CSystem4 :: mutationAllTree()