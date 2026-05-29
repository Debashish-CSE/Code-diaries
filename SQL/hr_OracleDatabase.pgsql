-- -- Sequences
-- CREATE SEQUENCE regions_seq START WITH 1;
-- CREATE SEQUENCE countries_seq START WITH 1; -- note: not used for FK but kept for symmetry
-- CREATE SEQUENCE locations_seq START WITH 1000;
-- CREATE SEQUENCE departments_seq START WITH 10;
-- CREATE SEQUENCE employees_seq START WITH 100;


-- -- REGIONS
-- CREATE TABLE regions (
--   region_id INTEGER PRIMARY KEY DEFAULT nextval('regions_seq'),
--   region_name VARCHAR(25) NOT NULL
-- );

-- -- COUNTRIES
-- CREATE TABLE countries (
--   country_id CHAR(2) PRIMARY KEY,
--   country_name VARCHAR(40),
--   region_id INTEGER REFERENCES regions(region_id)
-- );

-- -- LOCATIONS
-- CREATE TABLE locations (
--   location_id INTEGER PRIMARY KEY DEFAULT nextval('locations_seq'),
--   street_address VARCHAR(40),
--   postal_code VARCHAR(12),
--   city VARCHAR(30) NOT NULL,
--   state_province VARCHAR(25),
--   country_id CHAR(2) REFERENCES countries(country_id)
-- );

-- -- DEPARTMENTS
-- CREATE TABLE departments (
--   department_id INTEGER PRIMARY KEY DEFAULT nextval('departments_seq'),
--   department_name VARCHAR(30) NOT NULL,
--   manager_id INTEGER,
--   location_id INTEGER REFERENCES locations(location_id)
-- );

-- -- JOBS
-- CREATE TABLE jobs (
--   job_id VARCHAR(10) PRIMARY KEY,
--   job_title VARCHAR(35) NOT NULL,
--   min_salary NUMERIC(6),
--   max_salary NUMERIC(6)
-- );

-- -- EMPLOYEES
-- CREATE TABLE employees (
--   employee_id INTEGER PRIMARY KEY DEFAULT nextval('employees_seq'),
--   first_name VARCHAR(20),
--   last_name VARCHAR(25) NOT NULL,
--   email VARCHAR(25) NOT NULL UNIQUE,
--   phone_number VARCHAR(20),
--   hire_date DATE NOT NULL,
--   job_id VARCHAR(10) NOT NULL REFERENCES jobs(job_id),
--   salary NUMERIC(8,2) CHECK (salary > 0),
--   commission_pct NUMERIC(2,2),
--   manager_id INTEGER REFERENCES employees(employee_id),
--   department_id INTEGER REFERENCES departments(department_id)
-- );

-- -- JOB_HISTORY
-- CREATE TABLE job_history (
--   employee_id INTEGER NOT NULL REFERENCES employees(employee_id),
--   start_date DATE NOT NULL,
--   end_date DATE NOT NULL,
--   job_id VARCHAR(10) NOT NULL REFERENCES jobs(job_id),
--   department_id INTEGER REFERENCES departments(department_id),
--   PRIMARY KEY (employee_id, start_date),
--   CHECK (end_date > start_date)
-- );

-- CREATE OR REPLACE VIEW emp_details_view AS
-- SELECT
--   e.employee_id,
--   e.job_id,
--   e.manager_id,
--   e.department_id,
--   l.location_id,
--   l.country_id,
--   e.first_name,
--   e.last_name,
--   e.salary,
--   e.commission_pct,
--   d.department_name,
--   j.job_title,
--   l.city,
--   l.state_province,
--   c.country_name,
--   r.region_name
-- FROM employees e
-- JOIN departments d ON e.department_id = d.department_id
-- JOIN jobs j ON e.job_id = j.job_id
-- JOIN locations l ON d.location_id = l.location_id
-- JOIN countries c ON l.country_id = c.country_id
-- JOIN regions r ON c.region_id = r.region_id;


-- INSERT INTO regions(region_id, region_name) VALUES
-- (1, 'Europe'),
-- (2, 'Americas'),
-- (3, 'Asia'),
-- (4, 'Middle East and Africa');

