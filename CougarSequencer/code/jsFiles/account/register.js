     // POST function, send a request to the server.cpp 
    document.getElementById('registertBtn').addEventListener('click', async () => {
     // make the html values into valid js values
      const username = document.getElementById('username').value; 
      const password = document.getElementById('password').value;
      const id = 0;
      

     // connect with the C++ specific function for the POST request and push in the specific parameters
      const response = await fetch('http://localhost:18080/api/register', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ username: username, password: password, id: id})
      });
     
      const data = await response.json();
     // if the user had created a valid user, they can move onto the grid.html, else they are sent the error message and try again
      if (data.register === "success"){
        const u = new user(id, username);
        u.save();
        window.location.replace("../../htmlFiles/account/songManager.html");
      }
      else
        document.getElementById('registerOutput').innerText = data.register;
    });
