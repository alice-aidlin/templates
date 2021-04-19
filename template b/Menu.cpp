#include "Menu.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

Menu::Menu()
{
	main_Menu();
}

int Menu::choose_group()
{
	int choose;
	do
	{
		cout << "pleace choose group type\n1.group long\n2.group char A\n3.group char B\n4.group string\n";
		cin >> choose;
	} while (!(choose >= 1 && choose <= 4));
	return choose;
}

void Menu::main_Menu()
{
	int check1 = 0;
	int check2 = 0;
	long long_object;
	char charA_object;
	char charB_object;
	string string_object;
	int choice;
	do
	{
		cout << "\nplease enter your choice\n1.add object to group\n2.delete object from group\n3.union between chars groups\n4.intersect between chars groups\n5.differnce between chars groups\n6.print groups\n7.exit\n";
		cin >> choice;

		switch (choice)
		{
		case 1://add group

			switch (choose_group())
			{
			case 1://long
				cout << "enter long number" << endl;
				cin >> long_object;
				long_group += long_object;
				break;
			case 2://CHAR A
				check1 = 1;//know if we have there values
				cout << "enter char" << endl;
				cin >> charA_object;
				charA_group += charA_object;
				break;

			case 3://CHAR B
				check2 = 1;//know if we have there values
				cout << "enter char" << endl;
				cin >> charB_object;
				charB_group += charB_object;
				break;
			case 4://STRING
				cout << "enter string" << endl;
				cin >> string_object;
				string_group += string_object;
				break;
			}
			break;

		case 2://delete
			cout << "\n";
			switch (choose_group())
			{
			case 1:
				cout << "enter long number to delete" << endl;
				cin >> long_object;
				long_group -= long_object;
				break;
			case 2:
				cout << "enter char to delete" << endl;
				cin >> charA_object;
				charA_group -= charA_object;
				break;

			case 3:
				cout << "enter charto delete" << endl;
				cin >> charB_object;
				charB_group -= charB_object;
				break;
			case 4:
				cout << "enter string to delete" << endl;
				cin >> string_object;
				string_group -= string_object;
				break;
			}

			break;

		case 3://union
			cout << "\n";
			cout << charA_group.UNION(charB_group) << endl;
			cout << "\n";

			break;

		case 4://interest
			if (check1 == 0 || check2 == 0)//if one of this group is empty so the insterent is empty
				cout << "{ }";
			else
			{
				cout << "\n";
				cout << charB_group.INTERSECT(charA_group) << endl;
				cout << "\n";
			}
			break;

		case 5:
		
			if (check1 == 0)//if group A empty
			{
				cout << charB_group;

			}
			else if (check2 == 0)//if group A empty
			{
				cout << charA_group;

			}
			else//if no group empty
			{
				int num;
				cout << "What like to do?\n";
				cout << "1." << charA_group << " - " << charB_group << endl;;//charA-charB
				cout << "2." << charB_group << " - " << charA_group << endl;//charB-charA
				cin >> num;//option
				if (num == 1)
					cout << charA_group-charB_group << endl;
				else
					cout << charB_group - charA_group << endl;
			}
		
			

			break;
		case 6://print
			cout << "\n";
			switch (choose_group())
			{
			case 1:
				if(long_group.get_size()>0)
				cout << long_group;
				else { cout << "\nno group exist" << endl; }
				break;
			case 2:
				if (charA_group.get_size() > 0)
					cout << charA_group;
				else { cout << "\nno group exist" << endl; }
				break;

			case 3:
				if (charB_group.get_size() > 0)
					cout << charB_group;
				else { cout << "\nno group exist" << endl; }
				break;
			case 4:
				if (string_group.get_size() > 0)
					cout << string_group;
				else { cout << "\nno group exist" << endl; }
				break;
			}
			break;

		case 7:
			cout << "\n";
			cout << "goodbye\n";
			break;
		default:
			cout << "bad input, please try again!\n";
			break;
		}
	} while (choice != 7);

}
