#include <iostream>
#include <vector>
#include <stack>
#include <memory> // for smart pointers

using namespace std;

// Tree node structure
struct Node {
    int data;
    vector<shared_ptr<Node>> children; // dynamic children list
    Node(int val) : data(val) {}
};

// DFS function to search for a goal node
bool dfs(shared_ptr<Node> root, int goal) {
    if (!root) return false;

    stack<shared_ptr<Node>> s;
    s.push(root);

    while (!s.empty()) {
        auto current = s.top();
        s.pop();

        cout << "Visiting node: " << current->data << endl;

        if (current->data == goal) {
            cout << "Goal node " << goal << " found!" << endl;
            return true;
        }

        // Push children in reverse order to maintain left-to-right DFS
        for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
            if (*it) s.push(*it);
        }
    }

    cout << "Goal node " << goal << " not found." << endl;
    return false;
}

// Helper to create a node
shared_ptr<Node> createNode(int val) {
    return make_shared<Node>(val);
}

int main() {
    int goal = 7;

    // -------- Example Tree 1 --------
    //       1
    //     / | \
    //    2  3  4
    //       |   \
    //       5    7
    auto root1 = createNode(1);
    root1->children.push_back(createNode(2));
    root1->children.push_back(createNode(3));
    root1->children.push_back(createNode(4));
    root1->children[1]->children.push_back(createNode(5));
    root1->children[2]->children.push_back(createNode(7));

    cout << "\n--- DFS on Tree 1 ---\n";
    dfs(root1, goal);

    // -------- Example Tree 2 --------
    //       10
    //      /  \
    //     6    15
    //    / \     \
    //   3   7     20
    auto root2 = createNode(10);
    root2->children.push_back(createNode(6));
    root2->children.push_back(createNode(15));
    root2->children[0]->children.push_back(createNode(3));
    root2->children[0]->children.push_back(createNode(7));
    root2->children[1]->children.push_back(createNode(20));

    cout << "\n--- DFS on Tree 2 ---\n";
    dfs(root2, goal);

    return 0;
}
