#include<stdio.h>
#include<math.h>

float calcEMI(float p,float r,float m){
    printf("your Principal amount is    \t %.2f\n",p);
    printf("your Rate of Interest is    \t %.0f %\n",r);
    printf("your Total month for due is \t %.0f Months\n",m);
    int intr = (p*m*r)/(12*100);
    return (p/m)+intr;
}
void main(){
    int pamt,nmonths;
    float ri = 2.0;
    printf("Enter Principal Amount\n");
    scanf("%d",&pamt);
    printf("number of month for due\n");
    scanf("%d",&nmonths);
    printf("your EMI for Per Month is   \t %.2f\n\n\n\n\n\n\n\n",calcEMI(pamt,ri,nmonths));
}