function autoSubmit() {
    // 每次允许为十次
    let i = 0;
    const intervalId = setInterval(function() {
        // 修改input的值
        //任我行： 27483202
        //苦瓜： 64293
        //于心有愧： 64797
        //
        document.getElementById("tool_listen_songid").value = "64293";
        document.getElementById("tool_listen_times").value = 1000;
        // 调用ajax_tool_listen函数
        ajax_tool_listen("1546648386");
        i++;
        // 当i达到10时，清除定时器
        if (i >= 20) {
            clearInterval(intervalId);
        }
    }, 10000); // 每隔10秒执行一次
}

// 调用函数开始自动提交
autoSubmit();
