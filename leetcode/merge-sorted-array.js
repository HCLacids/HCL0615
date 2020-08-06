/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    for(let i = 0,j = 0; i < nums1.length;i++){
        if(!nums1[i] && i > m - 1){
            nums1[i] = nums2[j];
            j++;
        }
    }
    return nums1.sort((a,b)=>a-b)
};
