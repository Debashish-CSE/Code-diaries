CREATE TABLE CULTURE(
    CultureName text PRIMARY KEY
);

CREATE TABLE hasDimentions(
    length numeric,
    width numeric,
    height numeric,
    PRIMARY KEY (length, width, height)
);  

create table people(
    name text PRIMARY KEY
);

create table museum(
    museumNumber integer PRIMARY KEY,
    prefix text
);

create table object(
    objectNumber integer primary key,
    objectName TEXT,
    sort_number integer,
    role text,
    dated text,
    rolltype text,     
    displayName text,
    title text,      
    acquiredBy REFERENCES people(name),
    locatedIn REFERENCES museum(museumNumber),
    hasDimention REFERENCES hasDimentions(length, width, height)
);

create table medium(
    medium_name text,
    mediumof text REFERENCES object(objectNumber)
);

