/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
  return functions.reduceRight(function(prevFn, nextFn) {
    return function(x) {
      return nextFn(prevFn(x));
    };
  },  function(x) { return x; });
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */