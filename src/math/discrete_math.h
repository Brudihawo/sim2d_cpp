#pragma once

struct interval
{
    double max;
    double min;
};

float ddx(double** s, long  x, long  y, long  NX);
float ddy(double** s, long  x, long  y, long  NY);

float d2dx(double** s, long  x, long  y, long  NX);
float d2dy(double** s, long  x, long  y, long  NY);

void smooth(int n_iterations, double** s, double** tmp, long NX, long  NY);

void find_min_max(interval& iv, double* s, long  NX, long  NY);