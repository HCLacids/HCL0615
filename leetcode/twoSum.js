function twoSum(arr,target) {
    let p1 = 0;
    let p2 = arr.length - 1;
    while(p2 > p1) {
        if(arr[p1] + arr[p2] === target) return [p1, p2];
        if(arr[p1] + arr[p2] > target) p2--;
        else {
            p1++;
        };
    }
}
console.log(twoSum([1,2,2,4],4))
