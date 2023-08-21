#include <cassert>

#include "sparse_matrix.h"

using namespace std;

int main()
{
    cout << "Initializing matrix..." << endl;
    Sparse_matrix m(6, 6);
    cout << "Matrix initialized" << endl;
    m.add_element(4, 3, "element43");
    m.add_element(4, 5, "element45");
    m.add_element(4, 4, "element44");
    m.add_element(4, 2, "element42");
    m.add_element(4, 1, "element41");
    m.add_element(1, 5, "element15");
    m.add_element(1, 2, "element12");
    m.add_element(1, 3, "element13");
    m.add_element(1, 1, "element11");
    m.add_element(1, 4, "element14");
    m.add_element(3, 2, "element32");
    m.add_element(5, 5, "element55");
    cout << "Elements added" << endl;
    m.print();

    assert(m.add_element(6, 1, "wrong") == 0);
    assert(m.add_element(3, 6, "wrong") == 0);
    assert(m.add_element(3, -1, "wrong") == 0);
    assert(m.add_element(1, 5, "wrong") == 0);

    string word;
    cout << endl << "Retrieved element" << endl;
    assert(m.get(1, 4, word) == 1);
    assert(word == "element14");
    assert(m.get(6, 1, word) == 0);
    assert(m.get(3, 6, word) == 0);
    assert(m.get(3, -1, word) == 0);
    assert(m.get(3, 3, word) == 0);

    m.remove_element(1, 4);
    m.remove_element(3, 2);
    cout << endl << "Removed elements (1, 4) and (3, 2)" << endl;
    m.print();
    assert(m.get(1, 4, word) == 0);
    assert(m.get(3, 2, word) == 0);

    m.transpose();
    cout << endl << "Transposed matrix" << endl;
    m.print();
    assert(m.get(1, 4, word) == 1);
    assert(word == "element41");
    assert(m.get(5, 1, word) == 1);
    assert(word == "element15");
    assert(m.get(4, 5, word) == 0);

	Sparse_matrix k(m);
	cout << endl << "Copy constructor" << endl;
	k.print();
	assert(k.get(1, 4, word) == 1);
    assert(word == "element41");
    assert(k.get(5, 1, word) == 1);
    assert(word == "element15");
    assert(k.get(4, 5, word) == 0);

	cout << endl << "Operator +" << endl;
	Sparse_matrix l(2, 8);
    cout << "Matrix initialized..." << endl;
    l.add_element(1, 7, "element17");
    l.add_element(0, 3, "element03");
    l.print();
	Sparse_matrix n = m + l;
	n.print();
}
