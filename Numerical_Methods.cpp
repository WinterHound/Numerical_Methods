//NUMERICAL METHODS

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double bisection_method (int i, int p, int x); 
double regular_falsi (int i, int p, int x);
double newton_raphson (int i, int p, int x); 
double secant_method (int i, int p, int x);
double auto_limit_mn (int x); 
double mtn[1];

double input_equation (double b){
  double equation;
  equation = pow(b,6.0)-8*b - 5;                                                                                  
  return equation;
}

double diff_equation (double b){
  double diff_equation;
  diff_equation = 6*pow(b,5) - 8;                                                                                             
  return diff_equation;
}

int main (int argc, char const *argv[]){
  int s,i,p,x;

  do {
  cout << "\n 1. Bisection Method\n 2. Regular Falsi Method\n 3. Newton Raphson Method\n 4. Secant Method\n 0.Exit\n";
  cin >> s;
  switch (s){

    case 1: 
    cout << "------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t\vBISECTION METHOD : \n\nEnter the number of Irritation and Precision :\n";
    cin >> i >> p;
    bisection_method (i,p,x=0); bisection_method (i,p,x=-10);
    break;

    case 2: 
    cout << "------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t\vREGULAT FLASE METHOD : \n\nEnter the number of Irritation and Precision :\n";
    cin >> i >> p;
    regular_falsi (i,p,x=0); regular_falsi (i,p,x=-10);
    break;

    case 3:
    cout << "------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t\vNEWTON RAPHSON METHOD : \n\nEnter the number of Irritation and Precision :\n";
    cin >> i >> p;
    newton_raphson (i,p,x=0); newton_raphson (i,p,x=-10);
    break;

    case 4: 
    cout << "------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t\vSECANT METHOD : \n\nEnter the number of Irritation and Precision :\n";
    cin >> i >> p;
    secant_method (i,p,x=0); secant_method (i,p,x=-10);
    break;

    default: cout << "Exited\n";} 

  }while(s!=0);  

  return 0; }


//BISECTION METHOD


double bisection_method (int i, int p, int x){  
  double m=0, n=0, r=0, z=0;
    auto_limit_mn(x);
    m = mtn [0]; n = mtn[1];                                                         
    //m = ;n = ;    //For manual interval                                                                                                                                                                                                                                                                                        
  cout << "\nInterval : " << m << "," << n << "\n\v";
  x=0;
  
  do{
      r = (m+n) / 2;                                                                                     
      z = input_equation(r);  
      cout << fixed << setprecision(p) << "Root: " << r << "\t" << "m: " << m << "\t"
                                       << "n: " << n << "\t"<< "z: " << z << "\t"<< endl;    
      if (z < 0) m = r;
        else if (z > 0) n = r;
      x++;
    }while(x<i);
    cout << "\nThe root : " << r << endl;
    cout << "\n------------------------------------------------------------------------------------------------------\n";

    return r;                                                                                                      
}


//REGULAR FALSI METHOD


double regular_falsi (int i, int p, int x){
  double m=0, n=0, r=0, z=0; 

    auto_limit_mn(x);
    m = mtn [0]; n = mtn[1];                                                                                           
    //m = ,n =  ;    //For manual interval                                                                                                           
  double zm = 0,zn = 0; x=0;                                                                                              
  cout << "\nInterval : " << m << "," << n << "\n\v";

  do{
    zm = input_equation(m);
    zn = input_equation(n);
    r = (m*zn-n*zm) / (zn-zm);                                                                             
    z = input_equation(r);
    cout << fixed << setprecision(p) << "Root: "<< r <<"\t"<< "z: " << z << "\t"
                                     << "m: " << m << "\t"<< "zm: " << zm << "\t"
                                     << "n: " << n << "\t"<< "zn: " << zn << endl;
    if (z < 0) m = r;
      else if (z > 0) n = r;
    x++;
  }while (x<i);
  cout << "\nThe root : " << r << endl;
  cout << "\n------------------------------------------------------------------------------------------------------\n";

  return r;
}


//NEWTON RAPHSON METHOD


double newton_raphson (int i, int p, int x){
  double r=0, z=0, Z=0;

    auto_limit_mn(x);
    r = mtn[1]; x=0;
    //r= ;    //For manual interval     
  cout << "\nInterval : " << r << "\n\v";
  
  do{
    z = input_equation(r);
    Z = diff_equation(r);
    cout << fixed << setprecision(p) << "Root: " << r <<"\t"
                                     << "z: " << z << "\t"
                                     << "Z: " << Z << "\t" << endl;
    r = r - (z/Z);                                                                                                        
    x++;
  }while(x<i);
  cout << "\nThe root : " << r << endl;
  cout << "\n------------------------------------------------------------------------------------------------------\n";

  return r;
}


//SECANT METHOD


double secant_method (int i, int p, int x){
  double m=0, n=0, r=0, z=0; 

    auto_limit_mn(x);
    m = mtn [0]; n = mtn[1];
    //m = ,n =  ;    //For manual interval                                                                                                                                                                      
  double zm = 0, zn = 0;                                                                                               
  cout << "\nInterval : " << m << "," << n << "\n\v";
  x=0;

  do{
    zm = input_equation (m);
    zn = input_equation (n);
    r = (m*zn-n*zm) / (zn-zm);                                                                                                                                                            
    z = input_equation(r);
    cout << fixed << setprecision (p) << "Root: "<< r <<"\t"<< "z: " << z << "\t"
                                      << "m: " << m << "\t"<< "zm: " << zm << "\t"
                                      << "n: " << n << "\t"<< "zn: " << zn << endl;
    m = n; n = r;
    x++;
  }while(x<i);
  cout << "\nThe root : " << r << endl;
  cout << "\n------------------------------------------------------------------------------------------------------\n";

  return r;
}


//AUTO INTERVAL


double auto_limit_mn (int x){
    int i=0, j=0, k; double z;
    if (x < 0)k=0;
      else if (x=0)k=11;
    do{ 
      z = input_equation(x);      
      if (z < 0) i = x;
      else if (z > 0) j = x;
      x++;
    }while (!((i < 0)||(j > 0)||(x > k))); 
    mtn [0] = i; mtn [1] = j;

    return mtn[1];
}


//Note : Auto interval gives only two roots. For specifc root enter the intervals manually.









