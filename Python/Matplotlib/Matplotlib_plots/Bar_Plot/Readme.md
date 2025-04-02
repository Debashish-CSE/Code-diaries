# Most Popular Programming Languages Visualization

## Code Explanation

### Importing Libraries

```python
import pandas as pd
from collections import Counter
from matplotlib import pyplot as plt
```

- `pandas` is imported as `pd` for data manipulation and reading the CSV file.
- `Counter` is imported from Python's `collections` module to count the occurrences of each programming language.
- `matplotlib.pyplot` is imported as `plt` for creating visualizations.

### Style Customization

```python
plt.style.use("Solarize_Light2")
```

- `plt.style.use("Solarize_Light2")` sets the plot style to "Solarize_Light2," giving the plot a specific color scheme and design.

### Reading Data from CSV

```python
data_frame = pd.read_csv(r"Matplotlib\Bar_Plot\data.csv")
```

- `pd.read_csv()` reads the data from the CSV file located at `"Matplotlib\Bar_Plot\data.csv"` and stores it in a DataFrame called `data_frame`.

### Extracting and Counting Programming Languages

```python
Language_Response = data_frame["LanguagesWorkedWith"]

Language_Counter = Counter()
for response in Language_Response:
    Language_List = response.split(";")
    Language_Counter.update(Language_List)
```

- `Language_Response` extracts the column `LanguagesWorkedWith` from the DataFrame, which contains the programming languages used by each respondent.
- `Language_Counter = Counter()` initializes an empty `Counter` object to store the frequency of each programming language.
- The `for` loop iterates through each response, splits the string into individual languages using `split(";")`, and updates the `Language_Counter` with each language.

### Finding the Top 10 Languages

```python
Top_Language = Language_Counter.most_common(10)
```

- `Language_Counter.most_common(10)` returns a list of the top 10 most common programming languages and their counts, stored in `Top_Language`.

### Preparing Data for Plotting

```python
Languages = []
Used_By = []
for i in Top_Language:
    Languages.append(i[0])
    Used_By.append(i[1])

Languages.reverse()
Used_By.reverse()
```

- `Languages` and `Used_By` lists are created to store the top 10 languages and their respective usage counts.
- The `for` loop iterates through `Top_Language`, appending the language names to `Languages` and their counts to `Used_By`.
- The `reverse()` method is called on both lists to reverse their order so that the most popular languages appear at the top of the bar chart.

### Defining Color Scheme

```python
Color_Scheme = [
    "#A2CCB0",
    "#79B3B3",
    "#A1B8AE",
    "#55806E",
    "#84C6BB",
    "#6EA28E",
    "#8EA69C",
    "#5C8777",
    "#6AA5A0",
    "#95BFB2",
]
```

- `Color_Scheme` defines a list of hex color codes to be used for the bars in the bar chart, ensuring a visually appealing and consistent color palette.

### Plotting the Data

```python
plt.barh(Languages, Used_By, color=Color_Scheme)
plt.xlabel("Languages")
plt.ylabel("Used By")
plt.title("Most Popular Languages")
```

- `plt.barh()` creates a horizontal bar chart using `Languages` and `Used_By`.
- `color=Color_Scheme` applies the defined color scheme to the bars.
- `plt.xlabel()` sets the label for the x-axis as "Languages."
- `plt.ylabel()` sets the label for the y-axis as "Used By."
- `plt.title()` sets the title of the plot as "Most Popular Languages."

### Final Plot Adjustments

```python
plt.tight_layout()
plt.show()
```

- `plt.tight_layout()` adjusts the padding between the plot elements to prevent overlap and ensure a clean layout.
- `plt.show()` displays the final plot on the screen.

## Conclusion

This script provides a visualization of the top 10 most popular programming languages based on survey data. By using `Counter` from the `collections` module and Matplotlib, the script effectively counts the frequency of each language and displays the results in a well-organized horizontal bar chart.
