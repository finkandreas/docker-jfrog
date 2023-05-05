FROM fedora:37 as builder

ARG CUDA_ARCH=80

ENV DEBIAN_FRONTEND noninteractive
ENV FORCE_UNSAFE_CONFIGURE 1
ENV PATH="/spack/bin:${PATH}"
ENV MPICH_VERSION=4.0.3
ENV CMAKE_VERSION=3.25.2
ENV BASH_ENV="/usr/share/lmod/lmod/init/bash"
ENV LMOD_CMD="/usr/share/lmod/lmod/libexec/lmod"
ENV LMOD_DIR="/usr/share/lmod/lmod/libexec"
ENV LMOD_PKG="/usr/share/lmod/lmod"
ENV LMOD_ROOT="/usr/share/lmod"
ENV LMOD_SETTARG_FULL_SUPPORT="no"
ENV LMOD_VERSION="8.7.20"
ENV LMOD_sys="Linux"
ENV MODULEPATH="/etc/modulefiles:/usr/share/modulefiles:/usr/share/modulefiles/Linux:/usr/share/modulefiles/Core:/usr/share/lmod/lmod/modulefiles/Core"
ENV MODULEPATH_ROOT="/usr/share/modulefiles"
ENV MODULESHOME="/usr/share/lmod/lmod"

RUN dnf -y update

RUN dnf -y install cmake gcc git make autogen automake vim \
                   wget gnupg tar gcc-c++ boost-devel gfortran doxygen libtool \
                   m4 libpciaccess-devel clingo xz bzip2 gzip unzip zlib-devel \
                   ncurses-devel libxml2-devel gsl-devel zstd openblas-devel \
                   flexiblas-devel patch bzip2-devel mpich-devel ninja-build Lmod

RUN wget -qO /usr/local/bin/yq https://github.com/mikefarah/yq/releases/latest/download/yq_linux_386 && chmod a+x /usr/local/bin/yq
# get latest version of spack
RUN git clone https://github.com/spack/spack.git
# set the location of packages built by spack
RUN spack config add config:install_tree:root:/opt/spack

# find all external packages
RUN bash -c 'source /etc/profile.d/modules.sh && spack external find --all --exclude python'

# find compilers
RUN spack compiler find

# tweaking the arguments
RUN yq -i '.compilers[0].compiler.flags.fflags = "-fallow-argument-mismatch"' /root/.spack/linux/compilers.yaml

# copy bunch of things from the ci

RUN spack clean -dfs
RUN spack install openmpi
