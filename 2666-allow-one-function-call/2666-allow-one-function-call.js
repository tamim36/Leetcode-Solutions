/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    var privateFn = fn;
    return function(...args){
        if (privateFn){
            var res = privateFn(...args);
            privateFn = undefined;
            return res;
        }
        else {
            return undefined;
        }
    }
};
/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
