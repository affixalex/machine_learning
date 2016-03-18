FROM jupyter/notebook

RUN apt-get update && \
	apt-get -y dist-upgrade && \
	apt-get install -y gcc && \
	pip3 install --upgrade pip && \
	pip3 install fake-factory && \
	pip3 install numpy && \
	pip3 install sklearn && \
	pip3 install pandas && \
	pip3 install matplotlib && \
  pip3 install networkx && \
	pip3 install --upgrade https://storage.googleapis.com/tensorflow/linux/cpu/tensorflow-0.7.1-cp34-none-linux_x86_64.whl && \
	rm /var/cache/apt/archives/*
