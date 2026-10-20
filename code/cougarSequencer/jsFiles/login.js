    // POST
    document.getElementById('loginBtn').addEventListener('click', async () => {
      const username = document.getElementById('username').value;
      const password = document.getElementById('password').value;

      const response = await fetch('http://localhost:18080/api/login', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ username: username, password: password })
      });

      const data = await response.json();
      if (data.login === "success")
        window.location.href = "../htmlFiles/grid.html";
      else
        document.getElementById('loginOutput').innerText = data.login;
    });