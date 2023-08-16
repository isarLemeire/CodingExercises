#pragma once

#include "product.h"

class Computer : public Product{
public:
	Computer();
	Computer(std::string name, long price);
	Computer(Computer& comp);

	virtual std::string get_category();
};
