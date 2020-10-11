//
//  main.c
//  Project
//
//  Created by Karnbongkot Boonriong on 18/10/2562 BE.
//  Copyright © 2562 Karnbongkot Boonriong. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
void algebra(void);
void numoperation(void);
void calculator(void);
int clear(void);
int correctinput(char*,int,int);
int inputtrans(char*,int);
void baseconversion(void);
void LCM(void);
void GCD(void);
void solve(void);
void calculus(void);
void probability(void);
void statistics(void);
void matrixmenu(void);
void graph(void);
void valueatpoint(void);
void derivative(void);
void derivativeatpoint(void);
void integral(void);
void tangentline(void);
void factorial(void);
int factorialo(int);
void swap (int*, int*);
void print(int *[]);
void permutation(void);
void permute(int*[], int);
void combination(void);
void combinationUtil(char *[], int, int, int,char *[], int);
void printequation(int[],int);
void printequationdouble(double[],int);
void matrixoperation(int);
void transpose(void);
void trace(void);
void statcal(int);
int menu(void);
char choice;
int n1;

int clear(){
    for(int i=0;i<100;i++)
        printf("\n");
        return 0;
}

int correctinput(char *input,int max,int stat){
    int i =0;
    if(strlen(input)==0)return 0;
    if(strlen(input)==1&&input[0]=='x'){clear(); printf("Goodbye\n\n\n\n\n\n\n\n\n");exit(0);}
    if (stat==1&&input[0]=='-') i=1;
    for (i; i<strlen(input); i++) {
        if (isalpha(input[i])!=0) {
            return 0;
        }
        else if (ispunct(input[i])!=0) {
            return 0;
        }
        else if (isspace(input[i])!=0) {
            return 0;
        }
    }
    if(max>0){
        int x=0;
        x = inputtrans(input, x);
        for (int i = 1; i<=max; i++) {
            if(x == i)
                return 1;
        }
        return 0;
    }
    else
        return 1;
}

int doubleinput(char *input){
    int i =0,count=0;
    if(strlen(input)==0)return 0;
    if(strlen(input)==1&&input[0]=='x'){clear(); printf("Goodbye\n\n\n\n\n\n\n\n\n");exit(0);}
    if (input[0]=='-') i=1;
    for (i; i<strlen(input); i++) {
        if(input[i]=='.') count++;
        if (isalpha(input[i])!=0) {
            return 0;
        }
        else if (ispunct(input[i])!=0&&input[i]!='.')return 0;
        else if (isspace(input[i])!=0) {
            return 0;
        }
    }
    if(count>1)return 0;
    return 1;
}

double doubletrans(char *input,double x){
    char *ptr;
    x = strtod(input, &ptr);
    return x;
}

int inputtrans(char *input,int x){
    int n = strlen(input);
    int i=0;
    int neg = 0;
    if(input[0]=='-'){neg = 1;i=1;}
    x=0;
    for (i; i<n; i++) {
        x+=(int)(input[i]-48)*pow(10,n-i-1);
    }
    if(neg==1)x=-x;
    return x;
}

