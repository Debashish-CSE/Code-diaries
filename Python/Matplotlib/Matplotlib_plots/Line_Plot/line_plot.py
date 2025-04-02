import matplotlib.pyplot as plt
import pandas as pd

data_frame = pd.read_csv("Matplotlib\Line_Plot\IPL.csv")

# print(plt.style.available)
plt.style.use("fivethirtyeight")
# plt.xkcd()

teams = data_frame["team"][:7]
home_wins = data_frame["home_wins"][:7]
away_wins = data_frame["away_wins"][:7]

plt.plot(
    teams,
    home_wins,
    marker="o",
    linewidth=1,
    ls=":",
    mec="#16325B",
    mfc="#FFDC7F",
    label="Home",
    color="#A04747",
)
plt.plot(
    teams,
    away_wins,
    marker=".",
    linewidth=1,
    ls="-.",
    label="Away",
    color="#0C1844",
)

plt.xlabel("Teams")
plt.ylabel("Matches")
plt.title("IPL")

plt.tight_layout()
plt.legend()
plt.show()
