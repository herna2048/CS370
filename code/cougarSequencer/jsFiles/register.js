     // POST
    document.getElementById('registertBtn').addEventListener('click', async () => {
      const username = document.getElementById('username').value;
      const password = document.getElementById('password').value;

      const response = await fetch('http://localhost:18080/api/register', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ username: username, password: password })
      });

      const data = await response.json();
      if (data.register === "success")
        window.location.href = "../htmlFiles/grid.html";
      else
        document.getElementById('registerOutput').innerText = data.register;
    });