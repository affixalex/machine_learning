# The real README is [HERE](README.ipynb)

To run locally, just do:

    docker run -v~/path/to/machine_learning:/notebook -p8888:8888
    affixalex/notebook:latest

Note that the `affixalex/notebook` image is very large, although it can 
also run C++ kernels.
