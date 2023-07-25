#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Card.h"
#include "Payment.h"
#include <conio.h>
#include <map>
#include <algorithm>

//опис класу зберігання даних
class Store
{
private:
	vector<Card> cards;
	vector<Payment> payments;
public:
	Store();
	
	void load();
	void save();
	
	vector<Card> getAllCards();
	vector<Payment> getAllPayments();
	
	void addCard(Card card);
	void updateBalance(int index, int money);

	bool makePayment(Payment payment, int index);
	
	void getAllPaymentsByDay(int day, int month,int year);
	void getAllPaymentsByWeek(int week, int month, int year);
	void getAllPaymentsByMonth(int month, int year);
	void getAllPaymentsByDayAndCategory(int day, int month, int year, string category);
	void getAllPaymentsByWeekAndCategory(int week, int month, int year, string category);
	void getAllPaymentsByMonthAndCategory(int month, int year, string category);
	
	void getTop3PaymentByWeek(int week, int month, int year);
	void getTop3PaymentByMonth(int month, int year);
	void getTop3CategoryByWeek(int week, int month, int year);
	void getTop3CategoryByMonth(int month, int year);

};

