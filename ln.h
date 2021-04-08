#pragma once
double power(double x, int y, double z)
{
    for (int i = 1; i < y; i++)
        x = x * z;
    return x;
}


double ln(double x)
{
    int gg = 1;
    double z = x; double c = 0;
    for (int y = 1; y < 10; y++)
    {
        c += ((power(x, y, z) / (y)) * gg);
        gg *= -1;
    }
    return c;
}
