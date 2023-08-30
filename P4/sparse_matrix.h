#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdexcept>
#include <math.h>


class Matrix_element {
private:
	int column_number;
	std::string word;
	Matrix_element* next;

public:
	Matrix_element(int column_number, Matrix_element* next, const std::string& word): column_number(column_number), word(word), next(next) {}
	int get_column_number() const;
	std::string get_word() const;
	Matrix_element* get_next() const;
	void set_next(Matrix_element* next);
};

class Row_iterator {
    

public:
	Matrix_element* current;
	Row_iterator(Matrix_element* start): current(start) {};
	Matrix_element* next();
	bool has_next() const;
};

class Matrix_row {
    Matrix_element* first;

public:
	Matrix_row(): first(nullptr) {};
	~Matrix_row();
	bool has_first() const;
	Row_iterator get_iterator() const;
	int add(int column_number, const std::string& word);
	int remove(int column_number);
	int get(int column_number, std::string& word) const;
};

class Sparse_matrix {
    int number_of_rows;
    int number_of_columns;
    Matrix_row* matrix;

public:
	Sparse_matrix(int r, int c);
	Sparse_matrix(const Sparse_matrix&);
	~Sparse_matrix();
	int add_element(int r, int c, const std::string& s);
	int remove_element(int r, int c);
	int get(int r, int c, std::string& s) const;
	void transpose();
	void print() const;
	Sparse_matrix operator+(const Sparse_matrix&);
};

#endif
