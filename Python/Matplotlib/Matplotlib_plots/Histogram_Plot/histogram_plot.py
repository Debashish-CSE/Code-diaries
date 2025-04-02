from matplotlib import pyplot as plt
import pandas as pd
import numpy as np

plt.style.use("fivethirtyeight")

data_frame = pd.read_csv(r"Matplotlib\Histogram_Plot\olympics_dataset.csv")
participating_year = data_frame["Year"]
participating_year = np.array(participating_year)

bins = list(range(1896, 2024, 4))
# bins = [1896, 1900, 1904, 1908, 1912, 1916, 1920, 1924, 1928, 1932, 1936, 1940, 1944, 1948, 1952, 1956, 1960, 1964, 1968, 1972, 1976, 1980, 1984, 1988, 1992, 1996, 2000, 2004, 2008, 2012, 2016, 2020, 2024]
median_year = 1960

plt.hist(
    participating_year,
    bins=bins,
    edgecolor="black",
    alpha=0.75,
    # log=True,
)

plt.axvline(median_year, color="#3EC70B", lw=2, label="Year Median")

plt.xlabel("Olympic Year")
plt.ylabel("Participation")
plt.title("Histrogram Plotting")

plt.legend()
plt.tight_layout()
plt.show()