/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if(!root) return []; 
    let queue = [root];
    let res = [];
    while(queue.length) {
        let tmp = [];
        for(let i = queue.length; i > 0; i--) {
            let node = queue.shift();
            tmp.push(node.val);
            if(node.left) queue.push(node.left);
            if(node.right) queue.push(node.right);
        }
        res.push(tmp);
    }
    return res;
};
