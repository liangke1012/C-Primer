#include <iostream>
#include "stonewt.h"

using std::cout;

Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int (lbs) % Lbs_per_stn;
    pound = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pound = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
    stone = pound = pds_left = 0;
}

Stonewt::~Stonewt()
{
}

void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_lbs() const
{
    cout << pound << " pound\n";
}

Stonewt::operator int() const
{
    return int (pound + 0.5);
}

Stonewt::operator double() const
{
    return pound;
}