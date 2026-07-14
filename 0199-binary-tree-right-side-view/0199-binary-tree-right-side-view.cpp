class Solution
{
public:

    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> answer;

        if(root == NULL)
        {
            return answer;
        }

        queue<TreeNode*> queueOfNodes;
        queueOfNodes.push(root);

        while(queueOfNodes.empty() == false)
        {
            int sizeOfCurrentLevel = queueOfNodes.size();

            int currentIndex = 0;

            while(currentIndex < sizeOfCurrentLevel)
            {
                TreeNode* currentNode = queueOfNodes.front();
                queueOfNodes.pop();

                if(currentIndex == sizeOfCurrentLevel - 1)
                {
                    answer.push_back(currentNode->val);
                }

                if(currentNode->left != NULL)
                {
                    queueOfNodes.push(currentNode->left);
                }

                if(currentNode->right != NULL)
                {
                    queueOfNodes.push(currentNode->right);
                }

                currentIndex++;
            }
        }

        return answer;
    }
};