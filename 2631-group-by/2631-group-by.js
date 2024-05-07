/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    let results = {}

    this.forEach((elem) => {
        let key = fn(elem)
        if (!results[key])
            results[key] = [elem]
        else
            results[key].push(elem)
    })
    return results
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */