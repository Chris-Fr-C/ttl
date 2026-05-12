// This module will contain the part where the file is registered for later cleanup.

#include <absl/log/internal/check_op.h>
#include <absl/time/civil_time.h>
#include <filesystem>
#include <memory>
namespace ttl {

  class StorageInterface {
    public:
      StorageInterface() = delete;
      absl::Status const Add(const std::filesystem::path &path, const absl::Duration &duration);
      absl::Status const Remove(const std::filesystem::path &path);  
      std::vector<std::filesystem::path> const GetExpired(const absl::CivilDay &now);
  };


  class Register{
    public:
      std::unique_ptr<const StorageInterface> storage_;
      Register(std::unique_ptr<const StorageInterface> storage): storage_(std::move(storage)){};

      absl::Status const Add(const std::filesystem::path &path, const absl::Duration &duration); 
      void const Clean(const absl::CivilDay &now);
  };
}
