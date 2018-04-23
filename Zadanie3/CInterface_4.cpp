#include "stdafx.h"
#include "CInterface_4.h"



void startSystem(int iNp, int iNi)
{
	CSystem4 system_1;

	

		system_1.initialization(iNp);
		//cout << "PO INIZJALIZACJI: " << endl;
		//printTreeVector();
		//cout << "PO EVALUACJI: " << endl;
		system_1.evaluation();

		int i = 0;
		while (i < iNi)
		{
			system_1.selection();
			system_1.crossingAllTree();
			system_1.mutationAllTree();
			system_1.evaluation();
			i++;
		}//while (i < iNi)


		system_1.saveToFile();
}//void startSystem(int iNp, int iNi)