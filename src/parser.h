#include <absl/log/internal/check_op.h>
#include <absl/strings/string_view.h>
#include <absl/time/time.h>
#include "absl/status/statusor.h"
namespace ttl {
  
  // Parses a date such as:
  // 1h, 1d, 2w, 1m (month), 1y
  // Or combinations such as 
  // 1y2d
  absl::StatusOr<absl::Duration> Parse(absl::string_view input);
}
