#pragma once

#include "Arduino.h"
#include "FspTimer.h"
#include "gallery.h"

#define NUM_LEDS    96

#if __has_include("ArduinoGraphics.h")
#include <ArduinoGraphics.h>
#define MATRIX_WITH_ARDUINOGRAPHICS
#endif

static const int pin_zero_index = 28;

static const uint8_t pins[][2] = {
  { 7, 3 }, // 0
  { 3, 7 },
  { 7, 4 },
  { 4, 7 },
  { 3, 4 },
  { 4, 3 },
  { 7, 8 },
  { 8, 7 },
  { 3, 8 },
  { 8, 3 },
  { 4, 8 }, // 10
  { 8, 4 },
  { 7, 0 },
  { 0, 7 },
  { 3, 0 },
  { 0, 3 },
  { 4, 0 },
  { 0, 4 },
  { 8, 0 },
  { 0, 8 },
  { 7, 6 }, // 20
  { 6, 7 },
  { 3, 6 },
  { 6, 3 },
  { 4, 6 },
  { 6, 4 },
  { 8, 6 },
  { 6, 8 },
  { 0, 6 },
  { 6, 0 },
  { 7, 5 }, // 30
  { 5, 7 },
  { 3, 5 },
  { 5, 3 },
  { 4, 5 },
  { 5, 4 },
  { 8, 5 },
  { 5, 8 },
  { 0, 5 },
  { 5, 0 },
  { 6, 5 }, // 40
  { 5, 6 },
  { 7, 1 },
  { 1, 7 },
  { 3, 1 },
  { 1, 3 },
  { 4, 1 },
  { 1, 4 },
  { 8, 1 },
  { 1, 8 },
  { 0, 1 }, // 50
  { 1, 0 },
  { 6, 1 },
  { 1, 6 },
  { 5, 1 },
  { 1, 5 },
  { 7, 2 },
  { 2, 7 },
  { 3, 2 },
  { 2, 3 },
  { 4, 2 },
  { 2, 4 },
  { 8, 2 },
  { 2, 8 },
  { 0, 2 },
  { 2, 0 },
  { 6, 2 },
  { 2, 6 },
  { 5, 2 },
  { 2, 5 },
  { 1, 2 },
  { 2, 1 },
  { 7, 10 },
  { 10, 7 },
  { 3, 10 },
  { 10, 3 },
  { 4, 10 },
  { 10, 4 },
  { 8, 10 },
  { 10, 8 },
  { 0, 10 },
  { 10, 0 },
  { 6, 10 },
  { 10, 6 },
  { 5, 10 },
  { 10, 5 },
  { 1, 10 },
  { 10, 1 },
  { 2, 10 },
  { 10, 2 },
  { 7, 9 },
  { 9, 7 },
  { 3, 9 },
  { 9, 3 },
  { 4, 9 },
  { 9, 4 },
};

#define LED_MATRIX_PORT0_MASK       ((1 << 3) | (1 << 4) | (1 << 11) | (1 << 12) | (1 << 13) | (1 << 15))
#define LED_MATRIX_PORT2_MASK       ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 12) | (1 << 13))

static void turnLed(int idx, bool on) {
  R_PORT0->PCNTR1 &= ~((uint32_t) LED_MATRIX_PORT0_MASK);
  R_PORT2->PCNTR1 &= ~((uint32_t) LED_MATRIX_PORT2_MASK);

  if (on) {
    bsp_io_port_pin_t pin_a = g_pin_cfg[pins[idx][0] + pin_zero_index].pin;
    R_PFS->PORT[pin_a >> 8].PIN[pin_a & 0xFF].PmnPFS =
      IOPORT_CFG_PORT_DIRECTION_OUTPUT | IOPORT_CFG_PORT_OUTPUT_HIGH;

    bsp_io_port_pin_t pin_c = g_pin_cfg[pins[idx][1] + pin_zero_index].pin;
    R_PFS->PORT[pin_c >> 8].PIN[pin_c & 0xFF].PmnPFS =
      IOPORT_CFG_PORT_DIRECTION_OUTPUT | IOPORT_CFG_PORT_OUTPUT_LOW;
  }
}

static uint32_t reverse(uint32_t x)
{
    x = ((x >> 1) & 0x55555555u) | ((x & 0x55555555u) << 1);
    x = ((x >> 2) & 0x33333333u) | ((x & 0x33333333u) << 2);
    x = ((x >> 4) & 0x0f0f0f0fu) | ((x & 0x0f0f0f0fu) << 4);
    x = ((x >> 8) & 0x00ff00ffu) | ((x & 0x00ff00ffu) << 8);
    x = ((x >> 16) & 0xffffu) | ((x & 0xffffu) << 16);
    return x;
}

