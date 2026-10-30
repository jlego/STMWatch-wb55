#pragma once
#include <cstdint>
namespace Pinetime {
  class Version {
    public:
      static constexpr const char* VersionString() { return VERSION; }
      static constexpr uint32_t Major() { return VERSION_MAJOR; }
      static constexpr uint32_t Minor() { return VERSION_MINOR; }
      static constexpr uint32_t Patch() { return VERSION_PATCH; }
      static constexpr const char* GitCommitHash() { return "unknown"; }
    private:
      static constexpr const char* VERSION = "0.1.0";
      static constexpr uint32_t VERSION_MAJOR = 0;
      static constexpr uint32_t VERSION_MINOR = 1;
      static constexpr uint32_t VERSION_PATCH = 0;
  };
}