    // POST function, send a request to the server.cpp 
    document.getElementById('backBtn').addEventListener('click', async () => {
     // make the html values into valid js values
      const username = "guestUser"; 
      const id = 0;
      
     // connect with the C++ specific function for the POST request and push in the specific parameters
      const response = await fetch('http://localhost:18080/api/logOut', {
        method: 'PUT',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ username: username, id: id})
      });

      const data = await response.json();

       window.location.replace("../../htmlFiles/homePage.html");
    });
