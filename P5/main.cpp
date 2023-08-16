#include <iostream>
#include <stdio.h>

#include "binary_search_tree.h"
#include "binary_search_tree_stl.h"
#include "binary_search_tree_template.h"
#include "computer.h"
#include "food.h"
#include "fruit.h"
#include "product.h"
#include "vegetable.h"

void test_binary_search_tree() {
    std::cout << "\n\n# TESTING TREE\n";
    Binary_search_tree *bst = new Binary_search_tree();

    Timestamp *ts = new Timestamp(10, 12, 2014);

    Product *p_1 = new Computer("Dell", 1500);
    Product *p_2 = new Computer("Acer", 1240);
    Product *p_3 = new Fruit("Banana", 1, ts);

    bst->put(1, p_1);    
    bst->put(1, p_2);   
    bst->put(1, p_3);    
    bst->put(20, p_1);    
    bst->put(5, p_2);    
    bst->put(6, p_1);
    bst->put(11, p_2);
    bst->put(18, p_3);
    bst->put(15, p_3);
    bst->put(30, p_3);    
    bst->put(7, p_3);
    bst->put(9, p_3);
    bst->print_tree();
    // 11 is an easy element to remove (in the current tree configuration)
    bst->remove(11);
    // removing 15 properly is significantly more complicated, if stuck, then skip forward to the lookups and tree deletion
    bst->remove(15);    
    bst->remove(9);    
    bst->remove(7);

    std::cout << "\n## FULL TREE:\n";
    bst->print_tree();

    std::cout << "## FIND 5:\n";
    Product *p_found = bst->get(5);
    if (p_found) {
        std::cout << "\t" << *p_found << std::endl;
    } else {
        std::cout << "\t" << "NULL" << std::endl;
    }
    std::cout << "## FIND 1:\n";
    p_found = bst->get(1);
    if (p_found) {
        std::cout << "\t" << *p_found << std::endl;
    } else {
        std::cout << "\t" << "NULL" << std::endl;
    }
    std::cout << "## FIND 20:\n";
    p_found = bst->get(20);
    if (p_found) {
        std::cout << "\t" << *p_found << std::endl;
    } else {
        std::cout << "\t" << "NULL" << std::endl;
    }
    std::cout << "## FIND 9:\n";
    p_found = bst->get(9);
    if (p_found) {
        std::cout << "\t" << *p_found << std::endl;
    } else {
        std::cout << "\t" << "NULL" << std::endl;
    }

    delete bst;
    delete p_1;
    delete p_2;
    delete p_3;
}

void test_binary_search_tree_template() {
    std::cout << "\n\n# TESTING TEMPLATE TREE\n";
    Binary_search_tree_template<Product> *bst = new Binary_search_tree_template<Product>();
    Timestamp *ts = new Timestamp(10, 12, 2014);

    Product *p_1 = new Computer("Dell", 1500);
    Product *p_2 = new Computer("Acer", 1240);
    Product *p_3 = new Fruit("Banana", 1, ts);

    bst->put(1, p_1);    
    bst->put(1, p_2);   
    bst->put(1, p_3);    
    bst->put(20, p_1);    
    bst->put(5, p_2);    
    bst->put(6, p_1);
    bst->put(11, p_2);
    bst->put(18, p_3);
    bst->put(15, p_3);
    bst->put(30, p_3);    
    bst->put(7, p_3);
    bst->put(9, p_3);
    bst->print_tree();
    bst->remove(11);
    bst->remove(15);    
    bst->remove(9);    
    bst->remove(7);

    std::cout << "## FULL TREE:\n";
    bst->print_tree();

    std::cout << "## FIND 5:\n";
    Product *p_found = bst->get(5);
    if (p_found) {
        std::cout << "\t" << *p_found << std::endl;
    } else {
        std::cout << "\t" << "NULL" << std::endl;
    }
    std::cout << "## FIND 1:\n";
    p_found = bst->get(1);
    if (p_found) {
        std::cout << "\t" << *p_found << std::endl;
    } else {
        std::cout << "\t" << "NULL" << std::endl;
    }
    std::cout << "## FIND 20:\n";
    p_found = bst->get(20);
    if (p_found) {
        std::cout << "\t" << *p_found << std::endl;
    } else {
        std::cout << "\t" << "NULL" << std::endl;
    }
    std::cout << "## FIND 9:\n";
    p_found = bst->get(9);
    if (p_found) {
        std::cout << "\t" << *p_found << std::endl;
    } else {
        std::cout << "\t" << "NULL" << std::endl;
    }

    delete bst;
    delete p_1;
    delete p_2;
    delete p_3;
}

void test_binary_search_tree_stl() {
    std::cout << "\n\n# TESTING STL TREE\n";
    Binary_search_tree_stl<Product> *bst = new Binary_search_tree_stl<Product>();
    Timestamp *ts = new Timestamp(10, 12, 2014);

    Product *p_1 = new Computer("Dell", 1500);
    Product *p_2 = new Computer("Acer", 1240);
    Product *p_3 = new Fruit("Banana", 1, ts);

    bst->put(1, p_1);    
    bst->put(1, p_2);   
    bst->put(1, p_3);    
    bst->put(20, p_1);    
    bst->put(5, p_2); 
    bst->put(6, p_1);
    bst->put(11, p_2);
    bst->put(18, p_3);
    bst->put(15, p_3);
    bst->put(30, p_3);    
    bst->put(7, p_3);
    bst->put(9, p_3);
    bst->print_tree();    
    bst->remove(11);    
    bst->remove(15); 
    bst->remove(9);    
    bst->remove(7);

    std::cout << "## FULL TREE:\n";
    bst->print_tree();

    std::cout << "## FIND 5:\n";
    Product *p_found = bst->get(5);
    if (p_found) {
        std::cout << "\t" << *p_found << std::endl;
    } else {
        std::cout << "\t" << "NULL" << std::endl;
    }
    std::cout << "## FIND 1:\n";
    p_found = bst->get(1);
    if (p_found) {
        std::cout << "\t" << *p_found << std::endl;
    } else {
        std::cout << "\t" << "NULL" << std::endl;
    }
    std::cout << "## FIND 20:\n";
    p_found = bst->get(20);
    if (p_found) {
        std::cout << "\t" << *p_found << std::endl;
    } else {
        std::cout << "\t" << "NULL" << std::endl;
    }
    std::cout << "## FIND 9:\n";
    p_found = bst->get(9);
    if (p_found) {
        std::cout << "\t" << *p_found << std::endl;
    } else {
        std::cout << "\t" << "NULL" << std::endl;
    }

    delete bst;
    delete p_1;
    delete p_2;
    delete p_3;
}

int main() {
    // Note: these functions are almost all identical. This amount of code duplication
    // is generally considered a very bad practice, and should only be used in tests.
    test_binary_search_tree();
    test_binary_search_tree_template();
    test_binary_search_tree_stl();

    // Wait for user to press ENTER before closing
    getchar();
}
