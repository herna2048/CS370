// POST function: send a request to the server.cpp 
document.getElementById('selectSong').addEventListener('click', async () => {
// make the html values into valid js values
  const song_name = document.getElementById('song_name').innerText;

// connect with the C++ specific function for the POST request and push in the specific parameters
  const response = await fetch('http://localhost:18080/api/openProject', {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ song_name: song_name })
  });

  const data = await response.json();
// if the project can open, they can move onto the grid.html, else they are sent the error message and try again
  if (data.openProject === "success") {
    const proj = new project(data.bmp, data.grids);
    window.location.href = "accountCreateSong.html";
  }
  else
    document.getElementById('response').innerText = data.openProject;
});
