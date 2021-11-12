FROM art.cscs.ch/cray-ccpe/cray/ccpe-devel-sles15sp2-x86_64:21.09-101921

COPY . /opt/hello.src

SHELL ["bash", "-l", "-c"]

RUN --mount=type=secret,id=craylic,target=/opt/cray/pe/craype/2.7.9/AutoPass/Lic/CPE-licfile.dat \
  CC --version \
  && mkdir /opt/hello.src/build \
  && cd /opt/hello.src/build \
  && cmake -DCMAKE_INSTALL_PREFIX=/opt/hello ../ \
  && make \
  && make install

