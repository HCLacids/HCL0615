/**
 * @param {number[]} numbers
 * @return {number}
 */
// var minArray = function(numbers) {
//     let max = numbers[0];
//     for(let a of numbers){
//         if(a > max) max = a;
//         else if (a < max)return a;
//     }
//     if(max == numbers[numbers.length - 1]) return numbers[0];
// };

var minArray = function(numbers) {
    let low = 0, high = numbers.length -1, mid; 
    while(high > low){
        mid = low + Math.floor((high - low) / 2);
        if(numbers[high] > numbers[mid]) high = mid;
        else if(numbers[high] < numbers[mid]) low = mid + 1;
        else high -= 1;
    }
    return numbers[low];
};
