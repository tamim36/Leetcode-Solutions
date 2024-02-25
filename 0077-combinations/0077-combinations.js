/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
    let ans = []

    function recur_combine(cur, sofar){
        if (sofar.length == k){
            ans.push([...sofar])
            return
        }

        for (let i = cur; i <= n; i++){
            sofar.push(i)
            recur_combine(i+1, sofar)
            sofar.pop()
        }
    }

    recur_combine(1, [])
    return ans
};