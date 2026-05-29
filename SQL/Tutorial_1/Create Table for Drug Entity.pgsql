-- -- Table for Drug Entity
-- CREATE TABLE Drug (
--     drug_name VARCHAR(255) PRIMARY KEY,
--     drug_category VARCHAR(100),
--     product_name VARCHAR(255),
--     company_name VARCHAR(255)
-- );

-- -- Table for SideEffect Entity
-- CREATE TABLE SideEffect (
--     name VARCHAR(255) PRIMARY KEY
-- );

-- -- Table for Interaction Entity
-- CREATE TABLE Interaction (
--     name VARCHAR(255) PRIMARY KEY
-- );

-- -- Table for Disease Entity
-- CREATE TABLE Disease (
--     disease_name VARCHAR(255) PRIMARY KEY,
--     disease_category VARCHAR(100)
-- );

-- -- Table for ClinicalTrial Entity (dates as TEXT now)
-- CREATE TABLE ClinicalTrial (
--     clinical_trial_title VARCHAR(500) PRIMARY KEY,
--     clinical_trial_start_date TEXT,
--     clinical_trial_completion_date TEXT,
--     clinical_trial_participants NUMERIC,
--     clinical_trial_status VARCHAR(50),
--     clinical_trial_address VARCHAR(500),
--     clinical_trial_institution VARCHAR(255),
--     clinical_trial_address_1 VARCHAR(500),
--     clinical_trial_main_researcher VARCHAR(255)
-- );

-- -- Table for ClinicalTrialCondition Entity
-- CREATE TABLE ClinicalTrialCondition (
--     name VARCHAR(255) PRIMARY KEY
-- );

-- -- Junction Table for Drug-SideEffect relationship
-- CREATE TABLE Drug_SideEffect (
--     drug_name VARCHAR(255) REFERENCES Drug(drug_name) ON DELETE CASCADE,
--     side_effect_name VARCHAR(255) REFERENCES SideEffect(name) ON DELETE CASCADE,
--     PRIMARY KEY (drug_name, side_effect_name)
-- );

-- -- Junction Table for Drug-Interaction relationship
-- CREATE TABLE Drug_Interaction (
--     drug_name VARCHAR(255) REFERENCES Drug(drug_name) ON DELETE CASCADE,
--     interaction_name VARCHAR(255) REFERENCES Interaction(name) ON DELETE CASCADE,
--     PRIMARY KEY (drug_name, interaction_name)
-- );

-- -- Junction Table for Drug-Disease relationship
-- CREATE TABLE Drug_Disease (
--     drug_name VARCHAR(255) REFERENCES Drug(drug_name) ON DELETE CASCADE,
--     disease_name VARCHAR(255) REFERENCES Disease(disease_name) ON DELETE CASCADE,
--     PRIMARY KEY (drug_name, disease_name)
-- );

-- -- Junction Table for Drug-ClinicalTrial relationship
-- CREATE TABLE Drug_ClinicalTrial (
--     drug_name VARCHAR(255) REFERENCES Drug(drug_name) ON DELETE CASCADE,
--     clinical_trial_title VARCHAR(500) REFERENCES ClinicalTrial(clinical_trial_title) ON DELETE CASCADE,
--     PRIMARY KEY (drug_name, clinical_trial_title)
-- );

-- -- Junction Table for ClinicalTrial-Condition relationship
-- CREATE TABLE ClinicalTrial_Condition (
--     clinical_trial_title VARCHAR(500) REFERENCES ClinicalTrial(clinical_trial_title) ON DELETE CASCADE,
--     condition_name VARCHAR(255) REFERENCES ClinicalTrialCondition(name) ON DELETE CASCADE,
--     PRIMARY KEY (clinical_trial_title, condition_name)
-- );

-- -- Insert into Drug
-- INSERT INTO Drug (drug_name, drug_category, product_name, company_name)
-- SELECT DISTINCT drug_name, drug_category, product_name, company_name
-- FROM data
-- WHERE drug_name IS NOT NULL;

-- -- Insert into SideEffect
-- INSERT INTO SideEffect (name)
-- SELECT DISTINCT TRIM(UNNEST(STRING_TO_ARRAY(side_effects, ','))) AS name
-- FROM data
-- WHERE side_effects IS NOT NULL;

-- -- Insert into Interaction
-- INSERT INTO Interaction (name)
-- SELECT DISTINCT TRIM(UNNEST(STRING_TO_ARRAY(interactions, ','))) AS name
-- FROM data
-- WHERE interactions IS NOT NULL;

-- -- Insert into Disease
-- INSERT INTO Disease (disease_name, disease_category)
-- SELECT DISTINCT disease_name, disease_category
-- FROM data
-- WHERE disease_name IS NOT NULL;

-- -- Insert into ClinicalTrial
-- INSERT INTO ClinicalTrial (
--     clinical_trial_title,
--     clinical_trial_start_date,
--     clinical_trial_completion_date,
--     clinical_trial_participants,
--     clinical_trial_status,
--     clinical_trial_address,
--     clinical_trial_institution,
--     clinical_trial_address_1,
--     clinical_trial_main_researcher
-- )
-- SELECT DISTINCT
--     clinical_trial_title,
--     clinical_trial_start_date,
--     clinical_trial_completion_date,
--     clinical_trial_participants,
--     clinical_trial_status,
--     clinical_trial_address,
--     clinical_trial_institution,
--     clinical_trial_address_1,
--     clinical_trial_main_researcher
-- FROM data
-- WHERE clinical_trial_title IS NOT NULL;

-- -- Insert into ClinicalTrialCondition
-- INSERT INTO ClinicalTrialCondition (name)
-- SELECT DISTINCT TRIM(UNNEST(STRING_TO_ARRAY(clinical_trial_conditions, ','))) AS name
-- FROM data
-- WHERE clinical_trial_conditions IS NOT NULL;

-- -- Insert into Drug_SideEffect
-- INSERT INTO Drug_SideEffect (drug_name, side_effect_name)
-- SELECT DISTINCT drug_name, TRIM(value)
-- FROM data,
-- LATERAL UNNEST(STRING_TO_ARRAY(side_effects, ',')) AS value
-- WHERE drug_name IS NOT NULL AND side_effects IS NOT NULL;

-- -- Insert into Drug_Interaction
-- INSERT INTO Drug_Interaction (drug_name, interaction_name)
-- SELECT DISTINCT drug_name, TRIM(value)
-- FROM data,
-- LATERAL UNNEST(STRING_TO_ARRAY(interactions, ',')) AS value
-- WHERE drug_name IS NOT NULL AND interactions IS NOT NULL;

-- -- Insert into Drug_Disease
-- INSERT INTO Drug_Disease (drug_name, disease_name)
-- SELECT DISTINCT drug_name, disease_name
-- FROM data
-- WHERE drug_name IS NOT NULL AND disease_name IS NOT NULL;

-- -- Insert into Drug_ClinicalTrial
-- INSERT INTO Drug_ClinicalTrial (drug_name, clinical_trial_title)
-- SELECT DISTINCT drug_name, clinical_trial_title
-- FROM data
-- WHERE drug_name IS NOT NULL AND clinical_trial_title IS NOT NULL;

-- -- Insert into ClinicalTrial_Condition
-- INSERT INTO ClinicalTrial_Condition (clinical_trial_title, condition_name)
-- SELECT DISTINCT clinical_trial_title, TRIM(value)
-- FROM data,
-- LATERAL UNNEST(STRING_TO_ARRAY(clinical_trial_conditions, ',')) AS value
-- WHERE clinical_trial_title IS NOT NULL AND clinical_trial_conditions IS NOT NULL;
