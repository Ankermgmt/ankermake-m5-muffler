#include "esphome.h"

class PwmDutyCycleSensor : public PollingComponent, public Sensor {
 public:
  void set_pin(uint8_t pin) { pin_ = pin; }

  void setup() override {
    pinMode(pin_, INPUT);
    // Use attachInterruptArg with a lambda function without capturing context
    attachInterruptArg(digitalPinToInterrupt(pin_), [] (void* arg) {
      static_cast<PwmDutyCycleSensor*>(arg)->on_interrupt();
    }, this, CHANGE);
  }

  void update() override {
    if (interrupt_count_ > 1) {
      float duty_cycle = static_cast<float>(high_duration_) / (high_duration_ + low_duration_) * 100.0f;
      publish_state(duty_cycle);
    }
    high_duration_ = 0;
    low_duration_ = 0;
    interrupt_count_ = 0;
  }

  void on_interrupt() {
    uint32_t current_time = micros();
    if (digitalRead(pin_)) {
      low_duration_ += current_time - last_interrupt_time_;
    } else {
      high_duration_ += current_time - last_interrupt_time_;
    }
    last_interrupt_time_ = current_time;
    interrupt_count_++;
  }

 protected:
  uint8_t pin_;
  volatile uint32_t last_interrupt_time_ = 0;
  volatile uint32_t high_duration_ = 0;
  volatile uint32_t low_duration_ = 0;
  volatile uint8_t interrupt_count_ = 0;
};
