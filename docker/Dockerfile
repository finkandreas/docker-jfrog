ARG BASE_IMAGE
FROM $BASE_IMAGE

RUN ls -alh /sourcecode \
  && mpic++ -o /opt/hello_mpi /sourcecode/hello.cpp
