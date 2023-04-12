#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd) {
    if(postorderEnd - postorderBegin == 0) return nullptr;
    int rootValue = postorder[postorderEnd - 1];
    TreeNode* root = new TreeNode(rootValue);
    int i;
    for(i = inorderBegin; i < inorderEnd; i ++) {
        if(inorder[i] == rootValue) {
            // cout << i << " ";
            break;
        }
    }
    int leftInorderBegin = inorderBegin;
    int leftInorderEnd = i;
    int rightInorderBegin = i + 1;
    int rightInorderEnd = inorderEnd;
    int leftPostorderBegin = postorderBegin;
    int leftPostorderEnd = postorderBegin + i - inorderBegin;
    int rightPostorderBegin = leftPostorderEnd;
    int rightPostorderEnd = postorderEnd - 1;
    root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
    root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);
    return root;
}

vector<int> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> res;
    if(root != nullptr) q.push(root);
    while(!q.empty()) {
        int size = q.size();
        while(size -- ) {
            TreeNode* node = q.front();
            res.push_back(node->val);
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> inorder(n);
    vector<int> postorder(n);
    for(int i = 0; i < n; i ++)
        cin >> inorder[i];
    for(int i = 0; i < n; i ++ )
        cin >> postorder[i]; 
    vector<int> res;
    if(inorder.size() == 0 || postorder.size() == 0) return 0;  
    TreeNode* root = traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    res = levelOrder(root);
    for(int i = 0; i < res.size(); i ++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}