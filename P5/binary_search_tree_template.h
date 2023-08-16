#pragma once

#include "element_template.h"
#include "tree_element_template.h"

template<class T>
class Binary_search_tree_template {
public:
	Binary_search_tree_template();
	~Binary_search_tree_template();

	void put(long client_id, T* value);
	T* get(const long client_id);
	T* remove(const long client_id);

	void print_tree();

private:
	Tree_element_template<T>* root;

	Element_template<T>* get_element(const long client_id);
	Tree_element_template<T>* get_tree_element(const long client_id);
	Tree_element_template<T>* get_parent_tree_element(const long client_id);
	void remove_tree_element(Tree_element_template<T>* el);
	void rotate(Tree_element_template<T>* axis);

	void print_tree_element(int pos_x, int pos_y, Tree_element_template<T>* el);
};
