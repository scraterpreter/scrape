**scrape**: the **SCRA**tch inter**P**r**E**ter

[![Scrape Banner](https://cdn.paullee.dev/scrape/banner.png)](https://cdn.paullee.dev/scrape/dash.jpg)

Scrape is an interpreter to run Scratch projects.
First compile .sb3 files into .scrape files using [Scrapec](https://github.com/scraterpreter/scrapec), then run .scrape files using Scrape.

See [COMPATIBILITY.md](COMPATIBILITY.md) for information on compatibility with Scratch.

## Installation and Usage
### Snap
Scrape Snaps are available for installation at the Snap Store.
```bash
sudo snap install scraterpreter # install scrape
scraterpreter.scrapec project.sb3 # compile the .sb3 file into a .scrape file
scraterpreter.scrape project.scrape # run the .scrape file
```

### Binary
If you follow the instructions listed below to build scrape, and instructions listed [here](https://github.com/scraterpreter/scrapec/blob/master/README.md) to compile scrapec, these commands should be used to run scrape.
```bash
scrapec project.sb3 # compile the .sb3 file into a .scrape file
scrape project.scrape # run the .scrape file
```

## Build Instructions
### Linux
```bash
git clone https://github.com/scraterpreter/scrape.git # clones the repository
cd scrape
mkdir build # creates the build directory
cd build
cmake .. # uses CMake to create a Makefile
make # builds the source code
make install # installs the binary
```
