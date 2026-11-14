    // POST function: send a request to the server.cpp 
    document.getElementById('temp parameter').addEventListener('click', async () => {
    // make the html values into valid js values
      const temp_parameter = document.getElementById('temp parameter').value;

    // connect with the C++ specific function for the POST request and push in the specific parameters
      const response = await fetch('http://localhost:18080/api/saveProject', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ /*temp parameters*/  })
      });

      const data = await response.json();
    // if the project can save, they can move onto the grid.html, else they are sent the error message and try again
      if (data.saveProject === "success")
        window.location.href = "../htmlFiles/grid.html";
      else
        document.getElementById('temp parameter').innerText = data.saveProject;
    });
