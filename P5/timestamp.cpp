#include "timestamp.h"

Timestamp::Timestamp() {
	day = 0;
	month = 0;
	year = 0;
}

Timestamp::Timestamp(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

Timestamp::Timestamp(Timestamp& timestamp) {
	day = timestamp.day;
	month = timestamp.month;
	year = timestamp.year;
}

Timestamp::~Timestamp() {}

void Timestamp::set_day(int day) {
	this->day = day;
}

void Timestamp::set_month(int month) {
	this->month = month;
}

void Timestamp::set_year(int year) {
	this->year = year;
}

int Timestamp::get_day() {
	return day;
}

int Timestamp::get_month() {
	return month;
}

int Timestamp::get_year() {
	return year;
}
