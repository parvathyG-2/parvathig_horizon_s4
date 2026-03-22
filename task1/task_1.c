#include<stdio.h>
#include<math.h>

int main() {
    float x1,x2,y1,y2;
    float s,u,a,topSpeed;
    float s_acc,t_top,tr,t_total;
    float t,discriminant;
/*s_acc=distance covered while accelerating
  s=distance
  t_top= time to reach top speed
  tr= time for remaining distance at topSpeed
  t_total=
  u=initial velocity
  a=acceleration
  topSpeed=maximum allowed speed
  */


printf("Enter the coordinates of origin x1 and y1:\n");
scanf("%f %f",&x1,&y1);

printf("Enter the coordinates of destination x2 and y2:\n");
scanf("%f %f",&x2,&y2);

printf("Enter the value of initial velocity (SI unit):\n");
scanf("%f",&u);

printf("enter the value of acceleration (SI unit):\n");
scanf("%f",&a);

printf("Enter the top speed (SI unit)\n");
scanf("%f",&topSpeed);


//validation : initial velocity should not be negative
if(u<0){
    printf("Initial velocity cannot be negative. \n");
    return 0;
}

//validation:acceleration should not be negative
else if(a<0){
    printf(" acceleration cannot be negative. \n");
    return 0;
}

//validation:maximum allowed speed must be positive
else if(topSpeed <= 0) {
    printf("topSpeed must be greater than zero. \n");
    return 0;
}

//calculate the distance between the two points by using formula s=sqrt((x2-x1)^2+(y2-y1)^2)
s = sqrt(pow(x2-x1,2)+pow(y2-y1,2));

//check if the distance is zero,then time is zero
if(s==0){
    printf("Distance is zero then time=0\n");
    return 0;
}


//checking cases
//case 1: no acceleration
if(a==0){

    //no initial velocity,motion is not possible
    if(u==0){
        printf("rover cannot move \n");
        return 0;
    }

        //initial velocity limits to maximum allowed speed
    if(u>topSpeed){
        printf("initial velocity exceeds topSpeed,limit it");
        u=topSpeed;
    }

    //find the time using time=distance/velocity
    t_total=s/u;
}


//case 2:accn is not equal to zero
else {
     
   //initial velocity limits to maximum allowed speed
 if(u>topSpeed){
        printf("initial velocity exceeds topSpeed,limit it");
        u=topSpeed;
    }


    //Time required to reach top speed
    if(topSpeed>u){
        t_top=(topSpeed-u)/a;
    }
    else{
        t_top=0;

    }

    //distance covered during acceleration phase 
    s_acc=(u * t_top) + (0.5 * a * pow(t_top,2));


    //case 2.1:rover reaches maximum allowed speed before covering total distance
    if(s_acc < s){

        //time to travel remaining distance 
        tr = (s - s_acc)/topSpeed;

        //total time= accelerating time + time taken to travel remaining distance (constant speed)
        t_total = t_top + tr;

    }

    //case 2.2:rover does not reach max speed after covering the total distance 
    else{

        /*using the formula, distance = ut+1/2at^2
        convert into quadratic form Ax^2+Bx+C=0
        and the discriminant= B^2-4AC
        here  A=u,B=a/2,C=s
        and find t to solve the quadratic formula
       discriminant = pow(u,2)-(4*(a/2)*(-s));*/
       discriminant = u*u + 2*a*s;

       //discriminant is neg then the value of t gets imaginary value
       if(discriminant<0){
             printf("NO real value exists \n");
             return 0;
       }

       //solve quadratic eqn for time
       t = (-u + sqrt(discriminant))/a;


       //time cannot be negative
       if(t<0){
             printf("Negative value of time is not valid \n");
             return 0;
       }

       //total time when top speed not reached
       t_total = t;
    }


}

//outputs
    printf("\ndistance from origin to destination =%f m\n",s);
    printf("Total time required =  %f seconds\n",t_total);
    return 0;
}
