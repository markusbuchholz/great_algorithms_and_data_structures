#include <iostream>
#include <vector>


struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int d) :data{ d }, left{ nullptr }, right{ nullptr } {}
};

int max_height{ 0 };

void print_max_height() {

	std::cout << "max_height is :: " << max_height - 1 << std::endl;
}
void print(std::vector<int> v) {

	int h_temp = v.size();

	if (h_temp > max_height) {
		max_height = h_temp;
	}
		
	for (auto& i : v) {
		
		std::cout << i;
	}
	std::cout << std::endl;

}
void printPaths(Node* node, std::vector<int> path) {

	if (node == nullptr) {
		return;
	}

	path.push_back(node->data);

	if ((node->left == nullptr) && (node->right == nullptr)) {
		print(path);
	}
	else {
		
		printPaths(node->left, path);
		printPaths(node->right, path);
	}

}



int main() {

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->right->left = new Node(6);
	root->left->right->right = new Node(7);
	root->left->right->left->left = new Node(8);
	root->left->right->left->left->left = new Node(9);
	std::vector<int> vec;

	printPaths(root, vec);
	print_max_height();
	return 0;


}