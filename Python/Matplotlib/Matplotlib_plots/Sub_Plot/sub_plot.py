from matplotlib import pyplot as plt
import pandas as pd

plt.style.use("fivethirtyeight")

data_frame = pd.read_csv(r"Matplotlib\Sub_Plot\IPL.csv")

Teams = data_frame["team"][:5]
Home_Matches = data_frame["home_matches"][:5]
Home_Wins = data_frame["home_wins"][:5]
Away_Matches = data_frame["away_matches"][:5]
Away_Wins = data_frame["away_wins"][:5]

plt.subplot(2, 1, 1)
plt.plot(Teams, Home_Wins, marker=".", label="Home Wins", ls=":")
plt.plot(Teams, Home_Matches, marker=".", label="Home Matches", lw=1)
plt.legend()

plt.subplot(2, 1, 2)
plt.scatter(Teams, Away_Wins, marker=".", label="Away Wins", ls=":")
plt.scatter(Teams, Away_Matches, marker=".", label="Away Matches", lw=1)
plt.legend()

plt.suptitle("IPL Data")
plt.tight_layout()
plt.show()
