#pragma once

template <typename T>
class HysteresisTrigger {
public: 
    explicit HysteresisTrigger(const T high_trigger, const T low_trigger)
        : high_trigger_{high_trigger}, low_trigger_{low_trigger} {

    }

    bool isHigh() const {
        return is_high_;
    }

    bool updateState(const T value) {
        if(is_high_ && (value < low_trigger_)) {
            is_high_ = false;
        } else if (!is_high_ && value > high_trigger_) {
            is_high_ = true;
        }
        return is_high_;
    }
private:
    const T high_trigger_{};
    const T low_trigger_{};
    bool is_high_{false};
};