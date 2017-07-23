
#include "../boost_1_64_0/boost/program_options.hpp"
namespace po = boost::program_options;

int opt;
po::options_description desc("Allowed options");
desc.add_options()
    ("help", "produce help message")
    ("optimization", po::value<int>(&opt)->default_value(10), 
  "optimization level")
    ("include-path,I", po::value< vector<string> >(), 
  "include path")
    ("input-file", po::value< vector<string> >(), "input file")
;