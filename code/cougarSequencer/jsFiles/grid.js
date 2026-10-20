const grid = document.getElementById('sequencerGrid');
    const totalCells=24*24;

    for(let i = 0; i < totalCells; i++) {
        const cell = document.createElement('div');
        cell.classList.add("cell");

        cell.addEventListener('click', () => {
            cell.classList.toggle('active');
        });

        grid.appendChild(cell);

}
