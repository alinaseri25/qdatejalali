#ifndef QDATEJALALI_H
#define QDATEJALALI_H

#include "define.h"
#include "DateTime.h"

class QDATEJALALI
{
public:
    QDATEJALALI();
    bool SetMiladiDate(int16_t _year,int16_t _month,int16_t _day);
    bool SetShamsiDate(int16_t _year,int16_t _month,int16_t _day);

    int16_t getdaysh(void);
    int16_t getmonthsh(void);
    int16_t getyearsh(void);

    int16_t getdaymi(void);
    int16_t getmonthmi(void);
    int16_t getyearmi(void);

		DateTime getMiladiDate(void);
		DateTime getShamsiDate(void);

private:

		DateTime shmdate,mildate ;

		void miltoshmcv(unsigned char ym, unsigned char mm, unsigned char dm);
		void shmtomilcv(unsigned char ys, unsigned char ms, unsigned char ds);

};

#endif // QDATEJALALI_H
