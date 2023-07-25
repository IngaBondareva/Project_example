#pragma once
#include <string>

using namespace std;

// класс витрат
class Payment
{
private:
	string name;
	int day;
	int month;
	int year;
	string category;
	int cost;
public:
	Payment();
	Payment(string name, int day, int month, int year, string category, int cost);
	string getName();
	int getDay();
	int getMonth();
	int getYear();
	string getCategory();
	int getCost();
	string toString();
};

