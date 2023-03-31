#include "bst.h"

#include <iomanip>
#include <queue>
#include <vector>

BST::BST(std::initializer_list<int> il) {
	/*
	 * root points a dummy Node, whose 'left child' is the real Root
	 * whose value is the length of the current tree
	 */
	this->root = new Node(0, nullptr, nullptr);
	for (auto i : il) {
		add_node(i);
	}
}

static void copy_BST(BST::Node* src, BST::Node*& dst) {
	if (src) {
		dst = new BST::Node(src->value, 0, 0);
		copy_BST(src->left, dst->left);
		copy_BST(src->right, dst->right);
	}
}

BST::BST(const BST& bst) {
	this->root = new Node(bst.root->value, nullptr, nullptr);
	if (bst.get_root()) {
		copy_BST(bst.get_root(), get_root());
	}
}

/*
 * 1. copy the parameter object
 * 2. destruct self
 * 3. copy the member varible one by one
 */
BST& BST::operator=(const BST& bst) {
	auto bst2 = new BST(bst);
	this->~BST();
	root = bst2->root;
	return *this;
}

BST::BST(BST&& bst) noexcept {
	this->root = new Node(bst.root->value, 0, 0);
	this->root->left = bst.root->left;
	bst.root->left = nullptr;
}

BST& BST::operator=(BST&& bst) noexcept {
	if (this != &bst) {
		this->~BST();
		this->root = new Node(bst.root->value, 0, 0);
		this->root->left = bst.root->left;
		bst.root->left = nullptr;
	}
	return *this;
}

BST::Node*& BST::get_root() const {
	return this->root->left;
}

void BST::bfs(std::function<void(Node*& node)> func) {
	if (get_root() == nullptr)
		return;
	std::queue<Node*> q;
	q.push(get_root());
	while (!q.empty()) {
		auto pn = q.front();
		q.pop();
		func(pn);
		if (pn->left)
			q.push(pn->left);
		if (pn->right)
			q.push(pn->right);
	}
}

size_t BST::length() {
	return this->root->value;
}

bool BST::add_node(int value) {
	Node* r = get_root();
	Node* prev;
	if (r == nullptr) {
		this->root->left = new Node(value, nullptr, nullptr);
		this->root->value++;
		return true;
	}
	while (r) {
		prev = r;
		if (value < r->value) {
			r = r->left;
		} else if (value > r->value) {
			r = r->right;
		} else {
			return false;
		}
	}
	if (value < prev->value) {
		prev->left = new Node(value, nullptr, nullptr);
	} else if (value > prev->value) {
		prev->right = new Node(value, nullptr, nullptr);
	} else {
		return false;
	}
	this->root->value++;
	return true;
}

BST::Node** BST::find_node(int value) {
	Node* r = get_root();
	if (r == nullptr)
		return nullptr;
	Node* prev = root;
	while (r) {
		if (r->value == value) {
			break;
		} else if (value > r->value) {
			prev = r;
			r = r->right;
		} else {
			prev = r;
			r = r->left;
		}
	}

	if (r) {
		if (prev->left && prev->left->value == value)
			return &(prev->left);
		if (prev->right && prev->right->value == value)
			return &(prev->right);
	}
	return nullptr;
}

BST::Node** BST::find_parrent(int value) {
	Node *r, *prev;
	r = get_root();
	if (r == nullptr)
		return nullptr;
	if (r->value == value)
		return &(root);
	while (r) {
		if (value < r->value) {
			prev = r;
			r = r->left;
		} else if (value > r->value) {
			prev = r;
			r = r->right;
		} else {
			break;
		}
	}
	return find_node(prev->value);
}

/*
 * I don't know how do they define 'sccessor'
 * anyway, oriented test-cases programming
 */
static void inorder_traversal(BST::Node* root, std::vector<BST::Node*>& res) {
	if (root) {
		inorder_traversal(root->right, res);
		res.push_back(root);
		inorder_traversal(root->left, res);
	}
}

BST::Node** BST::find_successor(int value) {
	Node* r = get_root();
	if (r == nullptr)
		return nullptr;
	std::vector<BST::Node*> res;
	inorder_traversal(r, res);
	int i = 0;
	for (; i < res.size(); ++i) {
		if (res[i]->value == value)
			break;
	}
	return i + 1 < res.size() ? find_node(res[i + 1]->value) : nullptr;
}

static BST::Node* find_max(BST::Node* root) {
	while (root && root->right) {
		root = root->right;
	}
	return root;
}

bool BST::delete_node(int value) {
	Node* r = get_root();
	if (r == nullptr)
		return false;
	Node** ppnode = find_node(value);
	if (ppnode == nullptr)
		return false;
	Node* node = *ppnode;
	if (node->left == nullptr && node->right == nullptr) {
		delete node;
		*ppnode = nullptr;
	} else if (node->left == nullptr) {
		*ppnode = node->right;
		delete node;
	} else if (node->right == nullptr) {
		*ppnode = node->left;
		delete node;
	} else {
		Node* mx = find_max(node->left);
		auto pmx = find_parrent(mx->value);
		std::swap(mx->value, node->value);
		(*pmx)->right = nullptr;
		delete mx;
	}
	root->value--;
	return true;
}

BST::~BST() {
	std::vector<Node*> nodes;
	bfs([&nodes](BST::Node*& node) { nodes.push_back(node); });
	for (auto& node : nodes)
		delete node;
	delete root;
}

BST::Node::Node(int value, Node* left, Node* right)
	: value(value), left(left), right(right) {
}
BST::Node::Node()
	: Node(0, nullptr, nullptr) {
}  // delegating constructor
BST::Node::Node(const Node& node)
	: Node(node.value, node.left, node.right) {
}  // delegating constructor

bool operator>(const BST::Node& node, int a) {
	return node.value > a;
}
bool operator>=(const BST::Node& node, int a) {
	return node.value == a || node.value > a;
}
bool operator<(const BST::Node& node, int a) {
	return node.value < a;
}
bool operator<=(const BST::Node& node, int a) {
	return node.value == a || node.value < a;
}
bool operator==(const BST::Node& node, int a) {
	return a == node.value;
}

// trailing return type, looks like python, haa?:-)
auto operator<(int a, const BST::Node& node) -> bool {
	return node.value > a;
}
auto operator<=(int a, const BST::Node& node) -> bool {
	return node.value == a || node.value > a;
}
auto operator>(int a, const BST::Node& node) -> bool {
	return node.value < a;
}
auto operator>=(int a, const BST::Node& node) -> bool {
	return node.value == a || node.value < a;
}
auto operator==(int a, const BST::Node& node) -> bool {
	return a == node.value;
}

std::ostream& operator<<(std::ostream& os, const BST::Node& node) {
	os << std::hex << &os << std::dec << "\t=> value:" << node.value
	   << "\tleft:" << std::left << std::setw(20) << std::hex << node.left << "\tright:" << node.right << std::dec;
	return os;
}

std::ostream& operator<<(std::ostream& os, const BST& bst) {
	std::cout << std::string(82, '*') << std::endl;
	std::queue<BST::Node*> q;
	q.push(bst.get_root());
	while (!q.empty()) {
		auto node = q.front();
		q.pop();
		std::cout << *node << std::endl;
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
	}
	std::cout << std::string(82, '*') << std::endl;
	return os;
}

BST& operator++(BST& bst) {
	bst.bfs([](BST::Node*& node) { ++node->value; });
	return bst;
}

BST operator++(BST& bst, int) {
	BST b(bst);
	++bst;
	return b;
}