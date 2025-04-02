from matplotlib import pyplot as plt

plt.style.use("fivethirtyeight")
# plt.xkcd()

Used_By = [59219, 55466, 47544, 36443, 35917]
Languages = ["JavaScript", "HTML/CSS", "SQL", "Python", "Java"]
Color = ["#FFB6C1", "#ADD8E6", "#98FF98", "#FFDAB9", "#C8A2C8"]
Explode = [0.1, 0, 0, 0, 0]

plt.pie(
    Used_By,
    colors=Color,
    labels=Languages,
    explode=Explode,
    shadow=True,
    autopct="%1.1f%%",
)


plt.title("My Pie Chart")
plt.legend()
plt.tight_layout()
plt.show()
