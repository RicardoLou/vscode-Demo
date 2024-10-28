function roll() {
    var userList = [];
    let list = document.getElementsByClassName('user-name');
    for (var item of list) {
        userList.push(item.innerText);
    }
    console.log("总共"+ userList.length + "人评论");    
    let choose = new Set();
    while(1) {
        if(choose.size != 0) {
            break;
        }
        let lucky_num = Math.floor(Math.random() * userList.length);
        choose.add(lucky_num);
        console.log("lucky_num:" + lucky_num);
    }

    for (var item of choose) {
        console.log("中奖用户为:"+userList[item]);
    }
}