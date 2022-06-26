// The grand dinner

#include <iostream> 
#include <algorithm> 
#include <cstring>

using namespace std;
#define MAXTEAMS 70
#define MAXTABLES 50
#define UNSOLVABLE 0
#define SOLVABLE 1

struct team {
  int number;
  int nmembers;
};

bool cmp(team x, team y) {
  return x.nmembers > y.nmembers;
}

int main(int ac, char * av[]) {
  team teams[MAXTEAMS];
  int capacity[MAXTABLES];
  int nteams, ntables, ntemp;
  bool seat[MAXTABLES][MAXTEAMS];

  while (cin >> nteams >> ntables, nteams || ntables) {
    int maxMembers = 0;
    for (int i = 0; i < nteams; i++) {
      cin >> ntemp;
      if (maxMembers < ntemp) maxMembers = ntemp;
      teams[i].number = i;
      teams[i].nmembers = ntemp;
    }

    for (int i = 0; i < ntables; i++) cin >> capacity[i];

    if (nteams == 0) {
      cout << SOLVABLE << "\n";
      continue;
    }

    if (ntables == 0 || maxMembers > ntables) {
      cout << UNSOLVABLE << "\n";
      continue;
    }

    sort(teams, teams + nteams, cmp);
    bool sitting = true;
    memset(seat, false, sizeof(seat));
    for (int i = 0; i < nteams; i++) {
      ntemp = teams[i].nmembers;
      for (int j = 0; j < ntables && ntemp; j++)
        if (capacity[j]) {
          ntemp--;
          capacity[j]--;
          seat[j][teams[i].number] = true;
        }

      if (ntemp) {
        sitting = false;
        break;
      }
    }

    cout << (sitting ? SOLVABLE : UNSOLVABLE) << "\n";
    if (sitting) {
      for (int i = 0; i < nteams; i++) {
        int blank = 0;
        for (int j = 0; j < ntables; j++)
          if (seat[j][i])
            cout << (blank++ ? " " : "") << (j + 1);
        cout << "\n";
      }
    }
  }

  return 0;
}