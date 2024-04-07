/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    var val = init
  nums.forEach(element => {
    val = fn(val, element)
  });
  return val;
};