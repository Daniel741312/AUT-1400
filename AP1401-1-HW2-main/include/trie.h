#ifndef TRIE_H
#define TRIE_H
#include <functional>
#include <string>
#include <vector>

class Trie {
   public:
    class Node {
       public:
        Node(char data, bool is_finished)
            : data(data), is_finished(is_finished) {}
        Node(const Node& node) : Node(node.data, node.is_finished) {
            children.resize(node.children.size());
        }
        std::vector<Node*> children;
        char data;
        bool is_finished;
    };

    Trie() { root = new Node(0, false); }
    Trie(const std::initializer_list<std::string>& args) : Trie() {
        for (const auto& i : args) {
            this->insert(i);
        }
    }

    void insert(std::string str);
    bool search(std::string query);
    void bfs(std::function<void(Node*& node)> func);

    ~Trie() {
        if (root == nullptr) return;
        std::vector<Node*> nodes;
        this->bfs([&nodes](Trie::Node*& node) { nodes.push_back(node); });
        for (const auto& node : nodes) delete node;
    }
    Trie(const Trie& trie);
    Trie(Trie&& trie) noexcept;
    Trie& operator=(const Trie& trie);
    Trie& operator=(Trie&& trie) noexcept;
    Node* root;

   private:
};
#endif  // TRIE_H