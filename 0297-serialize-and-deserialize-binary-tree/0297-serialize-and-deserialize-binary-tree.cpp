class Codec {
public:

    void preorder(TreeNode* root, string& ans)
    {
        if(root == NULL)
        {
            ans += "N,";
            return;
        }

        ans += to_string(root->val) + ",";

        preorder(root->left, ans);

        preorder(root->right, ans);
    }

    string serialize(TreeNode* root)
    {
        string ans;

        preorder(root, ans);

        return ans;
    }

    TreeNode* build(vector<string>& values, int& index)
    {
        if(values[index] == "N")
        {
            index++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(values[index]));

        index++;

        root->left = build(values, index);

        root->right = build(values, index);

        return root;
    }

    TreeNode* deserialize(string data)
    {
        vector<string> values;

        string temp;

        for(char ch : data)
        {
            if(ch == ',')
            {
                values.push_back(temp);
                temp.clear();
            }
            else
            {
                temp += ch;
            }
        }

        int index = 0;

        return build(values, index);
    }
};