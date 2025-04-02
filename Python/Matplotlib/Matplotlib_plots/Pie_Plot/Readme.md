
---
# Pie Chart Visualization

This script creates a pie chart using Matplotlib to visualize the usage of different programming languages. The chart highlights the proportions of each language based on the number of users.

## Code Explanation

### Importing Libraries

```python
from matplotlib import pyplot as plt
```

- `pyplot` from `matplotlib` is imported as `plt` for creating and customizing plots.

### Setting Plot Style

```python
plt.style.use("Solarize_Light2")
```

- `plt.style.use("Solarize_Light2")` applies the "Solarize_Light2" style to the plot, which provides a specific color scheme and design for the pie chart.

### Data Preparation

```python
Used_By = [59219, 55466, 47544, 36443, 35917]
Languages = ["JavaScript", "HTML/CSS", "SQL", "Python", "Java"]
Color = ["#FFB6C1", "#ADD8E6", "#98FF98", "#FFDAB9", "#C8A2C8"]
Explode = [0.1, 0, 0, 0, 0]
```

- `Used_By` is a list containing the number of users for each programming language.
- `Languages` is a list of programming languages corresponding to the values in `Used_By`.
- `Color` is a list of hex color codes used to color each slice of the pie chart.
- `Explode` is a list that specifies the fraction of the radius by which to offset each slice. In this case, only the first slice ("JavaScript") is slightly exploded (offset) to highlight it.

### Creating the Pie Chart

```python
plt.pie(
    Used_By,
    colors=Color,
    labels=Languages,
    explode=Explode,
    shadow=True,
    autopct="%1.1f%%",
)
```

- `plt.pie()` creates a pie chart with the following parameters:
  - `Used_By` provides the data for the sizes of the pie slices.
  - `colors=Color` applies the specified colors to the slices.
  - `labels=Languages` adds labels to each slice.
  - `explode=Explode` slightly offsets the first slice to highlight it.
  - `shadow=True` adds a shadow effect to the pie chart for better visualization.
  - `autopct="%1.1f%%"` displays the percentage value of each slice on the chart, formatted to one decimal place.

### Customizing and Displaying the Plot

```python
plt.title("My Pie Chart")
plt.legend()
plt.tight_layout()
plt.show()
```

- `plt.title("My Pie Chart")` sets the title of the pie chart.
- `plt.legend()` adds a legend to the chart, displaying the language names and their corresponding colors.
- `plt.tight_layout()` adjusts the layout to prevent overlap and ensure a clean presentation.
- `plt.show()` displays the final pie chart.

## Conclusion

This script generates a pie chart to visualize the distribution of users among different programming languages. By customizing the chart's appearance with colors, explode effects, and percentage labels, the script provides a clear and visually appealing representation of the data.

---