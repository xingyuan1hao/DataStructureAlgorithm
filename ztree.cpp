/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if(pRoot == nullptr) return res;
        stack<TreeNode*> stackL;
        stack<TreeNode*> stackR;
        TreeNode* popNode;
        vector<int> tmp;
        tmp.push_back(pRoot->val);
        res.push_back(tmp);
        tmp.clear();
        stackL.push(pRoot);
        while(!stackL.empty() || !stackR.empty()){
            while(!stackL.empty()){
                popNode = stackL.top();
                stackL.pop();
                if(popNode->right){
                    stackR.push(popNode->right);
                    tmp.push_back(popNode->right->val);               
                }
                if(popNode->left){
                    stackR.push(popNode->left);
                    tmp.push_back(popNode->left->val);
                }
            }
            if(!tmp.empty()) {
                res.push_back(tmp);
                tmp.clear();
            }
            while(!stackR.empty()){
                popNode = stackR.top();
                stackR.pop();
                if(popNode->left){
                    stackL.push(popNode->left);
                    tmp.push_back(popNode->left->val);
                }
                if(popNode->right){
                    stackL.push(popNode->right);
                    tmp.push_back(popNode->right->val);
                }
            }
            if(!tmp.empty()){
                res.push_back(tmp);
                tmp.clear();
            }
        }
        return res;
         
    }
     
};