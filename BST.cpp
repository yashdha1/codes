#include <iostream>
 using namespace std;
 struct Node {
int data;
 Node* left;
 Node* right;
 Node(int value) : data(value), left(nullptr), right(nullptr) {}
 };
 class BinarySearchTree {
 private:
 Node* root;
 void insert(Node*& node, int value) {
 if (node == nullptr) {
 node = new Node(value);
 } else if (value < node->data) {
 insert(node->left, value);
 } else {
 insert(node->right, value);
 }
 }
 void inorder(Node* node) {
 if (node != nullptr) {
 inorder(node->left);
 cout << node->data << " ";
 inorder(node->right);
 }
 }
 void preorder(Node* node) {
 if (node != nullptr) {
 cout << node->data << " ";
 preorder(node->left);
 preorder(node->right);
 }
 }
 void postorder(Node* node) {
 if (node != nullptr) {
 postorder(node->left);
 postorder(node->right);
 cout << node->data << " ";
 }
 }
 bool search(Node* node, int value) {
if (node == nullptr) {
 return false;
 }
 if (node->data == value) {
 return true;
 } else if (value < node->data) {
 return search(node->left, value);
 } else {
 return search(node->right, value);
 }
 }
 public:
 BinarySearchTree() : root(nullptr) {}
 void insert(int value) {
 insert(root, value);
 }
 void inorder() {
 cout << "In-order Traversal: ";
 inorder(root);
 cout << endl;
 }
 void preorder() {
 cout << "Pre-order Traversal: ";
 preorder(root);
 cout << endl;
 }
 void postorder() {
 cout << "Post-order Traversal: ";
 postorder(root);
 cout << endl;
 }
 bool search(int value) {
 return search(root, value);
 }
 };
 int main() {
 BinarySearchTree bst;
 int choice, value;
do {
 cout << "\nBinary Search Tree Operations Menu:\n";
 cout << "1. Insert\n";
 cout << "2. In-order Traversal\n";
 cout << "3. Pre-order Traversal\n";
 cout << "4. Post-order Traversal\n";
 cout << "5. Search\n";
 cout << "6. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "Enter value to insert: ";
 cin >> value;
 bst.insert(value);
 break;
 case 2:
 bst.inorder();
 break;
 case 3:
 bst.preorder();
 break;
 case 4:
 bst.postorder();
 break;
 case 5:
 cout << "Enter value to search: ";
 cin >> value;
 if (bst.search(value)) {
 cout << value << " is found in the tree.\n";
 } else {
 cout << value << " is not found in the tree.\n";
 }
 break;
 case 6:
 cout << "Exiting program.\n";
 break;
 default:
 cout << "Invalid choice! Please try again.\n";
 }
 } while (choice != 6);
 return 0;
 }