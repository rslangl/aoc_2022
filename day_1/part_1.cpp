#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

struct solution
{
  static auto most_cals() -> int
  {
    std::fstream input;
    int largest{0}, intermediary{0};

    input.open("input.txt", std::ios::in);

    if(input.is_open())
    {
      std::string line{};

      while(std::getline(input, line))
      {
        intermediary = (line.empty()) ? 0 : intermediary + std::stoi(line);

        if(intermediary > largest)
        {
          largest = intermediary;
        }
      }

      input.close();
    }
    return largest;
  }
};

auto main() -> int
{
  std::cout << solution::most_cals() << '\n';
  return 0;
}
