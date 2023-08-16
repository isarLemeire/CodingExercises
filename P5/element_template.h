#pragma once

template<class T>
class Element_template {
public:
	Element_template(long client_id, T* value): client_id(client_id), value(value) {next_element = NULL;};
	~Element_template() {};

	long get_client_id() {return client_id;};
	T* get_value() {return value;};
    Element_template<T>* get_next_element() {return next_element;};
	void set_next_element(Element_template* el) {next_element = el;};

private:
	long client_id;
	T* value;
	Element_template<T>* next_element;
};
