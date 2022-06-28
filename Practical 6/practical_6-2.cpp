// Hanoi towers

#include <stdio.h>
#include <math.h>
#include <string.h>


int t, n;
int tot;
int arr[55];

void backtrack(int cur, int pos) {
  if (pos == n) return;
  if (arr[pos] == 0) {
    tot++;
    arr[pos] = cur;
    return backtrack(cur + 1, pos);
  }

  for (int i = 0; i <= pos; i++) {
    int r = sqrt(arr[i] + cur);
    if (r * r == arr[i] + cur) {
      arr[i] = cur;
      tot++;
      return backtrack(cur + 1, pos);
    }
  }

  backtrack(cur, pos + 1);
}

int main()
{
  printf("Enter the test cases numbers :\n");
  scanf("%d", & t);

  while (t--) {
    tot = 0;
    printf("Number Of Pegs :");
    scanf("%d", & n);
    memset(arr, 0, sizeof arr);
    backtrack(1, 0);
    printf("%d\n", tot);
    printf("-------------------\n");

  }
}
