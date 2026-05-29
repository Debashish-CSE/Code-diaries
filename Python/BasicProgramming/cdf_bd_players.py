import os
import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.add_subplot(111)

lnst = ["-", "--", "-.", ":", "-", "--", "-.", ":"]
marks = ["^", "d", "o", "v", "p", "s", "<", ">"]
# marks_size = [15, 17, 10, 15, 17, 10, 12, 15]
marks_size = [2, 2, 10, 15, 17, 10, 12, 15]
marker_color = [
  '#0F52BA',
  '#ff7518',
  '#6CA939',
  '#e34234',
  '#756bb1',
  'brown',
  '#c994c7',
  '#636363',
]


def collect_runs(records, years):
  """Read run data files for each player and year and populate records.

  Tries several common data locations ("data", "cricketdata") and supports
  tab- or whitespace-separated rows. Returns (records, max_run).
  """
  max_run = -1

  for player in records:
    for year in years:
      # try several likely file locations/patterns
      candidates = [
        os.path.join("data", player, "years", f"{year}.txt"),
        os.path.join("data", player, f"{year}.txt"),
        os.path.join("cricketdata", player, "years", f"{year}.txt"),
        os.path.join("cricketdata", player, f"{year}.txt"),
        os.path.join(player, "years", f"{year}.txt"),
        os.path.join(player, f"{year}.txt"),
      ]

      path = None
      for cand in candidates:
        if os.path.exists(cand):
          path = cand
          break
      if not path:
        continue

      with open(path, "r", encoding="utf-8") as fr:
        # ignore header
        fr.readline()
        for line in fr:
          line = line.strip()
          if not line:
            continue

          # support tab-separated or whitespace-separated rows
          if "\t" in line:
            parsed = line.split("\t")
          else:
            parsed = line.split()

          if len(parsed) <= 5:
            continue

          run = parsed[5].strip()
          if not run or run == "-":
            continue
          if "*" in run:
            run = run.split("*")[0]
          try:
            run = int(run)
          except (ValueError, TypeError):
            continue

          records[player]["runs"].append(run)
          if run > max_run:
            max_run = run

  return records, max_run

def initialize(players):
    records = {}
    for player in players:
        records[player] = {"runs": []}
    return records



def calculate_cdf(records, player):
    runs = records[player]["runs"]
    sm = len(runs)
    if sm == 0:
        # nothing to compute, return zeros for counts
        return [0.0] * len(records[player]["count"]) if records[player].get("count") else []

    for run in runs:
        # ensure index exists in count
        records[player]["count"][run] += 1.0

    cdf = []
    prev = 0.0
    for i in range(len(records[player]["count"])):
        prob = (records[player]["count"][i] / sm) + prev
        prev = prob
        cdf.append(prob)

    return cdf


def graph(players, records):
    index = 0
    for player in players:
        dist = calculate_cdf(records, player)
        if not dist:
            index += 1
            continue

        line_obj = plt.plot(range(len(dist)), dist)[0]
        mc = marker_color[index % len(marker_color)]
        stl = lnst[index % len(lnst)]
        mk = marks[index % len(marks)]

        plt.setp(line_obj, color=mc, linewidth=3, ls=stl)
        index += 1

    for label in ax.get_xticklabels():
        label.set_fontsize(17)
    for label in ax.get_yticklabels():
        label.set_fontsize(17)

    plt.title("Mushfiq VS Tamim VS Kohli", fontsize=20)
    plt.xlabel("Runs", fontsize=18)
    plt.ylabel("CDF", fontsize=18)
    plt.grid(True)
    plt.legend(players, loc=0, fontsize=20)
    plt.show()


if __name__ == "__main__":
    players = ["mushfiq", "tamim", "kohli"]
    years = ["2015", "2016", "2017", "2018", "2019"]

    records = initialize(players)
    records, max_run = collect_runs(records, years)
    missing = []
    if max_run < 0:
      # no runs found for any player
      for player in records:
        records[player]["count"] = []
        if not records[player]["runs"]:
          missing.append(player)
    else:
      for player in records:
        if records[player]["runs"]:
          records[player]["count"] = [0.0] * (max_run + 1)
        else:
          records[player]["count"] = []
          missing.append(player)

    if missing:
      print("Warning: no run data found for:", ", ".join(missing))

    # only plot players that have data
    plotted_players = [p for p in players if records[p]["runs"]]
    if not plotted_players:
      print("No data to plot.")
    else:
      graph(plotted_players, records)




