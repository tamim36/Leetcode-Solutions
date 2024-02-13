/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    let data = []
    function _permute(curr, remaining){
        if (!remaining.length){
            data.push(curr)
            return
        }

        let uniques = new Set()
        for (let i = 0; i < remaining.length; i++){
            if (uniques.has(remaining[i])){
                continue
            }
            else {
                uniques.add(remaining[i])
                curr.push(remaining[i])
                _permute([...curr], [...remaining.slice(0, i), ...remaining.slice(i+1)])
                curr.pop()
            }
        }
    }

    _permute([], nums)
    return data
};