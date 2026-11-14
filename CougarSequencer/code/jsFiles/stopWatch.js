const tempoMeter = document.getElementById("tempoMeter"); // get the tempo meter
let bpm = 60, mspb = 1000, loc = 1;

const display = document.getElementById("display"); // get the display
let updateTimer = null, updateTempoMeter = null;
let startTime = 0, elapsedTime = 0, seconds = 0, minutes = 0;
let running = false;

document.getElementById('bpmBtn').addEventListener('click', () => {
    if (document.getElementById("bpmNum").value <= 0 || document.getElementById("bpmNum").value > 500) document.getElementById("bpmNum").value = bpm; // the bpm is less than or equal to 0

    // set bpmNum to either what it was originally or the new valid bpmNum
    bpm = document.getElementById("bpmNum").value;
    document.getElementById('bpmNum').placeholder = `bmp = ${bpm}`;
    mspb = (1 / (bpm / 60)) * 1000; // bpm / 60 is beatsPerSec, 1 / bps is secsPerBeat, 1000 * spb is millisecondsPerBeat

    // make the timer go back to zero every time the tempo is changed
    reset();
});

document.getElementById('playBtn').addEventListener('click', () => {   
    if(parseInt(seconds) >= (col - 1) || loc == col)
        reset();

    if(!running){
        // increment the time and update it
        startTime = Date.now() - elapsedTime;
        updateTimer = setInterval(updateTime, 10);
        updateTempoMeter = setInterval(updateTempo, mspb);

        // swap
        document.getElementById('playBtn').style.display="none";
        document.getElementById('pauseBtn').style.display="inline-block";

        running = true;
    }
});

document.getElementById('pauseBtn').addEventListener('click', () => {
    pause();
});

function pause(){
    if(running){
        // stop the time
        clearInterval(updateTimer);
        clearInterval(updateTempoMeter);
        elapsedTime = Date.now() - startTime;

        // swap
        document.getElementById('pauseBtn').style.display="none";
        document.getElementById('playBtn').style.display="inline-block";

        running = false;
    }
}

function reset(){
    // clear the timer and set everything back to zero
    clearInterval(updateTimer);
    clearInterval(updateTempoMeter);
    loc = 1, startTime = 0, elapsedTime = 0, seconds = 0, minutes = 0;
    running = false;
    display.textContent = "00:00";
    tempoMeter.style = "grid-column: 1";
    // swap
    document.getElementById('pauseBtn').style.display="none"; 
    document.getElementById('playBtn').style.display="inline-block";
    }
    
function updateTime(){
    // set paramters
    if(parseInt(seconds) < col - 1){
        // update the current time and subtract it from the start time to get the new difference
        const currentTime = Date.now();
        elapsedTime = currentTime - startTime;

        // update the minutes and seconds from the newly updated elapsedtime
        minutes = Math.floor(elapsedTime / (1000 * 60) % 60);
        seconds = Math.floor(elapsedTime / 1000 % 60);

        minutes = String(minutes).padStart(2, "0");
        seconds = String(seconds).padStart(2, "0");
        
        display.textContent = `${minutes}:${seconds}`;
    }
    else{
         // update the current time and subtract it from the start time to get the new difference
        const currentTime = Date.now();
        elapsedTime = currentTime - startTime;

        // update the minutes and seconds from the newly updated elapsedtime
        minutes = Math.floor(elapsedTime / (1000 * 60) % 60);
        seconds = Math.floor(elapsedTime / 1000 % 60) + 1;

        minutes = String(minutes).padStart(2, "0");
        seconds = String(seconds).padStart(2, "0");
        
        display.textContent = `${minutes}:${seconds}`;
        
        pause();
    }
}

function updateTempo(){
    if(loc < col){
        loc++;
        tempoMeter.style.gridColumn = `${loc}`;
    }
    else{
        tempoMeter.style.justifySelf = `end`;
        loc = col;
        pause();
    }
}