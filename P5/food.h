#pragma once

#include "product.h"
#include "timestamp.h"

class Food : public Product {
public:
	Food();
	Food(std::string name, long price, Timestamp* ts);
	Food(Food& f);
	~Food();

	virtual std::string get_category() = 0;
private:
	Timestamp* best_before;
};
