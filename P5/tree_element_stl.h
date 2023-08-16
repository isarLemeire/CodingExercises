#pragma once

#include <list>

#include "element_stl.h"

template<class T>
class Tree_element_stl {
public:
	Tree_element_stl<T>() {};
	Tree_element_stl<T>(std::list<Element_stl<T>*> value_list) {this->value_list = value_list; left_tree = NULL; right_tree = NULL; parent = NULL;};
	Tree_element_stl<T>(Element_stl<T>* value) {value_list.push_front(value); left_tree = NULL; right_tree = NULL; parent = NULL;};
	~Tree_element_stl<T>() {
		typename std::list<Element_stl<T>*>::iterator i = value_list.begin();
		while (i != value_list.end()) {
			delete *i;
			i++;
		}
		value_list.clear();
	};

    std::list<Element_stl<T>*> get_value_list() {return value_list;};
	Tree_element_stl<T>* get_left_tree() {return left_tree;};
	Tree_element_stl<T>* get_right_tree() {return right_tree;};
	Tree_element_stl<T>* get_parent() {return parent;};
    void set_value_list(std::list<Element_stl<T>*> value_list) {this->value_list = value_list;};
	void set_left_tree(Tree_element_stl<T>* left_tree) {this->left_tree = left_tree;};
	void set_right_tree(Tree_element_stl<T>* right_tree) {this->right_tree = right_tree;};
	void set_parent(Tree_element_stl<T>* parent) {this->parent = parent;};

    void print_tree_element() {
		typename std::list<Element_stl<T>* >::const_iterator i = value_list.begin();
		while (i != value_list.end()) {
			std::cout << "--> Key: " << (*i)->get_client_id() << "\n";
			std::cout << "--> Product: " << *((*i)->get_value()) << "\n";
			i++;
		}
	};

	void put(Element_stl<T>* el) {value_list.push_back(el);};
	void pop() {value_list.pop_front();};

private:
    std::list<Element_stl<T>*> value_list;
	Tree_element_stl<T>* left_tree;
	Tree_element_stl<T>* right_tree;
	Tree_element_stl<T>* parent;
};
