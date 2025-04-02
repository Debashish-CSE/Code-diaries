from matplotlib import pyplot as plt
import pandas as pd

data_frame = pd.read_csv(r"Matplotlib\Fill_Line_Plots\Developer Salary.csv")

plt.style.use("fivethirtyeight")

Developer_Age = data_frame["Age"]
Python_Dev_Salary = data_frame["Python"]
All_Dev_Salary = data_frame["All_Devs"]
Average_Salary = 45000

plt.plot(
    Developer_Age, Python_Dev_Salary, label="Python", ls=":", color="#603F26", lw=1.5
)
plt.plot(Developer_Age, All_Dev_Salary, label="All_Dev", lw=1.5)


plt.fill_between(
    Developer_Age,
    Python_Dev_Salary,
    All_Dev_Salary,
    where=(Python_Dev_Salary > All_Dev_Salary),
    interpolate=True,
    label="Above All_Dev",
    alpha=0.25,
)
plt.fill_between(
    Developer_Age,
    Python_Dev_Salary,
    All_Dev_Salary,
    where=(Python_Dev_Salary <= All_Dev_Salary),
    interpolate=True,
    label="Below All_Dev",
    alpha=0.75,
)

plt.title("Fill Line Plot")
plt.xlabel("Age")
plt.ylabel("Salary")
plt.legend()
plt.tight_layout()
plt.show()
