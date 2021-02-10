#include "math.h"

double math_clamp(double _value, double _min, double _max)
{
  // Keep _value within _min and _max.

  if(_value <= _min) return _min;
  if(_value >= _max) return _max;

  return _value;
}

double math_deg_rad(double _deg)
{
  // Convert _deg from degrees to radians.

  return _deg / 180 * M_PI;
}

double math_distance(double _x1, double _y1, double _x2, double _y2)
{
  // Return Pythagorean distance between _x1/_y1 and _x2/_y2.

  double _dx = _x2 - _x1;
  double _dy = _y2 - _y1;

  return sqrt(_dx * _dx + _dy * _dy);
}

double math_linear_interpolate(double _value, double _min, double _max)
{
  // Return _value linearly interpolated between _min and _max.

  return (_max - _min) * _value + _min;
}

double math_map(
  double _value
  ,double _src_min
  ,double _src_max
  ,double _dest_min
  ,double _dest_max
)
{
  // Map _value from _src_min/_src_max to _dest_min/_dest_max.

  double _n = math_normalize(_value, _src_min, _src_max);

  return math_linear_interpolate(_n, _dest_min, _dest_max);
}

double math_normalize(double _value, double _min, double _max)
{
  // Convert _value to a number between _min and _max.

  return (_value - _min) / (_max - _min);
}

double math_rad_deg(double _rad)
{
  // Convert _rad from radians to degrees.

  return _rad * 180 / M_PI;
}

double math_random()
{
  // Return a random number between zero and one.

  return math_random_range(0, 1);
}

double math_random_distributed(double _min, double _max, unsigned _iterations)
{
  /*
  Return a random number between _min and _max which tends toward the center of
  _min and _max (bell curve normal distribution) as the value of _iterations is
  increased.
  */
  double _total = 0;

  for(int i = 0; i < _iterations; i++)
  {
    _total += math_random_range(_min, _max);
  }

  return _total / _iterations;
}

double math_random_range(double _min, double _max)
{
  // Return a random number between _min and _max, inclusive.

  for(int i = 0; i < 3; i++) rand();

  return math_map(rand(), 0, RAND_MAX, _min, _max);
}

int math_random_range_int(int _min, int _max)
{
  // Return a random integer between _min and _max, inclusive.

  return ~~((int) (math_random() * (_max - _min + 1) + _min));
}

double math_round_nearest(double _value, int _precision)
{
  // Round _value to the nearest 10 ^ _precision.

  double _p = pow(10, _precision);

  return round(_value * _p) / _p;
}

double math_snap(double _value, double _factor)
{
  /*
  Return the multiple of _factor which _value is closest to. When _value is
  exactly between two multiples, the higher multiple is chosen.

  Examples:
  math_snap(35, 40) -> 40
  math_snap(15, 20) -> 20
  math_snap(3, 16)  -> 0
  math_snap(60, 16)  -> 64
  */

  return round(_value / _factor) * _factor;
}

