#pragma once

#include "element.h"

class Tree_element {
public:
	Tree_element(Element* value) {this->value = value; left_tree = NULL; right_tree = NULL; parent = NULL;};
	~Tree_element() {
		if (value) {
			while (value->get_next_element()) {
				Element* el = value;
				value =	el->get_next_element();
				delete el;
			}
			delete value;
		}
	};

    Element* get_value() {return this->value;};
	Tree_element* get_left_tree() {return this->left_tree;};
	Tree_element* get_right_tree() {return this->right_tree;};
	Tree_element* get_parent() {return this->parent;};
    void set_value(Element* value) {this->value = value;};
	void set_left_tree(Tree_element* left_tree) {this->left_tree = left_tree;};
	void set_right_tree(Tree_element* right_tree) {this->right_tree = right_tree;};
	void set_parent(Tree_element* parent) {this->parent = parent;};

private:
    Element* value;
	Tree_element* left_tree;
	Tree_element* right_tree;
	Tree_element* parent;
};
