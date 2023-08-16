#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>


class Matrix_element {
	int column_number;
	std::string word;
	Matrix_element* next;

public:
	Matrix_element(int column_number, Matrix_element* next, const std::string& word): column_number(column_number), word(word), next(next) {}
	int get_column_number() const;
	std::string get_word();
	Matrix_element* get_next() const;
	void set_next(Matrix_element* next);
};

class Row_iterator {
    Matrix_element* current;

public:
	Row_iterator(Matrix_element* start);
	std::string next(int& column_number);
	bool has_next() const;
};

class Matrix_row {
    Matrix_element* first;

public:
	Matrix_row();
	~Matrix_row();
	int add(int column_number, const std::string& word);
	int remove(int column_number);
	int get(int column_number, std::string& word) const;
	Row_iterator get_iterator() const;
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
