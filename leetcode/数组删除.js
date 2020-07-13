/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    let index = 0;
    for(let num of nums){
        if(num != val){
            nums[index] = num;
            index++;
        }
    }
    return index;
};
