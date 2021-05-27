/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var mirrorTree = function(root) {
    if(!root) return null;
    let stack = [root];
    while(stack.length) {
        let node = stack.shift();
        let snode = node.left;
        if(node.right) stack.push(node.right);
        if(node.left) stack.push(node.left);
        node.left = node.right;
        node.right = snode;
    }
    return root;
};
