#include "Date.h"
//ctime

CDate CDate::default_date = { 1,Jan,1970 };

CDate :: CDate(int dd,Month mm,int yy)
{
	switch (mm)
	{
	case Jan:case Mar:case May:case Jul:
	case Aug:case Oct:case Dec:
	{
		d = (dd > 0 && dd <= 31) ? dd : default_date.d;
		m = (mm >= Jan && mm <= Dec) ? mm : default_date.m;
		y = (yy >= default_date.y) ? yy : default_date.y;
		break;
	}

	case Apr:case Jun:case Sep:case Nov:
	{
		d = (dd > 0 && dd <= 30) ? dd : default_date.d;
		m = (mm >= Jan && mm <= Dec) ? mm : default_date.m;
		y = (yy >= default_date.y) ? yy : default_date.y;
		break;
	}

	case Feb:
	{
		m = (mm >= Jan && mm <= Dec) ? mm : default_date.m;
		y = (yy >= default_date.y) ? yy : default_date.y;
		if(y % 4 == 0 && y % 100 != 0)
		{
			d = (dd > 0 && dd <= 29) ? dd : default_date.d;
		}
		else
		{
			d = (dd > 0 && dd <= 28) ? dd : default_date.d;
		}
		break;
	}
	default:
	{
		Bad_date();
		break;
	}
	}

}

CDate& CDate::add_year(int n)
{
	y += n;
	return *this;
}

CDate& CDate::add_month(int n)
{
	y += (m + n) / 12;
	m = (m + n) % 13 + 1;
	return *this;
}

CDate& CDate::add_day(int n)
{
	int tmp = 0;
	switch (m)
	{
	case Jan:case Mar:case May:case Jul:
	case Aug:case Oct:case Dec:
	{
		tmp = (d + n) / 31;
		if (d + n > 31)
		{
			d = (d + n) % 32 + 1;
		}
		else
			d += n;
		break;
	}

	case Apr:case Jun:case Sep:case Nov:
	{
		tmp = (d + n) / 30;
		if (d + n > 30)
		{
			d = (d + n) % 31 + 1;
		}
		else
			d += n;
		break;
	}

	case Feb:
	{
		if (y % 4 == 0 && y % 100 != 0)
		{
			tmp = (d + n) / 29;
			if (d + n > 29)
			{
				d = (d + n) % 30 + 1;
			}
			else
				d += n;
		}
		else
		{
			tmp = (d + n) / 28;
			if (d + n > 28)
			{
				d = (d + n) % 29 + 1;
			}
			else
				d += n;
		}
		break;
	}
	}

	if (m + tmp > Dec)
	{
		y += (m + tmp) / 12;
		m = (m + tmp) % 13 + 1;
	}
	else
	{
		m += tmp;
	}

	return *this;
}

int CDate :: get_year() const
{
	return y;
}

int CDate::get_month() const
{
	return m;
}

int CDate :: get_day() const
{
	return d;
}

ostream& operator<<(ostream& mout, const CDate& mdate)
{
	mout << mdate.get_year() << "Äê" << mdate.get_month() << "ÔÂ" << mdate.get_day() << "ÈÕ\n";
	return mout;
}

