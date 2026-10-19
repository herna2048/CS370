    async function message() {
        // Part 1: GET
        document.getElementById('greeterBtn').addEventListener('click', async () => {
        const response = await fetch('http://localhost:18080/api/greeter');
        const data = await response.json();
        document.getElementById('greeterOutput').innerText = data.message;
        });
    }