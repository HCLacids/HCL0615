/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 */
var validateStackSequences = function(pushed, popped) {
    let stack = [];
    let index = pushed.indexOf(popped.shift());

    for(let i = 0; i < index; i++) {
        stack.push(pushed[i]);
    }

    while(popped.length) {
        if(stack.indexOf(popped[0]) < 0) {
            for(let j = index + 1; j <= pushed.indexOf(popped[0]);j++) {
                stack.push(pushed[j]);
            }
            index = pushed.indexOf(popped[0]);
            continue;
        }
        let node = popped.shift();
        if(stack[stack.length - 1] !== node) return false;
        if(stack[stack.length - 1] === node) stack.pop();
    }
    return true;
};
