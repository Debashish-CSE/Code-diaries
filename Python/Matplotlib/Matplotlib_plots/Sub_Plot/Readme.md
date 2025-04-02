# IPL Data Subplot Visualization

This script creates subplots using Matplotlib to visualize IPL (Indian Premier League) data, specifically comparing home and away match statistics for different teams. The chart provides insights into the performance of teams in home and away matches.

## Code Explanation

### Importing Libraries

```python
from matplotlib import pyplot as plt
import pandas as pd
```

- `pyplot` from `matplotlib` is imported as `plt` to create and customize plots.
- `pandas` is imported as `pd` for data handling, particularly for reading the IPL data from a CSV file.

### Reading and Preparing Data

```python
data_frame = pd.read_csv(r"Matplotlib\Sub_Plot\IPL.csv")

Teams = data_frame["team"][:5]
Home_Matches = data_frame["home_matches"][:5]
Home_Wins = data_frame["home_wins"][:5]
Away_Matches = data_frame["away_matches"][:5]
Away_Wins = data_frame["away_wins"][:5]
```

- `pd.read_csv()` reads the IPL data from the CSV file located at `"Matplotlib\Sub_Plot\IPL.csv"` and stores it in a DataFrame called `data_frame`.
- `Teams`, `Home_Matches`, `Home_Wins`, `Away_Matches`, and `Away_Wins` extract the first five rows of the respective columns to be used for plotting.

### Creating the Subplots

#### Subplot 1: Home Matches and Wins

```python
plt.subplot(2, 1, 1)
plt.plot(Teams, Home_Wins, marker=".", label="Home Wins", ls=":")
plt.plot(Teams, Home_Matches, marker=".", label="Home Matches")
plt.legend()
```

- `plt.subplot(2, 1, 1)` creates the first subplot in a 2x1 grid layout (2 rows, 1 column). This subplot occupies the first position.
- `plt.plot(Teams, Home_Wins, marker=".", label="Home Wins", ls=":")` plots the number of home wins for each team with dotted lines and markers.
- `plt.plot(Teams, Home_Matches, marker=".", label="Home Matches")` plots the total number of home matches for each team.
- `plt.legend()` adds a legend to identify the plotted lines.

#### Subplot 2: Away Matches and Wins

```python
plt.subplot(2, 1, 2)
plt.scatter(Teams, Away_Wins, marker=".", label="Away Wins", ls=":")
plt.scatter(Teams, Away_Matches, marker=".", label="Away Matches", lw=1)
plt.legend()
```

- `plt.subplot(2, 1, 2)` creates the second subplot in the same 2x1 grid layout, placing it in the second position.
- `plt.scatter(Teams, Away_Wins, marker=".", label="Away Wins", ls=":")` creates a scatter plot showing the number of away wins for each team.
- `plt.scatter(Teams, Away_Matches, marker=".", label="Away Matches", lw=1)` creates a scatter plot showing the total number of away matches for each team.
- `plt.legend()` adds a legend to this subplot as well.

### Customizing and Displaying the Plot

```python
plt.suptitle("IPL Data")
plt.tight_layout()
plt.show()
```

- `plt.suptitle("IPL Data")` sets the overall title for the entire figure.
- `plt.tight_layout()` adjusts the layout to prevent overlapping of the subplots, ensuring a neat presentation.
- `plt.show()` displays the final visualization.

## Conclusion

This script generates a figure with two subplots that compare the performance of IPL teams in home and away matches. The first subplot focuses on home matches, while the second subplot highlights away matches, allowing for a clear comparison of team performances in different scenarios.

---