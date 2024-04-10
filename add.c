#include <bits/stdc++.h>
using namespace std;

//#define ORIG
#define BRANCH_PRAGMA
//#define CODE_OPT
//#define WITHOUT_IF
long rand_partsum(int n)
{
  int i,k;
  long sum = 0;
  int *vec = (int*) malloc(n * sizeof(int));

#ifdef ORIG
  for (i = 0; i < n; i++)
    vec[i] = rand()%n;

  for (k = 0; k < 1000000; k++)
    for (i = 0; i < n; i++)
      if (vec[i] > n/2)
	      sum += vec[i];
#endif

#ifdef BRANCH_PRAGMA
  for (i = 0; __builtin_expect(i < n, 1); i++)
    vec[i] = rand()%n;

  for (k = 0; __builtin_expect(k < 1000000, 1); k++)
    for (i = 0; __builtin_expect(i < n, 1); i++)
      if (vec[i] > n/2, 1)
	      sum += vec[i];
#endif

#ifdef CODE_OPT
  for (i = 0; i < n; i++) {
    vec[i] = rand()%n;

    if (vec[i] > n/2)
	      sum += vec[i] * 1000000;
  }
#endif
#ifdef WITHOUT_IF
  for (i = 0; i < n; i++)
    vec[i] = rand()%n;

  for (k = 0; k < 1000000; k++)
    for (i = 0; i < n; i++)
	      sum += (vec[i] > n/2) * vec[i];
#endif

  return sum;
}

int main(){
  srand(0);
	printf("%ld\n", rand_partsum(2000));
}
