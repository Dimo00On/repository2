FROM ubuntu:20.04

RUN mkdir -p /opt/techprog
WORKDIR /opt/techprog
COPY . /opt/techprog

RUN apt-get update
RUN apt-get install -y gcc g++ cmake
RUN mkdir -p /opt/techprog/build && cd build && cmake .. && make

RUN useradd tp2022user
USER tp2022user

CMD ["./bin/C"]