-- INSERT INTO countries(country_id, country_name, region_id) VALUES
-- ('IT','Italy',1),
-- ('JP','Japan',3),
-- ('US','United States of America',2),
-- ('CA','Canada',2),
-- ('CN','China',3),
-- ('IN','India',3),
-- ('AU','Australia',3),
-- ('ZW','Zimbabwe',4),
-- ('SG','Singapore',3),
-- ('UK','United Kingdom',1),
-- ('FR','France',1),
-- ('DE','Germany',1),
-- ('ZM','Zambia',4),
-- ('EG','Egypt',4),
-- ('BR','Brazil',2),
-- ('CH','Switzerland',1),
-- ('NL','Netherlands',1),
-- ('MX','Mexico',2),
-- ('KW','Kuwait',4),
-- ('IL','Israel',4),
-- ('DK','Denmark',1),
-- ('HK','Hong Kong',3),
-- ('NG','Nigeria',4),
-- ('AR','Argentina',2),
-- ('BE','Belgium',1);


-- INSERT INTO locations(location_id, street_address, postal_code, city, state_province, country_id) VALUES
-- (1000,'2004 Charade Rd.','98199','Seattle','WA','US'),
-- (1100,'93091 Lydia Branch Road',NULL,'South San Francisco','CA','US'),
-- (1200,'2017 Shinjuku-ku','1689','Tokyo',NULL,'JP'),
-- (1300,'9450 Kamiya-cho','6823','Hiroshima',NULL,'JP'),
-- (1400,'2014 Jabberwocky Rd','26192','Southlake','TX','US'),
-- (1500,'1297 Via Cola di Rie','10934','Reggio',NULL,'IT'),
-- (1600,'9702 Chester Rd','89010','Las Vegas','NV','US'),
-- (1700,'9450 Kamiya-cho','6823','Hiroshima',NULL,'JP'),
-- (1800,'2014 Jabberwocky Rd','26192','Southlake','TX','US'),
-- (1900,'1297 Via Cola di Rie','10934','Reggio',NULL,'IT'),
-- (2000,'2011 Interiors Blvd.','99236','South San Francisco','CA','US'),
-- (2100,'3990 Tuas South Rd.','63885','Singapore',NULL,'SG'),
-- (2200,'3211 Lyon Ln.','27829','Urbana','IL','US'),
-- (2300,'512  State Street','96534','South Bend','IN','US'),
-- (2400,'46 Laussat','75005','Paris',NULL,'FR'),
-- (2500,'Magdalen Centre, The Oxford Science Park','OX4 4GA','Oxford',NULL,'UK'),
-- (2600,'198 Clementi North','12934','Singapore',NULL,'SG'),
-- (2700,'8204 Arthur St.','87110','Albuquerque','NM','US'),
-- (2800,'9450 Kamiya-cho','6823','Hiroshima',NULL,'JP'),
-- (2900,'2014 Jabberwocky Rd','26192','Southlake','TX','US'),
-- (3000,'1297 Via Cola di Rie','10934','Reggio',NULL,'IT'),
-- (3100,'2017 Shinjuku-ku','1689','Tokyo',NULL,'JP'),
-- (3200,'2333 GHI Street','98102','Seattle','WA','US');


-- INSERT INTO departments(department_id, department_name, manager_id, location_id) VALUES
-- (10,'Administration',200,1000),
-- (20,'Marketing',201,1000),
-- (30,'Purchasing',114,1700),
-- (40,'Human Resources',203,2400),
-- (50,'Shipping',121,1500),
-- (60,'IT',103,1200),
-- (70,'Public Relations',204,2700),
-- (80,'Sales',145,2500),
-- (90,'Executive',100,1700),
-- (100,'Finance',108,1700),
-- (110,'Accounting',205,1700),
-- (120,'Treasury',0,1700),
-- (130,'Corporate Tax',0,1700),
-- (140,'Control And Risk',0,1700),
-- (150,'Shareholder Services',0,1700),
-- (160,'Benefits',0,1700),
-- (170,'Manufacturing',0,1700),
-- (180,'Construction',0,1700),
-- (190,'Contracting',0,1700),
-- (200,'Operations',0,1700),
-- (210,'IT Support',0,1700),
-- (220,'NOC',0,1700),
-- (230,'IT Helpdesk',0,1700),
-- (240,'Government Sales',0,1700),
-- (250,'Retail Sales',0,1700),
-- (260,'Recruiting',0,1700),
-- (270,'Payroll',0,1700);


