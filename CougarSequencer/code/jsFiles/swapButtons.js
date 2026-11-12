document.getElementById('playBtn').addEventListener('click', () => {
    document.getElementById('playBtn').style.display="none";
    document.getElementById('pauseBtn').style.display="inline-block";
});

document.getElementById('pauseBtn').addEventListener('click', () => {
    document.getElementById('pauseBtn').style.display="none";
    document.getElementById('playBtn').style.display="inline-block";
});