// TODO: this is dangerous, use with care
#define loadSequence(frames)                    loadWrapper(frames, sizeof(frames))
#define renderBitmap(bitmap, rows, columns)     loadPixels(&bitmap[0][0], rows*columns)
#define endTextAnimation(scrollDirection, anim) endTextToAnimationBuffer(scrollDirection, anim ## _buf, sizeof(anim ## _buf), anim ## _buf_used)
#define loadTextAnimationSequence(anim)         loadWrapper(anim ## _buf, anim ## _buf_used)

static uint8_t __attribute__((aligned)) framebuffer[NUM_LEDS / 8];

/**
 * @brief Class representing an LED matrix for Arduino.
 *
 * This class provides methods to control and manage the LED matrix.
 */
class ArduinoLEDMatrix
#ifdef MATRIX_WITH_ARDUINOGRAPHICS
    : public ArduinoGraphics
#endif
     {

public:
    /**
     * @brief Constructor for the ArduinoLEDMatrix class.
     *
     * Initializes the LED matrix and sets up any necessary configurations.
     */
    ArduinoLEDMatrix()
    #ifdef MATRIX_WITH_ARDUINOGRAPHICS
        : ArduinoGraphics(canvasWidth, canvasHeight)
    #endif
    {}
    // TODO: find a better name
    // autoscroll will be slower than calling next() at precise times
    void autoscroll(uint32_t interval_ms) {
        _interval = interval_ms;
    }

    /**
     * @brief Turns on the LED at the specified pin.
     *
     * @param `pin` The pin number where the LED is connected.
     */
    void on(size_t pin) {
        turnLed(pin, true);
    }

    /**
     * @brief Turns off the LED at the specified pin.
     *
     * @param `pin` The pin number where the LED is connected.
     */
    void off(size_t pin) {
        turnLed(pin, false);
    }
    
    /**
     * @brief Initializes the LED matrix and starts the timer.
     *
     * This function configures and starts a periodic timer for controlling the LED matrix.
     * It searches for an available timer, configures it, and starts it with a default frequency.
     *
     * @return Returns `1` (true) if initialization succeeds, otherwise `0` (false).
     */
    int begin() {
        bool rv = true;
        uint8_t type;
        int8_t ch = FspTimer::get_available_timer(type);
        if(ch == -1) {
            return false;
        }
        // TODO: avoid passing "this" argument to remove autoscroll
        rv &= _ledTimer.begin(TIMER_MODE_PERIODIC, type, ch, 10000.0, 50.0, turnOnLedISR, this);
        rv &= _ledTimer.setup_overflow_irq();
        rv &= _ledTimer.open();
        rv &= _ledTimer.start();
        return rv;
    }

    /**
     * @brief Advances to the next frame in the LED matrix animation sequence.
     *
     * This function updates the frame buffer by fetching the next frame data from 
     * the stored sequence. If the animation reaches the last frame, it either loops 
     * or stops based on the loop setting. If a callback function is set, it is 
     * triggered when the sequence completes.
     *
     * @note This function also reverses frame data before updating the framebuffer.
     *
     */
    void next() {
        uint32_t frame[3];
        frame[0] = reverse(*(_frames+(_currentFrame*4)+0));
        frame[1] = reverse(*(_frames+(_currentFrame*4)+1));
        frame[2] = reverse(*(_frames+(_currentFrame*4)+2));
        _interval = *(_frames+(_currentFrame*4)+3);
        _currentFrame = (_currentFrame + 1) % _framesCount;
        if(_currentFrame == 0){
            if(!_loop){
                _interval = 0;
            }
            if(_callBack != nullptr){
                _callBack();
            }
            _sequenceDone = true;
        }
        memcpy(framebuffer, (uint32_t*)frame, sizeof(frame));
    }

    /**
     * @brief Loads a single frame into the LED matrix and updates the display.
     *
     * This function takes a frame buffer containing LED matrix data and loads it
     * as a single-frame animation sequence. It then advances to display the frame
     * immediately and ensures the animation interval is set to 0 to prevent looping.
     *
     * @param `buffer` An array of three 32-bit values representing the frame data.
     *
     */
    void loadFrame(const uint32_t buffer[3]){
        uint32_t tempBuffer[][4] = {{
            buffer[0], buffer[1], buffer[2], 0
        }};
        loadSequence(tempBuffer);
        next();
        _interval = 0;
    }

    /**
     * @brief Renders a specific frame from the loaded sequence.
     *
     * This function sets the current frame index to the specified frame number,
     * ensuring it wraps around within the available frame count. It then updates
     * the display to show the selected frame and stops any automatic transitions
     * by setting the interval to 0.
     *
     * @param `frameNumber` The index of the frame to be displayed.
     */
    void renderFrame(uint8_t frameNumber){
        _currentFrame = frameNumber % _framesCount;
        next();
        _interval = 0;
    }

    /**
     * @brief Starts playing the loaded frame sequence.
     *
     * This function begins playback of the current sequence, advancing through 
     * frames automatically. If looping is enabled, the sequence will restart 
     * after reaching the last frame.
     *
     * @param `loop` Set to `true` to enable looping; `false` to play the sequence once. Default is `false`.
     */
    void play(bool loop = false){
        _loop = loop;
        _sequenceDone = false;
        next();
    }

    /**
     * @brief Checks if the sequence has finished playing.
     *
     * This function checks if the current frame sequence has completed. 
     * If the sequence is done, it will reset the `_sequenceDone` flag 
     * and return `true`, otherwise it returns `false`.
     *
     * @return `true` if the sequence is done, `false` otherwise.
     */
    bool sequenceDone(){
        if(_sequenceDone){
            _sequenceDone = false;
            return true;
        }
        return false;
    }

    /**
     * @brief Loads pixel data from an array into a buffer.
     *
     * This function takes a byte array (`arr`) containing pixel data and converts it 
     * into a `uint32_t` buffer (`dst`). Each byte in the array represents 8 pixels, 
     * and the data is packed into the 32-bit buffer accordingly. The function processes
     * the pixel data byte by byte and stores the packed data into the buffer in chunks of 32 bits.
     *
     * @param `arr` The input byte array containing pixel data.
     * @param `size` The number of elements in the array `arr` to process.
     * @param `dst` The destination buffer where the packed pixel data will be stored.
     */
    static void loadPixelsToBuffer(uint8_t* arr, size_t size, uint32_t* dst) {
        uint32_t partialBuffer = 0;
        uint8_t pixelIndex = 0;
        uint8_t *frameP = arr;
        uint32_t *frameHolderP = dst;
        while (pixelIndex < size) {
            partialBuffer |= *frameP++;
            if ((pixelIndex + 1) % 32 == 0) {
                *(frameHolderP++) = partialBuffer;
            }
            partialBuffer = partialBuffer << 1;
            pixelIndex++;
        }
    }

    /**
     * @brief Loads pixel data into the frame buffer and prepares it for rendering.
     *
     * This function takes a byte array (`arr`) containing pixel data, converts it 
     * into a 32-bit buffer using `loadPixelsToBuffer`, and then loads the buffer 
     * into the frame sequence using `loadFrame`. The function ensures that the pixel 
     * data is properly formatted and ready for display by converting the data into 
     * a suitable format and storing it in the internal frame buffer.
     *
     * @param `arr` The input byte array containing the pixel data to be loaded.
     * @param `size` The number of elements in the array `arr` to process.
     */
    void loadPixels(uint8_t *arr, size_t size){
        loadPixelsToBuffer(arr, size, _frameHolder);
        loadFrame(_frameHolder);
    };

    /**
     * @brief Loads a sequence of frames into the frame buffer.
     *
     * This function accepts a 2D array (`frames`) containing frame data and the 
     * number of frames (`howMany`). It calculates the total number of frames 
     * and sets the appropriate frame pointer for future frame rendering. The 
     * function also resets the current frame index to 0, ensuring that frame 
     * playback starts from the beginning.
     *
     * @param `frames` A 2D array containing the frame data to be loaded into the 
     * frame buffer. Each frame is expected to contain 4 uint32_t values.
     * @param `howMany` The total number of frame elements (in uint32_t) in the `frames` array.
     */
    void loadWrapper(const uint32_t frames[][4], uint32_t howMany) {
        _currentFrame = 0;
        _frames = (uint32_t*)frames;
        _framesCount = (howMany / 4) / sizeof(uint32_t);
    }
    // WARNING: callbacks are fired from ISR. The execution time will be limited.
    void setCallback(voidFuncPtr callBack){
        _callBack = callBack;
    }

    /**
     * @brief Clears the LED matrix display and resets the canvas buffer.
     *
     */
    void clear() {
        const uint32_t fullOff[] = {
            0x00000000,
            0x00000000,
            0x00000000
        };
        loadFrame(fullOff);
#ifdef MATRIX_WITH_ARDUINOGRAPHICS
        memset(_canvasBuffer, 0, sizeof(_canvasBuffer));
#endif
    }


#ifdef MATRIX_WITH_ARDUINOGRAPHICS
    /**
     * @brief Sets a pixel at the specified coordinates with a color.
     * 
     * This function updates the pixel at position `(x, y)` on the canvas. The pixel is 
     * set to on (1) if any of the red (r), green (g), or blue (b) values are greater 
     * than 0.
     * 
     * @param `x` The x-coordinate (horizontal position) of the pixel to set. 
     * Should be between 0 and `canvasWidth - 1`.
     * @param `y` The y-coordinate (vertical position) of the pixel to set. 
     * Should be between 0 and `canvasHeight - 1`.
     * @param `r` The red color value (used here for logical presence check).
     * @param `g` The green color value (used here for logical presence check).
     * @param `b` The blue color value (used here for logical presence check).
     * 
     */
    virtual void set(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
      if (y >= canvasHeight || x >= canvasWidth || y < 0 || x < 0) {
        return;
      }
      // the r parameter is (mis)used to set the character to draw with
      _canvasBuffer[y][x] = (r | g | b) > 0 ? 1 : 0;
    }

    /**
     * @brief Ends the text rendering and optionally scrolls.
     * 
     * This function finalizes the text rendering process and, if scrolling is 
     * requested, applies the scroll.
     * 
     * @param `scrollDirection` The direction to scroll the text after rendering. 
     * Possible values are:
     *  - `NO_SCROLL` (default): No scrolling.
     *  - A positive value indicates scrolling in a direction.
     */
    void endText(int scrollDirection = NO_SCROLL) {
      ArduinoGraphics::endText(scrollDirection);
      renderBitmap(_canvasBuffer, canvasHeight, canvasWidth);
    }

    // display the drawing or capture it to buffer when rendering dynamic anymation
    void endDraw() {
      ArduinoGraphics::endDraw();

      if (!captureAnimation) {
        renderBitmap(_canvasBuffer, canvasHeight, canvasWidth);
      } else {
        if (captureAnimationHowManyRemains >= 4) {
          loadPixelsToBuffer(&_canvasBuffer[0][0], sizeof(_canvasBuffer), captureAnimationFrame);
          captureAnimationFrame[3] = _textScrollSpeed;
          captureAnimationFrame += 4;
          captureAnimationHowManyRemains -= 16;
        }
      }
    }

    /**
     * @brief Ends the text rendering and captures it into an animation buffer.
     * 
     * @param `scrollDirection` The direction to scroll the text after rendering. 
     * Typically, the value can specify no scroll or a scroll speed for animation purposes.
     * 
     * @param `frames` A 2D array that holds the captured frames, where each frame is 
     * represented by a set of 4 32-bit values.
     * 
     * @param `howManyMax` The maximum number of frames that can be captured into the 
     * `frames` buffer.
     * 
     * @param `howManyUsed` A reference that will hold the number of frames actually 
     * used to capture the animation.
     * 
     */
    void endTextToAnimationBuffer(int scrollDirection, uint32_t frames[][4], uint32_t howManyMax, uint32_t& howManyUsed) {
      captureAnimationFrame = &frames[0][0];
      captureAnimationHowManyRemains = howManyMax;

      captureAnimation = true;
      ArduinoGraphics::textScrollSpeed(0);
      ArduinoGraphics::endText(scrollDirection);
      ArduinoGraphics::textScrollSpeed(_textScrollSpeed);
      captureAnimation = false;
        
      howManyUsed = howManyMax - captureAnimationHowManyRemains;
    }

    /**
     * @brief Sets the scroll speed for the text rendering.
     * 
     * @param `speed` The speed at which the text should scroll, typically in milliseconds 
     * or as defined by the graphics library. A higher value will make 
     * the text scroll slower, and a lower value will make it scroll faster.
     */
    void textScrollSpeed(unsigned long speed) {
      ArduinoGraphics::textScrollSpeed(speed);
      _textScrollSpeed = speed;
    }

  private:
    uint32_t* captureAnimationFrame = nullptr;
    uint32_t captureAnimationHowManyRemains = 0;
    bool captureAnimation = false;
    static const byte canvasWidth = 12;
    static const byte canvasHeight = 8;
    uint8_t _canvasBuffer[canvasHeight][canvasWidth] = {{0}};
    unsigned long _textScrollSpeed = 100;
#endif

private:
    int _currentFrame = 0;
    uint32_t _frameHolder[3];
    uint32_t* _frames;
    uint32_t _framesCount;
    uint32_t _interval = 0;
    uint32_t _lastInterval = 0;
    bool _loop = false;
    FspTimer _ledTimer;
    bool _sequenceDone = false;
    voidFuncPtr _callBack;

    static void turnOnLedISR(timer_callback_args_t *arg) {
        static volatile int i_isr = 0;
        turnLed(i_isr, ((framebuffer[i_isr >> 3] & (1 << (i_isr % 8))) != 0));
        i_isr = (i_isr + 1) % NUM_LEDS;
        if (arg != nullptr && arg->p_context != nullptr) {
            ArduinoLEDMatrix* _m = (ArduinoLEDMatrix*)arg->p_context;
            if (_m->_interval != 0 && millis() - _m->_lastInterval > _m->_interval) {
                _m->next();
                _m->_lastInterval = millis();
            }
        }
    }
};
