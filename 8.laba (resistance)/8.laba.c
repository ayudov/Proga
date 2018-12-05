#include <stdio.h>
#include <math.h>

int q;
int j;
float r1, r2, f1, f2, f, x, df, Z1, Z2,  w, a, b, c, d, ff, C, L;
char exitchar;
	main()
{
char tmp;
int i;
do
{	system ("cls");
	intro();
	choose_circuit();
	if (q==1)
	{
		enter_R1();
		enter_L();
		enter_C();
		enter_fmin();
		enter_fmax();
		enter_df(); 
		if (df==0)
		{
			calc_f0();
			f=f1;
			w=2*M_PI*f;
			f+=df;	
			
			a=L/C;
			b=r1/(w*C)*(-1);
			c=r1;
			d=w*L-1/(w*C);
			
			Z1=(a*c-b*d)/(c*c+d*d);
			Z2=(b*c-a*d)/(c*c+d*d);
			printf("f=%g Hertz  ", f);
			printf("Z=%g+i*(%g)Ohm\n", Z1, Z2);			
		}
		else 
		{
			calc_f0();calc_1();
		}
	}
	else if (q==2)
	{
		enter_R1();
		enter_L();
		enter_C();
		enter_fmin();
		enter_fmax();
		enter_df();
		if (df==0)
		{
			calc_f0();
			f=f1;
			w=2*M_PI*f;
			printf("f=%g Hertz; ", f);
			f+=df;	
			
			a=L/C;
			b=(r1/(w*C));
			c=r1;
			d=w*L-1/(w*C);
		
			Z1=(a*c+b*d)/(c*c+d*d);
			Z2=(b*c-a*d)/(c*c+d*d);
			printf("Z=%g+i*(%g)Ohm\n", Z1, Z2);		
		}
		else 
		{
			calc_f0();calc_2();
		}
	}
	else if (q==3)
	{
		enter_R1();
		enter_R2();
		enter_L();
		enter_C();
		enter_fmin();
		enter_fmax();
		enter_df();
		if (df==0)
		{
			calc_f0();
			f=f1;
			w=2*M_PI*f;
			printf("f=%g Hertz; ", f);
			f+=df;
			
			a=r1*r2;
			b=r1*(w*L-1/(w*C));
			c=r1+r2;
			d=w*L-1/(w*C);
			
			Z1=(a*c+b*d)/(c*c+d*d);
			Z2=(b*c-a*d)/(c*c+d*d);
			printf("Z=%g+i*(%g)Ohm\n", Z1, Z2);		
		}
		else 
		{
			calc_f0();calc_3();
		}

	}
	else if (q==4)
	{
		enter_R1();
		enter_R2();
		enter_L();
		enter_C();
		enter_fmin();
		enter_fmax();
		enter_df();
		if (df==0)
		{
			calc_f0();
			f=f1;
			w=2*M_PI*f;
			printf("f=%g Hertz; ", f);
			f+=df;
			printf("w=%g Hertz; ", w);	
			a=r1*r2+L/C;
			b=(w*L*r1-r2/(w*C));
			c=r1+r2;
			d=w*L-1/(w*C);
			printf("a=%g Hertz; ", a);	
			printf("b=%g Hertz; ", b);	
			printf("c=%g Hertz; ", c);	
			printf("d=%g Hertz; ", d);	
			Z1=(a*c+b*d)/(c*c+d*d);
			Z2=(b*c-a*d)/(c*c+d*d);
			printf("Z=%g+i*(%g)Ohm\n", Z1, Z2);	
		}
		else 
		{
			calc_f0();calc_4();
		}
	}
printf ("Enter y to continue\n");		
exitchar = getch();
fflush(stdin);	
}
	while ( (exitchar == 'y')||(exitchar == 'Y') );	 
	return 0;
}

	intro()
{
	int i;
	printf("This programm will solve one of examples:\n");
	printf("Choose one of circuits:\n");
	
	printf("       ____\n");
	printf("o-----| R1 |----mmmmm-------o\n");
	printf("   |   ----       L      |\n");
	for (i=0; i<4; i++)
		{
	printf("   |                     |\n");		
		}
	printf("   |          C          |\n");	
	printf("   -----------||---------	Press 1\n\n");
	
	printf("OR\n");
	
	printf("       ____\n");
	printf("o-----| R1 |-----||---------o\n");
	printf("   |   ----      C       |\n");
	for (i=0; i<4; i++)
		{
	printf("   |                     |\n");		
		}
	printf("   |             L       |\n");	
	printf("   ------------mmmmm------	Press 2\n\n");
	
	printf("OR\n");
	
	printf("       ____\n");
	printf("o-----| R2  |-----||---------o\n");
	printf("   |   ----       C      |\n");
	printf("  ___                    |\n");
	printf(" |   |                   |\n");
	printf(" |R1 |                   |\n");
	printf("  ---                    |\n");
	for (i=0; i<2; i++)
		{
	printf("   |                     |\n");		
		}
	printf("   |             L       |\n");	
	printf("   ------------mmmmm------	Press 3\n\n");
	
	printf("OR\n");
	
	printf("       ____\n");
	printf("o-----| R2  |----------------o\n");
	printf("   |   ----              |\n");
	printf("  ___                    |\n");
	printf(" |   |                   |\n");
	printf(" |R1 |                   |\n");
	printf("  ---                    |\n");
	for (i=0; i<2; i++)
		{
	printf("   |                     |\n");		
		}
	printf("  ____                   |\n");	
	printf("  ____ C                 |\n");
	printf("   |             L       |\n");	
	printf("   ------------mmmmm------	Press 4\n\n");
}

	choose_circuit()
{
	scanf("%d", &q);
	switch (q)
	{
	case 1:{printf("You you choosed the circuit #1\n");
			break;
			}
	case 2:{printf("You you choosed the circuit #2\n");
			break;
			}
	case 3:{printf("You you choosed the circuit #3\n");
			break;
			}
	case 4:{printf("You you choosed the circuit #4\n");
			break;
			}
	default:{printf("There's no circuit with this number\n");	
			break;
			return 0;
			}
	}
	return (q);
}

	enter_R1()
{	
do
{
	printf("Enter the value for R1 (Ohm) (<2560)\n");
	printf("R1=");
	scanf("%f", &r1);
	if (r1<=0)
	{
		printf("Error R1<=0\n");
		fflush(stdin);
		j=0;
	}
	else if (r1>2560)
	{
		printf("Error R1>2560\n");
		fflush(stdin);
		j=0;
	} 
	else
	j=1;
}
while (j==0);
}

	enter_R2()
{	
do
{
	printf("Enter the value for R2 (Ohm) (<2560)\n");
	printf("R2=");
	scanf("%f", &r2);
	if (r2<=0)
	{
		printf("Error R2<=0\n");
		fflush(stdin);
		j=0;
	}
	else if (r2>2560)
	{
		printf("Error R2>2560\n");
		fflush(stdin);
		j=0;
	} 
	else
	j=1;
}
while (j==0);
}

	enter_L()
{
do
{	
	printf("Enter the value for L (mH) (<2560)\n");
	printf("L=");
	scanf("%f", &L);
	if (L == 0)
	{
		printf("Error L=0\n");
		fflush(stdin);
		j=0;		
	}
	else if (L < 0)
	{
		printf("Error L<0\n");
		fflush(stdin);
		j=0;		
	}
	else if (L > 2560)
	{
		printf("Error L>2560\n");
		fflush(stdin);
		j=0;		
	}
	else	
	j=1;	
}
while (j==0);
}

	enter_C()
{
do
{
	printf("Enter the value for C (mkF) (<2560)\n");
	printf("C=");
	scanf("%f", &C);
	if (C == 0)
	{
		printf("Error C=0\n");
		fflush(stdin);
		j=0;		
	}
	else if (C < 0)
	{
		printf("Error C<0\n");
		fflush(stdin);
		j=0;		
	}
	else if (C > 2560)
	{
		printf("Error C>2560\n");
		fflush(stdin);
		j=0;		
	}
	else	
	j=1;
}
while (j==0);
}

	enter_fmin()
{	
do
{
		printf("Enter the min frequency (<2560)\n");
		printf("fmin=");
		scanf("%f", &f1);
		if ( f1<=0 )
		{
			printf("Error fmin<=0 (w=0)\n");
			fflush(stdin);
			j=0;		
		}else j=1;	
}
while(j==0);
}

	enter_fmax()
{	
do
{	
		printf("Enter the max frequency (<2560)\n");
		printf("fmax=");
		scanf("%f", &f2);
		if (f1==f2)
		{
			printf("Beginning and ending of a frequency must be different\n");
			fflush(stdin);
			j=0;
		}
		else if ( f2<=0 )
		{
			printf("Error fmax<=0 (w=0)\n");
			fflush(stdin);
			j=0;		
		}else j=1;	
}
while (j!=1);
}

	enter_df()
{
do
{
	printf("Enter step of frequency\n");
	printf("df=");
	scanf("%f", &df);
	if ((f2>f1)&&(df<0))
		{
			printf("The last frequency is higher than the first. Enter only positive numbers.\n");
			fflush(stdin);
			j=0;
		}		
		else if ((f2<f1)&&(df>0))
		{
			printf("The last frequency is lower than the first. Enter only negative numbers.\n");
			fflush(stdin);
			j=0;
		}
		else if ((f2-f1)<df)
		{
			printf("The step is higher than the differnce fmin & fmax\n");
			fflush(stdin);
			j=0;	
		}
		else j=1;
	}
	while (j!=1);
}

	calc_f0()
{
	f=1/(2*M_PI*sqrt(L*C));
	printf("\nResonant frequency=%g\n\n", f);	
}

	calc_1()
{
if ((f2==1)||(f2==2)){f2=f2+df;}
else{f=f1;}

do
{
	w=2*M_PI*f;
	printf("f=%g Hertz  ", f);
	f+=df;	
	a=L/C;
	b=(r1/(w*C))*(-1);
	c=r1;
	d=w*L-1/(w*C);
		
	Z1=(a*c+b*d)/(c*c+d*d);
	Z2=(b*c-a*d)/(c*c+d*d);
	printf("Z=%e+i*(%e)Ohm\n", Z1, Z2);	
}
while (f<=f2);
}

	calc_2()
{
if ((f2==1)||(f2==2)){f2=f2+df;}
else{f=f1;}

do
{
	w=2*M_PI*f;
	printf("f=%g Hertz; ", f);
	f+=df;	
	a=L/C;
	b=(r1/(w*C));
	c=r1;
	d=w*L-1/(w*C);

	Z1=(a*c+b*d)/(c*c+d*d);
	Z2=(b*c-a*d)/(c*c+d*d);
	printf("Z=%e+i*(%e)Ohm\n", Z1, Z2);
}
while (f<=f2);
}


	calc_3()
{
if ((f2==1)||(f2==2)){f2=f2+df;}
else{f=f1;}

do
{
	w=2*M_PI*f;
	printf("f=%g Hertz; ", f);
	f+=df;
	
	a=r1*r2;
	b=r1*(w*L-1/(w*C));
	c=r1+r2;
	d=w*L-1/(w*C);

	Z1=(a*c+b*d)/(c*c+d*d);
	Z2=(b*c-a*d)/(c*c+d*d);
	printf("Z=%e+i*(%e)Ohm\n", Z1, Z2);
}
while (f<=f2);
}

	calc_4()
{
if ((f2==1)||(f2==2)){f2=f2+df;}
else{f=f1;}

do
{
	w=2*M_PI*f;
	printf("f=%e Hertz; ", f);
	f+=df;
	
	a=r1*r2+L/C;
	b=(w*L*r1-r2/(w*C));
	c=r1+r2;
	d=w*L-1/(w*C);

	Z1=(a*c+b*d)/(c*c+d*d);
	Z2=(b*c-a*d)/(c*c+d*d);
	printf("Z=%e+i*(%e)Ohm\n", Z1, Z2);
}
while (f<=f2);
}