-- INSERT INTO jobs(job_id, job_title, min_salary, max_salary) VALUES
-- ('AD_PRES','President',20080,40000),
-- ('AD_VP','Administration Vice President',15000,30000),
-- ('AD_ASST','Administration Assistant',3000,6000),
-- ('FI_MGR','Finance Manager',8200,16000),
-- ('FI_ACCOUNT','Accountant',4200,9000),
-- ('AC_MGR','Accounting Manager',8200,16000),
-- ('AC_ACCOUNT','Public Accountant',4200,9000),
-- ('SA_MAN','Sales Manager',10000,20080),
-- ('SA_REP','Sales Representative',6000,12008),
-- ('PU_MAN','Purchasing Manager',8000,15000),
-- ('PU_CLERK','Purchasing Clerk',2500,5500),
-- ('ST_MAN','Stock Manager',5500,8500),
-- ('ST_CLERK','Stock Clerk',2008,5000),
-- ('SH_CLERK','Shipping Clerk',2500,5500),
-- ('IT_PROG','Programmer',4000,10000),
-- ('MK_MAN','Marketing Manager',9000,15000),
-- ('MK_REP','Marketing Representative',4000,9000),
-- ('HR_REP','Human Resources Representative',4000,9000),
-- ('PR_REP','Public Relations Representative',4500,10500);