void calculator(){
    int m1=0,m2=0,input1=0,input2=0;
    double num=0,total=0;
    char choose,howmany,mod1,mod2,fcheck;
    do{
        printf("%40s%26s\n%23s\n%-28s\t%s\n%-28s\t%s\n%-28s\t%s\n%-28s\n%s","*You can always enter 'x' to exit*\n","Calculator","Menu","1.Addition","2.Subtraction","3.Multiplication","4.Division","5.Modulus","6.Power","7.Back","Type the number to enter menu : ");
        gets(&choose);
        clear();
    }while(correctinput(&choose, 7,0)==0||strlen(&choose)!=1);
    input1 =inputtrans(&choose,input1);
    int check=0;
    switch (input1) {
        case 1:
            printf("Addition\n");
            do{
                printf("How many elements ? : ");
                gets(&howmany);
            }while(correctinput(&howmany, 0,0)==0);
            input2 =inputtrans(&howmany,input2);
            for(int i =1;i<=input2;i++){
                do{
                    printf("Enter element number %d : ",i);
                    gets(&fcheck);
                }while(doubleinput(&fcheck)==0);
                num = doubletrans(&fcheck, num);
                total += num;
                num=0;
            }
            printf("\nResult : %lf\n",total);
            break;
        case 2:
            printf("Subtraction\n");
            do{
                printf("How many elements ? : ");
                gets(&howmany);
            }while(correctinput(&howmany, 0,0)==0);
            input2 =inputtrans(&howmany,input2);
            for(int i =1;i<=input2;i++){
                do{
                    printf("Enter element number %d : ",i);
                    gets(&fcheck);
                }while(doubleinput(&fcheck)==0);
                num = doubletrans(&fcheck, num);
                if(i==1){ total=num;continue;}
                total -= num;
                num=0;
            }
            printf("\nResult : %lf\n",total);
            break;
        case 3:
            printf("Multiplication\n");
            do{
                printf("How many elements ? : ");
                gets(&howmany);
            }while(correctinput(&howmany, 0,0)==0);
            input2 =inputtrans(&howmany,input2);
            for(int i =1;i<=input2;i++){
                do{
                    printf("Enter element number %d : ",i);
                    gets(&fcheck);
                }while(doubleinput(&fcheck)==0);
                num = doubletrans(&fcheck, num);
                total *= num;
                num=0;
            }
            printf("\nResult : %lf\n",total);
            break;
        case 4:
            printf("Division\n");
            do{
                printf("How many elements ? : ");
                gets(&howmany);
            }while(correctinput(&howmany, 0,0)==0);
            input2 =inputtrans(&howmany,input2);
            for(int i =1;i<=input2;i++){
                do{
                    printf("Enter element number %d : ",i);
                    gets(&fcheck);
                }while(doubleinput(&fcheck)==0);
                num = doubletrans(&fcheck, num);
                if (i==1) total = num;
                else total /= num;
                num=0;
            }
            printf("\nResult : %lf\n",total);
            break;
        case 5:
            printf("Modulus\n");
            do{
                printf("Enter element number 1 : ");
                gets(&mod1);
                m1 =inputtrans(&mod1,m1);
            }while(correctinput(&mod1, 0,0)==0||m1==0);
            do{
                printf("Enter element number 2 : ");
                gets(&mod2);
                m2 =inputtrans(&mod2,m2);
            }while(correctinput(&mod2, 0,0)==0|| m2==0);
            printf("\nResult : %d\n",m1 % m2);
            break;
        case 6:
            do{
                printf("Enter base : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            num = doubletrans(&fcheck, num);
            do{
                printf("Enter power : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            total = doubletrans(&fcheck, total);
            printf("\nResult : %lf\n",pow(num,total));
            break;
        case 7:
            clear();
            menu();
            return;
            
    }
    printf("Press enter to continue...");
    getchar();
    clear();
    calculator();
}

void baseconversion(){
    int base=0,dec=0,remainder=0,digit=0,x=0,count=0;
    char input1,input2;
    char answer[100];
    printf("Base conversion\n");
    do{
        printf("Enter your decimal number:");
        gets(&input1);
    }while(correctinput(&input1, 0,0)==0);
    dec = inputtrans(&input1, dec);
    do{
        printf("Enter the base to be converted:");
        gets(&input2);
    }while(correctinput(&input2, 0,0)==0);
    base=inputtrans(&input2, base);
    x=dec;
    count=0;
    do
    {
        remainder=x%base;
        digit=48+remainder;
        if(digit>57)
            digit=digit+7;
        answer[count]=digit;
        count++;
        x=x/base;
    }while(x!=0);
    printf("\n%d in base %d is ",dec,base);
    for(int i=count-1;i>=0;i--)
        printf("%c",answer[i]);
    printf(".\nPress enter to continue...");
    getchar();
    clear();
    numoperation();
}

void LCM(){
    int howmany=0,answer=1,x,temp=0,lcm[10];
    char check1,check2;
    printf("Least Common Multiple\n");
    do{
        printf("How many elements ? : ");
        gets(&check1);
    }while(correctinput(&check1, 0,0)==0);
    howmany=inputtrans(&check1, howmany);
    for(int j = 1;j<=howmany;j++){
        do{
            printf("Enter element %d : ",j);
            gets(&check2);
        }while(correctinput(&check2, 0,1)==0);
        lcm[j-1]=inputtrans(&check2, temp);
    }
    while(1){
        x = 0;
        for(int i = 1;i<=howmany;i++){
            if(answer%lcm[i-1]!=0)x++;
            
        }
        if(x!=0)answer++;
        else break;
    }
    printf("\nThe Least Common Multiple of ");
    for(int i =0;i<howmany;i++){
        printf("%d ",lcm[i]);}
    printf("is %d\n",answer);
    printf("Press enter to continue...");
    getchar();
    clear();
    numoperation();
}

void GCD(){
    int howmany=0,answer=1,x = 0,input=0,gcd[10];
    char check1,check2;
    printf("Greatest Common Divisor\n");
    do{
        printf("How many elements ? : ");
        gets(&check1);
    }while(correctinput(&check1, 0,0)==0);
    howmany=inputtrans(&check1, howmany);
    for(int i = 0;i<howmany;i++){
        do{
            printf("Enter element %d : ",i+1);
            gets(&check2);
            gcd[i]=inputtrans(&check2, input);
        }while(correctinput(&check2, 0,1)==0);
        if(gcd[i]>answer) answer=gcd[i];
    }
    
    while(1){
        x=0;

        for(int i = 0;i<howmany;i++){
            if(gcd[i]%answer!=0)x++;
        }
        if(x!=0)answer--;
        else break;
    }
    printf("\nThe Greatest Common Divisor of ");
    for(int i =0;i<howmany;i++)
        printf("%d ",gcd[i]);
    printf("is %d\n",answer);
    printf("Press enter to continue...");
    getchar();
    clear();
    numoperation();
}

void solve(){
    int choose=0;
    double ans1,ans2,ans3,a,b,c,d,e,f,ex,value;
    char input,fcheck;
    printf("Equation Solver\n");
    printf("This program can only solve 4 format of equation\n1. ax + b = c\n2. ax + by + c = 0 and dx + ey + f = 0\n3. ax^2 + bx + c  = 0\n4. ax^3 + bx^2 + cx + d = 0\n");
    do{
        printf("Enter the number of form : ");
        gets(&input);
    }while(correctinput(&input, 0,0)==0);
    choose= inputtrans(&input, choose);
    clear();
    switch (choose) {
        case 1:
            printf("Form of equation : ax + b = c\n");
            do{
                printf("Enter a : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            a = doubletrans(&fcheck, a);
            do{
                printf("Enter b : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            b = doubletrans(&fcheck, b);
            do{
                printf("Enter c : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            c = doubletrans(&fcheck, c);
            ans1 = (c-b)/a;
            printf("\nThe value of x is %lf\n",ans1);
            break;
        case 2:
            printf("Form of equation : ax + by + c = 0 and dx + ey + f = 0\n");
            do{
                printf("Enter a : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            a = doubletrans(&fcheck, a);
            do{
                printf("Enter b : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            b = doubletrans(&fcheck, b);
            do{
                printf("Enter c : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            c = doubletrans(&fcheck, c);
            do{
                printf("Enter d : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            d = doubletrans(&fcheck, d);
            do{
                printf("Enter e : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            e = doubletrans(&fcheck, e);
            do{
                printf("Enter f : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            f = doubletrans(&fcheck, f);
            ans1 = (c-b)/a;
            ans1 = (f*b-c*e)/(a*e-d*b);
            ans2 = (c*d -f*a)/(a*e-d*b);
            printf("\nThe value of x is %lf\nThe value of y is %lf\n",ans1,ans2);
            break;
        case 3:
            printf("Form of equation : ax^2 + bx + c = 0\n");
            do{
                printf("Enter a : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            a = doubletrans(&fcheck, a);
            do{
                printf("Enter b : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            b = doubletrans(&fcheck, b);
            do{
                printf("Enter c : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            c = doubletrans(&fcheck, c);
            ans1 = (-b + sqrt(pow(b,2) - 4*a*c))/2*a;
            ans2 = (-b - sqrt(pow(b,2) - 4*a*c))/2*a;
            printf("\nThe value of x is %lf and %lf\n",ans1,ans2);
            break;
        case 4:
            printf("Form of equation : ax^3 + bx^2 + cx + d = 0\n");
            do{
                printf("Enter a : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            a = doubletrans(&fcheck, a);
            do{
                printf("Enter b : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            b = doubletrans(&fcheck, b);
            do{
                printf("Enter c : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            c = doubletrans(&fcheck, c);
            do{
                printf("Enter d : ");
                gets(&fcheck);
            }while(doubleinput(&fcheck)==0);
            d = doubletrans(&fcheck, d);
            int i = 0;
            while(1){
                ex = a*pow(i,3)+b*pow(i,2)+c*i+d;
                if(ex==0){
                    ans1=i;
                    break;
                }
                ex = a*pow(-i,3)+b*pow(-i,2)+c*(-i)+d;
                if(ex==0){
                    ans1=-i;
                    break;
                }
                i++;
            }
            printf("Root #1 = %lf",ans1);
            b = b + (a*(ans1));
            c = c + (b*(ans1));
            value = (b*b)-(4*a*c);
            if(value>=0){
                ans2 = (-b+sqrt(value))/(2*a);
                ans3 = (-b-sqrt(value))/(2*a);
                printf("\nRoot #2 = %lf\nRoot #3 = %lf",ans2,ans3);
            }
            else{
                value = ((4*a*c)-pow(b,2))/(2*a);
                printf("\nRoot #2 : %f+%fi",((-b)/(2*a)),value);
                printf("\nRoot #3 : %f-%fi",((-b)/(2*a)),value);
            }
        default:
            break;
    }
    printf("Press enter to continue...");
    getchar();
    clear();
    algebra();
}

void printequation(int eq[],int degree){
    for (int i=0;i<=degree; i++) {
        if (eq[i]>0 && i>1) printf("+ %dx^%d ",eq[i],i);
        else if(eq[i]==1&& i>1) printf("+ x^%d ",i);
        else if (eq[i]<0 && i>1) printf("- %dx^%d ",abs(eq[i]),i);
        else if (i==0&&eq[i]>0) printf("%d ",eq[i]);
        else if (i==0&&eq[i]<0) printf("-%d ",abs(eq[i]));
        else if (eq[i]==0) continue;
        else if (i==1 && eq[i]>0) printf("+ %dx ",eq[i]);
        else if (i==1 && eq[i]<0) printf("- %dx ",abs(eq[i]));
        else if (i==1 && eq[i]==1) printf("+ x ");
        
    }
    printf("= 0\n");
}

void printequationdouble(double eq[],int degree){
    for (int i=0;i<=degree; i++) {
        if (eq[i]>0 && i>1) printf("+ %.2lfx^%d ",eq[i],i);
        else if(eq[i]==1&& i>1) printf("+ x^%d ",i);
        else if (eq[i]<0 && i>1) printf("- %.2lfx^%d ",fabs(eq[i]),i);
        else if (i==0&&eq[i]>0) printf("%.2lf ",eq[i]);
        else if (i==0&&eq[i]<0) printf("-%.2lf ",fabs(eq[i]));
        else if (eq[i]==0) continue;
        else if (i==1 && eq[i]>0) printf("+ %.2lfx ",eq[i]);
        else if (i==1 && eq[i]<0) printf("- %.2lfx ",fabs(eq[i]));
        else if (i==1 && eq[i]==1) printf("+ x ");
        
    }
    printf("= 0\n");
}

void valueatpoint(){
    int degree=0,value=0,temp = 0,eq[10];
    double ans = 0;
    char input;
    printf("Find the value at specific point of the equation\n");
    do{
        printf("Enter the highest degree of the equation : ");
        gets(&input);
    }while(correctinput(&input, 0,0)==0);
    degree=inputtrans(&input, degree);
    for(int i=0;i<=degree;i++){
        do{
            printf("Enter x to the power of %d : ",i);
            gets(&input);
        }while(correctinput(&input, 0,1)==0);
        eq[i]=inputtrans(&input, temp);
    }
    printf("\nYour equation is ");
    printequation(eq,degree);
    do{
        printf("Enter the value of x : ");
        gets(&input);
    }while(correctinput(&input, 0,1)==0);
    value = inputtrans(&input, value);
    for(int i=0;i<=degree;i++){
        ans += eq[i]*pow(value, i);
    }
    printf("\nThe value of y at point %d is %lf\n",value,ans);
    printf("Press enter to continue...");
    getchar();
    clear();
    algebra();
}

void derivative(){
    int degree=0,temp1=0,eq[10];
    char input;
    printf("Derivative of a function\n");
    do{
        printf("Enter the highest degree of the equation : ");
        gets(&input);
    }while(correctinput(&input, 0,0)==0);
    degree=inputtrans(&input, degree);
    int degree1 = degree;
    for(int i=0;i<=degree;i++){
        do {
            printf("Enter x to the power of %d : ",i);
            gets(&input);
        }while(correctinput(&input, 0,1)==0);
        eq[i]=inputtrans(&input, temp1);
    }
    printf("\nYour equation is ");
    printequation(eq,degree);
    for (int i=0; i<=degree1; i++) {
            eq[i-1] = eq[i]*i;
    }
    printf("\nDerivative of the function is ");
    printequation(eq, degree1-1);
    printf("Press enter to continue...");
    getchar();
    clear();
    calculus();
}

void derivativeatpoint(){
    int degree=0,value=0,ans=0,temp=0,eq[10];
    char input;
    printf("Derivative of a function at a point\n");
    do{
        printf("Enter the highest degree of the equation : ");
        gets(&input);
    }while(correctinput(&input, 0,0)==0);
    degree = inputtrans(&input, degree);
    int degree1=degree;
    for(int i=0;i<=degree;i++){
        do{
            printf("Enter x to the power of %d : ",i);
            gets(&input);
        }while(correctinput(&input, 0,1)==0);
        eq[i]=inputtrans(&input, temp);
    }
    printf("\nYour equation is ");
    printequation(eq,degree);
    for (int i=0; i<=degree1; i++) {
            eq[i-1] = eq[i]*i;
    }
    printf("\nDerivative of the function is ");
    printequation(eq, degree1-1);
    do{
        printf("Enter the value of x : ");
        gets(&input);
    }while(correctinput(&input, 0,1)==0);
    value = inputtrans(&input, value);
    for(int i=0;i<degree1;i++){
        ans += eq[i]*pow(value, i);
    }
    printf("\nThe value of y' at x = %d is %d\n",value,ans);
    printf("Press enter to continue...");
    getchar();
    clear();
    calculus();
}

void integral(){
    double eqnew[20];
    int temp=0,eq[10],degree=0,degree1=0;
    char input;
    printf("Integral of a function\n");
    do{
        printf("Enter the highest degree of the equation : ");
        gets(&input);
    }while(correctinput(&input, 0,0)==0);
    degree=inputtrans(&input, degree1);
    
    for(int i=0;i<=degree;i++){
        do{
            printf("Enter x to the power of %d : ",i);
            gets(&input);
        }while(correctinput(&input, 0,1)==0);
        eq[i]=inputtrans(&input, temp);
        
    }
    printf("\nYour equation is ");
    printequation(eq,degree);
    for (int i=0; i<=degree+1; i++) {
        eqnew[i+1] = (double)eq[i]/(i+1);
    }
    eqnew[0]=0;
    printf("\nIntegrate of the function (assumed that constant is 'c') is ");
    printf("c ");
    printequationdouble(eqnew,degree+1);
    printf("Press enter to continue...");
    getchar();
    clear();
    calculus();
}

void tangentline(){
    int degree=0,value=0,m=0,y=0,c=0,eq[10],tempin=0;
    char input;
    printf("Tangent Line\n");
    do{
        printf("Enter the highest degree of the equation : ");
        gets(&input);
    }while(correctinput(&input, 0,0)==0);
    degree = inputtrans(&input, tempin);
    int degree1 = degree;
    for(int i=0;i<=degree;i++){
        do{
            printf("Enter x to the power of %d : ",i);
            gets(&input);
            
        }while(correctinput(&input, 0,1)==0);
        eq[i]=inputtrans(&input, eq[i]);
    }
    do{
        printf("Enter the value of x : ");
        gets(&input);
    }while(correctinput(&input, 0,1)==0);
    value = inputtrans(&input, value);
    for(int i=0;i<=degree1;i++){
        y += eq[i]*pow(value, i);
    }
    printf("\nYour equation is ");
    printequation(eq,degree);
    for (int i=0; i<=degree1; i++) {
            eq[i-1] = eq[i]*i;
    }
    for(int i=0;i<degree1;i++){
        m += eq[i]*pow(value, i);
    }
    printf("\nDerivative of the function is ");
    printequation(eq, degree1-1);
    printf("\nThe value of y at x = %d is %d\n",value,y);
    printf("The value of y' at x = %d is %d\n",value,m);
    c = (y - (m*value));
    if(c<0) printf("The equation of the tangent line is y = %dx - %d\n",m,abs(c));
    else printf("The equation of the tangent line is y = %dx + %d\n",m,c);
    printf("Press enter to continue...");
    getchar();
    clear();
    calculus();
}

void factorial(){
    int input=0,ans=0;
    char check;
    printf("Factorial\n");
    do{
        printf("Enter a number : ");
        gets(&check);
    }while(correctinput(&check, 0,0)==0);
    input = inputtrans(&check, input);
    ans = input;
    for(int i = input-1 ; i>0 ; i--){
        ans *= i;
    }
    printf("\n%d! = %d\n",input,ans);
    printf("Press enter to continue...");
    getchar();
    clear();
    probability();
}


int factorialo(int n){
    int ans=0;
    ans = n;
    for(int i = n-1 ; i>0 ; i--){
        ans *= i;
    }
    return ans;
}
void swap (int *x, int *y)
{
    int temp=0;
    temp = *x;
    *x = *y;
    *y = temp;
}

void print(int *v[])
{
    int size = n1;
    if (v != 0) {
        printf("| ");
        for (int i = 0; i < size; i++) {
            printf("%d", v[i] );
            if(i!=size-1)printf(",");
        }
        printf(" ");
  }
}

void permute(int *v[], int x) {
    int i=0;
    if (x == 1) {
        print(v);
    }
    else {
        for (i = 0; i < x; i++) {
            permute(v, x-1);
            if (x % 2 == 1) {
                swap(&v[0],&v[x-1]);
            }
            else {
                swap(&v[i],&v[x-1]);
            }
        }

    }
}
 
void permutation()
{
    int *num[10],temp=0;
    char input;
    printf("Permutations\n");
    do{
        printf("How many elements ? : ");
        gets(&input);
    }while(correctinput(&input, 0,0)==0);
    n1= inputtrans(&input, n1);
    for (int i = 0 ; i < n1; i++){
        do{
            printf("Element number %d : ",i+1);
            gets(&input);
            num[i]=inputtrans(&input, temp);
        }while(correctinput(&input, 0,1)==0);
    }
    printf("\n%d permutations of ",factorialo(n1));
    for (int i = 0 ; i < n1; i++){
        printf("%d",num[i]);
        if(i!=n1-1)printf(",");
    }
    printf(" is ");
    permute(&num, n1);
    printf("\n");
    printf("Press enter to continue...");
    getchar();
    clear();
    probability();
}

void combinationUtil(char *arr[], int n, int r, int index,
                     char *data[], int i){
    static int t=1;
    if (index == r) {
        printf("| ");
        for (int j = 0; j < r; j++){
            printf("%d", data[j]);
            if(j!=r-1)printf(",");
        }
        printf(" ");
        t++;
        return;
    }
    if (i >= n)
        return;
    data[index] = arr[i];
    combinationUtil(arr, n, r, index + 1, data, i + 1);
    combinationUtil(arr, n, r, index, data, i + 1);
}
void combination()
{
    printf("Combination\n");
    int *num[10],n=0,r = 0,temp=0;
    char input;
    do{
        printf("How many elements ? : ");
        gets(&input);
        n=inputtrans(&input, n);
    }while(correctinput(&input, 0,0)==0||n<=1);
    for (int i = 0 ; i < n; i++){
        do{
            printf("Element number %d : ",i+1);
            gets(&input);
        }while(correctinput(&input, 0,1)==0);
        num[i]=inputtrans(&input, temp);
    }
    do{
        printf("How many elements do you want in a combination? : ");
        scanf("%s",&input);
        getchar();
    }while(correctinput(&input,n-1,0)==0);
    r=inputtrans(&input, r);
    printf("\n%d combinations of ",(factorialo(n)/(factorialo(n-r)*factorialo(r))));
    for (int i = 0 ; i < n; i++){
        printf("%d",num[i]);
        if(i!=n-1)printf(",");
    }
    printf(" is ");
    char *data[r];
    combinationUtil(&num, n, r, 0, &data, 0);
    printf("\n");
    printf("Press enter to continue...");
    getchar();
    clear();
    probability();
}

struct coordinate{
    int x;
    int y;
};

void matrixoperation(int choice){
    int k=0,i=0, j=0, m=0, n=0,temp=0;
    char input,check;
    do{
        printf("Enter the row of the matrix : ");
        gets(&input);
    }while(correctinput(&input, 0,0)==0);
    m=inputtrans(&input, m);
    do{
        printf("Enter the column of the matrix : ");
        gets(&input);
    }while(correctinput(&input, 0,0)==0);
    n=inputtrans(&input, n);
    int matrix1[m][n],matrix2[m][n],sum[m][n],sub[m][n],mul[m][n];
    for(k=1;k<=2;k++){
       for (i = 0; i < m; ++i)
       {
           for (j = 0; j < n; ++j)
           {
               do{
                   printf("Matrix %d Row %d Column %d : ",k,i+1,j+1);
                   if(k==1){
                       gets(&check);
                       matrix1[i][j]=inputtrans(&check, temp);
                   }
                   else if (k==2){
                       gets(&check);
                       matrix2[i][j]=inputtrans(&check, temp);
                   }
               }while(correctinput(&check, 0,1)==0);
           }
       }
    }
    for(k=1;k<=2;k++){
        printf("Matrix %d\n",k);
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                    if(k==1) printf("%3d", matrix1[i][j]);
                    else if (k==2) printf("%3d", matrix2[i][j]);
            }
            printf("\n");
        }
    }
    switch (choice) {
        case 1:
            printf("\nThe addition result is\n");
            for (i = 0; i < m; i++){
                for (j = 0; j < n; j++){
                    sum[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            for (i = 0; i < m; i++){
                for (j = 0; j < n; j++){
                    printf("%3d", sum[i][j]) ;
                }
                printf("\n");
            }
            break;
        case 2:
            printf("\nThe subtraction result is\n");
            for (i = 0; i < m; i++){
                for (j = 0; j < n; j++){
                    sub[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    printf("%3d", sub[i][j]) ;
                }
                printf("\n");
            }
            break;
        case 3:
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    mul[i][j] = 0;
                    for (k = 0; k < n; k++)
                    {
                        mul[i][j] = mul[i][j] + matrix1[i][k] * matrix2[k][j];
                    }
                }
            }
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    printf("%3d", mul[i][j]) ;
                }
                printf("\n");
            }
            break;
    }
    printf("Press enter to continue...");
    getchar();
    clear();
    matrixmenu();
}

void transpose(){
    char input,check;
    int i=0, j=0, m=0, n=0,temp=0;
    printf("Matrix Transpose\n");
    do{
        printf("Enter the row of the matrix : ");
        gets(&input);
    }while(correctinput(&input, 0,0)==0);
    m=inputtrans(&input, m);
    do{
        printf("Enter the column of the matrix : ");
        gets(&input);
    }while(correctinput(&input, 0,0)==0);
    n=inputtrans(&input, n);
    int matrix[m][n];
       for (i = 0; i < m; ++i)
       {
           for (j = 0; j < n; ++j)
           {
                do{
                   printf("Row %d Column %d : ",i+1,j+1);
                    gets(&check);
                    matrix[i][j]=inputtrans(&check, temp);
               }while(correctinput(&check, 0,1)==0);
           }
       }
       printf("\nThe given matrix is \n");
       for (i = 0; i < m; ++i)
       {
           for (j = 0; j < n; ++j)
           {
               printf("%3d", matrix[i][j]);
           }
           printf("\n");
       }
       printf("\nTranspose of matrix is \n");
       for (j = 0; j < n; ++j)
       {
           for (i = 0; i < m; ++i)
           {
               printf("%3d", matrix[i][j]);
           }
           printf("\n");
    }
    printf("Press enter to continue...");
    getchar();
    clear();
    matrixmenu();
}

void trace(){
    char input,check;
    int i=0, j=0, m=0,trace=0,temp=0;
    do{
        printf("Enter the row and column of the matrix (Only a square matrix can be trace) : ");
        gets(&input);
    }while(correctinput(&input, 0,0)==0);
    m=inputtrans(&input, m);
    int matrix[m][m];
       for (i = 0; i < m; ++i)
       {
           for (j = 0; j < m; ++j)
           {
               do{
                   printf("Row %d Column %d : ",i+1,j+1);
                   gets(&check);
                   matrix[i][j]=inputtrans(&check, temp);
               }while(correctinput(&check, 0,1)==0);
           }
       }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i == j)
            {
                trace = trace + matrix[i][j];
            }
        }
    }
    printf("\nTrace of the matrix is = %d\n", trace);
    printf("Press enter to continue...");
    getchar();
    clear();
    matrixmenu();
}

void statcal(int choice){
    char input,fcheck;
    double sum = 0, mean=0,t=0,median=0,mode=0,variance=0, sumsqr=0, deviation=0,std_deviation=0,temp=0;
    int count=0,num=0,max=0,checkout=0;
    int SIZE=0,check=0,choose=choice;
    double listmax[SIZE];
    do{
        printf("Enter size : ");
        gets(&input);
    }while(correctinput(&input, 0,0)==0);
    SIZE=inputtrans(&input, SIZE);
    double list[SIZE];
    for(int i=0; i<SIZE; i++){
        do{
            printf("Enter value number %d : ",i+1);
            gets(&fcheck);
        }while(doubleinput(&fcheck)==0);
        list[i] = doubletrans(&fcheck, temp);
    }
    switch (choose) {
        case 1:
            for(int i=0; i<SIZE; i++)
              sum = sum + list[i];
            mean = sum/SIZE;
            printf("\nThe mean is %lf\n",mean);
            break;
        case 2:
            for(int i=1; i<=SIZE-1; i++)
            {
              for(int j=1; j<SIZE-i; j++)
              {
                if (list[j] <= list[j+1])
                {
                  t=list[j];
                  list[j]=list[j+1];
                  list[j+1]=t;
                }
                else
                continue;
              }
            }
            for(int i=1; i<=SIZE; i++)
            printf("\n%lf ",list[i]);
            if(SIZE%2 == 0)
              median = (list[SIZE/2] + list[SIZE/2+1])/2.0;
            else
              median = list[SIZE/2 + 1];
            printf("\nThe median is %lf\n",median);
            break;
        case 3:
            for (int i = 0; i < SIZE; ++i) {
               int count = 0;
               for (int j = 0; j < SIZE; ++j) {
                  if (list[j] == list[i])
                  ++count;
               }
               if (count >= max) {
                  max = count;
                  listmax[checkout] = list[i];
                   checkout++;
               }
            }
            for (int i=0; i<=checkout; i++) {
                for (int j=0; j<=checkout; j++) {
                    if((listmax[i]==listmax[j])&&(j!=i)){
                        listmax[j]=0;
                        checkout-=1;
                    }
                }
            }
            printf("\nThe mode is ");
            for(int i=0;i<=checkout;i++){
                if(listmax[i]!=0)printf("%lf ",listmax[i]);
            }
            printf("\n");
            break;
        case 4:
            for(int i=0; i<n1; i++)
              sum = sum + list[i];
            mean = sum/(SIZE);
            for(int i=1; i<=SIZE; i++)
            {
              deviation = list[i] - mean;
              sumsqr += deviation*deviation;
            }
            variance = sumsqr/SIZE;
            printf("\nThe variance is %lf\n",variance);
            break;
        case 5:
            for(int i=0; i<SIZE; i++)
              sum = sum + list[i];
            mean = sum/SIZE;
            for(int i=1; i<=SIZE; i++)
            {
              deviation = list[i] - mean;
              sumsqr += deviation*deviation;
            }
            variance = sumsqr/SIZE;
            std_deviation = sqrt(variance);
            printf("\nThe standard deviation is %lf",std_deviation);
            break;
    }
    printf("Press enter to continue...");
    getchar();
    clear();
    statistics();
}


void numoperation(){
    char choose;
    int input=0;
    do{
        printf("%46s%35s\n%29s\n%-28s\t%s\n%-28s\t%s\n%s","*You can always enter 'x' to exit*\n","Number Operation","Menu","1.Base Conversion","2.Least Common Multiple","3.Greatest Common Divisor","4.Back to Menu","Type the number to enter menu : ");
        gets(&choose);
        clear();
    }while(correctinput(&choose, 4,0)==0||strlen(&choose)!=1);
    input =inputtrans(&choose,input);
    switch (input) {
        case 1:
            baseconversion();
            break;
        case 2:
            LCM();
            break;
        case 3:
            GCD();
            break;
        case 4:
            menu();
            break;
        default:
            break;
    }
}

void algebra(){
    char choose;
    int input=0;
    do{
        printf("%36s%21s\n%19s\n%-18s\t%s\n%-18s\n%s","*You can always enter 'x' to exit*\n","Algebra","Menu","1.Equation Solver","2.Value at point","3.Back to Menu","Type the number to enter menu : ");
        gets(&choose);
        clear();
    }while(correctinput(&choose, 3,0)==0||strlen(&choose)!=1);
    input =inputtrans(&choose,input);
    switch (input) {
        case 1:
            solve();
            break;
        case 2:
            valueatpoint();
            break;
        case 3:
            menu();
            break;
        default:
            break;
    }
}

void calculus(){
    char choose;
    int input=0;
    do{
        printf("%40s%25s\n%23s\n%-24s\t%s\n%-24s\t%s\n%-24s\n%s","*You can always enter 'x' to exit*\n","Calculus","Menu","1.Derivative","2.Derivative at Point","3.Integral","4.Tangent Line","5.Back to Menu","Type the number to enter menu : ");
        gets(&choose);
        clear();
    }while(correctinput(&choose, 5,0)==0||strlen(&choose)!=1);
    input =inputtrans(&choose,input);
    switch (input) {
        case 1:
            derivative();
            break;
        case 2:
            derivativeatpoint();
            break;
        case 3:
            integral();
            break;
        case 4:
            tangentline();
            break;
        case 5:
            menu();
            break;
        default:
            break;
    }
}

void probability(){
    char choose;
    int input=0;
    do{
        printf("%36s%23s\n%19s\n%-18s\t%s\n%-18s\t%s\n%s","*You can always enter 'x' to exit*\n","Probability","Menu","1.Factorial","2.Permutations","3.Combinations","4.Back to Menu","Type the number to enter menu : ");
        gets(&choose);
        clear();
    }while(correctinput(&choose, 4,0)==0||strlen(&choose)!=1);
    input =inputtrans(&choose,input);
    switch (input) {
        case 1:
            factorial();
            break;
         case 2:
            permutation();
            break;
        case 3:
            combination();
            break;
        case 4:
            menu();
            break;
        default:
            break;
    }
}

void statistics(){
    char choose;
    int input=0;
    do{
        printf("%36s%22s\n%19s\n%-21s\t%s\n%-21s\t%s\n%-21s\t%s\n%s","*You can always enter 'x' to exit*\n","Statistics","Menu","1.Mean","2.Median","3.Mode","4.Variance","5.Standard Deviation","6.Back to Menu","Type the number to enter menu : ");
        gets(&choose);
        clear();
    }while(correctinput(&choose, 6,0)==0||strlen(&choose)!=1);
    input =inputtrans(&choose,input);
    switch (input) {
        case 6:
            menu();
            break;
        default:
            statcal(input);
            break;
    }
}

void matrixmenu(){
    int input=0;
    char choose;
    do{
        printf("%36s%20s\n%19s\n%-18s\t%s\n%-18s\t%s\n%-18s\t%s\n%s","*You can always enter 'x' to exit*\n","Matrix","Menu","1.Addition","2.Subtraction","3.Multiplication","4.Trace","5.Transpose","6.Back to Menu","Type the number to enter menu : ");
        gets(&choose);
        clear();
    }while(correctinput(&choose, 6,0)==0||strlen(&choose)!=1);
    input =inputtrans(&choose,input);
    switch (input) {
        case 4:
            trace();
            break;
        case 5:
            transpose();
            break;
        case 6:
            menu();
            break;
        default:
            matrixoperation(input);
            break;
    }
}

void graph(){
    printf("Graphs\n*You can always enter 'x' to exit*\n");
    int degree=0,temp=0,choice=0,eq[20];
    struct coordinate list[102];
    char input;
    FILE *file;
    do{
        printf("Enter the highest degree of the equation : ");
        gets(&input);
    }while(correctinput(&input, 0,0)==0);
    degree=inputtrans(&input, degree);
    for(int i=0;i<=degree;i++){
        do {
            printf("Enter x to the power of %d : ",i);
            gets(&input);
        }while(correctinput(&input, 0,1)==0);
        eq[i]=inputtrans(&input, temp);
    }
    printf("Your equation is ");
    printequation(eq,degree);
    int count = 0;
    for(int i = -50 ; i<=50;i++){
        list[count].x = i;
        temp = eq[0];
        for(int j=1;j<=degree;j++){
            temp  +=  eq[j]*pow(i,j);
        }
        list[count].y = temp;
        count++;
    }
    do{
        printf("Due to the limit of the screen, this program can only show 50 units of x\n");
        printf("Which quadrant ?\n1 for (+,+)\n2 for (-,+)\n3 for (-,-)\n4 for (-,+)\n");
        do{
            printf("Enter your choice : ");
            gets(&input);
        }while(correctinput(&input, 4,0)==0);
        choice = inputtrans(&input, choice);
        int plus = 0;
        switch (choice) {
            case 1:
                file = fopen("quadrant1.txt", "w");
                fprintf(file, "Quadrant 1\n");
                for (int i = 50; i>=0; i--) {
                    fprintf(file, "|");
                    for (int j = 100; j>=51; j--){
                        if (list[j].y == i) {
                            for (int k = 0 ; k < list[j].x; k++) {
                                fprintf(file,"   ");
                            }
                            fprintf(file,"+  (%d,%d)",list[j].x,list[j].y);
                        }
                    }
                    fprintf(file,"\n");
                }
                fprintf(file, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------");
                fclose(file);
                printf("Your graph has been saved as quadrant1.txt\n");
                break;
            case 2:
                file = fopen("quadrant2.txt", "w");
                fprintf(file, "Quadrant 2");
                for (int i = 50; i>=0; i--) {
                    plus = 0;
                    for (int j = 0; j<=49; j++){
                        if (list[j].y == i) {
                            for (int k = 0 ; k < plus ; k++) {
                                fprintf(file,"   ");
                            }
                            fprintf(file,"+  (%d,%d)",list[j].x,list[j].y);
                        }
                        plus++;
                    }
                    fprintf(file,"\n");
                }
                fprintf(file, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------");
                fclose(file);
                printf("Your graph has been saved as quadrant2.txt\n");
                break;
            case 4:
                file = fopen("quadrant4.txt", "w");
                fprintf(file, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------");
                fprintf(file, "Quadrant 4\n");
                for (int i = 0; i>=-50; i--) {
                    fprintf(file, "|");
                    for (int j = 100; j>=51; j--){
                        if (list[j].y == i) {
                            for (int k = 0 ; k < list[j].x; k++) {
                                fprintf(file,"   ");
                            }
                            fprintf(file,"+  (%d,%d)",list[j].x,list[j].y);
                        }
                    }
                    fprintf(file,"\n");
                }
                fclose(file);
                printf("Your graph has been saved as quadrant4.txt\n");
                break;
            case 3:
                file = fopen("quadrant3.txt", "w");
                fprintf(file, "Quadrant 3");
                fprintf(file, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------");
                for (int i = 0; i>=-50; i--) {
                    plus = 0;
                    for (int j = 0; j<=49; j++){
                        if (list[j].y == i) {
                            for (int k = 0 ; k < plus ; k++) {
                                fprintf(file,"   ");
                            }
                            fprintf(file,"+  (%d,%d)",list[j].x,list[j].y);
                        }
                        plus++;
                    }
                    fprintf(file,"\n");
                }
                fclose(file);
                printf("Your graph has been saved as quadrant3.txt\n");
                break;
        }
        do{
            printf("Want another quadrant ? (Yes : 1 \\ No : 2) :");
            gets(&input);
        }while(correctinput(&input, 2, 0)==0||strlen(&input)!=1);
        choice=inputtrans(&input, choice);
    }while(choice==1);
    printf("\n");
    printf("Press enter to continue...");
    getchar();
    clear();
    menu();
}

int menu(){
    char choose;
    int input=0;
    do{
        printf("%34s\n%19s\n%-18s\t%s\n%-18s\t%s\n%-18s\t%s\n%-18s\t%s\n%-18s\n%s","Advanced Mathematics Calculator","Menu","1.Calculator","2.Number Operation","3.Algebra","4.Calculus","5.Probability","6.Statistics","7.Matrix","8.Graphs","9.Exit","Type the number to enter menu : ");
        gets(&choose);
        clear();
    }while(correctinput(&choose, 9,0)==0||strlen(&choose)!=1);
    input =inputtrans(&choose,input);
    switch (input) {
        case 1:
            calculator();
            break;
        case 2:
            numoperation();
            break;
        case 3:
            algebra();
            break;
        case 4:
            calculus();
            break;
        case 5:
            probability();
            break;
        case 6:
            statistics();
            break;
        case 7:
            matrixmenu();
            break;
        case 8:
            graph();
            break;
        case 9:
            printf("Goodbye.\n\n\n\n\n\n\n");
            exit(0);
            return 0;
    }
    return 0;
}

int main(){
    menu();
    return 0;
}

