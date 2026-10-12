-- 6.2 Logical Database Requirements

-- Specify the logical requirements for any information that is to be placed into a 
-- database, including data entities and their relationships, and Integrity constraints.  

-- If the customer provided you with data models, those can be presented here.  
-- ER diagrams (or static class diagrams) can be useful here to show entity 
-- relationships.  Remember a diagram is worth a thousand words of confusing text. 

DROP TABLE IF EXISTS users;
DROP TABLE IF EXISTS instrument;
DROP TABLE IF EXISTS note;
DROP TABLE IF EXISTS grid;
DROP TABLE IF EXISTS song;
DROP TABLE IF EXISTS project;

-- Users
CREATE TABLE users (
	id         INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	username   TEXT NOT NULL,
	password   TEXT NOT NULL,  
	CONSTRAINT uq_users_email UNIQUE (username)
	);

-- Instrument
CREATE TABLE instrument (
	id     INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	name   TEXT NOT NULL
);

-- Note (This is the row of the grid)
CREATE TABLE note (
	id            INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	key           TEXT NOT NULL,
	dynamics      TEXT NOT NULL
);

-- Grid
CREATE TABLE grid (
	id            INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	note_id       INT NOT NULL,
	location_id   INT NOT NULL, -- this is the column in the grid
	CONSTRAINT    uq_grid_note_id UNIQUE (note_id)
);

-- Song
CREATE TABLE song (
	id            INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	grid_id       INT NOT NULL,
	instrument_id INT NOT NULL,
	CONSTRAINT    uq_project_grid_id UNIQUE (grid_id),
	CONSTRAINT    uq_project_instrument_id UNIQUE (instrument_id)
);

-- Project
CREATE TABLE project (
	id         INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	users_id   INT NOT NULL,
	song_id    INT NOT NULL,
	name       TEXT NOT NULL,
	CONSTRAINT uq_project_users_id_song_id UNIQUE (users_id, song_id)
);

	
-- Sample Data


-- Users data
INSERT INTO users (username, password) VALUES
('CoolUser1',   'Secretpassword123'),
('AwesomePerson',   'Musicrules222'),
('AnnoyedMuscian',    'Ilovethepiano2321');

-- Instruments data
INSERT INTO instrument (name) VALUES
('Piano'),
('Synthesizer'),
('Drum'),
('Bass');

-- Note data
INSERT INTO note (key, dynamics) VALUES
-- # Pitch A
('A', 'Pianissimo'),
('A', 'Piano'),
('A', 'Mezzo-piano'),
('A', 'Mezzo-forte'),
('A', 'Forte'),
('A', 'Fortissimo'),
('A#', 'Pianissimo'),
('A#', 'Piano'),
('A#', 'Mezzo-piano'),
('A#', 'Mezzo-forte'),
('A#', 'Forte'),
('A#', 'Fortissimo'),
('Ab', 'Pianissimo'),
('Ab', 'Piano'),
('Ab', 'Mezzo-piano'),
('Ab', 'Mezzo-forte'),
('Ab', 'Forte'),
('Ab', 'Fortissimo'),

-- # Pitch B
('B', 'Pianissimo'),
('B', 'Piano'),
('B', 'Mezzo-piano'),
('B', 'Mezzo-forte'),
('B', 'Forte'),
('B', 'Fortissimo'),
('Bb', 'Pianissimo'),
('Bb', 'Piano'),
('Bb', 'Mezzo-piano'),
('Bb', 'Mezzo-forte'),
('Bb', 'Forte'),
('Bb', 'Fortissimo'),

-- # Pitch C
('C', 'Pianissimo'),
('C', 'Piano'),
('C', 'Mezzo-piano'),
('C', 'Mezzo-forte'),
('C', 'Forte'),
('C', 'Fortissimo'),
('C#', 'Pianissimo'),
('C#', 'Piano'),
('C#', 'Mezzo-piano'),
('C#', 'Mezzo-forte'),
('C#', 'Forte'),
('C#', 'Fortissimo'),

-- # Pitch D
('D', 'Pianissimo'),
('D', 'Piano'),
('D', 'Mezzo-piano'),
('D', 'Mezzo-forte'),
('D', 'Forte'),
('D', 'Fortissimo'),
('D#', 'Pianissimo'),
('D#', 'Piano'),
('D#', 'Mezzo-piano'),
('D#', 'Mezzo-forte'),
('D#', 'Forte'),
('D#', 'Fortissimo'),
('Db', 'Pianissimo'),
('Db', 'Piano'),
('Db', 'Mezzo-piano'),
('Db', 'Mezzo-forte'),
('Db', 'Forte'),
('Db', 'Fortissimo'),

-- # Pitch E
('E', 'Pianissimo'),
('E', 'Piano'),
('E', 'Mezzo-piano'),
('E', 'Mezzo-forte'),
('E', 'Forte'),
('E', 'Fortissimo'),
('Eb', 'Pianissimo'),
('Eb', 'Piano'),
('Eb', 'Mezzo-piano'),
('Eb', 'Mezzo-forte'),
('Eb', 'Forte'),
('Eb', 'Fortissimo'),

-- # Pitch F
('F', 'Pianissimo'),
('F', 'Piano'),
('F', 'Mezzo-piano'),
('F', 'Mezzo-forte'),
('F', 'Forte'),
('F', 'Fortissimo'),
('F#', 'Pianissimo'),
('F#', 'Piano'),
('F#', 'Mezzo-piano'),
('F#', 'Mezzo-forte'),
('F#', 'Forte'),
('F#', 'Fortissimo'),

-- # Pitch G
('G', 'Pianissimo'),
('G', 'Piano'),
('G', 'Mezzo-piano'),
('G', 'Mezzo-forte'),
('G', 'Forte'),
('G', 'Fortissimo'),
('G#', 'Pianissimo'),
('G#', 'Piano'),
('G#', 'Mezzo-piano'),
('G#', 'Mezzo-forte'),
('G#', 'Forte'),
('G#', 'Fortissimo'),
('Gb', 'Pianissimo'),
('Gb', 'Piano'),
('Gb', 'Mezzo-piano'),
('Gb', 'Mezzo-forte'),
('Gb', 'Forte'),
('Gb', 'Fortissimo');

-- Grid data
INSERT INTO grid (note_id, location_id) VALUES
(1, 1),
(24, 4),
(43, 7),
(36, 10),
(19, 20),
(50, 24);

-- Song data
INSERT INTO song (grid_id, instrument_id) VALUES
(1, 1),
(2, 2),
(3, 3);

-- Products data
INSERT INTO project (name, users_id, song_id) VALUES
('My great song', 1, 1),
('My awesome project', 2, 1),
('My great song', 2, 2),
('My great song', 3, 4);