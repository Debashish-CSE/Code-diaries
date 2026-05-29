-- CREATE TABLE data (
--     drug_name TEXT,
--     side_effect TEXT,
--     side_effect_1 TEXT,
--     side_effect_2 TEXT,
--     side_effect_3 TEXT,
--     side_effect_4 TEXT,
--     interacts_with TEXT,
--     interacts_with_1 TEXT,
--     interacts_with_2 TEXT,
--     disease_name TEXT,
--     disease_category TEXT,
--     drug_category TEXT,
--     product_name TEXT,
--     company_name TEXT,
--     clinical_trial_title TEXT,
--     clinical_trial_start_date TEXT,
--     clinical_trial_completion_date TEXT,
--     clinical_trial_participants NUMERIC,
--     clinical_trial_status TEXT,
--     clinical_trial_condition TEXT,
--     clinical_trial_condition_1 TEXT,
--     clinical_trial_address TEXT,
--     clinical_trial_institution TEXT,
--     clinical_trial_address_1 TEXT,
--     clinical_trial_main_researcher TEXT,
--     clinical_trial_condition_2 TEXT
-- );

-- 

-- run in psql terminal
-- \copy data 
-- FROM 'C:\Users\user\Downloads\Telegram Desktop\Database\Tutorial_1\Tutorial1_data.csv' 
-- DELIMITER ',' CSV HEADER;

select *
from data;