FROM ubuntu:eoan

ENV CONDA_DIR="/opt/conda"
ENV PATH="$CONDA_DIR/bin:$PATH"

RUN apt -y update && apt -y dist-upgrade && apt -y install wget

# Install conda
RUN CONDA_VERSION="4.7.12" && \
    wget "https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh" -O miniconda.sh && \
    bash miniconda.sh -b -p $CONDA_DIR && \
    echo "export PATH=$CONDA_DIR/bin:$PATH" > /etc/profile.d/conda.sh && \
    rm miniconda.sh && \
    conda update --all --yes && \
    conda config --set auto_update_conda False && \
    rm -r "$CONDA_DIR/pkgs/" && \
    mkdir -p "$CONDA_DIR/locks" && \
    chmod 777 "$CONDA_DIR/locks" && \
    conda install jupyter xeus-cling -c conda-forge

RUN conda install tensorflow \
        scipy \
        cython \
        matplotlib \
        pandas \
        networkx -c conda-forge

RUN mkdir /notebook
EXPOSE 8888
CMD jupyter notebook --ip=0.0.0.0 --port=8888 --allow-root /notebook
