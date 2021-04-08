class Solution {
private:
    string reform = "";
public:
    bool isValidSerialization(string preorder) {
        string pre = preorder;
        replace(preorder.begin(), preorder.end(), ',', ' ');
        stringstream ss(preorder);
        //cout << ss.str() << "letmeseesee" << endl;
        //cout << "\nNo.1_________" << pre << "===========" << pre.length() << "_______" << endl;
        TreeNode* root = traverse(ss);
        //cout << "\nNo.2_________" << pre << "===========" << reform << "_______" << endl;
        
        tra(root);
        reform.erase(0, 1);
        replace(reform.begin(), reform.end(), ' ', ',');
        
        //cout << "\nNo.3_________" << pre << "===========" << reform << "_______" << endl;
        return pre == reform;
    }
    
    void tra(TreeNode* node) {
        if(!node) {
            reform += " #";
            return;
        } 
        //cout << node->val << " ";
        reform += " " + to_string(node->val);
        
        tra(node->left);
        tra(node->right);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return traverse(ss);
    }
    
    TreeNode* traverse(stringstream& ss) {
        string s;
        if(!ss.eof()) {
            ss >> s;
        } else {
            return nullptr;
        }
        //cout << "1s = ____" << s << "____ \n";
        //cout << typeid(s).name() << endl;
        if(s == "#") return nullptr;
        //cout << "\t2s = " << s << "$\n";

        TreeNode* root = new TreeNode(stoi(s));

        root->left = traverse(ss);
        root->right = traverse(ss);
        
        return root;
    }
};