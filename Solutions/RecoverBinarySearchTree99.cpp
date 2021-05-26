#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};


void find_wrong(TreeNode* root, vector<TreeNode*>& missed) {
    if (root == NULL) return;
    find_wrong(root->left, missed);
    if (missed[0] == NULL && root->val < missed[2]->val) missed[0] = missed[2];
    if (missed[0] != NULL && root->val < missed[2]->val) missed[1] = root;
    missed[2] = root;
    find_wrong(root->right, missed);
}


void recoverTree(TreeNode* root) {
    vector<TreeNode*> missed(3, NULL);
    missed[2] = new TreeNode(INT_MIN);
    find_wrong(root, missed);
    TreeNode* f = missed[0];
    TreeNode* s = missed[1];
    int tmp;
    tmp = s->val;
    s->val = f->val;
    f->val = tmp;
    return;
}