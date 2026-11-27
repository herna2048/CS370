//initialize the Tone.js piano sampler
const instruSample = new Tone.Sampler({
    urls: instru.sample,
    release:1.2, // Adjust the release time for a more natural sound
    baseUrl: 'https://tonejs.' + 'github.io/audio/salamander/',
    onload: () => {
        isLoaded = true; // Set the flag to true when the sampler is loaded
        console.log(`${instru.instruName} loaded successfully`);
    }
}).toDestination();

//volume slider mapping
function UpdateVolume() {
    const val=Number(instru.volume);
    if(val==0){
        instruSample.volume.value=-Infinity; // Mute the piano
    } else {
        instruSample.volume.value=Tone.gainToDb(val/100); // Convert gain to decibels
    }
}
volumeInput.addEventListener('input', UpdateVolume);
UpdateVolume(); // Initialize volume on page load

//BPM Mapping
Tone.getTransport().bpm.value = proj.bpm; // Set the initial BPM to the saved bpm

const loop = new Tone.Loop((time) => {

    const step= currentStep;
    const activeNotes=[];

    columns[step].forEach(cell => {
        if (cell.classList.contains('active')) { // Check if the cell is active
            activeNotes.push(cell.dataset.note); // Use the note from the cell's dataset
        }
    });

    if (activeNotes.length > 0 && isLoaded) {
        instruSample.triggerAttackRelease(activeNotes, '8n', time); // Play all active notes at the current step
    }

    currentStep = (currentStep + 1) % col; // Move to the next step, wrapping around
}, '4n'); // Set the loop interval to quarter note