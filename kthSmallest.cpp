// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// class Solution {
// public:
//     TreeNode* buildBSTFromLevelOrder(vector<int>& levelOrder) {
//         TreeNode* root = NULL;
//         for (int val : levelOrder) {
//             root = insertIntoBST(root, val);
//         }
//         return root;
//     }

//     TreeNode* insertIntoBST(TreeNode* node, int val) {
//         if (node == NULL) {
//             return new TreeNode(val);
//         }
//         if (val < node->val) {
//             node->left = insertIntoBST(node->left, val);
//         } else {
//             node->right = insertIntoBST(node->right, val);
//         }
//         return node;
//     }

//     int kthSmallest(TreeNode* root, int k) {
//         int count = 0;
//         int result = -1;
//         inorderTraversal(root, k, count, result);
//         return result;
//     }

//     void inorderTraversal(TreeNode* node, int k, int& count, int& result) {
//         if (node == NULL || count >= k) {
//             return;
//         }
//         inorderTraversal(node->left, k, count, result);
//         count++;
//         if (count == k) {
//             result = node->val;
//             return;
//         }
//         inorderTraversal(node->right, k, count, result);
//     }
// };

// int main() {
//     vector<int> levelOrder = {5, 3, 7, 2, 4, 6, 8};

//     Solution solution;
//     TreeNode* root = solution.buildBSTFromLevelOrder(levelOrder);

//     int k = 3;
//     cout << "第 " << k << " 小的节点是: " << solution.kthSmallest(root, k) << endl;

//     return 0;
// }
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildBSTFromLevelOrder(vector<string>& levelOrder) {
        if (levelOrder.empty() || levelOrder[0] == "null") {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(stoi(levelOrder[0]));
        queue<TreeNode*> q;
        q.push(root);
        
        int index = 1;
        while (!q.empty() && index < levelOrder.size()) {
            TreeNode* current = q.front();
            q.pop();
            
            if (levelOrder[index] != "null") {
                current->left = new TreeNode(stoi(levelOrder[index]));
                q.push(current->left);
            }
            index++;
            
            if (index < levelOrder.size() && levelOrder[index] != "null") {
                current->right = new TreeNode(stoi(levelOrder[index]));
                q.push(current->right);
            }
            index++;
        }
        return root;
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        inorderTraversal(root, k, count, result);
        return result;
    }

    void inorderTraversal(TreeNode* node, int k, int& count, int& result) {
        if (node == NULL || count >= k) {
            return;
        }
        inorderTraversal(node->left, k, count, result);
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        inorderTraversal(node->right, k, count, result);
    }
};

int main() {
    vector<string> levelOrder = {"5", "3", "7", "2", "4", "6", "8"};

    Solution solution;
    TreeNode* root = solution.buildBSTFromLevelOrder(levelOrder);

    int k = 3;
    cout << "第 " << k << " 小的结点值是: " << solution.kthSmallest(root, k) << endl;

    return 0;
}

