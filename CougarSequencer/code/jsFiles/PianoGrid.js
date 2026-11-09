const pianoGrid=document.getElementById('sequencerGrid');
    const labelsColumn = document.getElementById('labelsColumn');
    const totalCells=24*24;
    const scaleNotes=['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B'];
    let generatedNotes=[];

    for(let i=0; i<24; i++){
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

    for(let i=0; i < totalCells; i++) {
        const cell= document.createElement('div');
        cell.classList.add("cell");

        cell.addEventListener('click', () => {
            cell.classList.toggle('active');
        });

        pianoGrid.appendChild(cell);
    }