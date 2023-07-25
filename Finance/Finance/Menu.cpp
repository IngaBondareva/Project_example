#include "Menu.h"
#include <conio.h>

Menu::Menu() 
{
	//������ ����
	main();
}

//����
void Menu::main()
{
	int choose = -1;
	while (choose != 3)
	{
		system("cls");
		cout << "1.������\n" ;
		cout << "2.������\n" ;
		cout << "3.�����\n" ;
		cin >> choose;
		switch (choose) 
		{
			case 1:
			{
				cards();
				break;
			}
			case 2:
			{
				payments();
				break;
			}
			case 3:
			{
				cout << choose << endl;
				break;
			}
		}
	}
}

//���� ������ � �������
void Menu::cards()
{
	
	int choose = -1;
	while (choose != 3) 
	{
		system("cls");
		cout << "1.�� ������" << endl;
		cout << "2.������� �����" << endl;
		cout << "3.������ ������" << endl;
		cout << "4.�����" << endl;
		cin >> choose;
		switch (choose) 
		{
			case 1:
			{
				store.getAllCards();
				_getch();
				break;
			}
			case 2:
			{
				int index;
				int money;
				store.getAllCards();
				cout << "������ ����� ������ ��� ����������: ";
				cin >> index;
				cout << "������ ���� ������ : ";
				cin >> money;
				store.updateBalance(index, money);
				break;
			}
			case 3:
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				string name;
				int balance;
				cout << "������ ����� ������" << endl;
				fflush(stdin);
				getline(cin, name);
				cout << "������ ������ ������" << endl;
				cin >> balance;
				cout << "1.������" << endl;
				cout << "1.Debit" << endl;
				cout << "2.Credit" << endl;
				int type;
				cin >> type;
				Card card(name, balance, type == 1 ? false : true);
				store.addCard(card);
				break;
			}
			case 4:
			{
				main();
				break;
			}
		}
	}
}

