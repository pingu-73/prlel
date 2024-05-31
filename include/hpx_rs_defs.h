#pragma once

#include <hpx/hpx_init.hpp>
#include <hpx/algorithm.hpp>
#include <cstdint>
#include <iostream>
#include <vector>
#include <hpx/execution.hpp>

extern "C" std::int32_t hpx_init();
extern "C" void hpx_cpy(const int* src, const int* src_end, int* dest);

extern "C" int hpx_main_rust(int argc, char* argv[]);
