/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    res = new Array()
    let i = 0 

    let temp = []
    while (i< arr.length){
        
        temp.push(arr[i])
        if (temp.length === size && temp!= null){
            res.push(temp)
             temp= []
        }
       i++
    
    }
    if (temp.length !== 0){
        res.push(temp)
    }

    return res
};
