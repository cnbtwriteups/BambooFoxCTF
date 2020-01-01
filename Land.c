#include "Land.h"

//----do not modify above----

rectangle find_rectangle(){
	rectangle r;
	
	r.a = 0;
	r.b = 0;
	r.c = 1000000000;
    r.d = 1000000000;
	
	long long total = area(0, 0, 1000000000, 1000000000);

	if(total == 1000000000l * 1000000000l) return r;
	
	int lb = 1;
	int rb = 999999999;
	int mid;
	
	while(lb <= rb)
	{
		mid = (rb - lb) / 2 + lb;
		if (area(mid, 0, 1000000000, 1000000000) < total)
			rb = mid - 1;
		else
		{
			if(mid > r.a) r.a = mid;
			lb = mid + 1;
		}
	}
	
	lb = 1;
	rb = 999999999;
	
	while (lb <= rb)
    {
        mid = (rb - lb) / 2 + lb;
        if (area(0, mid, 1000000000, 1000000000) < total)
            rb = mid - 1;
        else
        {
            if (mid > r.b) r.b = mid;
			lb = mid + 1;
        }
    }
	
	long dX = total - area(r.a + 1, 0, 1000000000, 1000000000);
    long dY = total / dX;

	r.c = r.a + dY;
	r.d = r.b + dX;

	return r;
}
