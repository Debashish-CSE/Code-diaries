-- -- Insert into SideEffect
-- INSERT INTO SideEffect (name)
-- SELECT DISTINCT TRIM(val) AS name
-- FROM data,
-- LATERAL UNNEST(ARRAY[
--     side_effect, side_effect_1, side_effect_2, side_effect_3, side_effect_4
-- ]) AS val
-- WHERE val IS NOT NULL AND TRIM(val) <> ''
-- ON CONFLICT (name) DO NOTHING;

-- Insert into Interaction
-- INSERT INTO Interaction (name)
-- SELECT DISTINCT TRIM(val) AS name
-- FROM data,
-- LATERAL UNNEST(ARRAY[
--     interacts_with, interacts_with_1, interacts_with_2
-- ]) AS val
-- WHERE val IS NOT NULL AND TRIM(val) <> ''
-- ON CONFLICT (name) DO NOTHING;

-- -- Insert into Disease
-- INSERT INTO Disease (disease_name, disease_category)
-- SELECT DISTINCT disease_name, disease_category
-- FROM data
-- WHERE disease_name IS NOT NULL
-- ON CONFLICT (disease_name) DO NOTHING;

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
-- WHERE clinical_trial_title IS NOT NULL
-- ON CONFLICT (clinical_trial_title) DO NOTHING;

-- -- Insert into ClinicalTrialCondition
-- INSERT INTO ClinicalTrialCondition (name)
-- SELECT DISTINCT TRIM(val) AS name
-- FROM data,
-- LATERAL UNNEST(ARRAY[
--     clinical_trial_condition, clinical_trial_condition_1, clinical_trial_condition_2
-- ]) AS val
-- WHERE val IS NOT NULL AND TRIM(val) <> ''
-- ON CONFLICT (name) DO NOTHING;

-- -- Insert into Drug_SideEffect
-- INSERT INTO Drug_SideEffect (drug_name, side_effect_name)
-- SELECT DISTINCT drug_name, TRIM(val)
-- FROM data,
-- LATERAL UNNEST(ARRAY[
--     side_effect, side_effect_1, side_effect_2, side_effect_3, side_effect_4
-- ]) AS val
-- WHERE drug_name IS NOT NULL AND val IS NOT NULL AND TRIM(val) <> ''
-- ON CONFLICT (drug_name, side_effect_name) DO NOTHING;

-- -- Insert into Drug_Interaction
-- INSERT INTO Drug_Interaction (drug_name, interaction_name)
-- SELECT DISTINCT drug_name, TRIM(val)
-- FROM data,
-- LATERAL UNNEST(ARRAY[
--     interacts_with, interacts_with_1, interacts_with_2
-- ]) AS val
-- WHERE drug_name IS NOT NULL AND val IS NOT NULL AND TRIM(val) <> ''
-- ON CONFLICT (drug_name, interaction_name) DO NOTHING;

-- -- Insert into Drug_Disease
-- INSERT INTO Drug_Disease (drug_name, disease_name)
-- SELECT DISTINCT drug_name, disease_name
-- FROM data
-- WHERE drug_name IS NOT NULL AND disease_name IS NOT NULL
-- ON CONFLICT (drug_name, disease_name) DO NOTHING;

-- -- Insert into Drug_ClinicalTrial
-- INSERT INTO Drug_ClinicalTrial (drug_name, clinical_trial_title)
-- SELECT DISTINCT drug_name, clinical_trial_title
-- FROM data
-- WHERE drug_name IS NOT NULL AND clinical_trial_title IS NOT NULL
-- ON CONFLICT (drug_name, clinical_trial_title) DO NOTHING;

-- -- Insert into ClinicalTrial_Condition
-- INSERT INTO ClinicalTrial_Condition (clinical_trial_title, condition_name)
-- SELECT DISTINCT clinical_trial_title, TRIM(val)
-- FROM data,
-- LATERAL UNNEST(ARRAY[
--     clinical_trial_condition, clinical_trial_condition_1, clinical_trial_condition_2
-- ]) AS val
-- WHERE clinical_trial_title IS NOT NULL AND val IS NOT NULL AND TRIM(val) <> ''
-- ON CONFLICT (clinical_trial_title, condition_name) DO NOTHING;
SELECT drug_name, STRING_AGG(side_effect_name, ', ' ORDER BY side_effect_name) AS side_effects
FROM Drug_SideEffect
GROUP BY drug_name;
