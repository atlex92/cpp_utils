#pragma once

class Initializable {
public:
  virtual ~Initializable() = default;
  bool isInitialized() const {
    return is_initialized_;
  }

  bool initialize() {
    bool ret{false};
    if (initializeImpl()) {
      setInitFlag();
      ret = true;
    }
    return ret;
  }

protected:
  virtual bool initializeImpl() = 0;
  void setInitFlag() {
    is_initialized_ = true;
  }
  void resetInitFlag() {
    is_initialized_ = false;
  }

private:
  bool is_initialized_{false};
};
