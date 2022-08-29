{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
    name = "alexandria-env";
    buildInputs = with pkgs; [
#        gcc
#        gdb
        clang
        lldb
        cmake
        SDL2.dev
        SDL2_image
        libdecor
        pkg-config
    ];
}