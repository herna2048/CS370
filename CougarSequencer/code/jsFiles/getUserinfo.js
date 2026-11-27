class project {
    bpm = 60;
    grid = [];

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
    
    set grid(g) {
        this.grid = g;
    }

    get grid() {
        return `${this.grid}`
    }

    static clear() {
        sessionStorage.removeItem('project');
    }
}

class Grid {
    instruName = "instrument";
    instruProp = [];

    constructor(sN, json) {
        this.instruName = "instrument";
        this.instruProp = typeof json === "string" ? JSON.parse(json) : json;
    }

    save(name) {
        sessionStorage.setItem(`${name}Grid`, JSON.stringify({instruName: this.instruName, instruProp: this.instruProp}));
    }

    static load(name) {
        const g = JSON.parse(sessionStorage.getItem(`${name}Grid`));

        if(g == null) {   
            return new Grid("instrument", []);
        }

        return new Grid(p.instruName, p.notes);
    }

    set instruProp(i) {
        this.instruProp = i;
    }

    get instruProp() {
        return this.instruProp;
    }

    static clear(name) {
        sessionStorage.removeItem(`${name}Grid`);
    }
}

class instrument {

    constructor(iN, v, sN, r, c, s, json) {
        this.instruName = iN;
        this.volume = v;
        this.scaleNotes = sN;
        this.row = r;
        this.col = c;
        this.sample = s;
        this.notes = typeof json === "string" ? JSON.parse(json) : json;
    }

    save(name) {
        sessionStorage.setItem(`${name}`, JSON.stringify({
            volume: this.volume,
            scaleNotes: this.scaleNotes,
            row: this.row,
            col: this.col,
            sample: this.sample,
            notes: this.notes
        }));
    }

    static load(name) {
        const i = JSON.parse(sessionStorage.getItem(`${name}`));

        if(i == null)
            return new instrument("instrument", 50, [], 0, 0, {}, []);
    
        return new instrument(
            i.instruName,
            i.volume,
            i.scaleNotes,
            i.row,
            i.col,
            i.sample,
            i.notes);
    }  

    static clear(name) {
        sessionStorage.removeItem(`${name}`);
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
