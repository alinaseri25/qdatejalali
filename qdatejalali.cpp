#include "qdatejalali.h"

QDATEJALALI::QDATEJALALI()
{	
    shmdate.setDay(0);shmdate.setMonth(0);shmdate.setYear(0 - 1300);
    mildate.setDay(0);mildate.setMonth(0);mildate.setYear(0 - 2000);
}

bool QDATEJALALI::SetMiladiDate(int16_t _year, int16_t _month, int16_t _day)
{
    mildate.setDay(_day);
    mildate.setMonth(_month);
		if(_year >= 2000) _year -= 2000;
    mildate.setYear(_year);
    miltoshmcv(mildate.getYear(),mildate.getMonth(),mildate.getDay());
    return true;
}

bool QDATEJALALI::SetShamsiDate(int16_t _year, int16_t _month, int16_t _day)
{
    shmdate.setDay(_day);
    shmdate.setMonth(_month);
		if(_year >= 1300) _year -= 1300;
    shmdate.setYear(_year);
    shmtomilcv(shmdate.getYear(),shmdate.getMonth(),shmdate.getDay());
    return true;
}

int16_t QDATEJALALI::getdaymi()
{
    return mildate.getDay();
}

int16_t QDATEJALALI::getmonthmi()
{
    return mildate.getMonth();
}

int16_t QDATEJALALI::getyearmi()
{
    return mildate.getYear() + 2000;
}

int16_t QDATEJALALI::getdaysh()
{
    return shmdate.getDay();
}

int16_t QDATEJALALI::getmonthsh()
{
    return shmdate.getMonth();
}

int16_t QDATEJALALI::getyearsh()
{
    return shmdate.getYear() + 1300;
}

/*************************************************************************/
void QDATEJALALI::miltoshmcv(unsigned char ym,unsigned char mm,unsigned char dm)
{
    //ym -= 2000;
    unsigned char k,t1,t2;
    k=ym%4;
    if(k==3)
       k=2;
    k*=2;
    t1=miltable[k][mm-1];
    t2=miltable[k+1][mm-1];
    if(mm<3 || (mm==3 && dm<=miltable[k][mm-1]))
       shmdate.setYear(ym + 78);
    else
       shmdate.setYear(ym + 79);


    if(dm<=t1)
    {
       shmdate.setDay(dm+t2);
       shmdate.setMonth((mm+8)%12+1);
    }
    else
    {
       shmdate.setDay(dm-t1);
       shmdate.setMonth((mm+9)%12+1);
    }
}
/**********************************************************************/
void QDATEJALALI::shmtomilcv(unsigned char ys ,unsigned char ms,unsigned char ds)
{
    //ys -= 1300;
    unsigned char k,t1,t2;
    k = ys%4;
    if( k == 0)
       k = 2;
    else
       k = k + k;
    t1 =shmtable[k - 2][ms-1];
    t2 = shmtable[k-1][ms-1];
    if(ms<10 || (ms==10 && ds <= shmtable[k-2][ms-1]))
       mildate.setYear(ys - 79);
    else
       mildate.setYear(ys - 78);

    //mildate.year += 2000;

    if(ds <= t1)
    {
       mildate.setDay(ds + t2);
       mildate.setMonth((ms + 1)%12 + 1);
    }
    else
    {
       mildate.setDay(ds - t1);
       mildate.setMonth((ms + 2)%12 + 1);
    }
}

DateTime QDATEJALALI::getMiladiDate(void)
{
	return mildate;
}

DateTime QDATEJALALI::getShamsiDate(void)
{
	return shmdate;
}
