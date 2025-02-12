/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let temp = []
    arr.map((item,index)=>temp.push(fn(item,index)))

    return temp
};