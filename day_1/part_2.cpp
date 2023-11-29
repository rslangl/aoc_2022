#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <vector>

struct solution
{
  static auto most_cals() -> std::vector<int>
  {
    std::fstream input;
    std::vector<int> top_three{0,0,0};

    input.open("input.txt", std::ios::in);

    if(input.is_open())
    {
      std::string line{};
      int intermediary{0};

      while(std::getline(input, line))
      {
	// When an empty line is encountered, we consider the sum of the whole block
	if(line.empty())
	{
          // Iterate the top three list
          for(int idx = 0; idx <= 2; ++idx)
	  {
	    // If the block value is greater than any element in the top three list,
	    // then we shift all elements below that index to the right before inserting
	    // the new value in the current index
            if(intermediary > top_three[idx])
	    {
	      // To shift elements, we iterate from the end of the list until the element 
	      // after the current index and copies the value from the element preseding it,
	      // before finally inserting the new value at the appropriate index
	      for(int i = 2; i > idx; --i)
	      {
                top_three[i] = top_three[i - 1]; 
	      }
	      top_three[idx] = intermediary;
	      break;
	    }
	  }
	  // Reset intermediary value before continuing
          intermediary = 0;
	}
	// If an empty line is not encountered, keep accumulating the block value
	else
	{
          intermediary += std::stoi(line);
	}
      }
      input.close();
    }
    return top_three;
  }
};

auto main() -> int
{
  auto top_three = solution::most_cals();
  for(const auto val : top_three)
  {
    std::cout << val << '\n';
  }
  int sum = std::accumulate(top_three.begin(), top_three.end(), 0);
  std::cout << "Total: " << sum << '\n';
  return 0;
}
