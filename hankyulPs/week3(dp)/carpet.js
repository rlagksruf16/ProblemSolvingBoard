function solution(brown, yellow) {
    let answer = [];
    
    let tmp = false;
    
    for(let i = 1; i <= yellow; i++) {
        for(let j = 1; j <= i; j++) {
            const si = i * j;
            if(yellow === si) {
                if(brown === ((i+2)*2+j*2) ) {
                    answer.push(i+2);
                    answer.push(j+2);
                    tmp = true;
                    break;
                }
            }
        }
        if(tmp === true)
            break;
    }
    return answer;
}