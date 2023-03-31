#ifndef BST_H
#define BST_H
#include <functional>
#include <iostream>

class BST {
public:
    class Node; //nested class
    BST(std::initializer_list<int>);
    BST(const BST& bst);
    BST& operator=(const BST& bst);
    BST(BST&& bst) noexcept; //move copy constructor
    BST& operator=(BST&& bst) noexcept; //move assignment

    Node*& get_root() const;
    void bfs(std::function<void(Node*& node)> func);
    size_t length();
    bool add_node(int value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);
    /*
     * declaring increment operator as a member function will be better,
     * while violating the rule
     * BST& operator++();
     * BST operator++(int);
    */
    ~BST();

private:
    Node* root = nullptr;
};

//nested class
class BST::Node {
public:
	Node(int value, Node* left, Node* right);
    Node();
    Node(const Node& node);

	int value = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

bool operator>(const BST::Node& node, int a); 
bool operator>=(const BST::Node& node, int a); 
bool operator<(const BST::Node& node, int a); 
bool operator<=(const BST::Node& node, int a); 
bool operator==(const BST::Node& node, int a); 

//trailing return type, looks like python, haa?:-)
auto operator<(int a, const BST::Node& node) -> bool; 
auto operator<=(int a, const BST::Node& node) -> bool; 
auto operator>(int a, const BST::Node& node) -> bool; 
auto operator>=(int a, const BST::Node& node) -> bool; 
auto operator==(int a, const BST::Node& node) -> bool; 

std::ostream& operator<<(std::ostream& os, const BST::Node& node);

std::ostream& operator<<(std::ostream& os, const BST& bst);

BST& operator++(BST& bst);

BST operator++(BST& bst, int);
#endif //BST_H