#pragma once

#include "food.h"

class Fruit : public Food {
public:
	Fruit();
	Fruit(std::string name, long price, Timestamp* ts);
	Fruit(Fruit& f);
	~Fruit();

	virtual std::string get_category();
};
