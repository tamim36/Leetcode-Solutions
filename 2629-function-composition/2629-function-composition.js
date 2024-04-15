/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    return function(inp) {
        return functions.reduceRight((acc, func) => {
            acc = func(acc)
            return acc
        }, inp);
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */