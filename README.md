# Example Projects and Experiments

## Projects

### System/backend (C)
  * [algorithms_data_structures][algo_data]: various generic data structures
    and algorithms
  * [daemon][daemon]: a simple daemon for running a background process
  * [math][math]: various mathematical functions
  * [memory][memory]: exercises in memory management
  * [opaque_pointer][opaque_ptr]: OOP encapsulation (information-hiding) in C
  * [parsing][parsing]: a parser which identifies all tokens in a string
  * [primes][primes]: outputs all primes up to a given number
  * [state_machine][state_machine]: a simple finite state machine which cycles
    between two states
  * [threads][threads]: pthreads test
  * [time][time]: prints formatted local time on interval
  * [cointab (WIP)][cointab]: terminal cryptocurrency tracker (uses Coinbase
    API)
  * [pygrid][pygrid]: Python ASCII grid module
  * [okcli][okcli]: OkCupid stats via command line

### Frontend
  * [dresscodejs][dresscode]: experimental JS library that quickly generates
    CSS from HTML
  * [jquery-easy-number-animate][jquery-easy-number-animate]: number animation
    library
  * [frosted panel][frosted_panel]: a neat UI experiment (best on large
    screens)
  * [flight tracker][flight_tracker]: another neat UI experiment
  * [Makerbot 3D printer UI][makerbot_ui]: A UI that interfaces with a Makerbot
    3D printer

### Building and Running

* Requirements
  * Linux/Mac
  * Make (recent version)
  * CMake (recent version)
  * C compiler (GCC/Clang)

Projects containing a `CMakeLists.txt` file can be built and run with the
following…

```sh
$ cd <project_directory>
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./bin/<executable>
```

Projects containing a `Makefile` file can be built and run with the following…

```sh
$ cd <project_directory>
$ make      # For some projects
$ make run  # For other projects
```


[algo_data]: algorithms_data_structures
[daemon]: daemon
[math]: math
[memory]: memory
[opaque_ptr]: opaque_pointer
[parsing]: parsing
[primes]: primes
[state_machine]: state_machine
[threads]: threads
[time]: time
[cointab]: https://github.com/shammellee/cointab
[pygrid]: https://github.com/shammellee/pygrid
[okcli]: https://github.com/shammellee/okcli
[dresscode]: https://github.com/shammellee/dresscodejs
[jquery-easy-number-animate]: https://github.com/shammellee/jquery-easy-number-animate
[frosted_panel]: https://codepen.io/amandoesnothaveaname/full/dypKWQV
[flight_tracker]: https://codepen.io/amandoesnothaveaname/full/qjXJYM
[makerbot_ui]: https://github.com/shammellee/makerbot_3d_printer_ui

