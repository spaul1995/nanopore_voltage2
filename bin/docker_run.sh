#!/bin/bash

# run as root, user/group permissions will not be preserved
# all simulation output will be assigned uid:gid as 0:0
# docker run -u 0 -it -v $(pwd):/home/docker/run -w /home/docker/run openfoam-ml:latest bash

# run the container as non-root user
UNAME=$(uname)
if [[ $UNAME =~ Darwin ]]; then  # macOS
  USER=$(stat -f "%u:%g" .)
else
  USER=$(stat -c "%u:%g" .)  # assume ubuntu
fi

echo "INFO: User UID/GID info set to $USER"
docker run -it -v $(pwd):/home/openfoam/run -u $USER openfoam-simulate:latest bash
