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
        "instrument": "Piano",
        "notes": [
            {"pitch": "C4", "start": 1, "duration": 2},
            {"pitch": "E4", "start": 3, "duration": 1}
        ]
    },
    {
        "instrument": "Bass",
        "notes": [
            {"pitch": "D4", "start": 1, "duration": 4},
            {"pitch": "F4", "start": 5, "duration": 3}
        ]
    }
]}');


SELECT * FROM users;
SELECT * FROM songs;

-- SELECT max(id) FROM users;
-- SELECT nextval(pg_get_serial_sequence('users', 'id'));
-- SELECT setval(pg_get_serial_sequence('users', 'id'), COALESCE(max(id), 1)) FROM users;
