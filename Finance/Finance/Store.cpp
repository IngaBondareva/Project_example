#include "Store.h"
using namespace std;
//конструктор класу сховища
Store::Store()
{
	load();
}

//завантаження із файлів
void Store::load() 
{
    ifstream my_file("Cards.txt");
    if (my_file.is_open())
    {
        string name;
        while (getline(my_file, name))
        {
            string balance;
            string credit;

            getline(my_file, balance);
            getline(my_file, credit);
            Card card(name, stoi(balance), stoi(credit) == 1 ? true : false);
            cards.push_back(card);
        }
        my_file.close();
    }
    else cout << "Не вдається відкрити файл Shops";
    ifstream my_file2("Payments.txt");
    if (my_file2.is_open())
    {
        string name;
        while (getline(my_file2, name))
        {

            string day;
            string month;
            string year;
            string category;
            string cost;

            getline(my_file2, day);
            getline(my_file2, month);
            getline(my_file2, year);
            getline(my_file2, category);
            getline(my_file2, cost);

            Payment payment(name,stoi(day),stoi(month),stoi(year),category,stoi(cost));
            payments.push_back(payment);

        }
        my_file2.close();
    }
    else cout << "Неможливо відкрити файл Payments";
}
//запис в файл
void Store::save() 
{
    ofstream my_file("Cards.txt");
    for (int i = 0; i < cards.size(); i++)
    {
        if (my_file.is_open())
        {
            my_file << cards.at(i).getName();
            my_file << "\n";
            my_file << cards.at(i).getBalance();
            my_file << "\n";
            my_file << cards.at(i).Credit() ? 1 : 0;
            my_file << "\n";            
        }
    }
    my_file.close();
    ofstream my_file2("Payments.txt");
    for (int i = 0; i < payments.size(); i++)
    {
        if (my_file2.is_open())
        {
            my_file2 << payments.at(i).getName();
            my_file2 << "\n";
            my_file2 << payments.at(i).getDay();
            my_file2 << "\n";
            my_file2 << payments.at(i).getMonth();
            my_file2 << "\n";
            my_file2 << payments.at(i).getYear();
            my_file2 << "\n";
            my_file2 << payments.at(i).getCategory();
            my_file2 << "\n";
            my_file2 << payments.at(i).getCost();
            my_file2 << "\n";
        }
    }
    my_file2.close();
}
//обновлення баланса карти
void Store::updateBalance(int index, int money) 
{
    cards.at(index - 1).updateBalance(money);
    save();
}
//отримання списку всіх карт
vector<Card> Store::getAllCards()
{
    system("cls");
    for (int i = 0; i < cards.size(); i++) 
    {
        cout <<"Card number: " << i + 1 << endl;
        cout << cards.at(i).toString() << endl;
        cout << "_________________________>" << endl;
    }
	return this->cards;
}
//отримання списку всіх платежів
vector<Payment> Store::getAllPayments() 
{
    system("cls");
    for (int i = 0; i < payments.size(); i++) 
    {
        cout << payments.at(i).toString() << endl;
        cout << "___________________________>" << endl;
    }
    return this->payments;
}
//оформлення нового платежу
bool Store::makePayment(Payment payment, int index) 
{
    if (payment.getCost() < cards.at(index-1).getBalance()) 
    {
        payments.push_back(payment);
        cards.at(index - 1).updateBalance(-1 * payment.getCost());
        save();
        return true;
    }
    else
    {
        cout << "На картці немає грошей для цієї оплати..." << endl;
        _getch();
        return false;
    }
}
//додавання картки
void Store::addCard(Card card) 
{
    cards.push_back(card);
    save();
}
//отримання всіх покупок за певний день
void Store::getAllPaymentsByDay(int day, int month, int year) 
{
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) 
    {
        if (payments.at(i).getDay() == day && payments.at(i).getMonth() == month && payments.at(i).getYear() == year) 
        {
            cout << payments.at(i).toString() << endl;
            cout << "___________________________>" << endl;
            flag = true;
        }
    }
    if (!flag)
    {
        cout << "Таких виплат немає..." << endl;
    }
}
//отримання всіх покупок за тиждень
void Store::getAllPaymentsByWeek(int week, int month, int year) 
{
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++)
    {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year ) 
        {
            if (week == 1 && payments.at(i).getDay() >= 1 && payments.at(i).getDay() <= 7) 
            {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "___________________________>" << endl;
            }
            else if (week == 2 && payments.at(i).getDay() > 7 && payments.at(i).getDay() <= 14)
            {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "___________________________>" << endl;
            }
            else if (week == 3 && payments.at(i).getDay() > 14 && payments.at(i).getDay() <= 21) 
            {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "___________________________>" << endl;
            }
            else if (week == 4 && payments.at(i).getDay() > 21 && payments.at(i).getDay() < 31)
            {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "___________________________>" << endl;
            }
        }
    }
    if (!flag) 
    {
        cout << "Таких виплат немає..." << endl;
    }
}
//отримання всіх покупок за певний місяць
void Store::getAllPaymentsByMonth(int month, int year) 
{
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) 
    {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year) 
        {
            cout << payments.at(i).toString() << endl;
            cout << "___________________________>" << endl;
            flag = true;
        }
    }
    if (!flag) {
        cout << "Таких виплат немає..." << endl;
    }
}
//отримання всіх покупок за певний день + категорія
void Store::getAllPaymentsByDayAndCategory(int day, int month, int year, string category) 
{
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++)
    {
        if (payments.at(i).getDay() == day && payments.at(i).getMonth() == month && payments.at(i).getYear() == year && category.compare(payments.at(i).getCategory())==0) {
            cout << payments.at(i).toString() << endl;
            cout << "___________________________>" << endl;
            flag = true;
        }
    }
    if (!flag) 
    {
        cout << "Таких виплат немає..." << endl;
    }
}
//отримання всіх покупок за тиждень + категорія
void Store::getAllPaymentsByWeekAndCategory(int week, int month, int year, string category) 
{
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) 
    {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year && category.compare(payments.at(i).getCategory()) == 0)
        {
            if (week == 1 && payments.at(i).getDay() >= 1 && payments.at(i).getDay() <= 7) 
            {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "___________________________>" << endl;
            }
            else if (week == 2 && payments.at(i).getDay() > 7 && payments.at(i).getDay() <= 14) 
            {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "___________________________>" << endl;
            }
            else if (week == 3 && payments.at(i).getDay() > 14 && payments.at(i).getDay() <= 21) 
            {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "___________________________>" << endl;
            }
            else if (week == 4 && payments.at(i).getDay() > 21 && payments.at(i).getDay() < 31) 
            {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "___________________________>" << endl;
            }
        }
    }
    if (!flag) 
    {
        cout << "Таких виплат немає..." << endl;
    }
}
//отримання всіх покупок за місяць + категорія
void Store::getAllPaymentsByMonthAndCategory(int month, int year, string category) 
{
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) 
    {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year && category.compare(payments.at(i).getCategory()) == 0)
        {
            cout << payments.at(i).toString() << endl;
            cout << "___________________________>" << endl;
            flag = true;
        }
    }
    if (!flag) 
    {
        cout << "Таких виплат немає..." << endl;
    }
}
//топ 3 покупки за тиждень
void Store::getTop3PaymentByWeek(int week, int month, int year) 
{
    vector<Payment> sorted;
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) 
    {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year) 
        {
            if (week == 1 && payments.at(i).getDay() >= 1 && payments.at(i).getDay() <= 7) 
            {
                flag = true;
                sorted.push_back(payments.at(i));
            }
            else if (week == 2 && payments.at(i).getDay() > 7 && payments.at(i).getDay() <= 14) 
            {
                flag = true;
                sorted.push_back(payments.at(i));
            }
            else if (week == 3 && payments.at(i).getDay() > 14 && payments.at(i).getDay() <= 21) 
            {
                flag = true;
                sorted.push_back(payments.at(i));
            }
            else if (week == 4 && payments.at(i).getDay() > 21 && payments.at(i).getDay() < 31) 
            {
                flag = true;
                sorted.push_back(payments.at(i));
            }
        }
    }
    if (!flag) 
    {
        cout << "Таких виплат немає..." << endl;
    }
    else {
        Payment temp;
        for (int i = 0; i < sorted.size() - 1; i++)
        {
            for (int j = 0; j < sorted.size() - i - 1; j++) 
            {
                if (sorted.at(j).getCost() < sorted.at(j + 1).getCost()) 
                {
                    temp = sorted.at(j);
                    sorted.at(j) = sorted.at(j + 1);
                    sorted.at(j + 1) = temp;
                }
            }
        }
        for (int i = 0; i < sorted.size(); i++) 
        {
            if (i < 3) {
                cout << sorted.at(i).toString() << endl;
                cout << "___________________________>" << endl;
            }
        }
    }
}
//топ 3 покупки за месяц
void Store::getTop3PaymentByMonth(int month, int year)
{
    vector<Payment> sorted;
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++)
    {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year)
        {
            flag = true;
            sorted.push_back(payments.at(i));
        }
    }
    if (!flag) 
    {
        cout << "Таких виплат немає..." << endl;
    }
    else 
    {
        Payment temp;
        for (int i = 0; i < sorted.size() - 1; i++) 
        {
            for (int j = 0; j < sorted.size() - i - 1; j++)
            {
                if (sorted.at(j).getCost() < sorted.at(j + 1).getCost()) 
                {
                    temp = sorted.at(j);
                    sorted.at(j) = sorted.at(j + 1);
                    sorted.at(j + 1) = temp;
                }
            }
        }
        for (int i = 0; i < sorted.size(); i++) 
        {
            if (i < 3) {
                cout << sorted.at(i).toString() << endl;
                cout << "___________________________>" << endl;
            }
        }
    }
}
//топ 3 категории за тиждень
void Store::getTop3CategoryByWeek(int week, int month, int year) 
{
    map<string, int> result;
    vector<Payment> sorted;
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) 
    {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year) 
        {
            if (week == 1 && payments.at(i).getDay() >= 1 && payments.at(i).getDay() <= 7) 
            {
                flag = true;
                sorted.push_back(payments.at(i));
            }
            else if (week == 2 && payments.at(i).getDay() > 7 && payments.at(i).getDay() <= 14)
            {
                flag = true;
                sorted.push_back(payments.at(i));
            }
            else if (week == 3 && payments.at(i).getDay() > 14 && payments.at(i).getDay() <= 21)
            {
                flag = true;
                sorted.push_back(payments.at(i));
            }
            else if (week == 4 && payments.at(i).getDay() > 21 && payments.at(i).getDay() < 31)
            {
                flag = true;
                sorted.push_back(payments.at(i));
            }
        }
    }
    if (!flag) 
    {
        cout << "Немає таких виплат…" << endl;
    }
    else
    {
        for (int i = 0; i < sorted.size(); i++)
        {
            if (result.count(sorted.at(i).getCategory())) 
            {
                int value = result.find(sorted.at(i).getCategory())->second;
                result.find(sorted.at(i).getCategory())->second += sorted.at(i).getCost();
            }
            else 
            {
                result.insert({ sorted.at(i).getCategory(),sorted.at(i).getCost() });
            }
        }
        vector<pair<string, int>> vec;


        copy(result.begin(),
            result.end(),
            back_inserter<vector<pair<string, int>>>(vec));


         sort(vec.begin(), vec.end(),
            [](const pair<string, int>& l, const pair<string, int>& r)
            {
                if (l.second != r.second)
                {
                    return l.second > r.second;
                }

                return l.first > r.first;
            });

        int count = 0;
        for (auto const& pair : vec) 
        {
            if (count < 3)
            {
                cout << '{' << pair.first << "," << pair.second << '}' << endl;
                count++;
            }
        }

    }
}
//топ 3 категорії за місяць
void Store::getTop3CategoryByMonth(int month, int year)
{
    map<string, int> result;
    
    vector<Payment> sorted;
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) 
    {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year) 
        {
            flag = true;
            sorted.push_back(payments.at(i));
        }
    }
    if (!flag) 
    {
        cout << "Немає таких виплат…" << endl;
    }
    else 
    {
        for (int i = 0; i < sorted.size(); i++) 
        {
            if (result.count(sorted.at(i).getCategory())) 
            {
                int value = result.find(sorted.at(i).getCategory())->second;
                result.find(sorted.at(i).getCategory())->second += sorted.at(i).getCost();
            }
            else 
            {
                result.insert({ sorted.at(i).getCategory(),sorted.at(i).getCost() });
            }
        }
        // створення порожнього вектору пар
        vector<pair<string,int>> vec;

        copy(result.begin(),
            result.end(),
            back_inserter<std::vector<pair<string, int>>>(vec));

        
        sort(vec.begin(), vec.end(),
            [](const pair<string, int>& l, const pair<string, int>& r)
            {
                if (l.second != r.second) {
                    return l.second > r.second;
                }

                return l.first > r.first;
            });

        
        int count = 0;
        for (auto const& pair : vec) 
        {
            if (count < 3) 
            {
                cout << '{' << pair.first << "," << pair.second << '}' << endl;
                count++;
            }
        }  
    }
}