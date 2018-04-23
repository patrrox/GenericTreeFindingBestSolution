// Zadanie3.cpp: Definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include"CInterface.h"
#include "CInterface4.h"
#include "CSystem.h"
#include "CInterface_4.h"
using namespace std;



vector<string> getInput()
{
	string wejscie;
	string komenda = "";
	vector<string> wektor;

	getline(cin, wejscie);
	wejscie += " ";

	int i = 0;
	while (i < wejscie.size())
	{
		if (wejscie[i] == ' ') {
			wektor.push_back(komenda);
			komenda = "";
		}
		else {
			komenda += wejscie[i];
		}
		i++;
	}

	return wektor;
}

int main()
{
	srand(time(NULL));
	/*
	vector <CFunction> vectors;

	CFunction fun_1(2, 1, 0);
	CFunction fun_2(2.5,2,3);
	CFunction fun_3(10,23.8, 222.4);


	vectors.push_back(fun_1);
	vectors.push_back(fun_2);
	vectors.push_back(fun_3);

	vector <string> vector_1;
	vector_1.push_back("enter");
	vector_1.push_back("*");
	vector_1.push_back("-");
	vector_1.push_back("x");
	vector_1.push_back("1");
	vector_1.push_back("+");
	vector_1.push_back("y");
	vector_1.push_back("4");
	CTree *tree1 = new CTree();
	enter(*tree1, vector_1);


	tree1->calcFitness(vectors);
	cout << "FITNESS TO: " << tree1->getEvaluationResult();

	cout << endl;
	*/

	//cout << "TEST NOWEGO" << endl;

	/*
	vector <string> vector_1;
	vector_1.push_back("enter");
	vector_1.push_back("+");
	vector_1.push_back("y");
	vector_1.push_back("-");
	vector_1.push_back("4");
	vector_1.push_back("x");
	CTree *tree1 = new CTree();

	enter(*tree1, vector_1);

	print(*tree1, vector_1);
	

	tree1->cutTree(2, 0, tree1->getRoot());
	*/
	//cout << "po usunieciu: " << endl;

	//print(*tree1, vector_1);


	


	startSystem(1000, 150);

	
	cout << "END TESTU";
	cin.get();
	

	/*

	CInterface4 system_1;
	system_1.start(10000, 1000000);
	//system_1.start(100, 1);
	system_1.saveToFile();

	cout << "END";
	cin.get();
	*/		//DZIALA









	//system_1.test(10000);

	
	//system_1.start(100, 10000);


	/*
	CTree * tree_1 = new CTree();
	tree_1->generateTree();

	string s_result = VAL_S_EMPTY;
	tree_1->preOrder(tree_1->getRoot(), s_result);
	cout << s_result << endl;
	
	cout << "wartosc" << tree_1->calculateValue(tree_1->getRoot(), 1, 2);
	*/
	


	/*
	vector <string> vector_1;
	vector_1.push_back("enter");
	vector_1.push_back("+");
	vector_1.push_back("y");
	vector_1.push_back("-");
	vector_1.push_back("4");
	vector_1.push_back("x");
	CTree *tree1 = new CTree();

	

	vector <string>vector_2;
	vector_2.push_back("enter");
	vector_2.push_back("+");
	vector_2.push_back("+");
	vector_2.push_back("3");
	vector_2.push_back("x");
	vector_2.push_back("-");
	vector_2.push_back("4");
	vector_2.push_back("/");
	vector_2.push_back("y");
	vector_2.push_back("2");

	CTree *tree2 = new CTree();



	
	cout << "TEST GENEROWANIA DRZEWA 1" << endl;
	enter(*tree1, vector_1);
	print(*tree1,vector_1);
	cout << endl;
	cout << "TEST GENEROWANIA DRZEWA 2" << endl;
	enter(*tree2, vector_2);
	print(*tree2, vector_2);


	


	cout << endl<<"TEST GENEROWANIA DRZEWA 3" << endl;

	CTree *tree3 = new CTree();
	tree3->generateTree();

	string s_result = VAL_S_EMPTY;
	tree3->preOrder(tree3->getRoot(), s_result);
	cout << s_result << endl;
	
	cout << "TEST GENEROWANIA DRZEWA 4" << endl;
	CTree *tree4 = new CTree();
	tree4->generateTree();
	
	string s_result1 = VAL_S_EMPTY;
	tree4->preOrder(tree4->getRoot(), s_result1);
	cout << s_result1 << endl;
	
	
	
	CVariable variable1("x");
	variable1.setValue(1);
	CVariable variable2("y");
	variable2.setValue(5);
	tree3->addVariable(variable1);
	tree3->addVariable(variable2);
	tree2->addVariable(variable2);
	tree2->addVariable(variable1);

	cout << "wartosc 2 drzewa to: ";
	cout << calculateValue(tree2->getRoot(), *tree2)<<endl;

	cout << "wartosc 3 drzewa to: ";
	cout<<calculateValue(tree3->getRoot(),*tree3)<<endl;


	cout << "TEST DRZEWA 5" << endl;
	vector <string> vector_5;
	vector_5.push_back("enter");
	vector_5.push_back("+");
	vector_5.push_back("x");
	vector_5.push_back("y");
	CTree *tree5 = new CTree();
	enter(*tree5, vector_5);
	print(*tree5, vector_5);
	cout << "TEST DRZEWA 5 PO MUTACJI" << endl;
	tree5->mutationTree();
	print(*tree5, vector_5);

	cout <<endl<<endl<< "TEST DRZEWA 6 i 7 PO KRZYZOWANIU" << endl << endl;

	vector <string> vector_6;
	vector_6.push_back("enter");
	vector_6.push_back("+");
	vector_6.push_back("x");
	vector_6.push_back("y");
	CTree *tree6 = new CTree();
	enter(*tree6, vector_6);
	print(*tree6, vector_6);
	cout << endl;
	vector <string> vector_7;
	vector_7.push_back("enter");
	vector_7.push_back("-");
	vector_7.push_back("d");
	vector_7.push_back("c");
	CTree *tree7 = new CTree();
	enter(*tree7, vector_7);
	print(*tree7, vector_7);
	cout << endl;

	cout << endl << "PO KRZYZOWANIU" << endl;

	tree6->crossingTree(*tree7);

	print(*tree6, vector_6);
	cout << endl;
	print(*tree7, vector_7);




	cout << endl << "TEST GENEROWANIA W INTERFACE" << endl;

	
	*/

	
	//system_1.printTreeVector();




	/*
	tree9->mutationTree();
	tree10->mutationTree();
	tree11->mutationTree();
	tree12->mutationTree();
	tree13->mutationTree();
	tree14->mutationTree();
	*/


	
	//CSystem system;
	//system.start();
	
	/*
	vector <string>wektor = getInput();
	CTree *tree= new CTree();
	enter(*tree, wektor);
	print(*tree, wektor);

	

	vector <string>wektor1 = getInput();
	CTree *tree1 = new CTree();
	enter(*tree1, wektor1);
	print(*tree1, wektor1);

	CTree *newtree= new CTree();
	*newtree = *tree + *tree1;
	cout << endl << endl<< "newtree: "  << endl;
	print(*newtree, wektor);

	cout << endl << endl << endl;

	delete newtree;
	

	*/












	//delete newtree;


	//print(*newtree, wektor1);




	//, posprawdzac tego delete z kons usuwajacego, kopiowac vektor z variable, operator +




	//tree = tree1;
	//print(tree1, wektor);

	/*
	cout << endl << endl << "test dolaczania" << endl;
	CTree newtree;
	newtree = join(tree, wektor);
	cout << endl << endl << endl << "nowy";
	print(newtree, wektor);

	cout << endl << endl << "KONIEC";

	*/
	

	//CSystem system;
	//system.start();

	/*
	//P
	vector <string>wektor = getInput();
	
	CTree* tree=new CTree();
	enter(*tree,wektor);
	print(*tree,wektor);

	cout << endl << "kasuje drzewo" << endl;
	delete tree;
	//P
	*/


	/*
	wektor = getInput();
	comp(tree, wektor);

	cout << endl<<endl;
	vars(tree);
	*/

	/*
	vector <string>wektor = getInput();

	CTree tree;
	enter(tree, wektor);
	print(tree, wektor);

	
	
	cout <<endl<< endl << "test dolaczania" << endl;
	CTree newtree;
	newtree=join(tree, wektor);
	cout << endl << endl << endl << "nowy";
	print(newtree, wektor);

	cout << endl << endl<<"KONIEC";
	//delete tree;
	//delete tree;
	_CrtDumpMemoryLeaks();
	cin.get();
	*/
	
	
	

    return 0;
}

