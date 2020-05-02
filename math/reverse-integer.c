// by Cdg_Jacobs

int reverse(int x)
{
int i,j,factor;
int _Reverse=0;

if((x>pow(2,31)-1)||x<=-pow(2,31))
{
	printf("overflow!");
	return 0;
}
else if(x>=0)
{
	for(i=0;i<=11;i++)
	{
		factor = pow(10,i);
		if(x/factor == 0)break; 
	}    

	for(j=i;j>=1;j--)
	{
		factor = pow(10,j-1);
		_Reverse += (x/factor)*pow(10,(i-j));
		if(_Reverse==pow(2,31)-1||_Reverse==-pow(2,31))return 0;
		x -= (x/factor)*pow(10,j-1);
	}
}
else return -reverse(-x);

return _Reverse;
}
