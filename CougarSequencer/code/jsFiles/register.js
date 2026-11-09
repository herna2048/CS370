     // POST function, send a request to the server.cpp 
    document.getElementById('registertBtn').addEventListener('click', async () => {
     // make the html values into valid js values
      const username = document.getElementById('username').value; 
      const password = document.getElementById('password').value;

     // connect with the C++ specific function for the POST request and push in the specific parameters
      const response = await fetch('http://localhost:18080/api/register', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ username: username, password: password }) 
      });
     
      const data = await response.json();
     // if the user had created a valid user, they can move onto the grid.html, else they are sent the error message and try again
      if (data.register === "success")
        window.location.href = "../htmlFiles/accountPage.html";
      else
        document.getElementById('registerOutput').innerText = data.register;
    });
