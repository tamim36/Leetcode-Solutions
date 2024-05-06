/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let results = []
    let count = 0
    let chunk = []

    arr.forEach((elem) => {
        chunk.push(elem)
        count++;

        if (count === size){
            count = 0
            results.push(chunk)
            chunk = []
        }
    })

    if (chunk.length)
        results.push(chunk)
    return results
};