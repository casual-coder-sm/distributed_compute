# distributed_compute

Hands On excercise related to parallel compute using mpi

To install OpenMPI on (Ubuntu) Linux

Option 1:
1. sudo apt-get install libopenmpi-dev
2. sudo apt-get install openmpi-bin
this will get enable the mpicc and mpirun command

Option 2:
1. create folder named openmpi under $HOME
2. Download latest openmpi-xxx.tar.gz from open-mpi.org 
3. sudo apt update && sudo apt install build-essential
4. extract the zip file tar -xzvf openmpi-xxx.tar.gz  => one more sub directory (compilation directory)
5. run ./configure --prefix=$HOME/openmpi
6. make all
7. make install (it will create bin, lib... under OpenMPI)
8. Update $PATH and $LD_LIBRARY_PATH 
