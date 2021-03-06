#pragma once
#include "CTree.h"
#include "CFunction.h"
#include <fstream>


class CSystem4
{
public:
	CSystem4();
	~CSystem4();

	void initialization(int iNp);

	void evaluation();

	void printTreeVector();


	void selection();


//	void test(int iNp);

//	void start(int iNp, int iNi);

	void crossingAllTree();
	void mutationAllTree();

	void getFromFile();
	void saveToFile();
private:
	vector <CTree*>tree_vector;
	vector <CFunction> function_vector;
	vector <CTree*> result_vector;
};

