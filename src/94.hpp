/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


#ifdef HH_PRACTISE
#pragma once
#include "practise/preheader.h"
#endif // HH_PRACTISE


class Solution {
public:
    //vector<int> inorderTraversal(TreeNode* root) {
    //    vector<int> result;

    //    traversal(result, root);

    //    return result;
    //}

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        stack<TreeNode*> s;
        while (root || s.size()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            result.push_back(root->val);
            root = root->right;
        }

        return result;
    }

private:

    void traversal(vector<int>& result, const TreeNode* node) {
        if (node == nullptr) return;

        traversal(result, node->left);
        result.push_back(node->val);
        traversal(result, node->right);
    }

    void buildTree(int* tree, size_t size, TreeNode*& root, size_t index) {
        //// ÍêÈ«¶þ²æÊ÷
        //if (size <= index) return;
        //if (tree[index] == 0) return;
        //
        //root = new TreeNode(tree[index]);
        //buildTree(tree, size, root->left, index * 2 + 1);
        //buildTree(tree, size, root->right, index * 2 + 2);
        if (size == 0 || tree[0] == 0) {
            root = nullptr;
            return;
        }

        queue<TreeNode*> q;

        q.push(new TreeNode(tree[0]));

        root = q.front();

        TreeNode* tmp = nullptr;

        for (int i = 1; i < size || q.empty(); ++i) {
            tmp = q.front();
            q.pop();
            if (tree[i] == 0) {
                tmp->left = nullptr;
            }
            else {
                tmp->left = new TreeNode(tree[i]);
                q.push(tmp->left);
            }
            if (++i < size) {
                if (tree[i] == 0) {
                    tmp->right = nullptr;
                }
                else {
                    tmp->right = new TreeNode(tree[i]);
                    q.push(tmp->right);
                }
            }
        }
    }

    void freeTree(TreeNode* node) {
        if (node == nullptr) return;

        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }

public:

    void stub() {
        //int tree[] = { 1,0,2,0,0,3,0 };
        //int tree[] = { 1,0,2,3 };
        int tree[] = { 5, 4, 7, 3, 0, 2, 0, -1, 0, 9 };
        TreeNode* root = nullptr;
        buildTree(tree, sizeof(tree) / sizeof(int), root, 0);

        auto result = inorderTraversal(root);
        for (auto& elem : result) {
            cout << elem;
        }
        cout << endl;

        freeTree(root);
        root = nullptr;
    }
};