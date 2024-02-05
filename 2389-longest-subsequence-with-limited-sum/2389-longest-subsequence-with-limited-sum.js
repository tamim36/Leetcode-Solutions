/**
 * @param {number[]} nums
 * @param {number[]} queries
 * @return {number[]}
 */
var answerQueries = function(nums, queries) {
    nums.sort((a, b) => a - b);

    const prefixSum = [nums[0]];
    for (let i = 1; i < nums.length; i++){
        prefixSum.push(prefixSum[i - 1] + nums[i]);
    }

    const binarySearch = (arr, left, right, val) => {
        if (right >= left){
            let mid = left + Math.floor((right - left) / 2);

            if (arr[mid] == val){
                return mid;
            } 
            else if (val < arr[mid]){
                return binarySearch(arr, left, mid - 1, val);
            }
            else {
                return binarySearch(arr, mid+1, right, val);
            }
        }
        else {
            return right;
        }
    }

    const answer = [];
    for (let j = 0; j < queries.length; j++){
        answer.push(binarySearch(prefixSum, 0, prefixSum.length - 1, queries[j]) + 1);
    }

    return answer;
};