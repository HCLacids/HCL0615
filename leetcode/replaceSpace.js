/**
 * @param {string} s
 * @return {string}
 */
var replaceSpace = function(s) {
    let words = s.split(' ');
    let res = '';
    words.forEach((a)=>{res += a + "%20"});
    return res.replace(/%20$/,"");
};
