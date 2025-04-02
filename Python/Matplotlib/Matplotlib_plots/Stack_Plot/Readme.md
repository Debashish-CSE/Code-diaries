
---

# Temperature Data Stack Plot Visualization

This script creates a stack plot using Matplotlib to visualize temperature data over a period of five days. The chart shows how the temperature changes across different times on each day.

## Code Explanation

### Importing Libraries

```python
from matplotlib import pyplot as plt
import pandas as pd
```

- `pyplot` from `matplotlib` is imported as `plt` for creating and customizing plots.
- `pandas` is imported as `pd` for handling and manipulating data, specifically for reading the CSV file containing temperature data.

### Reading and Preparing Data

```python
data_frame = pd.read_csv(r"Matplotlib\Stack_Plot\temperature_data.csv")
X_Axis = data_frame["Time"]
X_Axis = sorted(set(X_Axis))
```

- `pd.read_csv()` reads the temperature data from the CSV file located at `"Matplotlib\Stack_Plot\temperature_data.csv"` and stores it in a DataFrame called `data_frame`.
- `X_Axis` is set to the "Time" column from the DataFrame, representing the time of day when the temperature was recorded.
- `X_Axis = sorted(set(X_Axis))` sorts the time data and removes duplicates to prepare the x-axis for the stack plot.

### Extracting Temperature Data for Each Day

```python
September_1 = data_frame[data_frame["Date"] == "September-1"]["Temperature"].tolist()
September_2 = data_frame[data_frame["Date"] == "September-2"]["Temperature"].tolist()
September_3 = data_frame[data_frame["Date"] == "September-3"]["Temperature"].tolist()
September_4 = data_frame[data_frame["Date"] == "September-4"]["Temperature"].tolist()
September_5 = data_frame[data_frame["Date"] == "September-5"]["Temperature"].tolist()
```

- These lines extract the temperature data for each day (September 1 to September 5) by filtering the DataFrame based on the "Date" column. The temperatures for each day are converted to a list using the `tolist()` method.

### Defining Color Schemes and Labels

```python
Color_Schemes = ["#FF6347", "#39FF14", "#00FFFF", "#FFF44F", "#FF69B4"]
Label = ["September_1", "September_2", "September_3", "September_4", "September_5"]
```

- `Color_Schemes` is a list of hex color codes that will be used to color the different areas in the stack plot, with each color corresponding to a specific day.
- `Label` is a list of labels for each day, which will be used in the legend to identify the different layers of the stack plot.

### Creating the Stack Plot

```python
plt.stackplot(
    X_Axis,
    September_1,
    September_2,
    September_3,
    September_4,
    September_5,
    labels=Label,
    colors=Color_Schemes,
)
```

- `plt.stackplot()` creates a stack plot with the following parameters:
  - `X_Axis` provides the x-axis values (time).
  - `September_1`, `September_2`, `September_3`, `September_4`, and `September_5` provide the y-values for each day, creating stacked areas in the plot.
  - `labels=Label` assigns the corresponding labels to each stacked area.
  - `colors=Color_Schemes` applies the defined color scheme to the stacked areas.

### Customizing and Displaying the Plot

```python
plt.xlabel("Time")
plt.ylabel("Temperature")
plt.title("My Stack Chart")

plt.legend()
plt.tight_layout()
plt.show()
```

- `plt.xlabel("Time")` sets the label for the x-axis as "Time."
- `plt.ylabel("Temperature")` sets the label for the y-axis as "Temperature."
- `plt.title("My Stack Chart")` sets the title of the plot to "My Stack Chart."
- `plt.legend()` adds a legend to the chart, displaying the labels for each day in the stack plot.
- `plt.tight_layout()` adjusts the layout to prevent overlap and ensure a clean presentation.
- `plt.show()` displays the final stack plot.

## Conclusion

This script generates a stack plot to visualize the temperature changes over five days at different times. The stack plot effectively shows the contribution of each day's temperature data to the overall chart, with different colors and labels making it easy to distinguish between the days.

---