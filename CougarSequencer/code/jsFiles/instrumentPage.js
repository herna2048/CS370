const proj = project.load();
const allGrid = proj.grid;

const pG = allGrid.Piano;
const pianoGrid = new Grid("Piano", pG);
pianoGrid.save("Piano");

const dG = allGrid.Drums;
const drumsGrid = new Grid("Drums", dG);
drumsGrid.save("Drums");

const bG = allGrid.Bass;
const bassGrid = new Grid("Bass", bG);
bassGrid.save("Bass");

const pianoProp = pianoGrid.instruProp;
const pN = pianoProp.notes;
const pV = pianoProp.volume;
const piano = new instrument(
    "Piano",
    pV, 
    ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B'],
    24, 
    24,
    {
    'C4': 'C4.mp3',
    'D#4': 'Ds4.mp3',
    'F#4': 'Fs4.mp3',
    'A4': 'A4.mp3',
    'C5': 'C5.mp3',
    'D#5': 'Ds5.mp3',
    'F#5': 'Fs5.mp3',
    'A5': 'A5.mp3'
    },
    pN
);
piano.save("Piano");

const bassProp = bassGrid.instruProp;
const bN = bassProp.notes;
const bV = bassProp.volume;
const bass = new instrument(
    "Bass",
    bV, 
    ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B'],
    24, 
    24,
    {
    'C4': 'C4.mp3',
    'D#4': 'Ds4.mp3',
    'F#4': 'Fs4.mp3',
    'A4': 'A4.mp3',
    'C5': 'C5.mp3',
    'D#5': 'Ds5.mp3',
    'F#5': 'Fs5.mp3',
    'A5': 'A5.mp3'
    },
    bN
);
bass.save("Bass");

const drumsProp = drumsGrid.instruProp;
const dN = drumsProp.notes;
const dV = drumsProp.volume;
const drums = new instrument(
    "Drums",
    pV, 
    ['Bass Drum', 'Snare', 'Floor Toms', 'Tom-Tom', 'Ride', 'Hi-Hat', 'Crash'],
    7, 
    24,
    {
    'Bass Drum': 'C4.mp3',
    'Snare': 'Ds4.mp3',
    'Floor Toms': 'Fs4.mp3',
    'Tom-Tom': 'A4.mp3',
    'Ride': 'C5.mp3',
    'Hi-Hat': 'Ds5.mp3',
    'Crash': 'Fs5.mp3',
    },
    pN
);
drums.save("Drums");