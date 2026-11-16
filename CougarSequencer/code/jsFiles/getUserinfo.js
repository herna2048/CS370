const params = JSON.parse(sessionStorage.getItem("params"));

const id = params.id;
const username = params.username;

document.getElementById("userGreeting").innerText = `Welcome ${username}!\nFeel free to make as much music as you want!`;