window.onload = function () {
    var minutes = 0;
    var seconds = 0;
    var tens = 0;
    var updateMin = document.getElementById("minutes");
    var updateTen = document.getElementById("tens");
    var updateSec = document.getElementById("seconds");
    var buttonSta = document.getElementById('start-but');
    var buttonSto = document.getElementById('stop-but');
    var buttonRes = document.getElementById('reset-but');
    var interval;

    buttonSta.onclick = function () {
        clearInterval(interval);
        interval = setInterval(startTimer, 10);
    }

    buttonSto.onclick = function () {
        clearInterval(interval);
    }

    buttonRes.onclick = function () {
        clearInterval(interval);
        minutes = "00";
        tens = "00";
        seconds = "00";
        updateTen.innerHTML = tens;
        updateSec.innerHTML = seconds;
        updateMin.innerHTML = minutes;
    }

    function startTimer () {
        tens++;

        if (tens <= 9) {
            updateTen.innerHTML = "0" + tens;
        }

        if (tens > 9) {
            updateTen.innerHTML = tens;
        }

        if (tens > 99) {
            console.log("seconds");
            seconds++;
            updateSec.innerHTML = "0" + seconds;
            tens = 0;
            updateTen.innerHTML = "0" + 0;
        }

        if (seconds > 9) {
            updateSec.innerHTML = seconds;
        }

        if (seconds > 59) {
            console.log("minutes");
            minutes++;
            updateMin.innerHTML = "0" + minutes;
            seconds = 0;
            updateSec.innerHTML = "0" + 0;
        }

        if (minutes > 9) {
            updateMin.innerHTML = minutes;
        }
    }
}