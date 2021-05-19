/**
 * @param {string} s
 * @return {string}
 */
// var replaceSpace = function(s) {
//     let words = s.split(' ');
//     let res = '';
//     words.forEach((a)=>{res += a + "%20"});
//     return res.replace(/%20$/,"");
// };

var replaceSpace = function(s) {
    let res = "";
    for (let c of s){
        if(c !== " ") res += c;
        else res += "%20";
    }
    return res;
};
