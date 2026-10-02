ARG BASE_IMG
FROM $BASE_IMG

COPY . /opt/hello.src

RUN mkdir /opt/hello.src/build \
  && cd /opt/hello.src/build \
  && cmake -DCMAKE_INSTALL_PREFIX=/opt/hello ../ \
  && make \
  && make install
