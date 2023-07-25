#include "Menu.h"
#include <conio.h>

Menu::Menu() 
{
	//запуск меню
	main();
}

//Меню
void Menu::main()
{
	int choose = -1;
	while (choose != 3)
	{
		system("cls");
		cout << "1.Картки\n" ;
		cout << "2.Платежі\n" ;
		cout << "3.Вихід\n" ;
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

//меню роботи с картами
void Menu::cards()
{
	
	int choose = -1;
	while (choose != 3) 
	{
		system("cls");
		cout << "1.Всі картки" << endl;
		cout << "2.Додайте гроші" << endl;
		cout << "3.Додати картку" << endl;
		cout << "4.Вихід" << endl;
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
				cout << "Введіть номер картки для поповнення: ";
				cin >> index;
				cout << "Введіть суму грошей : ";
				cin >> money;
				store.updateBalance(index, money);
				break;
			}
			case 3:
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				string name;
				int balance;
				cout << "Введіть назву картки" << endl;
				fflush(stdin);
				getline(cin, name);
				cout << "Введіть баланс картки" << endl;
				cin >> balance;
				cout << "1.Оберіть" << endl;
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

//меню для роботи з покупками (витратами)
void Menu::payments() 
{
	int choose = -1;

	while (choose != 13)
	{
		system("cls");
		cout << "1.Всі платежі" << endl;
		cout << "2.Здійснити оплату" << endl;
		cout << "3.Платежі за день" << endl;
		cout << "4.Платежі за тиждень " << endl;
		cout << "5.Платежі за місяць " << endl;
		cout << "6.Платежі за день і по категоріям " << endl;
		cout << "7.Платежі за тиждень і по категоріям " << endl;
		cout << "8.Платежі за місяць і по категоріям " << endl;
		cout << "9.TOP-3 Платежів за день" << endl;
		cout << "10.TOP-3 Платежів за місяць" << endl;
		cout << "11.TOP-3 Категорії за тиждень " << endl;
		cout << "12.TOP-3 Категорії за місяць " << endl;
		cout << "13.Вихід" << endl;
		
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
				cout << "Введіть назву платежу" << endl;
				fflush(stdin);
				getline(cin, name);
				
				cout << "Введіть день" << endl;
				cin >> day;
				cout << "Введіть місяць" << endl;
				cin >> month;
				cout << "Введіть рік" << endl;
				cin >> year;
				cout << "Виберіть категорію:" << endl;
				cout << "1.Продукти" << endl;
				cout << "2.Електроніка" << endl;
				cout << "3.Інтернет" << endl;
				cout << "4.Одяг" << endl;
				cout << "5.Комунальні послуги" << endl;
				cout << "6.Навчання" << endl;
				cout << "7.Інше" << endl;
				
				int cat =-1;
				cin >> cat;

				switch (cat)
				{
					case 1: 
					{
						category = "Продукти";
						break;
					}
					case 2: 
					{
						category = "Електроніка";
						break;
					}
					case 3:
					{
						category = "Інтернет";
						break;
					}
					case 4: 
					{
						category = "Одяг";
						break;
					}
					case 5:
					{
						category = "Комунальні послуги";
						break;
					}
					case 6: 
					{
						category = "Навчання";
						break;
					}
					case 7:
					{
						category = "Інше";
						break;
					}
				}

				cout << "Введіть вартість" << endl;
				cin >> cost;
				Payment payment(name, day, month, year, category, cost);
				int index;
					system("cls");
					store.getAllCards();
					cout << "Введіть номер картки для здійснення оплати:";
					cin >> index;
				
				break;
			}
			case 3:
			{
				system("cls");
				int day;
				int month;
				int year;
				
				cout << "Введіть день" << endl;
				cin >> day;
				cout << "Введіть місяць" << endl;
				cin >> month;
				cout << "Введіть рік" << endl;
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

				cout << "Введіть тиждень" << endl;
				cin >> week;
				cout << "Введіть місяць" << endl;
				cin >> month;
				cout << "Введіть рік" << endl;
				cin >> year;

				store.getAllPaymentsByWeek(week, month, year);
				_getch();

				break;
			}
			case 5:
			{	system("cls");
				
				int month;
				int year;

				cout << "Введіть місяць" << endl;
				cin >> month;
				cout << "Введіть рік" << endl;
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

				cout << "Введіть день" << endl;
				cin >> day;
				cout << "Введіть місяць" << endl;
				cin >> month;
				cout << "Введіть рік" << endl;
				cin >> year;


				cout << "Виберіть категорію:" << endl;
				cout << "1.Продукти" << endl;
				cout << "2.Електроніка" << endl;
				cout << "3.Інтернет" << endl;
				cout << "4.Одяг" << endl;
				cout << "5.Комунальні послуги" << endl;
				cout << "6.Навчання" << endl;
				cout << "7.Інше" << endl;

				int cat = -1;
				cin >> cat;

				switch (cat) 
				{
				case 1: 
				{
					category = "Продукти";
					break;
				}
				case 2: {
					category = "Електроніка";
					break;
				}
				case 3: {
					category = "Інтернет";
					break;
				}
				case 4: {
					category = "Одяг";
					break;
				}
				case 5: {
					category = "Комунальні послуги";
					break;
				}
				case 6: {
					category = "Навчання";
					break;
				}
				case 7: {
					category = "Інше";
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

				cout << "Введіть день" << endl;
				cin >> week;
				cout << "Введіть тиждень" << endl;
				cin >> month;
				cout << "Введіть рік" << endl;
				cin >> year;


				cout << "Виберіть категорію:" << endl;
				cout << "1.Продукти" << endl;
				cout << "2.Електроніка" << endl;
				cout << "3.Інтернет" << endl;
				cout << "4.Одяг" << endl;
				cout << "5.Комунальні послуги" << endl;
				cout << "6.Навчання" << endl;
				cout << "7.Інше" << endl;


				int cat = -1;
				cin >> cat;

				switch (cat)
				{
				case 1:
				{
					category = "Продукти";
					break;
				}
				case 2: 
				{
					category = "Електроніка";
					break;
				}
				case 3: 
				{
					category = "Інтернет";
					break;
				}
				case 4: 
				{
					category = "Одяг";
					break;
				}
				case 5: 
				{
					category = "Комунальні послуги";
					break;
				}
				case 6:
				{
					category = "Навчання";
					break;
				}
				case 7:
				{
					category = "Інше";
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

				cout << "Введіть місяць" << endl;
				cin >> month;
				cout << "Введіть рік" << endl;
				cin >> year;


				cout << "Виберіть категорію:" << endl;
				cout << "1.Продукти" << endl;
				cout << "2.Електроніка" << endl;
				cout << "3.Інтернет" << endl;
				cout << "4.Одяг" << endl;
				cout << "5.Комунальні послуги" << endl;
				cout << "6.Навчання" << endl;
				cout << "7.Інше" << endl;

				int cat = -1;
				cin >> cat;

				switch (cat)
				{
				case 1:
				{
					category = "Продукти";
					break;
				}
				case 2:
				{
					category = "Електроніка";
					break;
				}
				case 3:
				{
					category = "Інтернет";
					break;
				}
				case 4:
				{
					category = "Одяг";
					break;
				}
				case 5:
				{
					category = "Комунальні послуги";
					break;
				}
				case 6:
				{
					category = "Навчання";
					break;
				}
				case 7:
				{
					category = "Інше";
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

				cout << "Введіть тиждень" << endl;
				cin >> week;
				cout << "Введіть місяць" << endl;
				cin >> month;
				cout << "Введіть рік" << endl;
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

				cout << "Введіть місяць" << endl;
				cin >> month;
				cout << "Введіть рік" << endl;
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

				cout << "Введіть тиждень" << endl;
				cin >> week;
				cout << "Введіть місяць" << endl;
				cin >> month;
				cout << "Введіть рік" << endl;
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

				cout << "Введіть місяць"  << endl;
				cin >> month;
				cout << "Введіть рік" << endl;
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
