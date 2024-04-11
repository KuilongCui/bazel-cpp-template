#include <iostream>
#include <string>

#include "gflags/gflags.h"
#include "glog/logging.h"

DEFINE_string(Holder, "GFLAGS", "");

int main(int argc, char* argv[]) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);

  std::cout << "Hello world!\n";

  LOG(WARNING) << "GLOG works!";

  LOG(WARNING) << FLAGS_Holder + " works!";

  return 0;
}
