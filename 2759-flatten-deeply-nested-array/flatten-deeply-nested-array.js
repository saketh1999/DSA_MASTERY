/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    let res = []
    const flattening = (temp_arr,l)=>{
        for (const small_Arr of temp_arr){

        
        if (Array.isArray(small_Arr) && l>0){
            flattening(small_Arr,l-1)
        }
        else{
            res.push(small_Arr)
        }
    }

    }
    flattening(arr,n)
    return res
};