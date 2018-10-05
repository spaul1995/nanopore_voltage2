FROM hfdresearch/swak4foamandpyfoam:latest-v5.0

USER root
RUN apt-get update && apt-get -y install gmsh git sudo

RUN chmod -R 777 /home/openfoam/platforms

USER openfoam
WORKDIR /home/openfoam/run
