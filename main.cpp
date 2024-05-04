#include "main.hpp"

int main()
{   
    print_clock_resolution();

    namespace fs = std::filesystem;
    fs::path base_path("C:\\Users\\matt.gambill\\Documents\\yamlcpp");
    auto config_path = base_path / "config.yaml";
    
    std::cout << "Config Path is: " << config_path.generic_string() << "\n";
    std::cout << "Loading Config...\n";

    // Load yaml
    YAML::Node config = load_config(config_path.generic_string());
    

    std::string output_string = "First Address,Last Address\n";
    int ad0 = config["build_1"]["Address"].as<int>();
    int ad1 = config["build_100000"]["Address"].as<int>();

    int N = 10000000;
    int addr999;
    int addr000;
    for(int i =0; i < N; i++)
    {
        auto start0 = std::chrono::high_resolution_clock::now();
        addr000 = ad0;
        auto stop0 = std::chrono::high_resolution_clock::now();
        auto start1 = std::chrono::high_resolution_clock::now();
        addr999 = ad1;
        auto stop1 = std::chrono::high_resolution_clock::now();

        auto duration0 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop0 - start0);
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop1 - start1);
        output_string += std::to_string(duration0.count()) + ", " + std::to_string(duration1.count()) + "\n";
        addr000 = 1;
        addr999 = 5;
    }

    std::cout << "Simulation Complete.\nWriting File...\n";
    auto output_path = base_path / "output.csv";
   
    write_csv_file(output_path, output_string);

    return 0;
}