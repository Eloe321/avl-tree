#include <cstdlib>
#include <iostream>
#include "node.h"
using namespace std;

class BinaryTree {
	node* root;
	int size;

	node* create_node(int e, node* parent) {
		node* n = (node*) calloc( 1, sizeof(node) );
		n->elem = e;
		n->parent = parent;
		return n;
	}

	public:
	node* addRoot(int e) {
		if (root) {
			cout << "Root exists" << endl;
			return NULL;
		}
		node* n = create_node(e, NULL);
		root = n;
		size++;
		return n;
	}

	node* left(node* p) {
		return p->left;
	}

	node* right(node* p) {
		return p->right;
	}

	node* sibling(node* n) {
		node* par = n->parent;
		if (!par) {
			return NULL;
		}
		if (n == par->left) {
			return par->right;
		}
		return par->left;
	}

	node* addLeft(node* p, int e) {
		if (p->left) {
			cout << "Left of " << p->elem << " exists" << endl;
			return NULL;
		}
		node* n = create_node(e, p);
		p->left = n;
		size++;
		return n;
	}

	node* addRight(node* p, int e) {
		if (p->right) {
			cout << "Right of " << p->elem << " exists" << endl;
			return NULL;
		}
		node* n = create_node(e, p);
		p->right = n;
		size++;
		return n;
	}

    int remove(node* n) {
        int res = n->elem;
        if (left(n) && right(n)) {
            return -1;
        }
        if (!left(n) && !right(n)) {
            if (n->parent) {
                node* par = n->parent;
                if (left(par) == n) {
                    par->left = NULL;
                } else {
                    par->right = NULL;
                }
            } else {
                root = NULL;
            }
        } else {
            node* child;
            if (left(n)) {
                child = left(n);
            } else {
                child = right(n);
            }
            if (n->parent) {
                node* par = n->parent;
                if (left(par) == n) {
                    par->left = child;
                } else {
                    par->right = child;
                }
                child->parent = par;
            } else {
                root = child;
                child->parent = NULL;
            }
        }
        size--;
        free(n);
        return res;
    }

	node* getRoot() {
		return root;
	}

    // TODO copy your completed zigleft here
    void zigleft(node* curr) {
    	if(curr->parent == root){
    		if(curr->left){
    			node *tmp = curr->left;
    			curr->left = root;
    			root = curr;
                curr->parent = nullptr;
    			curr->left->right = tmp;
                curr->left->parent = root;
    			
    			
			}else{
    		curr->left = root;
    		curr->left->right = nullptr;
            curr->parent = nullptr;
    		root = curr;
            curr->left->parent = root;
    		
    		}
		}else{
			bool granpaps = (curr->parent->parent->left == curr->parent);
			node* tmpPaps = curr->parent;
				if(granpaps) {
                    tmpPaps->parent->left = curr;
                    curr->parent = tmpPaps->parent;
                    tmpPaps->parent = curr;
                }else {
                    curr->parent->parent->right = curr;
                    curr->parent = tmpPaps->parent;
                    tmpPaps->parent = curr;
                }

                if(curr->left ){
				
					node * tmp = curr->left;
					curr->left = tmpPaps;
					tmpPaps->right = tmp;
					
				
			}else{
				curr->left = tmpPaps;
				tmpPaps->right = nullptr;
			}
		}

    }

    // TODO copy your completed zigright here
    void zigright(node* curr) {
		if(curr->parent == root){
    		if(curr->right){
    			node *tmp = curr->right;
    			curr->right = root;
    			root = curr;
                curr->parent = nullptr;
    			curr->right->left = tmp;
                curr->right->parent = root;

    			
			}else{
    		curr->right = root;
    		curr->right->left = nullptr;
            curr->parent = nullptr;
            root = curr;
            curr->right->parent = root;
    		
    		}
		}else{
			bool granpaps = (curr->parent->parent->left == curr->parent);
			node* tmpPaps = curr->parent;
				if(granpaps) {
                    tmpPaps->parent->left = curr;
                    curr->parent = tmpPaps->parent;
                    tmpPaps->parent = curr;

                }else {
                    tmpPaps->parent->right = curr;
                    curr->parent = tmpPaps->parent;
                    tmpPaps->parent = curr;
                }


                if( curr->right){
				
					node * tmp = curr->right;
					curr->right = tmpPaps;
					tmpPaps->left = tmp;
					
				
			}else{
				curr->right = tmpPaps;
				tmpPaps->left = nullptr;
			}
		}

    }

	void print() {
		cout << "Size: " << size << endl;
		if (!root) {
			cout << "EMPTY" << endl;
			return;
		}
		node* curr = root;
		print_node("", root, false);
        cout << "Status: " << check_parent(root, NULL) << endl;
	}

	void print_node(string prefix, node* n, bool isLeft) {
		cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: " );
        cout << n->elem << endl;
		if (n->left) {
			print_node(prefix + "|   ", n->left, true);
		}
		if (n->right) {
			print_node(prefix + "|   ", n->right, false);
		}
	}

    bool check_parent(node* curr, node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            if (!curr->parent) {
                cout << "Illegal parent of " << curr->elem << ": NULL -- must be " << par->elem << endl;
            } else if (!par) {
                cout << "Illegal parent of " << curr->elem << ": " << curr->parent->elem << "must be NULL" << endl;
            } else {
                cout << "Illegal parent of " << curr->elem << ": " << curr->parent->elem << " -- must be " << par->elem << endl;
            }
            return false;
        }
        return check_parent(curr->left, curr) && check_parent(curr->right, curr);
    }
};
