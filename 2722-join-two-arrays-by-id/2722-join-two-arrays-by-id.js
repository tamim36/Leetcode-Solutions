/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    arr.sort(function(a, b) {
        return fn(a) - fn(b)
    })
};

// 2722
var join = function(arr1, arr2) {
    let results = []
    sortBy(arr1, (obj) => obj.id)
    sortBy(arr2, (obj) => obj.id)
    let i = 0, j = 0;
    while ( i < arr1.length && j < arr2.length ){
        if (arr1[i].id < arr2[j].id)
            results.push(arr1[i++])
        else if (arr1[i].id === arr2[j].id){
            results.push({...arr1[i], ...arr2[j]})
            i++
            j++
        }
        else
            results.push(arr2[j++])
    }

    while(i < arr1.length)
        results.push(arr1[i++])

    while(j < arr2.length)
        results.push(arr2[j++])

    return results
};