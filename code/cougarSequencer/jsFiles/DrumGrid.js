for(let i=0; i<7; i++){
   const noteIndex=i%12;
   const octaveOffset=Math.floor(i/12);
   generatedNotes.push(`${scaleNotes[noteIndex]}`);
 }

 generatedNotes.reverse(); /*so that the highest note is at the top*/

 generatedNotes.forEach(noteName=> {
   const labelNode=document.createElement('div');
   labelNode.textContent=noteName;
   labelsColumn.appendChild(labelNode);
 });


for(let i=0; i < totalCells; i++ ) {
   const cell= document.createElement('div');
   cell.classList.add("cell");

   cell.addEventListener('click', () => {
       cell.classList.toggle('active');
   });

   grid.appendChild(cell);
}