//���� ��� ������ � ��������� (���������)
void Menu::payments() 
{
	int choose = -1;

	while (choose != 13)
	{
		system("cls");
		cout << "1.�� ������" << endl;
		cout << "2.�������� ������" << endl;
		cout << "3.������ �� ����" << endl;
		cout << "4.������ �� ������� " << endl;
		cout << "5.������ �� ����� " << endl;
		cout << "6.������ �� ���� � �� ��������� " << endl;
		cout << "7.������ �� ������� � �� ��������� " << endl;
		cout << "8.������ �� ����� � �� ��������� " << endl;
		cout << "9.TOP-3 ������� �� ����" << endl;
		cout << "10.TOP-3 ������� �� �����" << endl;
		cout << "11.TOP-3 ������� �� ������� " << endl;
		cout << "12.TOP-3 ������� �� ����� " << endl;
		cout << "13.�����" << endl;
		
		cin >> choose;

		switch (choose)
		{
			case 1:
			{
				store.getAllPayments();
				_getch();
				break;
			}
			case 2:
			{	
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				string name;
				int day;
				int month;
				int year;
				string category;
				int cost;
				cout << "������ ����� �������" << endl;
				fflush(stdin);
				getline(cin, name);
				
				cout << "������ ����" << endl;
				cin >> day;
				cout << "������ �����" << endl;
				cin >> month;
				cout << "������ ��" << endl;
				cin >> year;
				cout << "������� ��������:" << endl;
				cout << "1.��������" << endl;
				cout << "2.����������" << endl;
				cout << "3.��������" << endl;
				cout << "4.����" << endl;
				cout << "5.��������� �������" << endl;
				cout << "6.��������" << endl;
				cout << "7.����" << endl;
				
				int cat =-1;
				cin >> cat;

				switch (cat)
				{
					case 1: 
					{
						category = "��������";
						break;
					}
					case 2: 
					{
						category = "����������";
						break;
					}
					case 3:
					{
						category = "��������";
						break;
					}
					case 4: 
					{
						category = "����";
						break;
					}
					case 5:
					{
						category = "��������� �������";
						break;
					}
					case 6: 
					{
						category = "��������";
						break;
					}
					case 7:
					{
						category = "����";
						break;
					}
				}

				cout << "������ �������" << endl;
				cin >> cost;
				Payment payment(name, day, month, year, category, cost);
				int index;
					system("cls");
					store.getAllCards();
					cout << "������ ����� ������ ��� ��������� ������:";
					cin >> index;
				
				break;
			}
			case 3:
			{
				system("cls");
				int day;
				int month;
				int year;
				
				cout << "������ ����" << endl;
				cin >> day;
				cout << "������ �����" << endl;
				cin >> month;
				cout << "������ ��" << endl;
				cin >> year;
				
				store.getAllPaymentsByDay(day, month, year);
				_getch();

				break;
			}
			case 4:
			{	
				system("cls");
				int week;
				int month;
				int year;

				cout << "������ �������" << endl;
				cin >> week;
				cout << "������ �����" << endl;
				cin >> month;
				cout << "������ ��" << endl;
				cin >> year;

				store.getAllPaymentsByWeek(week, month, year);
				_getch();

				break;
			}
			case 5:
			{	system("cls");
				
				int month;
				int year;

				cout << "������ �����" << endl;
				cin >> month;
				cout << "������ ��" << endl;
				cin >> year;

				store.getAllPaymentsByMonth(month, year);
				_getch();
				break;
			}
			case 6:
			{	
				system("cls");
				int day;
				int month;
				int year;
				string category;

				cout << "������ ����" << endl;
				cin >> day;
				cout << "������ �����" << endl;
				cin >> month;
				cout << "������ ��" << endl;
				cin >> year;


				cout << "������� ��������:" << endl;
				cout << "1.��������" << endl;
				cout << "2.����������" << endl;
				cout << "3.��������" << endl;
				cout << "4.����" << endl;
				cout << "5.��������� �������" << endl;
				cout << "6.��������" << endl;
				cout << "7.����" << endl;

				int cat = -1;
				cin >> cat;

				switch (cat) 
				{
				case 1: 
				{
					category = "��������";
					break;
				}
				case 2: {
					category = "����������";
					break;
				}
				case 3: {
					category = "��������";
					break;
				}
				case 4: {
					category = "����";
					break;
				}
				case 5: {
					category = "��������� �������";
					break;
				}
				case 6: {
					category = "��������";
					break;
				}
				case 7: {
					category = "����";
					break;
				}
				}
				
				store.getAllPaymentsByDayAndCategory(day, month, year,category);
				_getch();
				break;
			}
			case 7:
			{
				system("cls");
				int week;
				int month;
				int year;
				string category;

				cout << "������ ����" << endl;
				cin >> week;
				cout << "������ �������" << endl;
				cin >> month;
				cout << "������ ��" << endl;
				cin >> year;


				cout << "������� ��������:" << endl;
				cout << "1.��������" << endl;
				cout << "2.����������" << endl;
				cout << "3.��������" << endl;
				cout << "4.����" << endl;
				cout << "5.��������� �������" << endl;
				cout << "6.��������" << endl;
				cout << "7.����" << endl;


				int cat = -1;
				cin >> cat;

				switch (cat)
				{
				case 1:
				{
					category = "��������";
					break;
				}
				case 2: 
				{
					category = "����������";
					break;
				}
				case 3: 
				{
					category = "��������";
					break;
				}
				case 4: 
				{
					category = "����";
					break;
				}
				case 5: 
				{
					category = "��������� �������";
					break;
				}
				case 6:
				{
					category = "��������";
					break;
				}
				case 7:
				{
					category = "����";
					break;
				}

				}

				store.getAllPaymentsByWeekAndCategory(week, month, year, category);
				_getch();
				break;
			}
			case 8:
			{
				system("cls");
				
				int month;
				int year;
				string category;

				cout << "������ �����" << endl;
				cin >> month;
				cout << "������ ��" << endl;
				cin >> year;


				cout << "������� ��������:" << endl;
				cout << "1.��������" << endl;
				cout << "2.����������" << endl;
				cout << "3.��������" << endl;
				cout << "4.����" << endl;
				cout << "5.��������� �������" << endl;
				cout << "6.��������" << endl;
				cout << "7.����" << endl;

				int cat = -1;
				cin >> cat;

				switch (cat)
				{
				case 1:
				{
					category = "��������";
					break;
				}
				case 2:
				{
					category = "����������";
					break;
				}
				case 3:
				{
					category = "��������";
					break;
				}
				case 4:
				{
					category = "����";
					break;
				}
				case 5:
				{
					category = "��������� �������";
					break;
				}
				case 6:
				{
					category = "��������";
					break;
				}
				case 7:
				{
					category = "����";
					break;
				}

				}
				store.getAllPaymentsByMonthAndCategory(month, year, category);
				_getch();
				break;
			}
			case 9:
			{
				system("cls");
				int week;
				int month;
				int year;

				cout << "������ �������" << endl;
				cin >> week;
				cout << "������ �����" << endl;
				cin >> month;
				cout << "������ ��" << endl;
				cin >> year;

				store.getTop3PaymentByWeek(week, month, year);
				_getch();

				break;
			}
			case 10:
			{
				system("cls");
				int month;
				int year;

				cout << "������ �����" << endl;
				cin >> month;
				cout << "������ ��" << endl;
				cin >> year;

				store.getTop3PaymentByMonth(month, year);
				_getch();

				break;
			}
			case 11:
			{
				system("cls");
				int week;
				int month;
				int year;

				cout << "������ �������" << endl;
				cin >> week;
				cout << "������ �����" << endl;
				cin >> month;
				cout << "������ ��" << endl;
				cin >> year;

				store.getTop3CategoryByWeek(week, month, year);
				_getch();
				break;
			}
			case 12:
			{
				system("cls");

				int month;
				int year;

				cout << "������ �����"  << endl;
				cin >> month;
				cout << "������ ��" << endl;
				cin >> year;

				store.getTop3CategoryByMonth(month, year);
				_getch();
				break;
			}
			case 13:
			{
				main();
				break;
			}
		}
	}
}
