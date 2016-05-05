#!/bin/bash

echo "Installing conda..."

curl https://repo.continuum.io/miniconda/Miniconda3-latest-MacOSX-x86_64.sh > conda.sh
bash conda.sh -f -b -p $HOME/conda && rm conda.sh

echo "Creating conda environment..."

conda install --yes \
  notebook \
  ipywidgets \
  pandas \
  numexpr \
  matplotlib \
  scipy \
  seaborn \
  scikit-learn \
  scikit-image \
  sympy \
  cython \
  patsy \
  statsmodels \
  cloudpickle \
  dill \
  numba \
  bokeh \
  h5py \
  terminado \
  networkx \
  django \
  && conda clean -tipsy

pip install deap scoop sphinx flask feather-format tox
pip install --ignore-installed --upgrade https://storage.googleapis.com/tensorflow/mac/tensorflow-0.8.0-py3-none-any.whl

#pip install --upgrade pip 
#pip install sphinx jupyter pandas scipy sklearn matplotlib uvloop http-tools networkx deap django flask feather-format tox
#sudo /opt/pkg/bin/pip install https://storage.googleapis.com/tensorflow/mac/tensorflow-0.7.1-cp35-none-any.whl

mkdir ~/.matplotlib && echo "backend: qt4agg" >> ~/.matplotlib/matplotlibrc

echo "Done."