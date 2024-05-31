#include "hpx_rs_defs.h"

//hpx_main call hpx_main_rust
int hpx_main(int argc, char* argv[]) {
    int result = hpx_main_rust(argc, argv);

    return hpx::finalize();
}

int main(int argc, char* argv[]) {
    return hpx::init(argc, argv);
}

std::int32_t hpx_init() {
    return hpx::init();
}

void copy_hpx(const int* src, const int* src_end, int* dest) {
    hpx::copy(hpx::execution::par, src, src_end, dest);
}

