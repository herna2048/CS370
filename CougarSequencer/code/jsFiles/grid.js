const grid = document.getElementById('sequencerGrid');
const labelsColumn = document.getElementById('labelsColumn');
grid.style = `grid-template-columns: repeat(${col}, minmax(0, 1fr))`;
grid.style = `grid-template-rows: repeat(${row}, minmax(0, 1fr)`;
const totalCells= row * col;
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

for(let r = 0; r < row; r++) {
    for(let c = 0; c < col; c++) {
        const cell= document.createElement('div');
        cell.classList.add("cell");

        cell.addEventListener('click', () => {
            cell.classList.toggle('active');
        });

        cell.style.gridRow = `${r+1}`;
        cell.style.gridColumn = `${c+1}`;

        grid.appendChild(cell);       
    }   
}