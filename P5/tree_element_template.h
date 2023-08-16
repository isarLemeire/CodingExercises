#pragma once

#include "element_template.h"

template<class T>
class Tree_element_template {
public:
	Tree_element_template<T>(Element_template<T>* value) {this->value = value; left_tree = NULL; right_tree = NULL; parent = NULL;};
	~Tree_element_template<T>() {
		Element_template<T>* el;
		if (value) {
			while (value->get_next_element()) {
				el = value;
				value =	el->get_next_element();
				delete el;
			}
			delete value;
		}
	};
    Element_template<T>* get_value() {return value;};
	Tree_element_template<T>* get_left_tree() {return left_tree;};
	Tree_element_template<T>* get_right_tree() {return right_tree;};
	Tree_element_template<T>* get_parent() {return parent;};
    void set_value(Element_template<T>* value) {this->value = value;};
	void set_left_tree(Tree_element_template<T>* left_tree) {this->left_tree = left_tree;};
	void set_right_tree(Tree_element_template<T>* right_tree) {this->right_tree = right_tree;};
	void set_parent(Tree_element_template<T>* parent) {this->parent = parent;};

private:
    Element_template<T>* value;
	Tree_element_template<T>* left_tree;
	Tree_element_template<T>* right_tree;
	Tree_element_template<T>* parent;
};
