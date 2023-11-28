#include <stdio.h>
#define N 100

int main()
{
    int a[N];
    int n, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a+i) ;
    scanf("%d", &b);

    int i = 0;
    int j = n - 1;
   //Invariant: b possibly in a[i ... j]
   while (b != a[(i + j)/2] && i != j){
       if (b > a[(i + j) / 2]) i = (i + j)/2 + 1;
       else j = (i + j)/2 - 1;
   }
   //Post-condition: b possibly in a[i ... j] && (b == a[(i + j)/2] || i == j)

   if (b == a[(i + j)/2]) printf("%d\n", (i + j)/2);
   else printf("%d\n", -1);

   return 0;
}