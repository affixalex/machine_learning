# The real README is [HERE](README.ipynb)

To run locally, just do:

    docker run -it -p8888:8888 -v$HOME/code/machine_learning:/notebook \
    affixalex/notebook:latest

I run with `-it` so I can just do Ctrl+C to close the container easily.

Note that the `affixalex/notebook` image is very large, although it can 
also run C++ kernels. The C++ support is, shall we say, a bit finicky so 
my actual effort here is with Python. The workflow that I'm trying to 
develop is, in effect, to prototype solutions with Python and then write
much more high performance solutions in C++. 
