// The necklace

#include <iostream> 
#include <string.h>

#define maxcolors 50 
using namespace std;
struct node {
  int index;
  node * next;
};

struct graph {
  node * nodes[maxcolors + 1];
  node * headnodes[maxcolors + 1];
  int degree[maxcolors + 1];
};

bool visitededge[maxcolors][maxcolors];
int result[maxcolors];

graph g;

bool dfs(int n, int startnode, int currentnode, int k) {
  result[k] = currentnode;
  if ((k == n) && (startnode == currentnode)) return true;
  node * cur = g.nodes[currentnode];
  while (cur -> next != NULL) {
    if (!visitededge[currentnode][cur -> next -> index]) {
      visitededge[currentnode][cur -> next -> index] = true;
      visitededge[cur -> next -> index][currentnode] = true;
      if (dfs(n, startnode, cur -> next -> index, k + 1)) return true;
      else {
        visitededge[currentnode][cur -> next -> index] = false;
        visitededge[cur -> next -> index][currentnode] = false;
      }
    }
    cur = cur -> next;
  }
  return false;
}

bool solve(int n, int startnode) {
  for (int i = 0; i < maxcolors + 1; i++)
    if (g.degree[i] % 2 != 0) return false;
  return dfs(n, startnode, startnode, 0);
}

void insertnode(int color1, int color2) {
  g.degree[color1]++;
  g.degree[color2]++;
  node * nhead1 = g.headnodes[color1];
  node * nhead2 = g.headnodes[color2];
  nhead1 -> next = new node();
  nhead1 -> next -> index = color2;
  nhead1 -> next -> next = NULL;
  nhead2 -> next = new node();
  nhead2 -> next -> index = color1;
  nhead2 -> next -> next = NULL;
  g.headnodes[color1] = nhead1 -> next;
  g.headnodes[color2] = nhead2 -> next;
}

void init(int n) {
  for (int i = 0; i < n; i++) {
    g.nodes[i] = new node();
    g.nodes[i] -> index = i;
    g.nodes[i] -> next = NULL;
    g.headnodes[i] = g.nodes[i];
    g.degree[i] = 0;
  }
}

void printresult(int n) {
  for (int i = 0; i < n; i++) cout << result[i] << " " << result[i + 1] << endl;
}

int main() {
  int cases, n, color1, color2, temp;
  cin >> cases;
  init(maxcolors + 1);
  for (int z = 1; z <= cases; z++) {
    cin >> n;
    memset(g.degree, 0, sizeof(g.degree));
    temp = -1;
    for (int i = 0; i < n; i++) {
      cin >> color1 >> color2;
      if (temp == -1) temp = color1;
      insertnode(color1, color2);
    }
    memset(visitededge, false, sizeof(visitededge));
    cout << "Case #" << z << endl;
    if (!solve(n, temp)) cout << "some beads may be lost" << endl;
    else printresult(n);
    if ((n > 1) && (z != cases)) cout << endl;
  }
  return 0;
}