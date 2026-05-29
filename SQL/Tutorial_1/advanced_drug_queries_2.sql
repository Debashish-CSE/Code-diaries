
-- a) Find the number of drugs that have nausea as a side effect
SELECT COUNT(DISTINCT drug_name) AS drug_count
FROM Drug_SideEffect
WHERE side_effect_name ILIKE 'nausea';

-- b) Find the drugs that interact with butabarbital
SELECT DISTINCT drug_name
FROM Drug_Interaction
WHERE interaction_name ILIKE 'butabarbital';

-- c) Find the drugs with side effects cough and headache
SELECT drug_name
FROM Drug_SideEffect
WHERE side_effect_name ILIKE 'cough'
INTERSECT
SELECT drug_name
FROM Drug_SideEffect
WHERE side_effect_name ILIKE 'headache';

-- d) Find the drugs that can be used to treat endocrine diseases
SELECT DISTINCT drug_name
FROM Drug_Disease
JOIN Disease USING (disease_name)
WHERE disease_category ILIKE 'endocrine%';

-- e) Find the most common treatment for immunological diseases that have not been used for hematological diseases
SELECT drug_name
FROM Drug_Disease
JOIN Disease USING (disease_name)
WHERE disease_category ILIKE 'immunological'
  AND drug_name NOT IN (
    SELECT drug_name
    FROM Drug_Disease
    JOIN Disease USING (disease_name)
    WHERE disease_category ILIKE 'hematological'
  )
GROUP BY drug_name
ORDER BY COUNT(*) DESC
LIMIT 1;

-- f) Find the diseases that can be treated with hydrocortisone but not with etanercept
SELECT disease_name
FROM Drug_Disease
WHERE drug_name ILIKE 'hydrocortisone'
EXCEPT
SELECT disease_name
FROM Drug_Disease
WHERE drug_name ILIKE 'etanercept';

-- g) Find the top-10 side effects that drugs used to treat asthma related diseases have not been used for hematological diseases
SELECT side_effect_name, COUNT(*) AS freq
FROM Drug_SideEffect
WHERE drug_name IN (
    SELECT drug_name
    FROM Drug_Disease
    JOIN Disease USING (disease_name)
    WHERE disease_name ILIKE '%asthma%'
)
AND drug_name NOT IN (
    SELECT drug_name
    FROM Drug_Disease
    JOIN Disease USING (disease_name)
    WHERE disease_category ILIKE 'hematological'
)
GROUP BY side_effect_name
ORDER BY freq DESC
LIMIT 10;

-- h) Find the drugs that have been studied in more than three clinical trials with more than 30 participants
SELECT drug_name
FROM Drug_ClinicalTrial
JOIN ClinicalTrial USING (clinical_trial_title)
WHERE clinical_trial_participants > 30
GROUP BY drug_name
HAVING COUNT(DISTINCT clinical_trial_title) > 3;

-- i) Find the largest number of clinical trials 
-- and the drugs they have studied that have been active in the same period of time
WITH all_dates AS (
    SELECT clinical_trial_start_date AS date FROM ClinicalTrial
    UNION
    SELECT clinical_trial_completion_date AS date FROM ClinicalTrial
),
active_counts AS (
    SELECT date,
           (SELECT COUNT(*)
            FROM ClinicalTrial
            WHERE clinical_trial_start_date <= date
              AND clinical_trial_completion_date >= date) AS active_trial_count
    FROM all_dates
),
max_date AS (
    SELECT date, active_trial_count
    FROM active_counts
    ORDER BY active_trial_count DESC
    LIMIT 1
),
active_trials_on_max_date AS (
    SELECT clinical_trial_title
    FROM ClinicalTrial
    WHERE clinical_trial_start_date <= (SELECT date FROM max_date)
      AND clinical_trial_completion_date >= (SELECT date FROM max_date)
)
SELECT 
    (SELECT active_trial_count FROM max_date) AS max_active_trials,
    dct.drug_name
FROM Drug_ClinicalTrial dct
JOIN active_trials_on_max_date at ON dct.clinical_trial_title = at.clinical_trial_title;


-- j) Find the main researchers that have conducted clinical trials that study drugs that can be used to treat both respiratory and cardiovascular diseases
SELECT DISTINCT clinical_trial_main_researcher
FROM ClinicalTrial
JOIN Drug_ClinicalTrial USING (clinical_trial_title)
JOIN Drug_Disease USING (drug_name)
JOIN Disease USING (disease_name)
WHERE disease_category ILIKE 'respiratory'
INTERSECT
SELECT DISTINCT clinical_trial_main_researcher
FROM ClinicalTrial
JOIN Drug_ClinicalTrial USING (clinical_trial_title)
JOIN Drug_Disease USING (drug_name)
JOIN Disease USING (disease_name)
WHERE disease_category ILIKE 'cardiovascular';

-- k) Find up to three main researchers that have conducted the larger number of clinical trials that study drugs that can be used to treat both respiratory and cardiovascular diseases
WITH both_disease_drugs AS (
  SELECT drug_name
  FROM Drug_Disease
  JOIN Disease USING (disease_name)
  WHERE disease_category ILIKE 'respiratory'
)
INTERSECT
SELECT drug_name
FROM Drug_Disease
JOIN Disease USING (disease_name)
WHERE disease_category ILIKE 'cardiovascular'
),
relevant_trials AS (
  SELECT clinical_trial_main_researcher
  FROM Drug_ClinicalTrial
  JOIN ClinicalTrial USING (clinical_trial_title)
  WHERE drug_name IN (SELECT * FROM both_disease_drugs)
)
SELECT clinical_trial_main_researcher, COUNT(*) AS trial_count
FROM relevant_trials
GROUP BY clinical_trial_main_researcher
ORDER BY trial_count DESC
LIMIT 3;

-- l) Find the categories of drugs that have been only studied in clinical trials based in United States
SELECT DISTINCT drug_category
FROM Drug
WHERE drug_name IN (
  SELECT drug_name
  FROM Drug_ClinicalTrial
  JOIN ClinicalTrial USING (clinical_trial_title)
  WHERE clinical_trial_address ILIKE '%united states%'
)
AND drug_name NOT IN (
  SELECT drug_name
  FROM Drug_ClinicalTrial
  JOIN ClinicalTrial USING (clinical_trial_title)
  WHERE clinical_trial_address NOT ILIKE '%united states%'
);