-- INSERT INTO job_history(employee_id, start_date, end_date, job_id, department_id) VALUES
-- (101,'2005-09-21','2007-01-31','AD_VP',90),
-- (101,'2007-02-01','2008-12-31','AD_ASST',90),
-- (102,'2001-01-13','2006-01-02','ST_CLERK',30),
-- (103,'2006-01-03','2007-02-28','IT_PROG',60),
-- (114,'2002-12-07','2004-12-31','PU_MAN',30),
-- (115,'2003-05-18','2005-12-31','PU_CLERK',30),
-- (116,'2005-12-24','2007-12-31','PU_CLERK',30),
-- (117,'2005-12-24','2007-12-31','PU_CLERK',30),
-- (118,'2006-11-15','2007-12-31','PU_CLERK',30),
-- (146,'2004-03-04','2006-06-30','AC_ACCOUNT',110),
-- (157,'1997-06-14','1999-12-31','SH_CLERK',50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 100
--         , 'Steven'
--         , 'King'
--         , 'SKING'
--         , '515.123.4567'
--         , DATE '1987-06-17'
--         , 'AD_PRES'
--         , 24000
--         , NULL
--         , NULL
--         , 90
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 101
--         , 'Neena'
--         , 'Kochhar'
--         , 'NKOCHHAR'
--         , '515.123.4568'
--         , DATE '1989-09-21'
--         , 'AD_VP'
--         , 17000
--         , NULL
--         , 100
--         , 90
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 102
--         , 'Lex'
--         , 'De Haan'
--         , 'LDEHAAN'
--         , '515.123.4569'
--         , DATE '1993-01-13'
--         , 'AD_VP'
--         , 17000
--         , NULL
--         , 100
--         , 90
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 103
--         , 'Alexander'
--         , 'Hunold'
--         , 'AHUNOLD'
--         , '590.423.4567'
--         , DATE '1990-01-03'
--         , 'IT_PROG'
--         , 9000
--         , NULL
--         , 102
--         , 60
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 104
--         , 'Bruce'
--         , 'Ernst'
--         , 'BERNST'
--         , '590.423.4568'
--         , DATE '1991-05-21'
--         , 'IT_PROG'
--         , 6000
--         , NULL
--         , 103
--         , 60
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 105
--         , 'David'
--         , 'Austin'
--         , 'DAUSTIN'
--         , '590.423.4569'
--         , DATE '1997-06-25'
--         , 'IT_PROG'
--         , 4800
--         , NULL
--         , 103
--         , 60
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 106
--         , 'Valli'
--         , 'Pataballa'
--         , 'VPATABAL'
--         , '590.423.4560'
--         , DATE '1998-02-05'
--         , 'IT_PROG'
--         , 4800
--         , NULL
--         , 103
--         , 60
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 107
--         , 'Diana'
--         , 'Lorentz'
--         , 'DLORENTZ'
--         , '590.423.5567'
--         , DATE '1999-02-07'
--         , 'IT_PROG'
--         , 4200
--         , NULL
--         , 103
--         , 60
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 108
--         , 'Nancy'
--         , 'Greenberg'
--         , 'NGREENBE'
--         , '515.124.4569'
--         , DATE '1994-08-17'
--         , 'FI_MGR'
--         , 12000
--         , NULL
--         , 101
--         , 100
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 109
--         , 'Daniel'
--         , 'Faviet'
--         , 'DFAVIET'
--         , '515.124.4169'
--         , DATE '1994-08-16'
--         , 'FI_ACCOUNT'
--         , 9000
--         , NULL
--         , 108
--         , 100
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 110
--         , 'John'
--         , 'Chen'
--         , 'JCHEN'
--         , '515.124.4269'
--         , DATE '1997-09-28'
--         , 'FI_ACCOUNT'
--         , 8200
--         , NULL
--         , 108
--         , 100
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 111
--         , 'Ismael'
--         , 'Sciarra'
--         , 'ISCIARRA'
--         , '515.124.4369'
--         , DATE '1997-09-30'
--         , 'FI_ACCOUNT'
--         , 7700
--         , NULL
--         , 108
--         , 100
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 112
--         , 'Jose Manuel'
--         , 'Urman'
--         , 'JMURMAN'
--         , '515.124.4469'
--         , DATE '1998-03-07'
--         , 'FI_ACCOUNT'
--         , 7800
--         , NULL
--         , 108
--         , 100
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 113
--         , 'Luis'
--         , 'Popp'
--         , 'LPOPP'
--         , '515.124.4567'
--         , DATE '1999-12-07'
--         , 'FI_ACCOUNT'
--         , 6900
--         , NULL
--         , 108
--         , 100
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 114
--         , 'Den'
--         , 'Raphaely'
--         , 'DRAPHEAL'
--         , '515.127.4561'
--         , DATE '1994-12-07'
--         , 'PU_MAN'
--         , 11000
--         , NULL
--         , 100
--         , 30
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 115
--         , 'Alexander'
--         , 'Khoo'
--         , 'AKHOO'
--         , '515.127.4562'
--         , DATE '1995-05-18'
--         , 'PU_CLERK'
--         , 3100
--         , NULL
--         , 114
--         , 30
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 116
--         , 'Shelli'
--         , 'Baida'
--         , 'SBAIDA'
--         , '515.127.4563'
--         , DATE '1997-12-24'
--         , 'PU_CLERK'
--         , 2900
--         , NULL
--         , 114
--         , 30
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 117
--         , 'Sigal'
--         , 'Tobias'
--         , 'STOBIAS'
--         , '515.127.4564'
--         , DATE '1997-07-24'
--         , 'PU_CLERK'
--         , 2800
--         , NULL
--         , 114
--         , 30
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 118
--         , 'Guy'
--         , 'Himuro'
--         , 'GHIMURO'
--         , '515.127.4565'
--         , DATE '1998-11-15'
--         , 'PU_CLERK'
--         , 2600
--         , NULL
--         , 114
--         , 30
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 119
--         , 'Karen'
--         , 'Colmenares'
--         , 'KCOLMENA'
--         , '515.127.4566'
--         , DATE '1999-08-10'
--         , 'PU_CLERK'
--         , 2500
--         , NULL
--         , 114
--         , 30
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 120
--         , 'Matthew'
--         , 'Weiss'
--         , 'MWEISS'
--         , '650.123.1234'
--         , DATE '1996-07-18'
--         , 'ST_MAN'
--         , 8000
--         , NULL
--         , 100
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 121
--         , 'Adam'
--         , 'Fripp'
--         , 'AFRIPP'
--         , '650.123.2234'
--         , DATE '1997-04-10'
--         , 'ST_MAN'
--         , 8200
--         , NULL
--         , 100
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 122
--         , 'Payam'
--         , 'Kaufling'
--         , 'PKAUFLIN'
--         , '650.123.3234'
--         , DATE '1995-05-01'
--         , 'ST_MAN'
--         , 7900
--         , NULL
--         , 100
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 123
--         , 'Shanta'
--         , 'Vollman'
--         , 'SVOLLMAN'
--         , '650.123.4234'
--         , DATE '1997-10-10'
--         , 'ST_MAN'
--         , 6500
--         , NULL
--         , 100
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 124
--         , 'Kevin'
--         , 'Mourgos'
--         , 'KMOURGOS'
--         , '650.123.5234'
--         , DATE '1999-11-16'
--         , 'ST_MAN'
--         , 5800
--         , NULL
--         , 100
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 125
--         , 'Julia'
--         , 'Nayer'
--         , 'JNAYER'
--         , '650.124.1214'
--         , DATE '1997-07-16'
--         , 'ST_CLERK'
--         , 3200
--         , NULL
--         , 120
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 126
--         , 'Irene'
--         , 'Mikkilineni'
--         , 'IMIKKILI'
--         , '650.124.1224'
--         , DATE '1998-09-28'
--         , 'ST_CLERK'
--         , 2700
--         , NULL
--         , 120
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 127
--         , 'James'
--         , 'Landry'
--         , 'JLANDRY'
--         , '650.124.1334'
--         , DATE '1999-01-14'
--         , 'ST_CLERK'
--         , 2400
--         , NULL
--         , 120
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 128
--         , 'Steven'
--         , 'Markle'
--         , 'SMARKLE'
--         , '650.124.1434'
--         , DATE '2000-03-08'
--         , 'ST_CLERK'
--         , 2200
--         , NULL
--         , 120
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 129
--         , 'Laura'
--         , 'Bissot'
--         , 'LBISSOT'
--         , '650.124.5234'
--         , DATE '1997-08-20'
--         , 'ST_CLERK'
--         , 3300
--         , NULL
--         , 121
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 130
--         , 'Mozhe'
--         , 'Atkinson'
--         , 'MATKINSO'
--         , '650.124.6234'
--         , DATE '1997-10-30'
--         , 'ST_CLERK'
--         , 2800
--         , NULL
--         , 121
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 131
--         , 'James'
--         , 'Marlow'
--         , 'JAMRLOW'
--         , '650.124.7234'
--         , DATE '1997-02-16'
--         , 'ST_CLERK'
--         , 2500
--         , NULL
--         , 121
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 132
--         , 'TJ'
--         , 'Olson'
--         , 'TJOLSON'
--         , '650.124.8234'
--         , DATE '1999-04-10'
--         , 'ST_CLERK'
--         , 2100
--         , NULL
--         , 121
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 133
--         , 'Jason'
--         , 'Mallin'
--         , 'JMALLIN'
--         , '650.127.1934'
--         , DATE '1996-06-14'
--         , 'ST_CLERK'
--         , 3300
--         , NULL
--         , 122
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 134
--         , 'Michael'
--         , 'Rogers'
--         , 'MROGERS'
--         , '650.127.1834'
--         , DATE '1998-08-26'
--         , 'ST_CLERK'
--         , 2900
--         , NULL
--         , 122
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 135
--         , 'Ki'
--         , 'Gee'
--         , 'KGEE'
--         , '650.127.1734'
--         , DATE '1999-12-12'
--         , 'ST_CLERK'
--         , 2400
--         , NULL
--         , 122
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 136
--         , 'Hazel'
--         , 'Philtanker'
--         , 'HPHILTAN'
--         , '650.127.1634'
--         , DATE '2000-02-06'
--         , 'ST_CLERK'
--         , 2200
--         , NULL
--         , 122
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 137
--         , 'Renske'
--         , 'Ladwig'
--         , 'RLADWIG'
--         , '650.121.1234'
--         , DATE '1995-07-14'
--         , 'ST_CLERK'
--         , 3600
--         , NULL
--         , 123
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 138
--         , 'Stephen'
--         , 'Stiles'
--         , 'SSTILES'
--         , '650.121.2034'
--         , DATE '1997-10-26'
--         , 'ST_CLERK'
--         , 3200
--         , NULL
--         , 123
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 139
--         , 'John'
--         , 'Seo'
--         , 'JSEO'
--         , '650.121.2019'
--         , DATE '1998-02-12'
--         , 'ST_CLERK'
--         , 2700
--         , NULL
--         , 123
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 140
--         , 'Joshua'
--         , 'Patel'
--         , 'JPATEL'
--         , '650.121.1834'
--         , DATE '1998-04-06'
--         , 'ST_CLERK'
--         , 2500
--         , NULL
--         , 123
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 141
--         , 'Trenna'
--         , 'Rajs'
--         , 'TRAJS'
--         , '650.121.8009'
--         , DATE '1995-10-17'
--         , 'ST_CLERK'
--         , 3500
--         , NULL
--         , 124
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 142
--         , 'Curtis'
--         , 'Davies'
--         , 'CDAVIES'
--         , '650.121.2994'
--         , DATE '1997-01-29'
--         , 'ST_CLERK'
--         , 3100
--         , NULL
--         , 124
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 143
--         , 'Randall'
--         , 'Matos'
--         , 'RMATOS'
--         , '650.121.2874'
--         , DATE '1998-03-15'
--         , 'ST_CLERK'
--         , 2600
--         , NULL
--         , 124
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 144
--         , 'Peter'
--         , 'Vargas'
--         , 'PVARGAS'
--         , '650.121.2004'
--         , DATE '1998-07-09'
--         , 'ST_CLERK'
--         , 2500
--         , NULL
--         , 124
--         , 50
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 145
--         , 'John'
--         , 'Russell'
--         , 'JRUSSEL'
--         , '011.44.1344.429268'
--         , DATE '1996-10-01'
--         , 'SA_MAN'
--         , 14000
--         , 0.4
--         , 100
--         , 80
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 146
--         , 'Karen'
--         , 'Partners'
--         , 'KPARTNER'
--         , '011.44.1344.467268'
--         , DATE '1997-01-05'
--         , 'SA_MAN'
--         , 13500
--         , 0.3
--         , 100
--         , 80
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 147
--         , 'Alberto'
--         , 'Errazuriz'
--         , 'AERRAZUR'
--         , '011.44.1344.429278'
--         , DATE '1997-03-10'
--         , 'SA_MAN'
--         , 12000
--         , 0.3
--         , 100
--         , 80
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 148
--         , 'Gerald'
--         , 'Cambrault'
--         , 'GCAMBRAU'
--         , '011.44.1344.619268'
--         , DATE '1999-10-15'
--         , 'SA_MAN'
--         , 11000
--         , 0.3
--         , 100
--         , 80
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 149
--         , 'Eleni'
--         , 'Zlotkey'
--         , 'EZLOTKEY'
--         , '011.44.1344.429018'
--         , DATE '2000-01-29'
--         , 'SA_MAN'
--         , 10500
--         , 0.2
--         , 100
--         , 80
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 150
--         , 'Peter'
--         , 'Tucker'
--         , 'PTUCKER'
--         , '011.44.1344.129268'
--         , DATE '1997-01-30'
--         , 'SA_REP'
--         , 10000
--         , 0.3
--         , 145
--         , 80
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 151
--         , 'David'
--         , 'Bernstein'
--         , 'DBERNSTE'
--         , '011.44.1344.345268'
--         , DATE '1997-03-24'
--         , 'SA_REP'
--         , 9500
--         , 0.25
--         , 145
--         , 80
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 152
--         , 'Peter'
--         , 'Hall'
--         , 'PHALL'
--         , '011.44.1344.478968'
--         , DATE '1997-08-20'
--         , 'SA_REP'
--         , 9000
--         , 0.25
--         , 145
--         , 80
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 153
--         , 'Christopher'
--         , 'Olsen'
--         , 'COLSEN'
--         , '011.44.1344.498718'
--         , DATE '1998-03-30'
--         , 'SA_REP'
--         , 8000
--         , 0.2
--         , 145
--         , 80
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 154
--         , 'Nanette'
--         , 'Cambrault'
--         , 'NCAMBRAU'
--         , '011.44.1344.987668'
--         , DATE '1998-12-09'
--         , 'SA_REP'
--         , 7500
--         , 0.2
--         , 145
--         , 80
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 155
--         , 'Oliver'
--         , 'Tuvault'
--         , 'OTUVAULT'
--         , '011.44.1344.486508'
--         , DATE '1999-11-23'
--         , 'SA_REP'
--         , 7000
--         , 0.15
--         , 145
--         , 80
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 156
--         , 'Janette'
--         , 'King'
--         , 'JKING'
--         , '011.44.1345.429268'
--         , DATE '1996-01-30'
--         , 'SA_REP'
--         , 10000
--         , 0.35
--         , 146
--         , 80
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES 
--         ( 157
--         , 'Patrick'
--         , 'Sully'
--         , 'PSULLY'
--         , '011.44.1345.929268'
--         , DATE '1996-03-04'
--         , 'SA_REP'
--         , 9500
--         , 0.35
--         , 146
--         , 80
--         );

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (158, 'Allan', 'McEwen', 'AMCEWEN', '011.44.1345.829268', DATE '1996-08-01', 'SA_REP', 9000, 0.35, 146, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (159, 'Lindsey', 'Smith', 'LSMITH', '011.44.1345.729268', DATE '1997-03-10', 'SA_REP', 8000, 0.3, 146, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (160, 'Louise', 'Doran', 'LDORAN', '011.44.1345.629268', DATE '1997-12-15', 'SA_REP', 7500, 0.3, 146, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (161, 'Sarath', 'Sewall', 'SSEWALL', '011.44.1345.529268', DATE '1998-11-03', 'SA_REP', 7000, 0.25, 146, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (162, 'Clara', 'Vishney', 'CVISHNEY', '011.44.1346.129268', DATE '1997-11-11', 'SA_REP', 10500, 0.25, 147, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (163, 'Danielle', 'Greene', 'DGREENE', '011.44.1346.229268', DATE '1999-03-19', 'SA_REP', 9500, 0.15, 147, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (164, 'Mattea', 'Marvins', 'MMARVINS', '011.44.1346.329268', DATE '2000-01-24', 'SA_REP', 7200, 0.10, 147, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (165, 'David', 'Lee', 'DLEE', '011.44.1346.529268', DATE '2000-02-23', 'SA_REP', 6800, 0.1, 147, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (166, 'Sundar', 'Ande', 'SANDE', '011.44.1346.629268', DATE '2000-03-24', 'SA_REP', 6400, 0.10, 147, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (167, 'Amit', 'Banda', 'ABANDA', '011.44.1346.729268', DATE '2000-04-21', 'SA_REP', 6200, 0.10, 147, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (168, 'Lisa', 'Ozer', 'LOZER', '011.44.1343.929268', DATE '1997-03-11', 'SA_REP', 11500, 0.25, 148, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (169, 'Harrison', 'Bloom', 'HBLOOM', '011.44.1343.829268', DATE '1998-03-23', 'SA_REP', 10000, 0.20, 148, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (170, 'Tayler', 'Fox', 'TFOX', '011.44.1343.729268', DATE '1998-01-24', 'SA_REP', 9600, 0.20, 148, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (171, 'William', 'Smith', 'WSMITH', '011.44.1343.629268', DATE '1999-02-23', 'SA_REP', 7400, 0.15, 148, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (172, 'Elizabeth', 'Bates', 'EBATES', '011.44.1343.529268', DATE '1999-03-24', 'SA_REP', 7300, 0.15, 148, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (173, 'Sundita', 'Kumar', 'SKUMAR', '011.44.1343.329268', DATE '2000-04-21', 'SA_REP', 6100, 0.10, 148, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (174, 'Ellen', 'Abel', 'EABEL', '011.44.1644.429267', DATE '1996-05-11', 'SA_REP', 11000, 0.30, 149, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (175, 'Alyssa', 'Hutton', 'AHUTTON', '011.44.1644.429266', DATE '1997-03-19', 'SA_REP', 8800, 0.25, 149, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (176, 'Jonathon', 'Taylor', 'JTAYLOR', '011.44.1644.429265', DATE '1998-03-24', 'SA_REP', 8600, 0.20, 149, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (177, 'Jack', 'Livingston', 'JLIVINGS', '011.44.1644.429264', DATE '1998-04-23', 'SA_REP', 8400, 0.20, 149, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (178, 'Kimberely', 'Grant', 'KGRANT', '011.44.1644.429263', DATE '1999-05-24', 'SA_REP', 7000, 0.15, 149, NULL);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (179, 'Charles', 'Johnson', 'CJOHNSON', '011.44.1644.429262', DATE '2000-01-04', 'SA_REP', 6200, 0.10, 149, 80);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (180, 'Winston', 'Taylor', 'WTAYLOR', '650.507.9876', DATE '1998-01-24', 'SH_CLERK', 3200, NULL, 120, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (181, 'Jean', 'Fleaur', 'JFLEAUR', '650.507.9877', DATE '1998-02-23', 'SH_CLERK', 3100, NULL, 120, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (182, 'Martha', 'Sullivan', 'MSULLIVA', '650.507.9878', DATE '1999-06-21', 'SH_CLERK', 2500, NULL, 120, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (183, 'Girard', 'Geoni', 'GGEONI', '650.507.9879', DATE '2000-02-03', 'SH_CLERK', 2800, NULL, 120, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (184, 'Nandita', 'Sarchand', 'NSARCHAN', '650.509.1876', DATE '1996-01-27', 'SH_CLERK', 4200, NULL, 121, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (185, 'Alexis', 'Bull', 'ABULL', '650.509.2876', DATE '1997-02-20', 'SH_CLERK', 4100, NULL, 121, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (186, 'Julia', 'Dellinger', 'JDELLING', '650.509.3876', DATE '1998-06-24', 'SH_CLERK', 3400, NULL, 121, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (187, 'Anthony', 'Cabrio', 'ACABRIO', '650.509.4876', DATE '1999-02-07', 'SH_CLERK', 3000, NULL, 121, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (188, 'Kelly', 'Chung', 'KCHUNG', '650.505.1876', DATE '1997-06-14', 'SH_CLERK', 3800, NULL, 122, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (189, 'Jennifer', 'Dilly', 'JDILLY', '650.505.2876', DATE '1997-08-13', 'SH_CLERK', 3600, NULL, 122, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (190, 'Timothy', 'Gates', 'TGATES', '650.505.3876', DATE '1998-07-11', 'SH_CLERK', 2900, NULL, 122, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (191, 'Randall', 'Perkins', 'RPERKINS', '650.505.4876', DATE '1999-12-19', 'SH_CLERK', 2500, NULL, 122, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (192, 'Sarah', 'Bell', 'SBELL', '650.501.1876', DATE '1996-02-04', 'SH_CLERK', 4000, NULL, 123, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (193, 'Britney', 'Everett', 'BEVERETT', '650.501.2876', DATE '1997-03-03', 'SH_CLERK', 3900, NULL, 123, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (194, 'Samuel', 'McCain', 'SMCCAIN', '650.501.3876', DATE '1998-07-01', 'SH_CLERK', 3200, NULL, 123, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (195, 'Vance', 'Jones', 'VJONES', '650.501.4876', DATE '1999-03-17', 'SH_CLERK', 2800, NULL, 123, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (196, 'Alana', 'Walsh', 'AWALSH', '650.507.9811', DATE '1998-04-24', 'SH_CLERK', 3100, NULL, 124, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (197, 'Kevin', 'Feeney', 'KFEENEY', '650.507.9822', DATE '1998-05-23', 'SH_CLERK', 3000, NULL, 124, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (198, 'Donald', 'OConnell', 'DOCONNEL', '650.507.9833', DATE '1999-06-21', 'SH_CLERK', 2600, NULL, 124, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (199, 'Douglas', 'Grant', 'DGRANT', '650.507.9844', DATE '2000-01-13', 'SH_CLERK', 2600, NULL, 124, 50);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (200, 'Jennifer', 'Whalen', 'JWHALEN', '515.123.4444', DATE '1987-09-17', 'AD_ASST', 4400, NULL, 101, 10);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (201, 'Michael', 'Hartstein', 'MHARTSTE', '515.123.5555', DATE '1996-02-17', 'MK_MAN', 13000, NULL, 100, 20);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (202, 'Pat', 'Fay', 'PFAY', '603.123.6666', DATE '1997-08-17', 'MK_REP', 6000, NULL, 201, 20);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (203, 'Susan', 'Mavris', 'SMAVRIS', '515.123.7777', DATE '1994-06-07', 'HR_REP', 6500, NULL, 101, 40);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (204, 'Hermann', 'Baer', 'HBAER', '515.123.8888', DATE '1994-06-07', 'PR_REP', 10000, NULL, 101, 70);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (205, 'Shelley', 'Higgins', 'SHIGGINS', '515.123.8080', DATE '1994-06-07', 'AC_MGR', 12000, NULL, 101, 110);

-- INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_pct, manager_id, department_id) VALUES (206, 'William', 'Gietz', 'WGIETZ', '515.123.8181', DATE '1994-06-07', 'AC_ACCOUNT', 8300, NULL, 205, 110);