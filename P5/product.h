#pragma once

#include <ostream>
#include <string>

class Product {
public:
	Product();
	Product(std::string name, long price);
	Product(Product& prod);
	virtual ~Product();

	std::string get_name() const;
	long get_price() const;
	void set_name(std::string name);
	void set_price(long price);
	
	virtual std::string get_category() = 0;

	friend std::ostream& operator<< (std::ostream& out, const Product& prod);

protected:
	std::string name;
	long price;
};
