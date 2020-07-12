/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s){
    let s1 = new RegExp(/(\{\}|\(\)|\[\])/);
    return s1.test(s);
};
