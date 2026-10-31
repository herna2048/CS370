    // POST function: send a request to the server.cpp 
    document.getElementById('loginBtn').addEventListener('click', async () => {
    // make the html values into valid js values
      const username = document.getElementById('username').value;
      const password = document.getElementById('password').value;

    // connect with the C++ specific function for the POST request and push in the specific parameters
      const response = await fetch('http://localhost:18080/api/login', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ username: username, password: password })
      });

      const data = await response.json();
    // if the user had inputs a valid username and password, they can move onto the grid.html, else they are sent the error message and try again
      if (data.login === "success")
        window.location.href = "../htmlFiles/accountPage.html";
      else
        document.getElementById('loginOutput').innerText = data.login;
    });
