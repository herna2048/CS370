const tempoMeter = document.getElementById("tempoMeter"); // get the tempo meter
let bpm, bps = 0;
const width = pianoGrid.style.width;

const display = document.getElementById("display"); // get the display
let timer = null;
let startTime = 0;
let elapsedTime = 0;
let running = false;

document.getElementById('bpmBtn').addEventListener('click', () => {
    if (document.getElementById("bpmNum").value <= 0) document.getElementById("bpmNum").value = bpm; // the bpm is less than or equal to 0

    // set bpmNum to either what it was originally or the new valid bpmNum
    bpm = document.getElementById("bpmNum").value;
    document.getElementById('bpmNum').placeholder = `bmp = ${bpm}`;
    bps = bpm / 60; // bpm / 60 is beatPerSec

    // make the timer go back to zero every time the tempo is changed
    reset();
});

document.getElementById('playBtn').addEventListener('click', () => {    
    if(!running && bpm > 0){
        // increment the time and update it
        startTime = Date.now() - elapsedTime;
        timer = setInterval(update, 1000);

        // swap
        document.getElementById('playBtn').style.display="none";
        document.getElementById('pauseBtn').style.display="inline-block";

        running = true;
    }
});

document.getElementById('pauseBtn').addEventListener('click', () => {
    if(running){
        // stop the time
        clearInterval(timer);
        elapsedTime = Date.now() - startTime;

        // swap
        document.getElementById('pauseBtn').style.display="none";
        document.getElementById('playBtn').style.display="inline-block";

        running = false;
    }
});

function reset(){
    // clear the timer and set everything back to zero
    clearInterval(timer);
    startTime = 0;
    elapsedTime = 0;
    running = false;
    display.textContent = "00:00";
    
    tempoMeter.style = "grid-column: 3 / 4"

    // swap
    document.getElementById('pauseBtn').style.display="none"; 
    document.getElementById('playBtn').style.display="inline-block";
    }

function update(){
    // update the current time and subtract it from the start time to get the new difference
    const currentTime = Date.now();
    elapsedTime = currentTime - startTime;

    // update the minutes and seconds from the newly updated elapsedtime
    let minutes = Math.floor(elapsedTime / (1000 * 60) % 60);
    let seconds = Math.floor(elapsedTime / 1000 % 60);
    let msPerBeat = seconds / bps; 

    // tempoMeter.style = `grid-column: ${seconds} / ${seconds + 1}`;

    tempoMeter.style.transform = `translate(${seconds * width}px)`;

    minutes = String(minutes).padStart(2, "0");
    seconds = String(seconds).padStart(2, "0");
    
    display.textContent = `${minutes}:${seconds}`;
}
