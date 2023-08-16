#pragma once

#include <iostream>
#include <list>

#include "element_stl.h"
#include "tree_element_stl.h"

template<class T>
class Binary_search_tree_stl {
public:
	Binary_search_tree_stl();
	~Binary_search_tree_stl();

	void put(long client_id, T* value);
	T* get(const long client_id);
	std::list<Element_stl<T>*> get_all_elements(const long client_id);
	T* remove(const long client_id);

	void print_tree();

private:
	Tree_element_stl<T>* root;

	Element_stl<T>* get_element(const long client_id);
	Tree_element_stl<T>* get_tree_element(const long client_id);
	Tree_element_stl<T>* get_parent_tree_element(const long client_id);
	void remove_tree_element(Tree_element_stl<T>* el);
	void rotate(Tree_element_stl<T>* axis);

	void print_tree_element(int pos_x, int pos_y, Tree_element_stl<T>* el);
};
