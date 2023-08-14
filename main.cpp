#include <iostream>

template <class T>
struct Node {
	Node* left = nullptr;
	Node* right = nullptr;
	T value;
};

template <class T>
class Binary_Tree {
	Node<T>* m_root;
public:
	Binary_Tree() : m_root(nullptr) {};
	//insert(Node<T>* item) {  }
	void set_root(Node<T>* r) {
		m_root = r;
	}
	Node<T>* get_root() {
		return m_root;
	}
	void inorder(Node<T>* root) {
		if (root->left) {
			inorder(root->left);
		}
		std::cout << root->value << " " << std::endl;
		if (root->right) {
			inorder(root->right);
		}
	}
	void preorder(Node<T>* root) {
		std::cout << root->value << " " << std::endl;
		if (root->left) {
			preorder(root->left);
		}
		if (root->right) {
			preorder(root->right);
		}
	}
	void postorder(Node<T>* root) {
		if (root->left) {
			postorder(root->left);
		}
		if (root->right) {
			postorder(root->right);
		}
		std::cout << root->value << " " << std::endl;
	}
	void recursion_insert(Node<T>* root, Node<T>* item) {
		if (!root->left) {
			root->left = item;
			return;
		}
		else if(!root->right){
			root->right = item;
			return;
		}
		else if (root->left) {
			recursion_insert(root->left, item);
		}
		else {
			recursion_insert(root->right, item);
		}
	}

	void insert(Node<T>* item) {
		if (!m_root) {
			m_root = item;
		}
		else {
			recursion_insert(m_root, item);
		}
	}

};


int main() {


	Node<int>* n1 = new Node<int>();
	Node<int>* n2 = new Node<int>();
	Node<int>* n3 = new Node<int>();
	Node<int>* n4 = new Node<int>();
	Node<int>* n5 = new Node<int>();
	Node<int>* n6 = new Node<int>();
	Node<int>* n7 = new Node<int>();
	

	n1->value = 15;
	n2->value = 71;
	n3->value = 62;
	n4->value = 81;
	n5->value = 26;
	n6->value = 41;
	n7->value = 96;
	
	//n1->left = n2;
	//n1->right = n3;
	//n2->left = n4;
	//n2->right = n5;
	//n3->left = n6;
	//n3->right = n7;

	



	Binary_Tree<int>* bin_tree = new Binary_Tree<int>();
	bin_tree->insert(n1);
	bin_tree->insert(n2);
	bin_tree->insert(n3);
	bin_tree->insert(n4);
	bin_tree->insert(n5);
	bin_tree->insert(n6);
	bin_tree->insert(n7);

	Node<int>* bin_tree_root = bin_tree->get_root();
	std::cout << "Inorder: " << std::endl;
	bin_tree->inorder(bin_tree_root);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Preorder: " << std::endl;
	bin_tree->preorder(bin_tree_root);
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "Postorder: " << std::endl;
	bin_tree->postorder(bin_tree_root);
	std::cout << std::endl;
	std::cout << std::endl;


	return 0;
}