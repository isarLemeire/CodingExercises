#pragma once

class Timestamp {
public:
	Timestamp();
	Timestamp(int day, int month, int year);
	Timestamp(Timestamp &timestamp);
	~Timestamp();
	
	int get_day();
	int get_month();
	int get_year();

	void set_day(int day);
	void set_month(int month);
	void set_year(int year);

private:
	int day;
	int month;
	int year;
};
