/************************************************************
 * Implementation by Isar Lemeire
 * *********************************************************/

#include "sparse_matrix.h"


int Matrix_element::get_column_number() const {
    return column_number;
}

std::string Matrix_element::get_word() const {
    return word;
}

Matrix_element* Matrix_element::get_next() const {
    if(next == nullptr){
    }
    return next;
}

void Matrix_element::set_next(Matrix_element* next){
    this->next = next;
}

bool Row_iterator::has_next() const {
    return (current->get_next() != nullptr);
}

Matrix_element* Row_iterator::next(){
    Matrix_element* m  = current;
    if(has_next())
        current = current->get_next();
    return m;
}


bool Matrix_row::has_first() const{
    return (first != nullptr);
}

Row_iterator Matrix_row::get_iterator() const{
    return Row_iterator(first);
}

int Matrix_row::add(int column_number, const std::string& word){
    Matrix_element* new_element = new Matrix_element(column_number, nullptr, word);
    // empty row
    if (!has_first()){
        first = new_element;
        return 1;
    }
    
    // new element becomes the first element
    if(column_number < first->get_column_number()){
        new_element->set_next(first);
        first = new_element;
        return 1;
    }
    
    Row_iterator iterator = get_iterator();
    Matrix_element* current = iterator.next();
    Matrix_element* previous;
    while (current->get_column_number() < column_number && current->get_next()){
        previous = current;
        current = iterator.next();
    }

    // new element does not becomes the last element
    if (current->get_column_number() < column_number){
        current->set_next(new_element);
        return 1;
    }
    // element already present in the matrix
    if(current->get_column_number() == column_number){
        return 0;
    }
    // new element at any other position
    previous->set_next(new_element);
    new_element->set_next(current);
    return 1;
}

int Matrix_row::remove(int column_number){
    // remove the first element
    if(first->get_column_number() == column_number){
        Matrix_element* new_first = first->get_next();
        delete(first);
        first = new_first;
        return 1;
    }
    Row_iterator iterator = get_iterator();
    Matrix_element* current = iterator.next();
    Matrix_element* previous;
    while (current->get_column_number() != column_number){
        if(!iterator.has_next() || current->get_column_number() > column_number ){
            return 0;
        }
        previous = current;
        current = iterator.next();
    }
    previous->set_next(current->get_next());
    delete(current);
    return 1;
}

int Matrix_row::get(int column_number, std::string& word) const{

    if(!has_first()){
        return 0;
    }
    
    Row_iterator iterator = get_iterator();
    Matrix_element* current = iterator.next();
     while (current->get_column_number() != column_number){
        if(!current->get_next() || current->get_column_number() > column_number ){
            return 0;
        }
        current = iterator.next();
    }
    
    word = current->get_word();
    return 1;
}

Matrix_row::~Matrix_row(){   
    if(first){
        Row_iterator iterator = get_iterator();
        Matrix_element* current = iterator.next();
        Matrix_element* previous;
        while (iterator.has_next())
        {
            previous = current;
            current = iterator.next();
            delete(previous);
        }
        delete(current);  
    }
}

Sparse_matrix::Sparse_matrix(int r, int c) : number_of_rows(r), number_of_columns(c) {
    matrix = new Matrix_row[number_of_rows];
}

Sparse_matrix::Sparse_matrix(const Sparse_matrix& other)
    : number_of_rows(other.number_of_rows), number_of_columns(other.number_of_columns) {
    
    // Copy the matrix rows from the other object to the new object
    matrix = new Matrix_row[number_of_rows];
    for (int i = 0; i < number_of_rows; i++) {
        matrix[i] = other.matrix[i]; // Assuming Matrix_row has a proper copy constructor
    }
}

Sparse_matrix::~Sparse_matrix() {
    delete[] matrix; // Free the memory allocated for the matrix array
}

int Sparse_matrix::add_element(int r, int c, const std::string& s){
    if(r >= number_of_rows || c >= number_of_columns || r < 0 || c < 0){
        return 0;
    }
    return matrix[r].add(c, s);
}

int Sparse_matrix::remove_element(int r, int c){
    if(r >= number_of_rows || c >= number_of_columns){
        return 0;
    }
    return matrix[r].remove(c);
}

int Sparse_matrix::get(int r, int c, std::string& s) const{
    if(r >= number_of_rows || c >= number_of_columns){
        return 0;
    }
    return matrix[r].get(c, s);
}

void Sparse_matrix::transpose() {
    Matrix_row* new_matrix = new Matrix_row[number_of_columns];
    
    for (int i = 0; i < number_of_rows; i++) {
        for (int j = 0; j < number_of_columns; j++) {
            std::string content;
            if (get(i, j, content)) {
                // Add the element to the corresponding row in the new_matrix
                new_matrix[j].add(i, content);
            }
        }
    }        

    // Clean up the old matrix
    delete[] matrix;

    // Update the dimensions and assign the new_matrix to matrix
    int temp = number_of_columns;
    number_of_columns = number_of_rows;
    number_of_rows = temp;

    matrix = new_matrix;
}

void Sparse_matrix::print() const{
    for (int i = 0; i < number_of_rows; i++)
    {
        std::cout << "[";
        for (int j = 0; j < number_of_columns; j++)
        {
            std::string content;
            get(i, j, content)? std::cout << content : std::cout << "?";
            if(j != number_of_columns-1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

Sparse_matrix Sparse_matrix::operator+(const Sparse_matrix& other) {
    Sparse_matrix result(std::max(number_of_rows, other.number_of_rows)
        , std::max(number_of_columns, other.number_of_columns));

    for (int i = 0; i < result.number_of_rows; i++) {
        for (int j = 0; j < result.number_of_columns; j++) {
            std::string value;
            if (get(i, j, value)) {
                result.add_element(i, j, value);
            }
            if (other.get(i, j, value)) {
                result.add_element(i, j, value);
            }
        }
    }

    return result;
}
