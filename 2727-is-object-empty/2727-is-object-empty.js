/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    if (Object.keys(obj).length || obj.length)
        return false;
    else 
        return true;
};