/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
  const isArray = (x) => {
    return Array.isArray(x)
  }

  const isObject = (x) => {
    return typeof x === 'object' && !Array.isArray(x) && x !== null
  }

  const recurObj = (ob) => {
    let res = {}
    for (const[k, v] of Object.entries(ob)){
        if (isArray(v))
            res[k] = recurArr(v)
        else if (isObject(v))
            res[k] = recurObj(v)
        else if (v)
            res[k] = v
    }
    return res
  }
  
  const recurArr = (arr) => {
    let res = []
    arr.forEach((elem) => {
        if (isObject(elem))
            res.push(recurObj(elem))
        else if (isArray(elem))
            res.push(recurArr(elem))
        else if (elem)
            res.push(elem)
    })
    return res
  }

  if (isArray(obj))
    return recurArr(obj)
  else 
    return recurObj(obj)
};