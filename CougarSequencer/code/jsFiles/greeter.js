// GET function: request to the server.cpp to read and write over the specific saved message in greeter.cpp
document.getElementById('greeterBtn').addEventListener('click', async () => {
    // connect with the get function
    const response = await fetch('http://localhost:18080/api/greeter');
    const data = await response.json();
    document.getElementById('greeterOutput').innerText = data.greeter; // send over the message to HTML
});
