# Chess for GBA

Simple chess game made with [Butano engine](https://github.com/GValiente/butano).

Nothing to see for now, still working on it!


## Dependencies

This program uses [Butano](https://github.com/GValiente/butano), which is licensed under the zlib license.


## Build

> See my [Butano template README](https://github.com/copyrat90/butano-template/blob/main/README.md) for more detailed info about setting up dev environment.

First, make sure the [Butano](https://github.com/GValiente/butano) is set up correctly, with its own dependencies.

Next, change the path in `Makefile` which points to the directory where `butano.mak` is located,
from `LIBBUTANO   :=  C:/Libs/butano/butano` to your own path.

That should do it, now do `make -j16` and see what happens.


## License

Source code is licensed under the MIT/Expat license.

Chess pieces and board sprites are made by DANI MACCARI, and can be found [here](https://dani-maccari.itch.io/pixel-chess).
