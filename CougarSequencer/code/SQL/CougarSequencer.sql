-- CougarSequencer ERD

DROP TABLE IF EXISTS songs CASCADE;
DROP TABLE IF EXISTS users CASCADE;

CREATE TABLE IF NOT EXISTS users (
    id INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    user_name TEXT NOT NULL,
    pass_word TEXT,
    salt TEXT,
    CONSTRAINT uq_users_user_name UNIQUE (user_name)
);

CREATE TABLE IF NOT EXISTS songs (
    id INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    user_id INT NOT NULL REFERENCES users(id),
    song_name TEXT NOT NULL,
    bpm INT NOT NULL,
    grid JSON NOT NULL
);


-- Sample Data


-- Users data
INSERT INTO users (user_name, pass_word, salt) VALUES
('guestUser',   'NoPassWord', 'sha'),
('CoolUser1',   'Secretpassword123', 'asd');

INSERT INTO songs (user_id, song_name, bpm, grid) VALUES
(2,
'Song 1',
60,
'{"grids": [
    {
        "Piano": [
            {
            "notes": [
                {
                {"C4": []},
                {"C#4": []},
                {"D4": []},
                {"D#4": []},
                {"E4": []},
                {"F4": []},
                {"F#4": []},
                {"G4": []},
                {"G#4": []},
                {"A4": []},
                {"A#4": []},
                {"B4": []},
                {"C5": []},
                {"C#5": []},
                {"D5": []},
                {"D#5": []},
                {"E5": []},
                {"F5": []},
                {"F#5": []},
                {"G5": []},
                {"G#5": []},
                {"A5": []},
                {"A#5": []},
                {"B5": []}
                }
                ]
            "volume": 50
            }
            ]
    },
    {
        "Bass": [
            {
            "notes": [
                {
                {"C4": []},
                {"C#4": []},
                {"D4": []},
                {"D#4": []},
                {"E4": []},
                {"F4": []},
                {"F#4": []},
                {"G4": []},
                {"G#4": []},
                {"A4": []},
                {"A#4": []},
                {"B4": []},
                {"C5": []},
                {"C#5": []},
                {"D5": []},
                {"D#5": []},
                {"E5": []},
                {"F5": []},
                {"F#5": []},
                {"G5": []},
                {"G#5": []},
                {"A5": []},
                {"A#5": []},
                {"B5": []}
                }
                ]
            "volume": 50
            }
            ]
    },
    {
        "Drums": [
            {
            "notes": [
                {
                {"Bass Drum": []},
                {"Snare": []},
                {"Floor Toms": []},
                {"Tom-Tom": []},
                {"Ride": []},
                {"Hi-Hat": []},
                {"Crash": []}
                }
                ]
            "volume": 50
            }
            ]
    }
]}');


SELECT * FROM users;
SELECT * FROM songs;

-- SELECT max(id) FROM users;
-- SELECT nextval(pg_get_serial_sequence('users', 'id'));
-- SELECT setval(pg_get_serial_sequence('users', 'id'), COALESCE(max(id), 1)) FROM users;
