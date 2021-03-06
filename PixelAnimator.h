
#ifndef PixelAnimator_h
#define PixelAnimator_h

#include <FastLED.h>
#include "Config.h"
#include "ColorPicker.h"
#include "power_mgt.h"
#include "_defines.h"

class RPMAnimation {
  public:
    enum animations: uint8_t {
      LeftToRight = 0,
      RightToLeft = 1,
      Outward     = 2,
      Inward      = 3,
      Full        = 4
    };
};

class PixelAnimator {
  
  public:
    PixelAnimator(Config* config);
    
    void
      show(),
      setup(),
      updateColors(),
      setBrightness(uint8_t brightness),
      setFill(CRGB color),
      setEdges(CRGB color),
      setRPM(uint16_t rpm),
      showBlockingRunlight(CRGB color, uint16_t time=ANIM_MED),
      showSegmentPreview(uint8_t segment1, uint8_t segment2, uint8_t blackSegment=0, bool halved=false);
  
  private:
    Config* CONFIG;
    uint8_t targetBrightness;
    bool passedLow;
    CRGB CLow;
    CRGB CPart1;
    CRGB CPart2;
    CRGB CPart3;
    CRGB CFlash1;
    CRGB CFlash2;
    CRGB** CSegmentsFull;
    CRGB** CSegmentsHalved;
    CRGB colorFor(uint8_t index, bool halved=false);
  
};

#endif
