// CountingValleys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// https://www.hackerrank.com/challenges/counting-valleys/problem
//

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>


std::string ltrim(const std::string&);
std::string rtrim(const std::string&);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(const int _steps, std::string& _path) {

  if (static_cast<size_t>(_steps) != _path.length()) return -1;
  std::transform(_path.begin(), _path.end(), _path.begin(), ::toupper);
  int valleys = 0;
  int elevation = 0;
  int previousElevation = elevation;
  for (auto step : _path)
  {
    previousElevation = elevation;
    if (step == 'D')
    {
      --elevation;
    }
    else
    {
      ++elevation;
    }
    if (previousElevation == 0 && elevation == -1) ++valleys;

    //std::cout << step << ":" << elevation;

  }

  return valleys;
}

int main()
{

  int steps = 8;
  std::string path = "UDDDUDUU"; 
  std::cout << steps  << ":" << path << " " << countingValleys(steps, path) << "\n";

  steps = 12;
  path = "DDUUDDUDUUUD";
  std::cout << steps << ":" << path << " " << countingValleys(steps, path) << "\n";


  steps = 9;
  path = "UUDDDUDUU";
  std::cout << steps << ":" << path << " " << countingValleys(steps, path) << "\n";

  return 0;
}

std::string ltrim(const std::string& str) {
  std::string s(str);

  s.erase(
    s.begin(),
    find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(isspace)))
  );

  return s;
}

std::string rtrim(const std::string& str) {
  std::string s(str);

  s.erase(
    find_if(s.rbegin(), s.rend(), not1(std::ptr_fun<int, int>(isspace))).base(),
    s.end()
  );

  return s;
}
