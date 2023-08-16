#pragma once

#include "element.h"
#include "tree_element.h"

class Binary_search_tree {
public:
	Binary_search_tree();
	~Binary_search_tree();

	void put(long client_id, Product* value);
	Product* get(const long client_id);
	Product* remove(const long client_id);

	void print_tree();

private:
	Tree_element* root;

	Element* get_element(const long client_id);
	Tree_element* get_tree_element(const long client_id);
	Tree_element* get_parent_tree_element(const long client_id);
	void remove_tree_element(Tree_element* el);
	void rotate(Tree_element* axis);

	void print_tree_element(int pos_x, int pos_y, Tree_element* el);
};
