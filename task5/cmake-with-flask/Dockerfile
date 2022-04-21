FROM ubuntu:20.04

#RUN addgroup -g tp2022user node \ && adduser -u tp2022user -G node -s /bin/sh -D node
#USER tp2022user

RUN mkdir -p /opt/techprog
WORKDIR /opt/techprog
COPY . /opt/techprog

RUN apt-get update
RUN apt-get install -y gcc g++ cmake
RUN mkdir -p /opt/techprog/build && cd build && cmake .. && make

CMD ["./bin/C"]
