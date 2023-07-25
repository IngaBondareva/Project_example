#pragma once
#include <string>

using namespace std;
//опис класса карт і гаманців
class Card
{
private:
	string name;
	int balance;
	bool iscredit;
public:
	Card(string name, int balance, bool isCredit);
	void updateBalance(int balance);
	string getName();
	int getBalance();
	bool Credit();
	string toString();
};

