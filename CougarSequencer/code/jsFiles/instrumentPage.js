const pianoProp = pianoGrid.instruProp;
const pN = pianoProp.notes;
const pV = pianoProp.volume;
const piano = new instrument(
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
const bassProp = bassGrid.instruProp;
const bN = bassProp.notes;
const bV = bassProp.volume;
const bass = new instrument(
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
const drumsProp = pianoGrid.instruProp;
const dN = drumsProp.notes;
const dV = drumsProp.volume;
const drums = new instrument(
    pV, 
    ['Bass Drum', 'Snare', 'Floor Toms', 'Tom-Tom', 'Ride', 'Hi-Hat', 'Crash'],
    7, 
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