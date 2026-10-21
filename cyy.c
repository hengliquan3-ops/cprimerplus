#include<stdio.h>
int main(){
    printf("请输入水的夸脱数：");
    double n;
    scanf("%lf",&n);
    int water=950;
    double a_water=3.0e-23;
    double num;
    num=n*water/a_water;
    printf("%e",num);

    return 0;
}