# https://realpython.com/python-counter/
import pandas as pd
from collections import Counter
from matplotlib import pyplot as plt

plt.style.use("Solarize_Light2")
# plt.style.use("fivethirtyeight")
data_frame = pd.read_csv(r"Matplotlib\Bar_Plot\data.csv")

Language_Response = data_frame["LanguagesWorkedWith"]

Language_Counter = Counter()
for response in Language_Response:
    Language_List = response.split(";")
    Language_Counter.update(Language_List)

Top_Language = Language_Counter.most_common(10)

Languages = []
Used_By = []
for i in Top_Language:
    Languages.append(i[0])
    Used_By.append(i[1])

Languages.reverse()
Used_By.reverse()
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

plt.barh(Languages, Used_By, color=Color_Scheme)
plt.xlabel("Languages")
plt.ylabel("Used By")
plt.title("Most Popular Languages")

plt.tight_layout()
plt.show()
