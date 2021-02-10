#ifndef _MATH_H_
#define _MATH_H_
#include <stdlib.h>

#include <math.h>
#include <time.h>

double math_clamp(double _value, double _min, double _max);
double math_deg_rad(double _deg);
double math_distance(double _x1, double _y1, double _x2, double _y2);
double math_linear_interpolate(double _value, double _min, double _max);

double math_map(
  double _value
  ,double _src_min
  ,double _src_max
  ,double _dest_min
  ,double _dest_max
);

double math_normalize(double _value, double _min, double _max);
double math_rad_deg(double _rad);
double math_random();
double math_random_distributed(double _min, double _max, unsigned _iterations);
double math_random_range(double _min, double _max);
int math_random_range_int(int _min, int _max);
double math_round_nearest(double _value, int _precision);
double math_snap(double _value, double _factor);
#endif // _MATH_H_
