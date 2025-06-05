/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var fi = 0;
    for (var i = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            if (i !== fi) {
                var temp = arr[i];
                arr[i] = arr[fi];
                arr[fi] = temp;
            }
            fi++;
        }
    }
    arr.length = fi;
    return arr;
};