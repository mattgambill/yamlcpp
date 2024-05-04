#include<iostream>
#include "yaml-cpp/yaml.h"
#include <filesystem>
#include<vector>
#include<string>
#include<chrono>
#include<fstream>

YAML::Node load_config(std::string filepath)
{
    auto l1 = std::chrono::high_resolution_clock::now();
    const YAML::Node config = YAML::LoadFile(filepath);
    auto l2 = std::chrono::high_resolution_clock::now();
    auto lduration = std::chrono::duration_cast<std::chrono::seconds>(l2-l1);
    std::cout << "Config Loaded in " << lduration.count() << " seconds!\nStarting Simulation...\n";

    return config;
}

void write_csv_file(std::filesystem::path output_path, std::string csv_data)
{
    std::ofstream ofs(output_path);
    ofs << csv_data;
    ofs.close();
    std::cout << "Output CSV File Written!\n";
}

void print_clock_resolution(void)
{
    std::cout << "Clock Resolution (s): " << (double) std::chrono::high_resolution_clock::period::num
             / std::chrono::high_resolution_clock::period::den << '\n';
}