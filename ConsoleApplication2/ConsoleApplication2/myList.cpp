// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
//#include "List.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int choice;
	bool flag = false;
	int add_element,element,del_element;
	int pos;
	List<int>* list = new List<int>();

	do
	{
		std::cout << "1. Create list  " << std::endl;
		std::cout << "2. Show list " << std::endl;
		std::cout << "3. Add First element " << std::endl;	
		std::cout << "4. Insert " << std::endl;
		std::cout << "5. Find element " << std::endl;
		std::cout << "6. Reverse " << std::endl;
		std::cout << "7. Delete element " << std::endl;
		std::cout << "8. Delete list " << std::endl;
		std::cout << "9. Delete element with iterator " << std::endl;
		std::cout << "Type command number " << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "List create";
			for (int i=1;i<10;i++) list->add(i);
			break;
		case 2:
		std::cout << "List : ";
		    *list;
			

			list->print();
			break;
		case 3:
			std::cout << "Enter FirstElement " << std::endl;
			std::cin>>add_element;
			list->add_first(add_element);
			list->print();
		
			break;
		case 4:
			std::cout << "Enter Position " << std::endl;
			std::cin>>pos;
			std::cout << "Enter Element " << std::endl;
			std::cin>>add_element;
			list->insert(pos,add_element);
			list->print();
		    break;
		case 5:
			std::cout<<"Enter find element"<< std::endl;
			std::cin>>element;
				list->find(element);
			break;
		case 6:
			//cout<<"Revers list"<< endl << endl;
			list->operator*();	
			break;
		case 7:
			std::cout<<"Enter delete element";
			std::cin>>del_element;
			list->remove1(del_element);	
			break;
		case 8:
			list->del();	
			break;
        case 9:
			for(List<int>::iterator it = list->begin(); it != list->end(); it++)
			{
				if(*it == 8)
				{
					list->remove(it);
					break;
				}
			}
			
			break; 
		}
	}
	while(flag != true);


	std::cin.ignore();
	return 0;
}

