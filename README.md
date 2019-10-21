# The real README is [HERE](README.ipynb)

To run locally, just do:

    docker run -v~/path/to/machine_learning:/notebook -p8888:8888
    affixalex/notebook:latest

Note that the `affixalex/notebook` image is very large, although it can 
also run C++ kernels. The C++ support is, shall we say, a bit finicky so 
my actual effort here is with Python. The workflow that I'm trying to 
develop is, in effect, to prototype solutions with Python and then write
much more high performance solutions in C++. 
