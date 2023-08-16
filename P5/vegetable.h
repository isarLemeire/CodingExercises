#pragma once

#include "food.h"

class Vegetable : public Food {
public:
	Vegetable();
	Vegetable(std::string name, long price, Timestamp* ts);
	Vegetable(Vegetable& f);
	~Vegetable();

	virtual std::string get_category();
};
