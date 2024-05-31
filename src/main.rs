#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        include!("hpx_rs_defs.h");

        fn hpx_init() -> i32;
        unsafe fn hpx_cpy(src: *const i32, src_end: *const i32, dest: *mut i32);
    }
}

//hpx-main
#[no_mangle]
pub extern "C" fn hpx_main_rust(argc: i32, argv: *mut *mut i8) -> i32 {
    let src = vec![1, 2, 3, 4, 5];
    let mut dest = vec![0; src.len()];

    unsafe {
        ffi::hpx_cpy(src.as_ptr(), src.as_ptr().add(src.len()), dest.as_mut_ptr());
    }

    println!("Destination: {:?}", dest);

    0
}

fn main() {
    unsafe {
        ffi::hpx_init(); //initilizing hpx
    }
}
