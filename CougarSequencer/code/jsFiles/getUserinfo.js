class instrument {
    bpm 60;

    constructor(b) {
    this.bpm = b;
    }

    save() {
        sessionStorage.setItem('instrument', JSON.stringify({bpm: this.bpm}));
    }

    static load() {
        const i = JSON.parse(sessionStorage.getItem("instrument"));

        return new user(i.bpm);
    }

    set bpm(b) {
        // this.bpm = b;
    }

    get bpm() {
        return `${this.bpm}`;
    }    

    static clear() {
        sessionStorage.removeItem('instrument');
    }
}

class user {
    #id = 1;
    #username = "guestUser";

    constructor(id, username) {
        this.#id = id;
        this.#username = username;
    }

    greet() {
        return `Welcome ${this.#username}!\nFeel free to make as much music as you want!`;
    }

    save() {
        sessionStorage.setItem("user", JSON.stringify({id: this.#id, username: this.#username}));
    }

    static load() {
        const u = JSON.parse(sessionStorage.getItem("user"));

        return new user(u.id, u.username);
    }

    get id() {
        return `${this.#id}`;
    }

    get username() {
        return `${this.#username}`;
    }

    static clear() {
        sessionStorage.removeItem('user');
    }
}
