#include <ntdef.h>

struct node {
    node* parent;
    node* right;
    node* left;
    int elem;

    // TODO paste your height method here

    int height(node* tmp){
        if (tmp == nullptr)
            return 0;
        else {

            int leftctr = height(parent->left);
            int rightctr = height(parent->right);


            return std::max(leftctr, rightctr) + 1;
        }
    }

};
