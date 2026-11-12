const display = document.getElementById("display"); // get the display
const tempoMeter = document.getElementById("tempoMeter"); // get the tempo meter
let bpmNum = 0;

document.getElementById('bpmBtn').addEventListener('click', () => {
    bpmNum = document.getElementById("bpmNum").value; // get the bpm
    if (bpmNum < 0) bpmNum = 0;
    document.getElementById('bpmNum').placeholder = `bmp = ${bpmNum}`;
    bpm /= 60;
});

let timer = null;
let startTime = 0;
let elapsedTime = 0;
let running = false;

document.getElementById('playBtn').addEventListener('click', () => {    
    if(!running){
        startTime = Date.now() - elapsedTime;
        timer = setInterval(update, 10);
        running = true;
    }
});

document.getElementById('pauseBtn').addEventListener('click', () => {
    if(running){
        clearInterval(timer);
        elapsedTime = Date.now() - startTime;
        running = false;
    }
});

function reset(){
    clearInterval(timer);
    startTime = 0;
    elapsedTime = 0;
    running = false;
    display.textContent = "00:00";
    }

function update(){

    const currentTime = Date.now();
    elapsedTime = currentTime - startTime;

    let minutes = Math.floor(elapsedTime / (1000 * 60) % 60);
    let seconds = Math.floor(elapsedTime / 1000 % 60);

    if(bpmNum > 0){
        tempoMeter.style.transform = `translate(${seconds}px)`;
    }

    minutes = String(minutes).padStart(2, "0");
    seconds = String(seconds).padStart(2, "0");
    
    display.textContent = `${minutes}:${seconds}`;
}