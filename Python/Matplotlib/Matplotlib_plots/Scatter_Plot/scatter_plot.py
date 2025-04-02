from matplotlib import pyplot as plt
import pandas as pd
import numpy as np

plt.style.use("fivethirtyeight")
# print(plt.style.available)

data_frame = pd.read_csv(r"Matplotlib/Scatter_Plot/YT_Data.csv")
Views = data_frame["View_Count"]
Likes = data_frame["Likes"]
Ratio = data_frame["Ratio"]

Size = 100 * np.random.rand(len(Views))

plt.scatter(
    Views, Likes, edgecolors="#8D493A", c=Ratio, cmap="summer", alpha=0.75, lw=1, s=Size
)

plt.colorbar(label="Like/Dislike Ratio")

plt.tight_layout()
plt.xlabel("Views")
plt.ylabel("Likes")
plt.title("Customized Scatter Plot")
plt.show()
