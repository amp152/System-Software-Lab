# Sequential file allocation
#include <stdio.h>
int main() {
  int n, i, fnam;
  printf("Enter the no of files: ");
  scanf("%d", &n);
  int blk[n], sta[n], ts[n],
      loc[n][50]; // blk : no of blocks occupied
                  // sta : Starting block   ts : Temporary address
  loc[1][1] = 0;
  for (i = 0; i < n; i++) {
    int flag = 1;
    printf("\nFile %d \n", i + 1);
    printf("Enter the number of blocks occupied: ");
    scanf("%d", &blk[i]);
    printf("Enter the staring block:");
    scanf("%d", &sta[i]);
    ts[i] = sta[i];
    for (int j = 0; j < blk[i]; j++) {
      loc[i][j] = sta[i]++;
    }
    for (int x = 0; x < i; x++) {    //To check whether allocation is possible
      for (int k = 0; k <= blk[i]; k++) {
        if (loc[x][k] == ts[i]) {
          printf("%d\t", loc[x][k]);
          printf("Allocation not possible");
          i = i - 1;
          break;
        } else {
          continue;
        }
      }
    }
  }
  printf("\nFilename \tNo of blocks \tStarting block\t\n");
  for (i = 0; i < n; i++) {
    printf("%d\t\t\t\t%d\t\t\t\t%d\n", i + 1, blk[i], ts[i]);
  }
  printf("\nEnter file name: ");				//To show file and its allocation
  scanf("%d", &fnam);
  printf("Number of blocks required: %d \n", blk[fnam - 1]);
  printf("Number of blocks occupied: ");
  for (int j = 0; j < blk[fnam - 1]; j++) {
    printf("%d\t", loc[fnam - 1][j]);
  }
}
