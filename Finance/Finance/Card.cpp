#include "Card.h"

//Клас карт та гаманців
Card::Card(string name, int balance, bool iscredit) 
{
	this->name = name;
	this->balance = balance;
	this->iscredit = iscredit;
}
string Card::getName() 
{
	return name;
}
int Card::getBalance()
{
	return balance;
}
bool Card::Credit() 
{
	return iscredit;
}
void Card::updateBalance(int balance)
{
	this->balance += balance;
}

string Card::toString() 
{
	return name + "\n" + to_string(balance) + "\n" + (iscredit ? "Кредитна карта" : "Дебетова картка");
}