//60秒开始op，90秒op 片尾1300秒
function skip (start_length, start_end_length, end_length) {
    //三个都为0则是暂停
    if (!start_length && !end_length && !start_end_length) {
        return;
    }
    let total_time = player.getDuration();
    let skip_point_start = start_length;
    let skip_point_end = end_length;
    let has_listener = false;
    const interval = 1000;
    window.timer = 0;

    function start () {
        console.log('开搞');
        if (timer) {
            clearInterval(timer);
        }
        timer = setInterval(handler, interval)
    }
    function handler () {
        let current_time = player.getCurrentTime();
        if (current_time < skip_point_start) {
            console.log('跳过片头')
            return window.player.seek(start_length);
        }
        //到了op的时候
        if(current_time > start_end_length && current_time < start_end_length + 90) {
            console.log('跳过op');
            return window.player.seek(start_end_length + 90);
        }
        if (current_time >= skip_point_end) {
            console.log('跳过片尾,下一集')
            if (!has_listener) {
                has_listener = true;
                window.player.addEventListener('video_media_loaded', start);
            }
            return window.player.next();
        }
    }
    start();
}