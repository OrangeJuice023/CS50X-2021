# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000
two = 2
uno = 1


def main():

    # Ensure correct usage
    if len(sys.argv) != two:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    with open(sys.argv[uno]) as csvcontenstant:
        reading = csv.DictReader(csvcontenstant)
        for row in reading:
            row["rating"] = int(row["rating"])
            teams.append(row)
        print(teams)

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    for battles in range(N):
        win_times = simulate_tournament(teams)
        if win_times in counts:
            counts[win_times] = counts[win_times] + uno
        else:
            counts[win_times] = uno

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = uno / (uno + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), two):
        if simulate_game(teams[i], teams[i + uno]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + uno])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    matchups = len(teams)
    if matchups > two:
        winners = simulate_round(teams)
        victor = simulate_tournament(winners)
    else:
        victor = simulate_round(teams)
        return victor[0]['team']

    return victor


if __name__ == "__main__":
    main()
