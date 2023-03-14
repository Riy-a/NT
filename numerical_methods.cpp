// BISECTION METHOD


#include<bits/stdc++.h>
using namespace std;


double func(double x)
{
	return x*x*x - 5*x + 1;
}


void bisection(double a, double b)
{
	if (func(a) * func(b) >= 0)
	{
		cout << "You have not assumed right a and b\n";
		return;
	}

	double c = a;
	cout<<"enter the number of iteration you want:";
	int no;
	int i=0;
	cin>>no;
	while (i<no)
	{

		c = (a+b)/2;


		if (func(c) == 0.0)
			break;


		else if (func(c)*func(a) < 0)
			b = c;
		else
			a = c;

	i++;
	}
	cout << "The value of root is : " << c;
}


int main()
{

	double a =0, b = 1;
	bisection(a, b);
	return 0;
}


//REGULA FALSI METHOD


#include<bits/stdc++.h>
using namespace std;



double func(double x)
{
	return cos(x) - x*exp(x);
}


void regulaFalsi(double a, double b)
{
	if (func(a) * func(b) >= 0)
	{
		cout << "You have not assumed right a and b\n";
		return;
	}

	double c = a;
	cout<<"enter the numberof iterations :";
	int no;
	cin>>no;

	for (int i=0; i < no; i++)
	{

		c = (a*func(b) - b*func(a))/ (func(b) - func(a));


		if (func(c)==0)
			break;


		else if (func(c)*func(a) < 0)
			b = c;
		else
			a = c;
	}
	cout << "The value of root is : " << c;
}


int main()
{
	double a =0, b = 1;
	regulaFalsi(a, b);
	return 0;
}


// SECANT METHOD


#include <bits/stdc++.h>
using namespace std;

float f(float x)
{

	float f = cos(x) -x*exp(x);
	return f;
}

void secant(float x1, float x2)
{
	float n = 0, xm, x0, c;
	cout<<"enter the number of iterations:";
	int no,i=0;
	cin>>no;
	if (f(x1) * f(x2) < 0) {
		do {

			x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));


			c = f(x1) * f(x0);


			x1 = x2;
			x2 = x0;


			n++;


			if (c == 0)
				break;

		} while (i<no);

		cout << "Root of the given equation=" << x0 << endl;
		cout << "No. of iterations = " << n << endl;
	} else
		cout << "Can not find a root in the given interval";
}


int main()
{
	
	float x1 = 0, x2 = 1;
	secant(x1, x2);
	return 0;
}


// NEWTON RAPHSON METHOD



#include<bits/stdc++.h>
#define EPSILON 0.0001
using namespace std;


double func(double x)
{
	return cos(x) - x*exp(x);
}


double derivFunc(double x)
{
	return -sin(x)-x*exp(x)-exp(x);
}


void newtonRaphson(double x)
{
	double h = func(x) / derivFunc(x);
	while (abs(h) >= EPSILON)
	{
		h = func(x)/derivFunc(x);

		x = x - h;     //for multiplicity  x = x - m*h; where m is muliplicity

	}

	cout << "The value of the root is : " << x;
}


int main()
{
	double x0 = 1;
	newtonRaphson(x0);
	return 0;
}



// GAUSS ELIMINATION METHOD


#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

#define   SIZE   10

using namespace std;

int main()
{
	 float a[SIZE][SIZE], x[SIZE], ratio;
	 int i,j,k,n;


     cout<< setprecision(3)<< fixed;


	 cout<<"Enter number of unknowns: ";
	 cin>>n;


	 cout<<"Enter Coefficients of Augmented Matrix: "<< endl;
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n+1;j++)
		  {
			   cout<<"a["<< i<<"]"<< j<<"]= ";
			   cin>>a[i][j];
		  }
	 }

	 for(i=1;i<=n-1;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   cout<<"Mathematical Error!";
			   exit(0);
		  }
		  for(j=i+1;j<=n;j++)
		  {
			   ratio = a[j][i]/a[i][i];

			   for(k=1;k<=n+1;k++)
			   {
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
		  }
	 }

	 x[n] = a[n][n+1]/a[n][n];

	 for(i=n-1;i>=1;i--)
	 {
		  x[i] = a[i][n+1];
		  for(j=i+1;j<=n;j++)
		  {
		  		x[i] = x[i] - a[i][j]*x[j];
		  }
		  x[i] = x[i]/a[i][i];
	 }


	 cout<< endl<<"Solution: "<< endl;
	 for(i=1;i<=n;i++)
	 {
	  	cout<<"x["<< i<<"] = "<< x[i]<< endl;
	 }

	 return(0);
}


// GAUSS JORDAN METHOD



#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

#define SIZE 10

using namespace std;

int main()
{
		 float a[SIZE][SIZE], x[SIZE], ratio;
		 int i,j,k,n;

         cout<< setprecision(3)<< fixed;


		 cout<<"Enter order of matrix: ";
		 cin>>n;

		 /* 2. Reading Matrix */
		 cout<<"Enter coefficients of Matrix: " << endl;
		 for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=n;j++)
			  {
				   cout<<"a["<< i<<"]"<< j<<"]= ";
                   cin>>a[i][j];
			  }
		 }


		 for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=n;j++)
			  {
				   if(i==j)
				   {
				    	a[i][j+n] = 1;
				   }
				   else
				   {
				    	a[i][j+n] = 0;
				   }
			  }
		 }


		 for(i=1;i<=n;i++)
		 {
			  if(a[i][i] == 0.0)
			  {
				   cout<<"Mathematical Error!";
				   exit(0);
			  }
			  for(j=1;j<=n;j++)
			  {
				   if(i!=j)
				   {
					    ratio = a[j][i]/a[i][i];
					    for(k=1;k<=2*n;k++)
					    {
					     	a[j][k] = a[j][k] - ratio*a[i][k];
					    }
				   }
			  }
		 }

		 for(i=1;i<=n;i++)
		 {
			  for(j=n+1;j<=2*n;j++)
			  {
			   	a[i][j] = a[i][j]/a[i][i];
			  }
		 }

		 cout<< endl<<"Inverse Matrix is:"<< endl;
		 for(i=1;i<=n;i++)
		 {
			  for(j=n+1;j<=2*n;j++)
			  {
			   	cout<< a[i][j]<<"\t";
			  }
			  cout<< endl;
		 }
		 return(0);
}
