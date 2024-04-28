/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    let ans = 0;
    await promise1
        .then((val1) => promise2.then((val2) => {
            ans = val1 + val2;
            return ans;
        }))
    return new Promise(resolve => setTimeout(resolve(ans), 20))
};
/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */