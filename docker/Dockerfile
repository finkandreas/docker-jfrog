FROM docker.io/finkandreas/spack:0.19.2-ubuntu22.04 as builder

RUN spack-install-helper \
    hohgant-cpu \
    osu-micro-benchmarks

FROM docker.io./finkandreas/spack:base-ubuntu22.04

# it is important to keep the paths, otherwise your installation is broken
# all these paths are created with the above `spack-install-helper` invocation
COPY --from=builder /opt/spack-environment /opt/spack-environment
COPY --from=builder /opt/software /opt/software
COPY --from=builder /opt/._view /opt/._view
COPY --from=builder /etc/profile.d/z10_spack_environment.sh /etc/profile.d/z10_spack_environment.sh

RUN fix_spack_install

RUN apt-get -yqq update && apt-get -yqq upgrade \
 && apt-get -yqq install build-essential \
 && rm -rf /var/lib/apt/lists/*
