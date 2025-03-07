/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let result = [];
    for (let i = 0; i < arr.length; i++) {
        if (fn(arr[i], i)) {  // Apply fn and check if it returns true
            result.push(arr[i]); // Only push elements that satisfy fn
        }
    }
    return result;
};
