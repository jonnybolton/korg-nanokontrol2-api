#include "korg_nanokontrol2.h"

using namespace nantalesiokorgnanokontrol2;

GroupValues* KorgNanokontrol2::GetAllGroupValues()
{
  return new GroupValues[kNumChannels];
}

GroupValues KorgNanokontrol2::GetGroupValues(uint8 channel_index)
{
  return GroupValues();
}

real32 KorgNanokontrol2::GetSliderValue(uint8 channel_index)
{
  return 0.0f;
}

real32 KorgNanokontrol2::GetKnobValue(uint8 channel_index)
{
  return 0.0f;
}

bool KorgNanokontrol2::PollEvents(Event& out_event)
{
  if (events_.empty())
  {
    return false;
  }

  out_event = events_.front();
  events_.pop();
  return true;
}
