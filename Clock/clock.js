function displayTime() {
    var time = new Date();
    var hour = time.getHours();
    var min = time.getMinutes();
    var sec = time.getSeconds();
    var section = "AM";

    if (hour == 0) {
        hour = 12;
    }
    if (hour > 12) {
        hour = hour - 12;
        section = "PM";
    }

    hour = (hour < 10) ? "0" + hour : hour;
    min = (min < 10) ? "0" + min : min;
    sec = (sec < 10) ? "0" + sec : sec;
    
    var time = hour + ":" + min + ":" + sec + " " + section;
    document.getElementById("clock").innerText = time;
    document.getElementById("clock").textContent = time;

    setTimeout(displayTime, 1000);
}

displayTime();