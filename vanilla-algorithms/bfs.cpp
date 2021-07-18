void bfs(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        queue<TreeNode*> bfs;
        bfs.push(root);

        while (bfs.size() != 0) {
            int current_breadth = bfs.size();

            // This for loop isn't really necessary for BFS, but is useful to keep track
            // of levels
            for (int i = 0; i < current_breadth; i++) {
                TreeNode *node = bfs.front();
                bfs.pop();

                // Process `node`
                
                // Insert only non-null nodes into the queue
                if (node -> left != NULL) {
                    bfs.push(node -> left);
                }

                if (node -> right != NULL) {
                    bfs.push(node -> right);
                }
            }
        }

        return;
    }