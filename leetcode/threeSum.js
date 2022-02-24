function threeSum(arr) {
    let res = [];
    arr.sort((a, b) => a - b);
    let i = 0;
    while(i < arr.length - 2) {
        twoSum(arr, i, res)
        let temp = arr[i];
        while(i < arr.length && arr[i] == temp ){
            ++i;
        }
    }
    return res;
}

function twoSum(arr, i, res) {
    let j = i + 1;
    let k = arr.length - 1;
    while(j < k) {
        if(arr[i] + arr[j] + arr[k] == 0){
            res.push([arr[i], arr[j], arr[k]]);
            let temp = arr[j];
            while(temp == arr[j] && j < k){
                ++j;
            }
        } else if(arr[i] + arr[j] + arr[k] < 0) {
            ++j;
        } else {
            --k;
        }
    } 
}

console.log(threeSum([-1,0,1,2,-1,-4]))
