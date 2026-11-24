class instrument {
    bpm = 60;

    constructor(b = 60) {
        this.bpm = b;
        this.instruName = "instrument";
        this.row = 24; 
        this.col = 24;
        this.scaleNotes=['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B'];
    }

    save() {
        sessionStorage.setItem('instrument', JSON.stringify({bpm: this.bpm}));
    }

    static load() {
        const i = JSON.parse(sessionStorage.getItem("instrument"));

        if(i == null)
            i.bpm = 60;

        return new instrument(i.bpm);
    }

    set bpm(b) {
        this.bpm = b;
    }

    get bpm() {
        return `${this.bpm}`;
    }    

    static clear() {
        sessionStorage.removeItem('instrument');
    }
}

class piano extends instrument {
    constructor() {
        super(instruName);
        super(row);
        super(col);
        super(scaleNotes);
        this.name = "Piano";
    }
}

class drums extends instrument {
    constructor() {
        super(instruName);
        super(row);
        super(col);
        super(scaleNotes);
        this.name = "Drums";
        this.row = 7;
        this.scaleNotes=['Bass Drum', 'Snare', 'Floor Toms', 'Tom-Tom', 'Ride', 'Hi-Hat', 'Crash'];
    }
}

class bass extends instrument {
    constructor() {
        super(instruName);
        super(row);
        super(col);
        super(scaleNotes);
        this.name = "Bass";
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
