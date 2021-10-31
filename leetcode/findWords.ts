function findWords(words: string[]): string[] {
    let res: string[] = [];
    const lineOne: string[] = ['q','w','e','r','t','y','u','i','o','p'];
    const lineTwo: string[] = ['a','s','d','f','g','h','j','k','l'];
    const lineThree: string[] = ['z','x','c','v','b','n','m'];
    const dic: string[][] = [lineOne, lineTwo, lineThree];
    for(let str of words) {
        let index = 0;
        let point = 1;
        for(let i = 0; i < 3; i++) {
            if(dic[i].indexOf(str[0].toLowerCase()) > -1) 
                index = i;
        }
        for( ;point <= str.length - 1; point++) {          
            if(dic[index].indexOf(str[point].toLowerCase()) == -1)
                break;
        }
        if(point == str.length)
            res.push(str);
    }
    return(res);
};
