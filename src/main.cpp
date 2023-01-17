#include "cli-parser.hpp"

int main(int args_count, char** args_list) {
  Timelapse::CliParser cli_parser;
  cli_parser.Parse(args_count, args_list);
}
