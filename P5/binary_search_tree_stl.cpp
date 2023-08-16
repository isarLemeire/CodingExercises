#include <iostream>

#include "binary_search_tree_stl.h"
#include "product.h"

template<class T>
Binary_search_tree_stl<T>::Binary_search_tree_stl() {
	
}

template<class T>
Binary_search_tree_stl<T>::~Binary_search_tree_stl() {
	
}

template<class T>
void Binary_search_tree_stl<T>::put(long client_id, T* val) {
	
}

template<class T>
T* Binary_search_tree_stl<T>::get(const long client_id) {
	
}

template<class T>
std::list<Element_stl<T>*> Binary_search_tree_stl<T>::get_all_elements(const long client_id) {
	
}

template<class T>
T* Binary_search_tree_stl<T>::remove(const long client_id) {
	
}

template<class T>
void Binary_search_tree_stl<T>::print_tree() {
	
}

template<class T>
Element_stl<T>* Binary_search_tree_stl<T>::get_element(const long client_id) {
	
}

template<class T>
Tree_element_stl<T>* Binary_search_tree_stl<T>::get_tree_element(const long client_id) {
	
}

template<class T>
Tree_element_stl<T>* Binary_search_tree_stl<T>::get_parent_tree_element(const long client_id) {
	
}

template<class T>
void Binary_search_tree_stl<T>::remove_tree_element(Tree_element_stl<T>* te) {
	
}

template<class T>
void Binary_search_tree_stl<T>::rotate(Tree_element_stl<T>* axis) {
	
}

template<class T>
void Binary_search_tree_stl<T>::print_tree_element(int pos_x, int pos_y, Tree_element_stl<T>* te) {
	
}

template class Binary_search_tree_stl<Product>;
