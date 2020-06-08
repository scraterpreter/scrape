**scrape**: the **SCRA**tch inter**P**r**E**ter

[![Scrape Banner](https://cdn.paullee.dev/scrape/banner.png)](https://cdn.paullee.dev/scrape/dash.jpg)

Scrape is an interpreter to run Scratch projects.
First compile .sb3 files into .scrape files using [Scrapec](https://github.com/scraterpreter/scrapec), then run .scrape files using Scrape.

Click [here](https://vimeo.com/424433102) to view a demo.

Join our [Discord Server](https://discord.gg/3zV37x4) for support!

See [COMPATIBILITY.md](COMPATIBILITY.md) for information on compatibility with Scratch.

## Installation and Usage
### Linux (Flatpak)
Scrape and Scrapec are available for installation on FlatHub.

#### Scrape
[![Get it from FlatHub](https://flathub.org/assets/badges/flathub-badge-en.svg)](https://flathub.org/repo/appstream/dev.paullee.scraterpreter.Scrape.flatpakref)
```
flatpak install flathub dev.paullee.scraterpreter.Scrape
alias scrape='flatpak run dev.paullee.scraterpreter.Scrape' # Put this in your .*rc file. (Like .bashrc, .zshrc, etc.)
```

#### Scrapec
[![Get it from FlatHub](https://flathub.org/assets/badges/flathub-badge-en.svg)](https://flathub.org/repo/appstream/dev.paullee.scraterpreter.Scrapec.flatpakref)
```
flatpak install flathub dev.paullee.scraterpreter.Scrapec
alias scrapec='flatpak run dev.paullee.scraterpreter.Scrapec' # Put this in your .*rc file. (Like .bashrc, .zshrc, etc.)
```

### Linux (Snap)
Scrape Snaps are available for installation at the Snap Store.

[![Get it from the Snap Store](https://snapcraft.io/static/images/badges/en/snap-store-black.svg)](https://snapcraft.io/scraterpreter)

```bash
sudo snap install scraterpreter # install scrape
scraterpreter.scrapec project.sb3 # compile the .sb3 file into a .scrape file
scraterpreter.scrape project.scrape # run the .scrape file
```

### Windows (MSI and PIP)
Scrape is available as an MSI on our [releases page](https://github.com/scraterpreter/scrape/releases).
Scrapec is available as [a PIP package on the PYPI](https://pypi.org/project/scrapec/).
There may be some issues with PATH on Windows. Please contact us by creating [a GitHub issue](https://github.com/scraterpreter/scrape/issues/new) or by joining our [Discord Server](https://discord.gg/3zV37x4).

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
