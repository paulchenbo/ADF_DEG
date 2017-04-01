#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define ANGLE_DIFF(diff, x2, x1) \
do {  \
    diff = x2-x1+180; \
    if (diff < 0) {  \
        diff = diff + 360 - 180;  \
    } else if (diff > 360) {  \
        diff = diff - 360 - 180;  \
    } else {  \
        diff = diff - 180;  \
    }  \
} while(0)

float angle_avg(int *unsignedDegangle, int n)
{
    float diff = 0;
    float last = unsignedDegangle[0];
    float sum  = unsignedDegangle[0];
    int i = 0;

    for (i=1; i<n; i++) {
        /* diff = mod(angle[i]-angle[i-1]+180,360)-180 */
        ANGLE_DIFF(diff, unsignedDegangle[i], unsignedDegangle[i-1]);
        last += diff;   //a0+(a1-a0) diff
        sum  += last;   //a0+diff
    }
    while(sum>=360)
    {
        sum=sum-360;
    }
    return sum*1.0/n;
}

float angle_avg(int *angle, int n);
int main()
{
   int angle[5]={1,1,359,359,5};
   int adf_lock=1;
   float avg_ang;
   avg_ang=angle_avg(angle,5);
   if (avg_ang>=180)
       avg_ang=avg_ang-360;
 //  if ((abs(avg_ang)<20)&&(adf_lock==1))
       printf("失锁 : %f\n", avg_ang); //输出测量累积误差
  // else
  //     printf("锁定          %d\n",angle[1]);
}

