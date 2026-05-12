// This module will contain the part where the file is registered for later cleanup.

#include <absl/log/internal/check_op.h>
#include <absl/time/civil_time.h>
#include <filesystem>
#include <memory>
namespace ttl {

  class StorageInterface {
    public:
 
      StorageInterface() = delete;
      // Add file to clean.
      absl::Status const Add(const std::filesystem::path &path, const absl::Time &end_of_life);
      // Removes the file and cleans it from registry.
      absl::Status const RemoveFile(const std::filesystem::path &path);  
      // Unregisters for TTL but does not remove the file.
      absl::Status const Unregister(const std::filesystem::path &path); 
      std::vector<std::filesystem::path> const GetExpired(const absl::CivilDay &now);
  };


  class Register{
    public:
      std::unique_ptr<const StorageInterface> storage_;
      Register(std::unique_ptr<const StorageInterface> storage): storage_(std::move(storage)){};

      absl::Status const Add(const std::filesystem::path &path, absl::Time &now, const absl::Duration &duration); 
      void const Clean(const absl::CivilDay &now);
  };
}
