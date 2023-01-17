#ifndef CLI_PARSER
#define CLI_PARSER

#include <iostream>
#include <string>

#include <boost/program_options.hpp>

namespace Timelapse {
class CliParser {
public:
  CliParser ();
  ~CliParser ();
  void Parse(int args_count, char** args_list);
  std::string GetInputFilePath();
  std::string GetOutputFilePath();
  int GetOutputFps();
  bool HasFrameWidth();
  bool HasFrameHeight();
  void PrintHelp();
private:
  boost::program_options::options_description available_options_map;
  boost::program_options::variables_map parsed_options_map;
  const std::string options_separator = ",";
  const std::string help_option = "h";
  const std::string help_option_long = "help";
  const std::string help_option_description = "print help message";
  const std::string input_directory_option = "i";
  const std::string input_directory_option_long = "input-file";
  const std::string input_directory_option_description = "video to create timelapse for [mandatory]";
  const std::string output_directory_option = "o";
  const std::string output_directory_option_long = "output-directory";
  const std::string output_directory_option_description = "directory to save the output video [mandatory]";
  const std::string output_frame_width = "x";
  const std::string output_frame_width_long = "output-frame-width";
  const std::string output_frame_width_description = "frame width of the output video";
  const std::string output_frame_height = "y";
  const std::string output_frame_height_long = "output-frame-height";
  const std::string output_frame_height_description = "frame height of the output video";
  const std::string output_frame_second = "f";
  const std::string output_frame_second_long = "output-fps";
  const std::string output_frame_second_description = "fps of the output video [mandatory]";
};
}

#endif