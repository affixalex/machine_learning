#!/bin/bash

echo "Bootstrapping pkgsrc..."
curl -Os https://pkgsrc.joyent.com/packages/Darwin/bootstrap/bootstrap-trunk-x86_64-20160211.tar.gz
sudo tar -zxpf bootstrap-trunk-x86_64-20160211.tar.gz -C /
rm bootstrap-trunk-x86_64-20160211.tar.gz
sudo chown -R $(whoami) /opt/pkg && sudo chown -R $(whoami) /var/db/pkgin
echo "Installing pkgsrc packages..."
/opt/pkg/bin/pkgin -y update
/opt/pkg/bin/pkgin in gcc5-5.3.0nb1 python35-3.5.1nb2 py35-pip-7.1.2 zeromq-4.1.4 py35-qt4-4.11.4nb2 py35-sqlite3-3.5.1nb6
ln -s /opt/pkg/gcc5/bin/gfortran /opt/pkg/bin/gfortran
echo "Installing python packages..."
/opt/pkg/bin/pip install --upgrade pip 
/opt/pkg/bin/pip install sphinx jupyter pandas scipy sklearn matplotlib networkx deap
/opt/pkg/bin/pip install https://storage.googleapis.com/tensorflow/mac/tensorflow-0.7.1-cp35-none-any.whl
mkdir ~/.matplotlib && echo "backend: qt4agg" >> ~/.matplotlib/matplotlibrc
echo "PATH=/opt/pkg/bin:/opt/pkg/sbin:$PATH" >> ~/.bashrc
echo "PATH=/opt/pkg/bin:/opt/pkg/sbin:$PATH" >> ~/.zshrc
echo "Done."