#include <bits/stdc++.h>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int start, int end) {
        if (start > end) {
            vector<TreeNode*> ans;
            ans.push_back(nullptr);

            return ans;
        }

        vector<TreeNode*> trees;

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees, rightTrees;

            leftTrees = dfs(start, i - 1);
            rightTrees = dfs(i + 1, end);

            for (auto& leftTree: leftTrees) {
                for (auto& rightTree: rightTrees) {
                    TreeNode *tree = new TreeNode(i, leftTree, rightTree);

                    trees.push_back(tree);
                }
            }
        }

        return trees;
    }
};