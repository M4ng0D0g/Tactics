#pragma once

#include <string>
#include <random>
#include <sstream>
#include <iomanip>
#include <fstream>

namespace utils {

	inline std::string generateUUID() {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		static std::uniform_int_distribution<uint32_t> dist(0, 0xFFFFFFFF);
		static std::uniform_int_distribution<uint16_t> dist16(0, 0xFFFF);
		static std::uniform_int_distribution<uint8_t> dist8(0, 0xFF);

		std::stringstream ss;
		ss << std::hex << std::setfill('0')
			<< std::setw(8) << dist(gen) << "-"
			<< std::setw(4) << (dist16(gen) & 0xFFFF) << "-"
			<< std::setw(4) << ((dist16(gen) & 0x0FFF) | 0x4000) << "-"
			<< std::setw(4) << ((dist16(gen) & 0x3FFF) | 0x8000) << "-"
			<< std::setw(12) << ((uint64_t)dist8(gen) << 40 | (uint64_t)dist8(gen) << 32 |
			(uint64_t)dist8(gen) << 24 | (uint64_t)dist8(gen) << 16 |
			(uint64_t)dist8(gen) << 8  | dist8(gen));

		return ss.str();
	}

	std::string getOrCreateUUID(const std::string& filename) {
		std::ifstream infile(filename);
		std::string uuid;
	
		if(infile) {
			std::getline(infile, uuid);
			infile.close();
			if(!uuid.empty()) return uuid;
		}
	
		uuid = generateUUID();
		std::ofstream outfile(filename);
		if(outfile) {
			outfile << uuid;
			outfile.close();
		}
		
		return uuid;
	}

}