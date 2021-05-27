/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSymmetric = function(root) {
    if(!root) return true;
    let stackl = [root.left];
    let stackr = [root.right];
    while(stackl.length && stackr.length) {
        let nodel = stackl.shift();
        let noder = stackr.shift();
        if(!noder && !nodel) continue;
        if( !nodel || !noder ||nodel.val !== noder.val ) return false;
        if(nodel.left) stackl.push(nodel.left);
        if(!nodel.left)stackl.push(null);
        if(noder.right) stackr.push(noder.right)
        if(!noder.right)stackr.push(null);
        if(nodel.right) stackl.push(nodel.right);
        if(!nodel.right)stackl.push(null);
        if(noder.left) stackr.push(noder.left);
        if(!noder.left)stackr.push(null);
    }
    if(stackr.length || stackl.length) return false;
    return true;
};
