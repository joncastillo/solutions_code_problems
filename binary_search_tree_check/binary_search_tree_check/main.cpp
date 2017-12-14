//
//  main.cpp
//  binary_search_tree_check
//
//  Created by Jonathan Castillo on 14/12/17.
//  Copyright © 2017 joncastillo.org. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

class bst_node
{
public:
    int value;
    bst_node* l;
    bst_node* r;
    bst_node(int value):
        value(value),
        l(nullptr),
        r(nullptr)
            {}
};

// dfs
bool solution(bst_node* parent, bst_node* last_parent_going_left, bst_node* last_parent_going_right)
{

    bst_node* child_left = parent->l;
    bst_node* child_right = parent->r;
    

    if (child_left != nullptr)
    {
        if (child_left->value > parent->value)
            return false;
        
        if (last_parent_going_right != nullptr)
            if (child_left->value < last_parent_going_right->value)
                return false;

        if (solution(child_left, parent, last_parent_going_right) == false)
            return false;
    
    }
    
    if (child_right != nullptr)
    {
        if (child_right->value < parent->value)
            return false;
        
        if (last_parent_going_left != nullptr)
            if (child_right->value > last_parent_going_left->value)
                return false;

        if (solution(child_right, last_parent_going_left, parent) == false)
            return false;
    }
     
    return true;
}



int main(int argc, const char * argv[]) {

    // no violation:
    //
    //       5
    //      / \
    //     /   \
    //    2     7
    //   / \   / \
    //  1   3 6   8

    bst_node a_1(5);
    bst_node a_2(2);
    bst_node a_3(7);
    bst_node a_4(1);
    bst_node a_5(3);
    bst_node a_6(6);
    bst_node a_7(8);

    a_1.l = &a_2;
    a_1.r = &a_3;
    a_2.l = &a_4;
    a_2.r = &a_5;
    a_3.l = &a_6;
    a_3.r = &a_7;

    // violation 1:
    //
    //       5
    //      / \
    //     /   \
    //    3     8
    //   / \   / \
    //  1   4 9   10

    bst_node b_1(5);
    bst_node b_2(3);
    bst_node b_3(8);
    bst_node b_4(1);
    bst_node b_5(4);
    bst_node b_6(9);
    bst_node b_7(10);
    
    b_1.l = &b_2;
    b_1.r = &b_3;
    b_2.l = &b_4;
    b_2.r = &b_5;
    b_3.l = &b_6;
    b_3.r = &b_7;

    // violation 2:
    //
    //       5
    //      / \
    //     /   \
    //    3     8
    //   / \   / \
    //  2   1 7   10
    bst_node c_1(5);
    bst_node c_2(3);
    bst_node c_3(8);
    bst_node c_4(2);
    bst_node c_5(1);
    bst_node c_6(7);
    bst_node c_7(10);
    
    c_1.l = &c_2;
    c_1.r = &c_3;
    c_2.l = &c_4;
    c_2.r = &c_5;
    c_3.l = &c_6;
    c_3.r = &c_7;

    // violation 3:
    //
    //       5
    //      / \
    //     /   \
    //    3     8
    //   / \   / \
    //  1   7 6   9
    bst_node d_1(5);
    bst_node d_2(3);
    bst_node d_3(8);
    bst_node d_4(1);
    bst_node d_5(7);
    bst_node d_6(6);
    bst_node d_7(9);
    
    d_1.l = &d_2;
    d_1.r = &d_3;
    d_2.l = &d_4;
    d_2.r = &d_5;
    d_3.l = &d_6;
    d_3.r = &d_7;



    
    // violation 4:
    //
    //            5
    //           / \
    //          /   \
    //         /     \
    //        /       \
    //       /         \
    //      3           8
    //     / \         / \
    //    /   \       /   \
    //   2     4     6     9
    //  /       \   /     /
    // 1         5 4(F)  7(F)
    //          / \
    //         4   5
    
    //  1   4 6   9
    bst_node e_1(5);
    bst_node e_2(3);
    bst_node e_3(8);
    bst_node e_4(2);
    bst_node e_5(4);
    bst_node e_6(6);
    bst_node e_7(9);
    bst_node e_8(1);
    bst_node e_9(5);
    bst_node e_10(4);
    bst_node e_11(10);
    bst_node e_12(4);
    bst_node e_13(5);

    e_1.l = &e_2;
    e_1.r = &e_3;
    e_2.l = &e_4;
    e_2.r = &e_5;
    e_3.l = &e_6;
    e_3.r = &e_7;
    e_4.l = &e_8;
    e_5.r = &e_9;
    e_6.l = &e_10;
    e_7.l = &e_11;
    e_9.l = &e_12;
    e_9.r = &e_13;
    
    // no violations 2:
    //
    //            5
    //           / \
    //          /   \
    //         /     \
    //        /       \
    //       /         \
    //      3           8
    //     / \         / \
    //    /   \       /   \
    //   2     4     6     10
    //  /       \   /     /
    // 1         4 5     9
    //          / \
    //         4   5
    
    //  1   4 6   9
    bst_node f_1(5);
    bst_node f_2(3);
    bst_node f_3(8);
    bst_node f_4(2);
    bst_node f_5(4);
    bst_node f_6(6);
    bst_node f_7(10);
    bst_node f_8(1);
    bst_node f_9(4);
    bst_node f_10(5);
    bst_node f_11(9);
    bst_node f_12(4);
    bst_node f_13(5);
    
    f_1.l = &f_2;
    f_1.r = &f_3;
    f_2.l = &f_4;
    f_2.r = &f_5;
    f_3.l = &f_6;
    f_3.r = &f_7;
    f_4.l = &f_8;
    f_5.r = &f_9;
    f_6.l = &f_10;
    f_7.l = &f_11;
    f_9.l = &f_12;
    f_9.r = &f_13;

    bool output_a = solution(&a_1, nullptr,nullptr);
    bool output_b = solution(&b_1, nullptr,nullptr);
    bool output_c = solution(&c_1, nullptr,nullptr);
    bool output_d = solution(&d_1, nullptr,nullptr);
    bool output_e = solution(&e_1, nullptr,nullptr);
    bool output_f = solution(&f_1, nullptr,nullptr);

    assert(output_a == true);
    assert(output_b == false);
    assert(output_c == false);
    assert(output_d == false);
    assert(output_e == false);
    assert(output_f == true);

    return 0;
}
