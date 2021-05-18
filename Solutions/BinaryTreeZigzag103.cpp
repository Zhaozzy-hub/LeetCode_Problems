#include <vector>;
#include<iostream>;
using namespace std;




 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

void solver(vector<vector<int>>& l, int layer, TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    if (l.size() < layer + 1) {
        l.push_back(vector<int>(1, root->val));
        solver(l, layer + 1, root->left);
        solver(l, layer + 1, root->right);
    }
    else if (layer % 2 == 0) {
        l[layer].push_back(root->val);
        solver(l, layer + 1, root->left);
        solver(l, layer + 1, root->right);
    }
    else if (layer % 2 != 0) {
        l[layer].insert(l[layer].begin(), root->val);
        solver(l, layer + 1, root->left);
        solver(l, layer + 1, root->right);
    }
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> l;
    vector<int> cur;
    int layer = 0;
    solver(l, layer, root);
    return l;
}