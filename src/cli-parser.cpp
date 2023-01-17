#include "cli-parser.hpp"

namespace Timelapse {
  CliParser::CliParser() {
    this->available_options_map.add_options()
      ((this->help_option_long + this->options_separator + this->help_option).c_str(),
      this->help_option_description.c_str())
      ((this->input_directory_option_long + this->options_separator + this->input_directory_option).c_str(),
      this->input_directory_option_description.c_str())
      ((this->output_directory_option_long + this->options_separator + this->output_directory_option).c_str(),
      this->output_directory_option_description.c_str())
      ((this->output_frame_width_long + this->options_separator + this->output_frame_width).c_str(),
      this->output_frame_width_description.c_str())
      ((this->output_frame_height_long + this->options_separator + this->output_frame_height).c_str(),
      this->output_frame_height_description.c_str())
      ((this->output_frame_second_long + this->options_separator + this->output_frame_second).c_str(),
      this->output_frame_second_description.c_str());
  }

  CliParser::~CliParser() {

  }

  void CliParser::Parse(int args_count, char** args_list) {
    boost::program_options::store(boost::program_options::parse_command_line(
      args_count, args_list, this->available_options_map), this->parsed_options_map);
    boost::program_options::notify(this->parsed_options_map);

    if((this->parsed_options_map.size() == 0) || this->parsed_options_map.count(this->help_option_long)) {
      std::cout << this->available_options_map << std::endl;
      exit(EXIT_SUCCESS);
    }

    if(!(this->parsed_options_map.count(this->input_directory_option_long))) {
      std::cout << "Specify the input video file path!" << std::endl;
      std::cout << this->available_options_map << std::endl;
      exit(EXIT_SUCCESS);
    }

    if(!(this->parsed_options_map.count(this->output_directory_option_long))) {
      std::cout << "Specify the directory to save the output video file!" << std::endl;
      std::cout << this->available_options_map << std::endl;
      exit(EXIT_SUCCESS);
    }

    if(!(this->parsed_options_map.count(this->output_frame_second_long))) {
      std::cout << "Specify the frame per second of the output video file!" << std::endl;
      std::cout << this->available_options_map << std::endl;
      exit(EXIT_SUCCESS);
    }
  }

  std::string CliParser::GetInputFilePath() {
    return this->parsed_options_map[this->input_directory_option_long].as<std::string>();
  }

  std::string CliParser::GetOutputFilePath() {
    return this->parsed_options_map[this->output_directory_option_long].as<std::string>();
  }

  int CliParser::GetOutputFps() {
    return this->parsed_options_map[this->output_frame_second_long].as<int>();
  }

  bool CliParser::HasFrameWidth() {
    return this->parsed_options_map.count(this->output_frame_width_long);
  }

  bool CliParser::HasFrameHeight() {
    return this->parsed_options_map.count(this->output_frame_height_long);
  }

  void CliParser::PrintHelp() {
    std::cout << this->available_options_map << std::endl;
    exit(EXIT_SUCCESS);
  }
}