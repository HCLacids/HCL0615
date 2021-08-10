/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    function mathRight(target) {
        let j = nums.length-1;
        let i = 0;
        while(i<=j) {
        let mid =  parseInt((i+j)/2);
        if(nums[mid]<=target) i = mid + 1;
        else j = mid - 1;
        }
        return i;
    }
    let right = mathRight(target);
    let left = mathRight(target - 1);
    return right - left;
};
