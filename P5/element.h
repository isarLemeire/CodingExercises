#pragma once

#include "product.h"

class Element {
public:
	Element(long client_id, Product* value): client_id(client_id), value(value) {next_element = NULL;};
	~Element() {};

	long get_client_id() {return client_id;};
	Product* get_value() {return value;};
    Element* get_next_element() {return next_element;};
	void set_next_element(Element* el) {next_element = el;};

private:
	long client_id;
	Product* value;
	Element* next_element;
};
