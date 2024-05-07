/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    let results = []

  const recursiveTraverse = (arr, depth) => {
    arr.forEach((elem) => {
        if (Array.isArray(elem) && depth + 1 <= n){
            recursiveTraverse(elem, depth + 1)
        }
        else 
            results.push(elem)
    })
  }
  
  recursiveTraverse(arr, 0)
  return results
};