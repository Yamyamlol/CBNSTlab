#include<stdio.h>

// this is hardcode for the given equation and the code executes the equation
double equation(double a){
	return ((a*a*a)-2*a-5);
}

// abs function will make the value absolute
double absolute(double b){
    if(b<0) b = -b;
    return b;
}

int main(){

    printf("NAME:\t\t\tSANYAM RAWAT\nUNIVERSITY ROLL NUMBER:\t2021414\nSECTION:\t\tD\nCLASS ROLL NUMBER:\t 58\n");
    double x0, x1, x2, e, r0, r1, r2;

    // taking proper inputs here
    do {
        printf("Guess Value: ");
        scanf("%lf%lf", &x0, &x1);
        printf("Approximate Value: ");
        scanf("%lf", &e);

        // r0 and r1 stores the result for some value of x in the given equation using our function
        r0 = equation(x0);
        r1 = equation(x1);

        // if one of the result is greater than 0 while the other is less that means the values of x are incorrect hence we take another input
        if(r0 > 0 && r1 < 0 || r0 < 0 && r1 > 0)
            break;
        else
            printf("Your Values are not in range. Write correct values!\n");
    } while(1);
    printf("S.No. \t\tx0\t\t\tx1\t\t\tx2 \n");
    int i = 0;
    while(1){
        ++i;
        // x2 stores the average value of the result
        x2= (x0 + x1)/2;

        // r2 will store the result for the value of x as x2
		r2=equation(x2);
        // if absolute value of r2 is less than the error or r2 is equal to 0 we got our root hence we break
        if(absolute(r2) < e)
            break;
        if(r0 * r2 == 0)
            break;
        
        // if the product of r2 and r0 is greater than 0 that means we need to make x0 equal to x2;
        else if (r0*r2>0)
			x0=x2;
        // if the product of r2 and r0 is greater than 0 that means we need to make x1 equal to x2;
		else if (r0*r2<0)
			x1=x2;
        printf("%d\t\t%lf\t\t %lf\t\t %lf \n",i, x0, x1, x2);
    }
    printf("final approximate root is %lf\n", x2);

    return 0;
}
