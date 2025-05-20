#include <stdio.h>
#include <sys/time.h>

void towerofhanoi(int n, char A, char B, char C){
  if (n == 1){
    printf("Move disk 1 from %c to %c\n", 'S', 'D');
    return;
  }
  towerofhanoi(n - 1, A, C, B);
  printf("Moved disk %d from %c to %c\n", n, 'S', 'D');
  towerofhanoi(n - 1, C, B, A);
}

int main(){
  struct timeval start, end;
  for (int i = 1; i <= 3; i++){
    gettimeofday(&start, NULL);
    towerofhanoi(i, 'A', 'B', 'C');
    gettimeofday(&end, NULL);
    float time = (end.tv_usec - start.tv_usec)/1000000.0;
    printf("Time taken for %d disks : %f microseconds*\n", i, time);
  }
  return 0;
}