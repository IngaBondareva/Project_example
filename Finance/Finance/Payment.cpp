#include "Payment.h"
// класс витрат
Payment::Payment() 
{

}

Payment::Payment(string name, int day, int month, int year, string category, int cost)
{
	this->name = name;
	this->day = day;
	this->month = month;
	this->year = year;
	this->category = category;
	this->cost = cost;
}

string Payment::getName() 
{
	return name;
}
int Payment::getDay() 
{
	return day;
}
int Payment::getMonth() 
{
	return month;
}
int Payment::getYear() 
{
	return year;
}
string Payment::getCategory()
{
	return category;
}
int Payment::getCost()
{
	return cost;
}
string Payment::toString()
{
	return name + "\n" + to_string(day) + " " + to_string(month) + " " + to_string(year) + "\n" + category + "\n" + to_string(cost) + "$"; // строка
}