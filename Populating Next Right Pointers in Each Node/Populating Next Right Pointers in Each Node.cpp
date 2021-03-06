/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

 /*
    1.bfs
    2.从第一层开始遍历
    3.遍历每一层的时候我们实际上做的是把它的下一层的next给连好，因为当前层已经连好了
    time O(n),space O(1)
*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while(root){
            TreeLinkNode* cur = root;
            TreeLinkNode* prev = NULL;
            while(cur && cur->left){
                if(prev)    prev->next = cur->left;
                cur->left->next = cur->right;
                prev = cur->right;
                cur = cur->next;
            }
            root = root->left;
        }
    }
};

