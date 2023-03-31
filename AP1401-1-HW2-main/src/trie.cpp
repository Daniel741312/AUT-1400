#include "trie.h"

#include <queue>

static Trie::Node* search_prefix(std::string& query, const Trie* t) {
    size_t i = 0;
    Trie::Node* r = t->root;
    for (char ch : query) {
        bool dismatch = true;
        for (const auto& child : r->children) {
            if (child->data == ch) {
                r = child;
                dismatch = false;
                ++i;
            }
        }
        if (dismatch) {
            break;
        }
    }
    query = std::string(query.begin() + i, query.end());
    return r;
}

static Trie::Node* convert_string2trie(const std::string& str) {
    size_t i = 0;
    Trie::Node* root = new Trie::Node(str[i], false);
    ++i;
    Trie::Node* r = root;
    for (; i < str.size(); ++i) {
        Trie::Node* node = new Trie::Node(str[i], false);
        r->children.push_back(node);
        r = node;
    }
    r->is_finished = true;
    return root;
}

void Trie::insert(std::string str) {
    size_t i = 0;
    Node* r = root;
    auto node = search_prefix(str, this);
    if (str.empty()) {
        return;
    } else {
        auto trie = convert_string2trie(str);
        node->children.push_back(trie);
    }
}

// whath shoulw empty query return ?
bool Trie::search(std::string query) {
    Node* node = search_prefix(query, this);
    return query.empty() && node->is_finished;
}

void Trie::bfs(std::function<void(Node*& node)> func) {
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        func(node);
        for (auto& child : node->children) {
            q.push(child);
        }
    }
}

static Trie::Node* copy_trie(Trie::Node* root) {
    auto node = root;
    if (root) {
        node = new Trie::Node(*root);
        for (int i = 0; i < root->children.size(); ++i) {
            node->children[i] = copy_trie(root->children[i]);
        }
    }
    return node;
}

Trie::Trie(const Trie& trie) { root = copy_trie(trie.root); }

Trie::Trie(Trie&& trie) noexcept {
    this->root = trie.root;
    trie.root = nullptr;
}

Trie& Trie::operator=(const Trie& trie) {
    if (&trie != this) {
        std::vector<Node*> nodes;
        this->bfs([&nodes](Trie::Node*& node) { nodes.push_back(node); });
        for (const auto& node : nodes) delete node;
        root = copy_trie(trie.root);
    }
    return *this;
}

Trie& Trie::operator=(Trie&& trie) noexcept {
    if (&trie != this) {
        std::vector<Node*> nodes;
        this->bfs([&nodes](Trie::Node*& node) { nodes.push_back(node); });
        for (const auto& node : nodes) delete node;
        root = trie.root;
        trie.root = nullptr;
    }
    return *this;
}