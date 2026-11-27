const grid = document.getElementById('sequencerGrid');
const labelsColumn = document.getElementById('labelsColumn');
const playBtn = document.getElementById('playBtn');
const pauseBtn = document.getElementById('pauseBtn');
const volumeInput = document.getElementById('volume');
const bpmInput = document.getElementById('bpmNum');

const instru = instrument.load(document.getElementById("sequencer-title").innerText);
const col = instru.col;
const row = instru.row;
const scaleNotes = instru.scaleNotes;

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
                instruSample.triggerAttackRelease(generatedNotes[r], '8n');// Play the note when the cell is activated
             }
     });

        cell.style.gridRow = `${r+1}`;
        cell.style.gridColumn = `${c+1}`;
        grid.appendChild(cell);    
        columns[c].push(cell); // Store the cell reference in the corresponding column   
    }   
}