class BSTIterator {

public:

    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {

        TreeNode* node = st.top();
        st.pop();

        pushAll(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }

private:

    void pushAll(TreeNode* node){

        while(node != NULL){

            st.push(node);

            node = node->left;
        }
    }
};