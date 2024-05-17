/*
 * main.c
 *
 *  Created on: Dec 24, 2023
 *      Author: Mustafa Hafez
 */




int main()
{



	unsigned char nums[9] = {1,2,3,4,5,6,7,8,9};
	unsigned char num=6;
	int i,l,r,m;
	l = 0;
	r = 8;
	m = 4;
	for(i =0; i<9;i++)
	{
		if (num==nums[m])
		{
			printf("The index is %d\n",m);
		}
		else if(num > m)
		{
			l =m;
			m = (l+r)/2;
		}
		else if(num < m)
		{
			r =m;
			m = (l+r)/2;
		}

	}

	//Binary search



	return 0;
}
