FROM ubuntu:latest

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update -y
RUN apt-get install qtcreator -y
RUN apt-get install build-essential -y
RUN apt install qtbase5-dev qt5-qmake -y
RUN apt-get install qtmultimedia5-dev -y
RUN apt-get install qt6-multimedia-dev -y

COPY . /home/marko/Desktop/kOrganizify2
WORKDIR /home/marko/Desktop/kOrganizify2

RUN mkdir build
WORKDIR ./build
CMD ["cmake", ".."]
CMD ["make"]

CMD ["./kOrganizify"]
