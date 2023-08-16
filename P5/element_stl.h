#pragma once

template<class T>
class Element_stl {
public:
	Element_stl(long client_id, T* value): client_id(client_id), value(value) {};
	~Element_stl() {};
	
	long get_client_id() {return client_id;};
	T* get_value() {return value;};

private:
	long client_id;
	T* value;
};
