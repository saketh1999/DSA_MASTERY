/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    this.group = {}
    this.map((el)=> {
        key = fn(el)
        if (key in this.group){
             this.group[key].push(el)
        }
        else{
            this.group[key] = []
             this.group[key].push(el)

        }
       
    })
    return this.group
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */