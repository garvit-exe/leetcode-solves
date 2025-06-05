/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    if (Array.isArray(obj)) {
        return obj.length === 0;
    }

    for (const property in obj) {
        if (Object.hasOwn(obj, property)) {
            return false;
        }
    }

    return true;
};