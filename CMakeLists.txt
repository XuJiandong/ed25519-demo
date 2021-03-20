cmake_minimum_required(VERSION 3.17)
project(ed25519_demo C)

set(CMAKE_C_STANDARD 11)
include_directories(include)
include_directories(.)

add_executable(ed25519_demo main.c src/external_deps.c src/sign.c src/fe25519.c src/ge25519.c src/sc25519.c src/open.c src/keypair.c)