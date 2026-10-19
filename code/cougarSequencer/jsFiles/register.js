    // POST
    document.getElementById('registerBtn').addEventListener('click', async () => {
      const username = document.getElementById('username').value;
      const password = document.getElementById('password').value;

      const response = await fetch('http://localhost:18080/api/register', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ username: username, password: password })
      });

      const data = await response.json();
      document.getElementById('registerOutput').innerText = data.greeting;
    });