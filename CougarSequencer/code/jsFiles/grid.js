const grid = document.getElementById('sequencerGrid');
const labelsColumn = document.getElementById('labelsColumn');
const playBtn = document.getElementById('playBtn');
const pauseBtn = document.getElementById('pauseBtn');
const volumeInput = document.getElementById('volume');
const bpmInput = document.getElementById('bpmNum');
grid.style.position = 'relative';

let isLoaded = false; // Flag to track if the piano sampler is loaded
let currentStep = 0; // Track the current step in the sequencer


grid.style.gridTemplateColumns = `repeat(${col}, minmax(0, 1fr))`;
grid.style. gridTemplateRows= `repeat(${row}, minmax(0, 1fr))`;
labelsColumn.style.setProperty('--col',row);

let generatedNotes=[];

for(let i=0; i<row; i++){
    const noteIndex=i%12;
    const octaveOffset=Math.floor(i/12);
    const currentOctave= 4+ octaveOffset;
    generatedNotes.push(`${scaleNotes[noteIndex]}${currentOctave}`);
}

generatedNotes.reverse(); /*so that the highest note is at the top*/

generatedNotes.forEach(noteName=> {
    const labelNode=document.createElement('div');
    labelNode.textContent=noteName;
    labelsColumn.appendChild(labelNode);
});

/*This is a 24 x 24 matrix grid that will store references*/
const columns=Array.from({length:col }, () => []); 

for(let r = 0; r < row; r++) {
    for(let c = 0; c < col; c++) {
        const cell= document.createElement('div');
        cell.classList.add("cell");
        cell.dataset.row = r;
        cell.dataset.col = c;
        cell.dataset.note = generatedNotes[r]; // Assign the note to the cell's dataset

        cell.addEventListener('click',async () => {
             await Tone.start(); // Ensure Tone.js is started before playing sound
             cell.classList.toggle('active');

             if (cell.classList.contains('active') && isLoaded) {
                piano.triggerAttackRelease(generatedNotes[r], '8n');// Play the note when the cell is activated
             }
     });

        cell.style.gridRow = `${r+1}`;
        cell.style.gridColumn = `${c+1}`;
        grid.appendChild(cell);    
        columns[c].push(cell); // Store the cell reference in the corresponding column   
    }   
}

//initialize the Tone.js piano sampler
const piano = new Tone.Sampler({
    urls: {
        'C4': 'C4.mp3',
        'D#4': 'Ds4.mp3',
        'F#4': 'Fs4.mp3',
        'A4': 'A4.mp3',
        'C5': 'C5.mp3',
        'D#5': 'Ds5.mp3',
        'F#5': 'Fs5.mp3',
        'A5': 'A5.mp3'
    },
    release:1.2, // Adjust the release time for a more natural sound
    baseUrl: 'https://tonejs.' + 'github.io/audio/salamander/',
    onload: () => {
        isLoaded = true; // Set the flag to true when the sampler is loaded
        console.log('Piano loaded successfully');
    }
}).toDestination();

//volume slider mapping
function UpdateVolume() {
    const val=Number(volumeInput.value);
    if(val==0){
        piano.volume.value=-Infinity; // Mute the piano
    } else {
        piano.volume.value=Tone.gainToDb(val/100); // Convert gain to decibels
    }
}
volumeInput.addEventListener('input', UpdateVolume);
UpdateVolume(); // Initialize volume on page load

//BPM Mapping
Tone.getTransport().bpm.value = 60; // Set the initial BPM to 60

bpmInput.addEventListener('keydown', (event) => {
    if(event.key == 'Enter')
    {
        const bpmValue = parseInt(bpmInput.value,10);

        if (!isNaN(bpmValue) && bpmValue >= 20 && bpmValue <= 300) {
            Tone.getTransport().bpm.value = bpmValue;
            Tone.getTransport().stop(); // Stop the transport to apply the new BPM
            currentStep = 0; // Reset the current step to 0
    }
}
});


const loop =new Tone.Loop((time) => {

    const step= currentStep;
    const activeNotes=[];

    columns[step].forEach(cell => {
        if (cell.classList.contains('active')) { // Check if the cell is active
            activeNotes.push(cell.dataset.note); // Use the note from the cell's dataset
        }
    });

    if (activeNotes.length > 0 && isLoaded) {
        piano.triggerAttackRelease(activeNotes, '8n', time); // Play all active notes at the current step
    }

    currentStep = (currentStep + 1) % col; // Move to the next step, wrapping around
}, '4n'); // Set the loop interval to an eighth note

loop.start(0); // Start the loop at the beginning of the transport
//pause and play buttons
playBtn.addEventListener('click',async () => {
    await Tone.start(); // Ensure Tone.js is started before playing sound
    if (!isLoaded) {
        console.log('Piano is still loading. Please wait...');
        return;
    }
    if(loc==col || currentStep>=col){
        currentStep=0; // Reset the current step to 0 if it has reached the end
    }

    Tone.getTransport().start();
    
});

pauseBtn.addEventListener('click', () => {
    Tone.getTransport().pause();// Pause the transport
});