    bool areAnagrams(Node *root1, Node *root2)
    {
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;
        queue<Node*>q1,q2;
        q1.push(root1);
        q2.push(root2);
        while(1){
            int s1=q1.size();
            int s2=q2.size();
            if(s1!=s2) return false;
            if(s1==0) break;
            vector<int>Lt1,Lt2;
            while(s1--){
                Node* node1=q1.front();
                q1.pop();
                if(node1->left!=NULL) q1.push(node1->left);
                if(node1->right!=NULL) q1.push(node1->right);
                Lt1.push_back(node1->data);
                Node* node2=q2.front();
                q2.pop();
                if(node2->left!=NULL) q2.push(node2->left);
                if(node2->right!=NULL) q2.push(node2->right);
                Lt2.push_back(node2->data);
            }
            sort(Lt1.begin(),Lt1.end());
            sort(Lt2.begin(),Lt2.end());
            if(Lt1!=Lt2) return false;
        }
        return true;
    }
