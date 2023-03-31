
#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "trie.h"

TEST(HW2Test, TEST1) {
    Trie::Node node{'a', false};
    EXPECT_EQ(node.data, 'a');
    EXPECT_EQ(node.is_finished, false);
}
///*
TEST(HW2Test, TEST2) {
    Trie::Node node{'a', false};
    Trie::Node child1{'b', false};
    Trie::Node child2{'c', true};
    node.children.push_back(&child1);
    node.children.push_back(&child2);

    EXPECT_EQ(node.children.size(), 2);
    EXPECT_EQ(node.children[0]->data, 'b');
    EXPECT_EQ(node.children[1]->data, 'c');
    EXPECT_EQ(node.children[1]->is_finished, true); 
}
//*/

TEST(HW2Test, TEST3) {
    Trie trie{};
    EXPECT_EQ(trie.root->data, '\0');
    EXPECT_EQ(trie.root->children.size(), 0);
}

TEST(HW2Test, TEST4) {
    Trie trie{};
    trie.insert("there");

    EXPECT_EQ(trie.root->children.size(), 1);
    EXPECT_EQ(trie.root->children[0]->data, 't');
    EXPECT_EQ(trie.root->children[0]->children.size(), 1);
    EXPECT_EQ(trie.root->children[0]->children[0]->data, 'h');
    EXPECT_EQ(trie.root->children[0]->children[0]->is_finished, false);
    EXPECT_EQ(trie.root->children[0]->children[0]->children[0]->children[0]->children[0]->data, 'e');
    EXPECT_EQ(trie.root->children[0]->children[0]->children[0]->children[0]->children[0]->is_finished, true);
    EXPECT_EQ(trie.root->children[0]->children[0]->children[0]->children[0]->children[0]->children.size(), 0);
}

TEST(HW2Test, TEST5) {
    Trie trie{};
    trie.insert("there");
    trie.insert("does");

    EXPECT_EQ(trie.root->children.size(), 2);
    EXPECT_EQ(trie.root->children[1]->data, 'd');
    EXPECT_EQ(trie.root->children[1]->children[0]->data, 'o');
    EXPECT_EQ(trie.root->children[1]->children[0]->children[0]->children[0]->data, 's');
    EXPECT_EQ(trie.root->children[1]->children[0]->children[0]->children[0]->is_finished, true);
}

TEST(HW2Test, TEST6) {
    Trie trie{};
    trie.insert("there");
    trie.insert("does");
    trie.insert("that");

    EXPECT_EQ(trie.root->children.size(), 2);
    EXPECT_EQ(trie.root->children[0]->children.size(), 1);
    EXPECT_EQ(trie.root->children[0]->children[0]->children.size(), 2);
    EXPECT_EQ(trie.root->children[0]->children[0]->children[1]->data, 'a') ;
    EXPECT_EQ(trie.root->children[0]->children[0]->children[1]->children[0]->data, 't');
    EXPECT_EQ(trie.root->children[0]->children[0]->children[1]->children[0]->is_finished, true);
}

TEST(HW2Test, TEST7) {
    Trie trie{};
    trie.insert("there");
    trie.insert("does");
    trie.insert("that");
    trie.insert("this");
    trie.insert("did");

    EXPECT_EQ(trie.root->children.size(), 2);
    EXPECT_EQ(trie.root->children[0]->children[0]->children.size(), 3);
    EXPECT_EQ(trie.root->children[1]->children.size(), 2);
    EXPECT_EQ(trie.root->children[1]->children[1]->data, 'i');
    EXPECT_EQ(trie.root->children[1]->children[1]->is_finished, false);
    EXPECT_EQ(trie.root->children[0]->children[0]->children[2]->data, 'i');
}

TEST(HW2Test, TEST8) {
    Trie trie;
    trie.insert("there");
    std::vector<Trie::Node*> nodes;
    trie.bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
    EXPECT_EQ(nodes.size(), 6);
}

TEST(HW2Test, TEST9) {
    Trie trie;
    trie.insert("there");
    trie.insert("that");
    std::vector<Trie::Node*> nodes;
    trie.bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
    EXPECT_EQ(nodes.size(), 8);
}

TEST(HW2Test, TEST10) {
    Trie trie;
    trie.insert("there");
    trie.insert("does");
    trie.insert("that");
    trie.insert("this");
    trie.insert("did");

    std::vector<Trie::Node*> nodes;
    trie.bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
    EXPECT_EQ(nodes.size(), 16);
}

TEST(HW2Test, TEST11) {
    Trie trie;
    trie.insert("there");
    trie.insert("that");
    trie.insert("this");
    trie.insert("did");
    trie.insert("does");

    EXPECT_EQ(trie.search("hello"), false);
    EXPECT_EQ(trie.search("that"), true);
    EXPECT_EQ(trie.search("does"), true);
    EXPECT_EQ(trie.search("do"), false); // "do" exists in the tree but not as a full string (no is_finished after 'o')
    EXPECT_EQ(trie.search("this"), true);
    EXPECT_EQ(trie.search("thisis"), false);
}

///*
TEST(HW2Test, TEST12) {
    Trie trie{"there", "that", "does"};
    EXPECT_EQ(trie.root->children.size(), 2);
    EXPECT_EQ(trie.root->children[0]->children[0]->children[1]->data, 'a');
}

TEST(HW2Test, TEST13) {
    Trie trie{"there", "that", "this", "does", "did"};
    EXPECT_EQ(trie.root->children.size(), 2);
    EXPECT_EQ(trie.root->children[0]->children[0]->children.size(), 3);
    EXPECT_EQ(trie.root->children[1]->children.size(), 2);
    EXPECT_EQ(trie.root->children[1]->children[1]->data, 'i');
    EXPECT_EQ(trie.root->children[1]->children[1]->is_finished, false);
    EXPECT_EQ(trie.root->children[0]->children[0]->children[2]->data, 'i');
}

TEST(HW2Test, TEST14) {
    Trie copy{"there", "that", "this", "does", "did"};
    Trie trie{copy};

    std::vector<Trie::Node*> nodes;
    trie.bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
    EXPECT_EQ(nodes.size(), 16);
}

TEST(HW2Test, TEST15) {

    Trie move{"there", "that", "this", "does", "did"};
    Trie::Node* address{move.root};

    Trie trie{std::move(move)};
    EXPECT_EQ(address, trie.root);

    std::vector<Trie::Node*> nodes;
    trie.bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
    EXPECT_EQ(nodes.size(), 16);
}

TEST(HW2Test, TEST16) {

    Trie equal{"there", "that", "this", "does", "did"};
    Trie trie{};
    trie = equal;

    std::vector<Trie::Node*> nodes;
    trie.bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
    EXPECT_EQ(nodes.size(), 16);
}

TEST(HW2Test, TEST17) {

    Trie equal{"there", "that", "this", "does", "did"};
    Trie::Node* address{equal.root};

    Trie trie{};
    trie = std::move(equal);
    EXPECT_EQ(address, trie.root);

    std::vector<Trie::Node*> nodes;
    trie.bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
    EXPECT_EQ(nodes.size(), 16);
}
//*/