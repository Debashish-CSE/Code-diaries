from matplotlib import pyplot as plt
import pandas as pd

plt.style.use("fivethirtyeight")
data_frame = pd.read_csv(r"Matplotlib\Stack_Plot\temperature_data.csv")
X_Axis = data_frame["Time"]
X_Axis = sorted(set(X_Axis))

September_1 = data_frame[data_frame["Date"] == "September-1"]["Temperature"].tolist()
September_2 = data_frame[data_frame["Date"] == "September-2"]["Temperature"].tolist()
September_3 = data_frame[data_frame["Date"] == "September-3"]["Temperature"].tolist()
September_4 = data_frame[data_frame["Date"] == "September-4"]["Temperature"].tolist()
September_5 = data_frame[data_frame["Date"] == "September-5"]["Temperature"].tolist()

Color_Schemes = ["#FF6347", "#39FF14", "#00FFFF", "#FFF44F", "#FF69B4"]

Label = ["September_1", "September_2", "September_3", "September_4", "September_5"]

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

plt.xlabel("Time")
plt.ylabel("Temperature")
plt.title("My Stack Chart")

plt.xticks(rotation=45)

plt.legend()
plt.tight_layout()
plt.show()
