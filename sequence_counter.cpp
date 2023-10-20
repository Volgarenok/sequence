#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

dobsov::SequenceCounter::SequenceCounter():
  count_(0)
{}

void dobsov::SequenceCounter::operator()(int)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (count_ == max_size)
  {
      throw std::logic_error("seuqnec is too long");
  }
  ++count_;
}
size_t dobsov::SequenceCounter::operator()() const
{
  return count_;
}
