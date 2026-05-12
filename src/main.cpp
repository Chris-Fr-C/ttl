#include "absl/flags/parse.h"
#include "absl/log/check.h"
#include "absl/log/initialize.h"
#include "absl/time/time.h"
#include <iostream>
#include <string>
#include <vector>
#include "register.h"

int main(int argc, char *argv[]) {
  absl::InitializeLog();

  // Using parse command line cause the other (flag) forces to write -- which is annoying.
  std::vector<char *> positional_args = absl::ParseCommandLine(argc, argv);

  // 0 is program name, 1 is ttl 2 is file
  if (positional_args.size() < 3) {
    std::cerr << "Usage: " << positional_args[0] << " <ttl> <file>\n";
    return 1;
  }

  std::string file = positional_args[2];

  absl::Duration ttl;
  std::string error;
  bool parsed = absl::ParseDuration(positional_args[1], &ttl);

  CHECK(parsed) << "Failed to parse TTL duration: " << positional_args[1];

  // TODO: fix this cause duration only accepts up to the hour. but we want also day and months.
  std::cout << "Asking to delete " << file << " after "
            << absl::FormatDuration(ttl) << "\n";

  return 0;
}
