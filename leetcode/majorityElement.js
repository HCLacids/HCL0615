/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let obj = {};
    nums.forEach((num) => {
        if(!obj.hasOwnProperty(num)) {
            obj[num] = 1;
        } else {
            obj[num] = obj[num] + 1;
        }
    });
    for(let [key, value] of Object.entries(obj)) {
        if(value > Math.floor(nums.length / 2)) return Number(key);
    }
};
