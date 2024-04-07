/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    return arr.reduce((newArr, x, i) => {
        if (fn(x, i)){
            newArr.push(x)
        }
        return newArr
    }, []);
  };