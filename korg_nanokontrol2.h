#ifndef KORG_NANOKONTROL2_H_
#define KORG_NANOKONTROL2_H_

#include <queue>

typedef float real32;
typedef unsigned char uint8;

namespace nantalesiokorgnanokontrol2
{
  enum class TransportButton : uint8
  {
    kPlay,
    kStop,
    kRewind,
    kFastforward,
    kRecord,
    kCycle,
    kTrackRewind,
    kTrackFastforward,
    kSet,
    kMarkerRewind,
    kMarkerFastforward,
  };

  enum class GroupButton : uint8
  {
    kSolo,
    kMute,
    kRecord,
  };

  struct GroupValues
  {
    real32 slider_value;
    real32 knob_value;
    bool solo_button_state;
    bool mute_button_state;
    bool record_button_state;
  };

  struct Event
  {
    bool is_transport_button;
    union
    {
      TransportButton transport_button;
      struct {
        uint8 channel_index;
        GroupButton group_button;
      };
    };
    bool state;
  };

  class KorgNanokontrol2
  {
    public:
      static const uint8 kNumChannels = 8;

    public:
      static GroupValues* GetAllGroupValues();
      static GroupValues GetGroupValues(uint8 channel_index);
      static real32 GetSliderValue(uint8 channel_index);
      static real32 GetKnobValue(uint8 channel_index);

    public:
      bool PollEvents(Event& out_event);

    protected:
      std::queue<Event> events_;
  };
}

#endif /* KORG_NANOKONTROL2_H_ */
