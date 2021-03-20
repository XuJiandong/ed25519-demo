
set -e
cd "$(dirname "${BASH_SOURCE[0]}")"
mkdir -p cmake-build-test
cd cmake-build-test
cmake ..
make all
./ed25519_demo
