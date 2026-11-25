class project {
    bpm = 60;

    constructor(b = 60, json) {
        this.bpm = b;
        this.grid = typeof json === "string" ? JSON.parse(json) : json;
    }

    save() {
        sessionStorage.setItem('project', JSON.stringify({bpm: this.bpm, grid: this.grid}));
    }

    static load() {
        const p = JSON.parse(sessionStorage.getItem("project"));

        if(p == null) {   
            return new project(60, []);
        }

        return new project(p.bpm, p.grid);
    }

    set bpm(b) {
        this.bpm = b;
    }

    get bpm() {
        return `${this.bpm}`;
    }    

    static clear() {
        sessionStorage.removeItem('project');
    }
}

class Grid {
    constructor(sN, json) {
        this.instruName = "instrument";
        this.notes = typeof json === "string" ? JSON.parse(json) : json;
    }

    save() {
        sessionStorage.setItem('grid', JSON.stringify({instruName: this.instruName, notes: this.notes}));
    }

    static load() {
        const g = JSON.parse(sessionStorage.getItem("grid"));

        if(g == null) {   
            return new Grid("instrument", []);
        }

        return new project(p.instruName, p.notes);
    }

    static clear() {
        sessionStorage.removeItem('grid');
    }
}

class instrument {
    constructor() {
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


// class piano extends instrument {
//     constructor() {
//         super(instruName);
//         super(row);
//         super(col);
//         super(scaleNotes);
//         this.name = "Piano";
//     }
// }

// class drums extends instrument {
//     constructor() {
//         super(instruName);
//         super(row);
//         super(col);
//         super(scaleNotes);
//         this.name = "Drums";
//         this.row = 7;
//         this.scaleNotes=['Bass Drum', 'Snare', 'Floor Toms', 'Tom-Tom', 'Ride', 'Hi-Hat', 'Crash'];
//     }
// }

// class bass extends instrument {
//     constructor() {
//         super(instruName);
//         super(row);
//         super(col);
//         super(scaleNotes);
//         this.name = "Bass";
//     }
// }

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

        if(u == null) {
            u.id = 1;
            u.username = "guestUser";
        }

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
