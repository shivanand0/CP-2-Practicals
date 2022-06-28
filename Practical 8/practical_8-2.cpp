//ferry loading

#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

#define MAXN 201
#define MAXL 100001
#define EMPTY (-1)


class state
{
public:
    int current, left, right;
    state() {}
    state(int incurrent, int inleft, int inright)
    { current = incurrent; left = inleft; right = inright; }
    ~state() { }

    bool operator<(const state & other) const
    {
        return (current == other.current ?
            (left == other.left ? right < other.right :
            left < other.left) : current < other.current);
    }

    bool operator==(const state & other) const
    {
        return (current == other.current && left == other.left
            && right == other.right);
    }
};

set < state > cache;
bool port[MAXN + 1], answer[MAXN + 1];
int cars[MAXN + 1], nCars, maxCars;

void backtrack(int current, int left, int right)
{
    
    if (cache.count(state(current, left, right)) > 0)
        return;
    cache.insert(state(current, left, right));

   
    int carLength = cars[current];
    if (current > nCars || carLength > max(left, right))
    {
        if ((current - 1) > maxCars)
        {
            maxCars = current - 1;
            memcpy(answer, port, sizeof(port));
        }

        return;
    }

    // 回溯。
    if (carLength <= left)
    {
        port[current] = true;
        backtrack(current + 1, left - carLength, right);
    }

    if (carLength <= right)
    {
        port[current] = false;
        backtrack(current + 1, left, right - carLength);
    }
}

void solve_by_backtrack(void)
{
    int cases, ferryLength, carLength;
    bool printBoredBlankLine = false;

    cin >> cases;
    while (cases--)
    {
        if (printBoredBlankLine)
            cout << endl;
        else
            printBoredBlankLine = true;

        cin >> ferryLength;
        ferryLength *= 100;

        nCars = 1;
        while (cin >> carLength, carLength)
        {
            if (nCars < MAXN)
                cars[nCars++] = carLength;
        }
        nCars--;

        maxCars = 0;
        cache.clear();
        backtrack(1, ferryLength, ferryLength);

        cout << maxCars << endl;
        for (int i = 1; i <= maxCars; i++)
            cout << (answer[i] ? "port" : "starboard") << endl;
    }
}

bool memo[MAXN + 1][MAXL + 1];
int choice[MAXN + 1][MAXL + 1];
int sumLength[MAXN + 1];

void solve_by_dynamic_programming(void)
{
    int cases, ferryLength, carLength;
    bool printBoredBlankLine = false;

    cin >> cases;
    while (cases--)
    {
        if (printBoredBlankLine)
            cout << endl;
        else
            printBoredBlankLine = true;

        cin >> ferryLength;
        ferryLength *= 100;

        nCars = 1;
        sumLength[0] = 0;
        while (cin >> carLength, carLength)
        {
            if (nCars < MAXN)
            {
                cars[nCars] = carLength;
                sumLength[nCars] = sumLength[nCars - 1] + carLength;
                nCars++;
            }
        }
        nCars--;

        pair < int, int > longest;

        memset(memo, false, sizeof(memo));
        memset(choice, EMPTY, sizeof(choice));

        memo[0][0] = true;
        for (int i = 0; i < nCars; i++)
            for (int j = 0; j <= ferryLength; j++)
                if (memo[i][j])
                {
                    if ((j + cars[i + 1]) <= ferryLength)
                    {
                        memo[i + 1][j + cars[i + 1]] = true;
                        choice[i + 1][j + cars[i + 1]] = 1;
                        longest = make_pair(i + 1, j + cars[i + 1]);
                    }

                    if ((sumLength[i] - j + cars[i + 1]) <= ferryLength)
                    {
                        memo[i + 1][j] = true;
                        choice[i + 1][j] = 0;
                        longest = make_pair(i + 1, j);
                    }
                }

        cout << longest.first << endl;
        string solution;
        for (int i = longest.first, j = longest.second; i > 0 &&
                        choice[i][j] != EMPTY; i--)
        {
            solution = (choice[i][j] ? "port\n" : "starboard\n" ) + solution;
            if (choice[i][j])
                j -= cars[i];
        }
        cout << solution;
    }
}

int main(int ac, char *av[])
{
   solve_by_dynamic_programming();

    return 0;
}
