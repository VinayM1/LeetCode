class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse;

    void pushAll(TreeNode* node) {
        while (node != NULL) {
            st.push(node);

            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (reverse)
            pushAll(node->left);
        else
            pushAll(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if (root == NULL)
            return false;

        // Iterator from smallest to largest
        BSTIterator left(root, false);

        // Iterator from largest to smallest
        BSTIterator right(root, true);

        int i = left.next();
        int j = right.next();

        while (i < j) {

            int sum = i + j;

            if (sum == k)
                return true;

            else if (sum < k)
                i = left.next();

            else
                j = right.next();
        }

        return false;
    }
};