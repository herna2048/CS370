-- 6.2 Logical Database Requirements

-- Specify the logical requirements for any information that is to be placed into a 
-- database, including data entities and their relationships, and Integrity constraints.  

-- If the customer provided you with data models, those can be presented here.  
-- ER diagrams (or static class diagrams) can be useful here to show entity 
-- relationships.  Remember a diagram is worth a thousand words of confusing text. 

DROP TABLE IF EXISTS songs CASCADE;
DROP TABLE IF EXISTS users CASCADE;

CREATE TABLE users (
    id INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    user_name TEXT NOT NULL,
    pass_word TEXT NOT NULL,
    CONSTRAINT uq_users_user_name UNIQUE (user_name)
);

CREATE TABLE songs (
    id INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    user_id INT NOT NULL REFERENCES users(id),
    song_name TEXT NOT NULL,
    track JSON NOT NULL
);


-- Sample Data


-- Users data
INSERT INTO users (user_name, pass_word) VALUES
('CoolUser1',   'Secretpassword123'),
('AwesomePerson',   'Musicrules222'),
('AnnoyedMuscian',    'Ilovethepiano2321')
ON CONFLICT (username) DO NOTHING;

INSERT INTO songs (user_id, song_name, track) VALUES
(1,
'My first song',
'{"tracks": [
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